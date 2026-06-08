/*

 */
#ifndef __MVS__
#define __ptr32
#endif
#include "zosinfo-version.h"
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

int main ()
{
   Zos_Information zos_information;
   std::string error_message;
   bool areTesting = true;
   std::cout << "z/OS Info - version " << ZOSINFO_VERSION_STRING << std::endl; 
   
   int result = zosInfo (zos_information, error_message, areTesting);

   if (result != 0)
   {
      std::cerr << "Error retrieving z/OS information: " << error_message << std::endl;
      std::cout << "zosInfoTest: FAIL" << std::endl;
      return 1;
   }

   std::cout << zos_information.to_string() << std::endl;
   std::cout << "zosInfoTest: PASS" << std::endl;
   return 0;
}
