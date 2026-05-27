# zOSInfo

![Platform](https://img.shields.io/badge/platform-z%2FOS-1f6feb)
![Language](https://img.shields.io/badge/language-C%2B%2B-00599C)
![Compiler](https://img.shields.io/badge/compiler-IBM%20Open%20XL-0f9d58)
![License](https://img.shields.io/badge/license-MIT-lightgrey)


## Overview
zOSInfo is a lightweight C++ utility for retrieving system-level information
from z/OS Unix System Services (USS). It is intended for developers and
system programmers who need programmatic access to system metadata such as
CPU configuration, sysplex details, and memory statistics.

---

## Motivation

z/OS system information is typically accessed via assembler or system utilities.
This project provides a simple C++ interface for retrieving that data in USS.
These control blocks are readable and do not require special privileges under
normal configurations.

---

## Required Environment

- z/OS Unix System Services (USS)
- No special permissions required (read-only access to system control blocks)

---

## Example Output

```

System Name: ZAL1
Sysplex Name: ADCDPL
Sysplex ID: 1A
Product Owner: IBM CORP
Product Name: z/OS
Product Version: 02.04.00
CPU Model Number: 8562
CPU Serial Number: 44B8
Version Code: 00
Logical Partition Identifier: 01
Number of CPUs: 3
Number of 4K Frames: 8209452
Real Storage (MB): 32768
Number of regular CPUs: 2
Number of specialty CPUs: 1

````

---

## Output Description

- **System Name** – z/OS system identifier  
- **Sysplex Name** – Name of the sysplex cluster  
- **Sysplex ID** – 2-character unique identifier of a sysplex  
- **Product Owner** – Typically "IBM CORP"  
- **Product Name** – IBM operating system name  
- **Product Version** – Format: `version.release.modification`  
  - **Version** – Major generation of the operating system architecture  
  - **Release** – Feature update within that version  
  - **Modification Level** – Maintenance or patch level (`00` = base release)  
- **CPU Model Number** – IBM server Machine Type (CPC type)  
- **CPU Serial Number** – Processor serial number  
- **Real Storage (MB)** – Total physical memory in MB  
- **Number of CPUs** – Total number of processors  
- **Number of regular CPUs** – Standard processors  
- **Number of specialty CPUs** – Specialty processors (e.g., zIIP)  

---

## How It Works

The program begins at the PSA (Prefixed Save Area), which resides at address 0
for each processor. It traverses various system control blocks to locate and
extract system-level information.

### Control Blocks Used

- `cct.h`
- `cda.h`
- `csd.h`
- `cvt.h`
- `ecvt.h`
- `pcca.h`
- `pccavt.h`
- `psa.h`
- `rce.h`
- `rmct.h`

### Notes

- Header files were created using the DSECT conversion utility described in the  
  *z/OS XL C/C++ User's Guide*.
- Control block definitions are documented in the following IBM manuals:

  - *z/OS V2R4 MVS Data Areas Volume 1 (ABE - IAR)*  
  - *z/OS V2R4 MVS Data Areas Volume 2 (IAX - ISG)*  
  - *z/OS V2R4 MVS Data Areas Volume 3 (ITK - RQE)*  
  - *z/OS V2R4 MVS Data Areas Volume 4 (RRP - XTL)*  

© Copyright International Business Machines Corporation 1988, 2020

---

## Project Structure

- `zosInfo.cpp`        – Main implementation  
- `zosInfoTest.cpp`    – Test program  
- `Makefile`           – Build script  
- `Makefile-Test`      – Test build script  
- `*.h`                – Control block mappings  

---

## Build Instructions

```sh
cd zOSInfo
gmake
````

---

## Usage

This library is intended to be used within C++ applications.

### Include Header

```cpp
#include "zosInfo.h"
```

### Example Code

```cpp
Zos_Information zos_information;
std::string error_message;
bool areTesting = false;

int result = zosInfo(zos_information, error_message, areTesting);
if (result != 0)
{
    std::cerr << "Error retrieving z/OS information: "
              << error_message << std::endl;
    return 1;
}

std::cout << zos_information.to_string() << std::endl;
```

A complete usage example is available in `zosInfoTest.cpp`.

---

## Testing

A test program is provided to demonstrate usage.

### Build and Run Test

```sh
cd zOSInfo
gmake --file=Makefile-Test
./zosInfoTest
```

---

## Limitations

* Designed specifically for z/OS USS
* Depends on access to system control blocks

---

## Compiler

* IBM Open XL C/C++ 2.1 for z/OS
* Clang version 18.1.0

---

## License

This project is licensed under the MIT License.

---

## Support

For issues, please use GitHub Issues.
For direct contact: [john.parke@alebra.com](mailto:john.parke@alebra.com)

