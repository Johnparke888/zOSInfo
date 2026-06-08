#pragma once
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>

extern void ebcdic_field_to_ascii (const unsigned char *input_field, std::size_t field_length, std::string &output);
extern void ebcdic_field_to_ascii (const unsigned char *input_field, std::size_t field_length, char *output_buffer, std::size_t output_buffer_size);

struct Zos_Information
{
   Zos_Information ()
       : real_storage_mbytes (0), number_of_cpus (0), number_of_frames (0), number_regular_cpus (0), number_specialty_cpus (0), version_code (""),
         logical_partition_identifier (""), cpu_serial_number (""), cpu_model_number (""), sysplex_name (""), sysplex_id (""), system_name (""),
         product_owner (""), product_name (""), product_version ("")
   {
   }

   public:
   int real_storage_mbytes; /* CVT real storage in MB */
   int number_of_cpus;
   int number_of_frames; /* RCE total number of frames in 4k units */
   int number_regular_cpus;
   int number_specialty_cpus;
   std::string product_name;
   std::string product_owner;
   std::string product_version;
   std::string sysplex_id;
   std::string sysplex_name;
   std::string system_name;
   std::string version_code;                 /* - version code              */
   std::string logical_partition_identifier; /* - logical partition id      */
   std::string cpu_serial_number;            /* - cpu serial number         */
   std::string cpu_model_number;             /* - cpu model number          */

   public:
   int get_real_storage_mbytes () const
   {
      return real_storage_mbytes;
   }

   int get_number_of_cpus () const
   {
      return number_of_cpus;
   }

   int get_number_of_frames () const
   {
      return number_of_frames;
   }

   int get_number_regular_cpus () const
   {
      return number_regular_cpus;
   }

   int get_number_specialty_cpus () const
   {
      return number_specialty_cpus;
   }

   const std::string &get_product_name () const
   {
      return product_name;
   }

   const std::string &get_product_owner () const
   {
      return product_owner;
   }

   const std::string &get_product_version () const
   {
      return product_version;
   }

   const std::string &get_sysplex_id () const
   {
      return sysplex_id;
   }

   const std::string &get_sysplex_name () const
   {
      return sysplex_name;
   }

   const std::string &get_system_name () const
   {
      return system_name;
   }

   const std::string &get_version_code () const
   {
      return version_code;
   }

   const std::string &get_logical_partition_identifier () const
   {
      return logical_partition_identifier;
   }

   const std::string &get_cpu_serial_number () const
   {
      return cpu_serial_number;
   }

   const std::string &get_cpu_model_number () const
   {
      return cpu_model_number;
   }
   std::string to_string () const
   {
      std::ostringstream oss;
      oss << "System Name: " << system_name << "\n"
          << "Sysplex Name: " << sysplex_name << "\n"
          << "Sysplex Id: " << sysplex_id << "\n"
          << "Product Owner: " << product_owner << "\n"
          << "Product Name: " << product_name << "\n"
          << "Product Version: " << product_version << "\n"
          << "CPU Model Number: " << cpu_model_number << "\n"
          << "CPU Serial Number: " << cpu_serial_number << "\n"
          << "Version Code: " << version_code << "\n"
          << "Logical Partition Identifier: " << logical_partition_identifier << "\n"
          << "Number of CPU's: " << number_of_cpus << "\n"
          << "Number of 4K Frames: " << number_of_frames << "\n"
          << "Real Storage (MB): " << real_storage_mbytes << "\n"
          << "Number of regular CPU's: " << number_regular_cpus << "\n"
          << "Number of specialty CPU's: " << number_specialty_cpus;
      return oss.str ();
   }
};

int zosInfo (Zos_Information &zos_information, std::string &error_message, bool testing = false);
