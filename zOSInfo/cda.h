#ifndef __cda__
#define __cda__
#include <cstddef>
#include <Arb.h>

struct CommHeaderX
{

   struct
   {
      char cdassys[4];   /* sysid of system initiating request    */
      char cdasname[16]; /* name of system initiating rqst  @e050 */
      char cdasusys[4];  /* unique sysid of source                */
      char cdasid[4];    /* unique id of system initiating rqst   */
   } cdasrce;            /* source of message                      */

   struct
   {
      char cdadsys[4];   /* sysid of destination system           */
      char cdadname[16]; /* name of destination system      @e050 */
      char cdadusys[4];  /* unique sysid of destination           */
      char cdadid[4];    /* unique id of destination system       */
   } cdadest;            /* destination of message                */

   char cdavers[4];  /* version number                        */
   char cdacommd[8]; /* command to/from com tasks             */
   char cdaargu[8];  /* argument for command                  */
   char cdanpad;     /* number of pad bytes             @i194 */
   char _filler1[3]; /* filler                          @i194 */

   union {
      struct
      {
         unsigned char msbLength;       // MSB size of header AND data
         unsigned char lsbLength;       // LSB size of header AND data
         unsigned char msbSequence;     // MSB of 16 bit sequencing value
         unsigned char lsbSequence;     // LSB of 16 bit sequencing value
      };

      short int cdallbb; /* length of message */
      short int cdafill; /* filler            */
   };
};


#endif
