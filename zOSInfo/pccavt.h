#pragma once
/*
* PCCAVT programming interface information
* PCCAVT is a programming interface.
* PCCAVT heading information
* Common name: Physical Configuration Communication Area Vector Table
* Macro ID: IHAPCCAT
* DSECT name: PCCAVT
* Eye-catcher ID: NONE
* Storage attributes:
* Subpool: 245
* Key: 0
* 
* Size: CVTMAXMP+1 PCCAT00P Entries
* Length:  512
* Created by: IEAVNIP0
* Pointed to by: CVTPCCAT field of the CVT data area.
* Function: Contains the address of a PCCA for each CPU.

*/
#ifndef __MVS__
#define __ptr32
#endif

struct pccavt
{
   void *__ptr32 pccat00p;         /* -         address of pcca for cpu 0.  there are   */
                                   /* CVTMAXMP + 1 entries. Do not reference entries beyond CVTMAXMP + 1. */
   void *__ptr32 pccat01p;         /* -         address of pcca for cpu 1               */
   void *__ptr32 pccat02p;         /* -         address of pcca for cpu 2               */
   void *__ptr32 pccat03p;         /* -         address of pcca for cpu 3               */
   void *__ptr32 pccat04p;         /* -         address of pcca for cpu 4               */
   void *__ptr32 pccat05p;         /* -         address of pcca for cpu 5               */
   void *__ptr32 pccat06p;         /* -         address of pcca for cpu 6               */
   void *__ptr32 pccat07p;         /* -         address of pcca for cpu 7               */
   void *__ptr32 pccat08p;         /* -         address of pcca for cpu 8               */
   void *__ptr32 pccat09p;         /* -         address of pcca for cpu 9               */
   void *__ptr32 pccat10p;         /* -         address of pcca for cpu 10              */
   void *__ptr32 pccat11p;         /* -         address of pcca for cpu 11              */
   void *__ptr32 pccat12p;         /* -         address of pcca for cpu 12              */
   void *__ptr32 pccat13p;         /* -         address of pcca for cpu 13              */
   void *__ptr32 pccat14p;         /* -         address of pcca for cpu 14              */
   void *__ptr32 pccat15p;         /* -         address of pcca for cpu 15              */
   void *__ptr32 pccat16_31p[16];  /* -         address of pccas for cpus 16-31      @L3A */
   void *__ptr32 pccat32_63p[32];  /* -         address of pccas for cpus 32-63      @L3A */
   void *__ptr32 pccat64_127p[64]; /* -         address of pccas for cpus 64-127     @L4A  */
};

#define pccatend 0x200 /* END OF PCCAT.  There are CVTMAXMP+1 */
#define rcelen 1408    /* Length of RCE */
