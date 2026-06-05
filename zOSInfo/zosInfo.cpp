/*
 * zosInfo.cpp
 *
 * Retrieve information from z/OS control blocks pertaining to product and sysplex information.
 *
 *     PSA (addr 0) -> FLCCVT at offset x'10' -> CVT
 *
 *
 * Notes:
 *   - The PSA, CVT, and ECVT all live in 31-bit storage. In a 64-bit
 *     (LP64) program, ordinary pointers are 64-bit, so we MUST use
 *     __ptr32 to declare pointers to / inside these blocks. Without
 *     __ptr32 the compiler would sign-extend the 31-bit value or
 *     read 8 bytes instead of 4 and you would chase garbage.
 *
 *   - String fields in these blocks are EBCDIC. We convert any input_field
 *     we want to display with __e2a_l() (a no-op on EBCDIC builds;
 *     a real conversion on ASCII builds).
 */

#include "psa.h"
#include "cvt.h"
#include "ecvt.h"
#include "cct.h"
#include "rmct.h"
#include "pcca.h"
#include "pccavt.h"
#include "rce.h"
#include "csd.h"
#include "zosInfo.h"

#include <cstdio>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>

#if defined(__MVS__)
#include <unistd.h> /* __e2a_l() */
#endif

#define cct_length 0x0190
#define csd_length 0x0200
#define cvt_length 0x0500
#define ecvt_length 0x0438
#define pcca_length 0x0248
#define pccavt_length 0x0200
#define psa_length 0x1000
#define rce_length 0x0580
#define rmct_length 0x0400

// Control block eye-catchers (acronyms) in EBCDIC. These are not necessarily at the start of the
// block, so we will check them at their documented offsets.

static const unsigned char CVT_ACRONYM[4] = {0x40, 0xC3, 0xE5, 0xE3};
static const unsigned char ECVT_ACRONYM[4] = {0xC5, 0xC3, 0xE5, 0xE3};
static const unsigned char RMCT_ACRONYM[4] = {0xD9, 0xD4, 0xC3, 0xE3};
static const unsigned char CCT_ACRONYM[4] = {0xC3, 0xC3, 0xE3, 0x40};
static const unsigned char PCCA_ACRONYM[4] = {0xD7, 0xC3, 0xC3, 0xC1};
static const unsigned char RCE_ACRONYM[4] = {0xD9, 0xC3, 0xC5, 0x40};
static const unsigned char CSD_ACRONYM[4] = {0xC3, 0xE2, 0xC4, 0x40};

/*
 *  Helper: copy a fixed-length EBCDIC input_field into a NUL-terminated
 *  buffer, convert to ASCII for display, and trim trailing blanks.
 *  "input_field" need not be NUL-terminated; "field_length" is its declared length.
 *
 */

void ebcdic_field_to_ascii (const unsigned char *input_field, std::size_t field_length, char *output_buffer, std::size_t output_buffer_size)
{

   if (output_buffer_size == 0)
   {
      return;
   }

   std::size_t bytes_to_copy = (field_length < output_buffer_size - 1) ? field_length : output_buffer_size - 1;
   std::memcpy (output_buffer, input_field, bytes_to_copy);
   output_buffer[bytes_to_copy] = '\0';

#if defined(__MVS__)
   /* Convert in place from EBCDIC (IBM-1047) to ASCII (ISO8859-1).
    * If the source file is compiled in EBCDIC mode, __e2a_l is still
    * safe to call; the result for a pure-EBCDIC build will look
    * unchanged because stdio is also EBCDIC. */

   __e2a_l (output_buffer, bytes_to_copy);
#endif

   /* Trim trailing blanks (and the now-EBCDIC-or-ASCII space byte). */
   while (bytes_to_copy > 0 && (output_buffer[bytes_to_copy - 1] == ' ' || output_buffer[bytes_to_copy - 1] == '\0'))
   {
      output_buffer[--bytes_to_copy] = '\0';
   }
}


void ebcdic_field_to_ascii (const unsigned char *input_field, std::size_t field_length, std::string &output)
{
   // Copy the raw EBCDIC bytes into the string (length-based, no null-termination assumption).
   output.assign (reinterpret_cast<const char *> (input_field), field_length);

#if defined(__MVS__)
   // Convert in place IBM-1047 -> ISO8859-1. Operates on the string's buffer.
   if (!output.empty ())
   {
      __e2a_l (&output[0], output.size ());
   }
#endif

   // Trim trailing ASCII blanks (0x20). In ASCII-mode compilation ' ' == 0x20,
   // which matches the post-conversion padding bytes.

   std::size_t trimmed_length = output.size ();

   while (trimmed_length > 0 && output[trimmed_length - 1] == ' ')
   {
      --trimmed_length;
   }

   output.resize (trimmed_length);
}


int zosInfo (Zos_Information &zos_information, std::string &error_message, bool areTesting)
{

   /*
    * Step 1: get the CVT pointer from PSA.flccvt.
    * PSA - Prefixed Save Area
    *
    */
   std::ostringstream message;

   error_message.clear ();

   psa *__ptr32 psa_ptr = 0; /* PSA is always at virtual address 0. */

   cvt *__ptr32 cvt_ptr = static_cast<cvt *__ptr32> (psa_ptr->flccvt);

   //  Note: the CVT contains a pointer to the ECVT, and a pointer to the RMCT, which in turn contains a pointer to the CCT.
   //  We will sanity check all of these.

   zos_ecvt *__ptr32 ecvt_ptr = static_cast<zos_ecvt *__ptr32> (cvt_ptr->cvtecvt);       // Extended Communications Vector Table
   rmct *__ptr32 rmct_ptr = static_cast<rmct *__ptr32> (cvt_ptr->cvtopctp);              // Resource Manager Control Table
   cct *__ptr32 cct_ptr = static_cast<cct *__ptr32> (rmct_ptr->rmctcct);                 // system resources manager cpu management control table
   pccavt *__ptr32 pccavt_ptr = static_cast<pccavt *__ptr32> (cvt_ptr->cvtpccat);        // Physical Configuration Communication Area Vector Table
   pcca *__ptr32 pcca_ptr = static_cast<pcca *__ptr32> (pccavt_ptr->pccat00p);           // physical configuration communication area
   rce *__ptr32 rce_ptr = static_cast<rce *__ptr32> (cvt_ptr->cvtrcep);                  // RSM Control and Enumeration Area
   csd *__ptr32 csd_ptr = static_cast<csd *__ptr32> (cvt_ptr->cvtcsd);                   // common system data area


   // If we're in testing mode, display the pointers we just read and the sizes of the blocks they point to, so we can verify that our offsets and
   // lengths match reality.

   if (areTesting)
   {
      auto display_pointer = [] (const char *name, const void *ptr) { std::cout << name << "=" << ptr << '\n'; };

      auto display_size = [] (const char *name, std::size_t actual, std::size_t expected)
      {
         std::cout << std::hex << "size of " << name << "=0x" << actual << " " << name << "_length=0x" << expected
                   << " match=" << (actual == expected ? "yes" : "no") << std::dec << '\n';
      };

      auto display_offset = [] (const char *field_name, const char *struct_name, std::size_t actual, std::size_t expected)
      {
         std::cout << std::hex << "offset of " << field_name << " in " << struct_name << "=0x" << actual << " expected=0x" << expected
                   << " match=" << (actual == expected ? "yes" : "no") << std::dec << '\n';
      };

      display_pointer ("psa_ptr", static_cast<void *> (psa_ptr));
      display_pointer ("cvt_ptr", static_cast<void *> (cvt_ptr));
      display_pointer ("ecvt_ptr", static_cast<void *> (ecvt_ptr));
      display_pointer ("rmct_ptr", static_cast<void *> (rmct_ptr));
      display_pointer ("cct_ptr", static_cast<void *> (cct_ptr));
      display_pointer ("pccavt_ptr", static_cast<void *> (pccavt_ptr));
      display_pointer ("pcca_ptr", static_cast<void *> (pcca_ptr));
      display_pointer ("rce_ptr", static_cast<void *> (rce_ptr));
      display_pointer ("csd_ptr", static_cast<void *> (csd_ptr));

      std::cout << '\n';

      display_size ("cct", sizeof (cct), cct_length);
      display_size ("csd", sizeof (csd), csd_length);
      display_size ("cvt", sizeof (cvt), cvt_length);
      display_size ("ecvt", sizeof (zos_ecvt), ecvt_length);
      display_size ("pcca", sizeof (pcca), pcca_length);
      display_size ("pccavt", sizeof (pccavt), pccavt_length);
      display_size ("psa", sizeof (psa), psa_length);
      display_size ("rce", sizeof (rce), rce_length);
      display_size ("rmct", sizeof (rmct), rmct_length);

      std::cout << '\n';

      display_offset ("cvtecvt", "cvt", offsetof (cvt, cvtecvt), 0x8c);
      display_offset ("cvtopctp", "cvt", offsetof (cvt, cvtopctp), 0x25c);
      display_offset ("rmctcct", "rmct", offsetof (rmct, rmctcct), 0x4);
      display_offset ("cvtpccat", "cvt", offsetof (cvt, cvtpccat), 0x2fc);
      display_offset ("pccat00p", "pccavt", offsetof (pccavt, pccat00p), 0x0);
      display_offset ("cvtrcep", "cvt", offsetof (cvt, cvtrcep), 0x490);
      display_offset ("cvtcsd", "cvt", offsetof (cvt, cvtcsd), 0x294);

      std::cout << std::endl;
   }

   // At this point we have pointers to all the main control blocks we want to read.
   // We will validate that they look plausible before we trust them.
   // Validate that the pointers we just read from the CVT look plausible (non-null and point to blocks with the expected eye-catchers).

   auto validate_pointer = [&message, &error_message] (const void *ptr, const char *block_name, const char *pointer_name) -> bool
   {
      if (ptr == nullptr)
      {
         message.str ("");
         message.clear ();

         message << pointer_name << " is zero - cannot locate " << block_name << ".";

         error_message = message.str ();
         return false;
      }

      return true;
   };

   // Helper to validate that a pointer is non-null and that the block it points to starts with the expected eye-catcher bytes.
   auto validate_eyecatcher = [&message, &error_message, areTesting] (const void *ptr,
                                                                      const unsigned char *actual,
                                                                      const unsigned char *expected,
                                                                      std::size_t length,
                                                                      const char *block_name,
                                                                      const char *pointer_name) -> bool
   {
      if (ptr == nullptr)
      {
         message.str ("");
         message.clear ();

         message << pointer_name << " is zero - cannot locate " << block_name << ".";

         error_message = message.str ();
         return false;
      }

      if (std::memcmp (actual, expected, length) != 0)
      {
         message.str ("");
         message.clear ();

         message << block_name << " acronym mismatch at " << ptr << " - got ";

         for (std::size_t i = 0; i < length; ++i)
         {
            if (i != 0)
            {
               message << ' ';
            }

            message << std::hex << static_cast<int> (actual[i]);
         }

         error_message = message.str ();

         if (areTesting)
         {
            std::cout << error_message << std::endl;
         }

         return false;
      }

      return true;
   };

   /////////////////////////////////////////////////////////////////


   /*
    * Step 2: sanity check the CVT acronym. The first 4 bytes of the
    * input_field cvtcvt should be the EBCDIC characters ' ','C','V','T'
    *
    */
   if (!validate_eyecatcher (cvt_ptr, cvt_ptr->cvtcvt, CVT_ACRONYM, 4, "CVT", "FLCCVT"))
   {
      return -1;
   }

   int cvtrlstg = cvt_ptr->cvtrlstg;       //  size of actual real storage online - KB

   /*
    * Step 3: sanity check the ECVT acronym. The first 4 bytes of the dsect
    */
   if (!validate_eyecatcher (ecvt_ptr, ecvt_ptr->ecvtecvt, ECVT_ACRONYM, 4, "ECVT", "CVTECVT"))
   {
      return -1;
   }

   /*
    * Step 4: sanity check the RMCT acronym. The first 4 bytes of the dsect
    */
   if (!validate_eyecatcher (rmct_ptr, rmct_ptr->rmctname, RMCT_ACRONYM, 4, "RMCT", "CVTOPCTP"))
   {
      return -1;
   }

   /*
    * Step 5: sanity check the CCT acronym. The first 4 bytes of the dsect
    */
   if (!validate_eyecatcher (cct_ptr, cct_ptr->cctcct, CCT_ACRONYM, 4, "CCT", "RMCTCCT"))
   {
      return -1;
   }

   /*
    * Step 6: sanity check the pointer to the PCCAVT.
    * The PCCAVT does not have an eye-catcher, but we can at least check that the pointer is non-null and points to a plausible block of
    * memory before we dereference it to get the PCCA pointer and check the PCCA eye-catcher.
    * Physical Configuration Communication Area Vector Table (PCCAVT) is an array of pointers to PCCAs, one per CPU. The CVT has a pointer to the
    * start of the PCCAVT array, and the first entry (for CPU 0).
    *
    */
   if (!validate_pointer (pccavt_ptr, "PCCAVT", "CVTPCCAT"))
   {
      return -1;
   }
   /*
    * Step 7: sanity check the PCCA acronym. The first 4 bytes of the
    *
    */
   if (!validate_eyecatcher (pcca_ptr, pcca_ptr->pccapcca, PCCA_ACRONYM, 4, "PCCA", "PCCAT00P"))
   {
      return -1;
   }
   /*
    * Step 8: sanity check the RCE acronym. The first 4 bytes of the
    */
   if (!validate_eyecatcher (rce_ptr, rce_ptr->rceid, RCE_ACRONYM, 4, "RCE", "CVTRCEP"))
   {
      return -1;
   }
   /*
    * Step 8: sanity check the CSD acronym. The first 4 bytes of the
    *
    */
   if (!validate_eyecatcher (csd_ptr, csd_ptr->csdcsd, CSD_ACRONYM, 4, "CSD", "CVTCSD"))
   {
      return -1;
   }

   ebcdic_field_to_ascii (ecvt_ptr->ecvtsplx, sizeof (ecvt_ptr->ecvtsplx), zos_information.sysplex_name);

   /* CLONE value (1-2 char system identifier within the sysplex). */

   ebcdic_field_to_ascii (ecvt_ptr->ecvtclon, sizeof (ecvt_ptr->ecvtclon), zos_information.sysplex_id);

   /* System name lives in the CVT, not the ECVT. */

   ebcdic_field_to_ascii (cvt_ptr->cvtsname, sizeof (cvt_ptr->cvtsname), zos_information.system_name);


   /* z/OS product owner / name / version-release-mod. */

   std::string pver;
   std::string prel;
   std::string pmod;

   ebcdic_field_to_ascii (ecvt_ptr->ecvtpown, sizeof (ecvt_ptr->ecvtpown), zos_information.product_owner);
   ebcdic_field_to_ascii (ecvt_ptr->ecvtpnam, sizeof (ecvt_ptr->ecvtpnam), zos_information.product_name);
   ebcdic_field_to_ascii (ecvt_ptr->ecvtpver, sizeof (ecvt_ptr->ecvtpver), pver);
   ebcdic_field_to_ascii (ecvt_ptr->ecvtprel, sizeof (ecvt_ptr->ecvtprel), prel);
   ebcdic_field_to_ascii (ecvt_ptr->ecvtpmod, sizeof (ecvt_ptr->ecvtpmod), pmod);


   ebcdic_field_to_ascii (pcca_ptr->cpu_model_number, sizeof (pcca_ptr->cpu_model_number), zos_information.cpu_model_number);
   ebcdic_field_to_ascii (pcca_ptr->cpu_serial_number, sizeof (pcca_ptr->cpu_serial_number), zos_information.cpu_serial_number);
   ebcdic_field_to_ascii (pcca_ptr->version_code, sizeof (pcca_ptr->version_code), zos_information.version_code);
   ebcdic_field_to_ascii (
       pcca_ptr->logical_partition_identifier, sizeof (pcca_ptr->logical_partition_identifier), zos_information.logical_partition_identifier);


   zos_information.number_of_cpus = cct_ptr->ccvcpuct;
   zos_information.number_of_frames = rce_ptr->rcepool;

   zos_information.product_version = pver + "." + prel + "." + pmod;
   zos_information.real_storage_mbytes = cvtrlstg / 1024;
   zos_information.number_regular_cpus = csd_ptr->csd_number_online_bylpar_standard_cps;
   zos_information.number_specialty_cpus = csd_ptr->csd_number_online_sups;

   return 0;
}
