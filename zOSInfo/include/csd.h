#pragma once


/*
*
* Common name: common system data area (CSD).
* Macro id:* IHACSD.
* DSECT name:CSD.
* Eye-catcher id: CSD.
* Offset:  0
* Length:  4
* Storage attributes:
* Subpool:   245.
* Key:       0, not fetch protected.
* Residency: below 16m, SQA.
* Size:312 Bytes.
* Created by: IEAVNIP0 during nip.
* Pointed to by:
* CVT fields cvtcsd and cvtcsdrl.
* Function:
* Contains information about the processors in the system.
*
ONLY the following fields are part of the programming interface information:

CSD_BYLPAR_CP_MASK_ADDR
CSD_BYLPAR_ZAAP_MASK_ADDR
CSD_BYLPAR_zCBP_MASK_ADDR
CSD_BYLPAR_ZIIP_MASK_ADDR
CSD_CPU_ALIVE_ADDR
CSD_NUMBER_ONLINE_ByLPAR_IFAS
CSD_NUMBER_ONLINE_ByLPAR_zAAPs
CSD_NUMBER_ONLINE_ByLPAR_zCBPs
CSD_NUMBER_ONLINE_CPUS
CSD_NUMBER_ONLINE_IFAS
CSD_NUMBER_ONLINE_STANDARD_CPS
CSD_NUMBER_ONLINE_zCBPs
CSD_NUMBER_ONLINE_zIIPS
CSDCPUAL
CSDCPUOL
CSDRCPT
*/
#ifndef __MVS__
#define __ptr32
#endif

struct csd
{
   unsigned char csdcsd[4]; /* -    CONTROL BLOCK ACRONYM IN EBCDIC */
   union {
      int csdcpujw; /* CPUS AVAILABLE FOR JOB SCHEDULING    @D1A */
      struct
      {
         unsigned char csdcpujs[2]; /* -      Bit mask of CPUs available for Affinity         */
         short int _filler1;        /* -         Reserved: (was CSDCHAD)              @L9C    */
         struct
         {
            struct
            {
               unsigned char csdcpual[2]; /* -      Bit mask of CPUs currently alive.               */
            }; /* -         bit mask of cpus available to process        */
            short int csdcpuol; /* -         Number of CPUs currently alive. This         */
         }; /* cpus online information word.        @d1a              */
         struct
         {
            unsigned char csdscfl1; /* -      first byte of csdscwrd                          */
            unsigned char csdscfl2; /* -      second byte of csdscwrd                         */
            unsigned char csdscfl3; /* -      third byte of csdscwrd                          */
            unsigned char csdscfl4; /* -      fourth byte of csdscwrd                         */
         }; /* -         supervisor control information               */
         int _filler2;               /* Was csdaxpow, csdaxpal, csdaxpol     @l9c              */
         unsigned char csdmf1cp[2];  /* -      bit mask of cpus varied on or offline.          */
         unsigned char csdacr;       /* -      value of x'ff' means acr is in progress         */
         unsigned char csdflags;     /* -      flag byte                                       */
         unsigned char csdrv039[64]; /* reserved                             @lac              */
         unsigned char csdrv04c[16]; /* Reserved space on dword bdy          @hac              */
         unsigned char _filler3[2];  /* -      reserved: was csdcpwlm               @l9c       */
         short int csdddrct;         /* -         ddr device allocation interface count        */
         int csdgdcc;                /* -         count of usable clock comparators            */
         int csdgdint;               /* -         count of usable cpu timers currently in      */
         int csdgdtod;               /* -         count of cpus that have access to a good     */
         int csdtcnt;                /* -         count of tape allocations in progress        */
         int csducnt;                /* -         count of unit record allocations in          */
         struct
         {
            struct
            {
               unsigned char _filler4[2];  /* -      CPU 0                                           */
               unsigned char _filler5[2];  /* -      CPU 1                                           */
               unsigned char _filler6[2];  /* -      CPU 2                                           */
               unsigned char _filler7[2];  /* -      CPU 3                                           */
               unsigned char _filler8[2];  /* -      CPU 4                                           */
               unsigned char _filler9[2];  /* -      CPU 5                                           */
               unsigned char _filler10[2]; /* -      CPU 6                                           */
               unsigned char _filler11[2]; /* -      CPU 7                                           */
               unsigned char _filler12[2]; /* -      CPU 8                                           */
               unsigned char _filler13[2]; /* -      CPU 9                                           */
               unsigned char _filler14[2]; /* -      CPU A                                           */
               unsigned char _filler15[2]; /* -      CPU B                                           */
               unsigned char _filler16[2]; /* -      CPU C                                           */
               unsigned char _filler17[2]; /* -      CPU D                                           */
               unsigned char _filler18[2]; /* -      CPU E                                           */
               unsigned char _filler19[2]; /* -      CPU F                                           */
            }; /* -        table of bit masks for testing bits in        */
         }; /* -        table of bit masks for testing bits in        */
         unsigned char csdiosid; /* reserved -- do not reuse             @l6c              */
         unsigned char csdicpus; /* -      the number of initial (lpar-defined)            */
         struct
         {
            struct
            {
               unsigned char csdi_bylpar_ifas; /* -                                      @HBA            */
            } ;               /* -                                    @LEA              */
         }; /* -      The number of initial (LPAR-defined)            */
         struct
         {
            unsigned char csdi_bylpar_sups; /* -                                      @hba            */
         } csdisups;                        /* -      the number of initial (lpar-defined)            */
         unsigned char csdrv0a4[4];         /* reserved was csdcpuvw                @lcc              */
         void *__ptr32 csdcmt;              /* -            address of the configuration management   */
         void *__ptr32 csdesat;             /* -            address of the excessive spin        @l1a */
         void *__ptr32 csdtmpes;            /* -            address of the excessive spin        @d3c */
         void *__ptr32 csdrcfv;             /* -            address of the reconfiguration vector     */
         unsigned char csdcpsid[16];        /* table of side id for each cpu in     @l4a              */
         int csdexsfl_word;                 /* flags for excessive spin             @pca              */
         void *__ptr32 csdlwvct;            /* -            address of the loadwait vector table @h4a */
         struct
         {
            unsigned char csdcrypt[2]; /* -    bit mask of online crypto facilities.@h7a         */
            unsigned char csdcrins[2]; /* -    bit mask of installed crypto facilities.          */
         }; /* crypto information word.             @h7a              */
         int csd_number_online_cpus; /* 32-bit count of alive cpus. this                       */
         void *__ptr32 csdumvcl;     /* -            address of the ieeumvcl entry point  @h5a */
         void *__ptr32 csdustck;     /* -            address of the ieeustck entry point  @h5a */
         void *__ptr32 csd_esta;     /* -            address of the isn$esta entry point  @h5a */
         void *__ptr32 csd_frr;      /* -            address of the isn$frr  entry point  @h5a */
         void *__ptr32 csdscpin;     /* -            address of the isn$scpi entry point  @h6a */
         short int csdmaxmp;         /* maximum cpu address in configuration @l9a              */
         unsigned char _filler20[2]; /* -     reserved.                            @l9c        */
         struct
         {
            int csdexcnt; /* count of active users of global spin-loop              */
            int csdexsec; /* expiration time (down to seconds) for                  */
         }; /* dword bdy for cds instruction to update                */
         void *__ptr32 csdglex;      /* -            address of the macro processor (blwglex)  */
         unsigned char csdplpn;      /* prsm logical partition number        @h8a              */
         unsigned char _filler21;    /* reserved.  was csdexsfl              @pcd              */
         unsigned char _filler22[2]; /* reserved                             @05a              */

         void *__ptr32 csdrcpt; /* Address to the LCCA,LCCX and PCCA                      */

         int csd_number_online_bylpar_ifas; /* zAAPs online                    @HBA                   */
                                            /* zCBPs online                         @LEA              */

         int csd_number_online_bylpar_standard_cps; /* Regular CPs online      @HBA                           */
                                               

         int csd_number_online_sups;            /* ziips online                                                     */
            
         unsigned char csdr110[88];             /* -    RESERVED.                            @LDC         */
        
         void *__ptr32 csd_cpu_alive_addr;      /* CPU alive mask pointer. Points to a                    */
         void *__ptr32 csd_bylpar_cp_mask_addr; /* Pointer to mask of processors defined                  */

         void *__ptr32 csd_bylpar_zaap_mask_addr;                /* Pointer to mask of processors defined                  */
                                                                 /* @LEA                                                   */
         void *__ptr32 csd_bylpar_ziip_mask_addr;                /* Pointer to mask of processors defined                  */
         void *__ptr32 csd_cpus_going_on_or_off_mask_addr;       /* Pointer to mask of CPUs                                */
         void *__ptr32 csd_cpus_manipulated_by_wlm_addr;         /* Pointer to mask of CPUs                                */
         void *__ptr32 csd_cpus_varied_offline_by_operator_addr; /* Pointer to mask of                                     */
         void *__ptr32 csd_cpus_taken_offline_by_acr_addr;       /* Pointer to mask of CPUs                                */
         unsigned char _filler23[120];                           /* -     RESERVED (primarily readonly)      @LBC          */
         //  __extension__ double csdend[0];                     /* End of CSD control block             @L9C              */
      };
   };
};

/* Values for field "csdscfl1" */
#define csdrv042 0x80 /* -  RESERVED                                        */
#define csdsysnd 0x40 /* -        SYSTEM-WIDE NON-DISPATCHABILITY BIT.      */
#define csdrv001 0x20 /* -  RESERVED                                        */
#define csdrv002 0x10 /* -  RESERVED                                        */
#define csdrv003 0x08 /* -  RESERVED                                        */
#define csdrv004 0x04 /* -  RESERVED                                        */
#define csdrv005 0x02 /* -  RESERVED                                        */
#define csdrv006 0x01 /* -  RESERVED                                        */

/* Values for field "csdscfl2" */
#define csdrv007 0x80 /* -  RESERVED                                        */
#define csdrv008 0x40 /* -  RESERVED                                        */
#define csdrv009 0x20 /* -  RESERVED                                        */
#define csdrv010 0x10 /* -  RESERVED                                        */
#define csdrv011 0x08 /* -  RESERVED                                        */
#define csdrv012 0x04 /* -  RESERVED                                        */
#define csdrv013 0x02 /* -  RESERVED                                        */
#define csdrv014 0x01 /* -  RESERVED                                        */

/* Values for field "csdscfl3" */
#define csdrv015 0x80 /* -  RESERVED                                        */
#define csdrv016 0x40 /* -  RESERVED                                        */
#define csdrv017 0x20 /* -  RESERVED                                        */
#define csdrv018 0x10 /* -  RESERVED                                        */
#define csdrv019 0x08 /* -  RESERVED                                        */
#define csdrv020 0x04 /* -  RESERVED                                        */
#define csdrv021 0x02 /* -  RESERVED                                        */
#define csdrv022 0x01 /* -  RESERVED                                        */

/* Values for field "csdscfl4" */
#define csdrv023 0x80 /* -  RESERVED                                        */
#define csdrv024 0x40 /* -  RESERVED                                        */
#define csdrv025 0x20 /* -  RESERVED                                        */
#define csdrv026 0x10 /* -  RESERVED                                        */
#define csdrv027 0x08 /* -  RESERVED                                        */
#define csdrv028 0x04 /* -  RESERVED                                        */
#define csdrv029 0x02 /* -  RESERVED                                        */
#define csdrv030 0x01 /* -  RESERVED                                        */

/* Values for field "csdflags" */
#define csdmp 0x80    /* -        RESERVED - DO NOT USE                @L7C */
#define csdstchk 0x40 /* -        STORAGE CHECK INDICATOR - SET BY RSM      */
#define csdcpudn 0x20 /* -  GLOBAL BIT INDICATING CPU INITIALIZATION        */
#define csdndpar 0x10 /* -  RUNNING IN NON-DEDICATED PARTITION.  @P7A       */
#define csdprcpu 0x08 /* -  Preserve CPU status                  @07A       */
#define csdrv036 0x04 /* -  RESERVED                                        */
#define csdrv037 0x02 /* -  RESERVED                                        */
#define csdrv038 0x01 /* -  RESERVED                                        */

/* Values for field "csdexsfl_word" */
#define csdexsfl_esai 0xF0 /* SET BY IEEVESAI                      @PCA          */
#define csdexsfl_exsn 0x0F /* SET BY IEEVEXSN                      @PCA          */

/* Values for field "csdend" */
#define csdlen 0x200                /* Length of CSD control block          @L9C          */
#define csd_max_crypto_address 15   /* Maximum supported Crypto address     @L9A          */
#define csd_max_affinity_address 15 /* Max CPU supporting affinity        @L9A            */
