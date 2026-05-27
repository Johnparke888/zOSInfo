#pragma once
/*
*
* 
* Common name: Extended Communications Vector Table
* Macro ID: IHAECVT
* DSECT name: ECVT
* Owning component: Supervisor Control (SC1C5)
* Eye-catcher ID: ECVT
* Offset: 0
* Length: 4
* Storage attributes:
* Residency: EXTENDED NUCLEUS, Above 16M line
* Size: Offset of ECVTEND minus the offset of ECVT
* Created by: IEAVECVT
* Pointed to by: CVTECVT
* Serialization: Dependent on the specific field (see field descriptions)
* Function: The ECVT is a logical extension of the CVT.
* 
* z/OS: z/OS MVS Data Areas Volume 1 (ABE - IAR)
* © Copyright IBM Corp. 1988, 2020

*/
#ifndef __MVS__
#define __ptr32
#endif
struct zos_ecvt
{
   unsigned char ecvtecvt[4]; /* ECVT ACRONYM                                        */
   void *__ptr32 ecvtcplx;    /* -              ADDRESS OF IXCCPLX CONTROL           */
   unsigned char ecvtsplx[8]; /* -           SYSPLEX NAME USED FOR           @D1A    */
   int ecvtsple;              /* -              SYSPLEX PARTITIONING ECB THAT   @D1A */
   void *__ptr32 ecvtsplq;    /* -              SYSPLEX PARTITIONING QUEUE.     @D1A */
   void *__ptr32 ecvtstc1;    /* -       STCKSYNC, NON-AR MODE,          @L1A        */
   void *__ptr32 ecvtstc2;    /* -       STCKSYNC, NON-AR MODE,          @L1A        */
   void *__ptr32 ecvtstc3;    /* -       STCKSYNC, AR MODE,              @L1A        */
   void *__ptr32 ecvtstc4;    /* -       STCKSYNC, AR MODE,              @L1A        */
   void *__ptr32 ecvtappc;    /* -           ANCHOR FOR APPC DATA STRUCTURES @L5C    */
   void *__ptr32 ecvtsch;     /* -           ANCHOR FOR APPC SCHEDULER       @L5A    */
   union {
      unsigned char ecvtiosf[4]; /* IOS FLAGS                       @L7A */
      struct
      {
         unsigned char ecvtios1;    /* -           IOS FLAGS BYTE 1                @L7A */
         unsigned char ecvtios2;    /* -           RESERVED.                       @L7A */
         unsigned char ecvtios3;    /* -           RESERVED.                       @L7A */
         unsigned char ecvtios4;    /* -           RESERVED.                       @L7A */
         void *__ptr32 ecvtomda;    /* -           ADDRESS OF THE OPERATIONS       @L3A */
         unsigned char ecvtcsvn[2]; /* -           Counter Second Version Number   @A2A */
         unsigned char ecvtcnz;     /* -           Ownership: Consoles             @0FA */
         unsigned char ecvtaloc;    /* -           Ownership: Allocation           @09A */
         void *__ptr32 ecvtbpms;    /* -           BELOW 16M, PAGEABLE DEVICE      @L4A */
         void *__ptr32 ecvtbpme;    /* -           BELOW 16M, PAGEABLE DEVICE      @L4A */
         void *__ptr32 ecvtapms;    /* -           ABOVE 16M, PAGEABLE DEVICE      @L4A */
         void *__ptr32 ecvtapme;    /* -           ABOVE 16M, PAGEABLE DEVICE      @L4A */
         void *__ptr32 ecvtqucb;    /* -           XCF DATA AREA (IXCYQUCB)        @D2C */
         struct
         {
            void *__ptr32 ecvtssdf;             /* -           THE ADDRESS OF THE FREE SSD     @D3A */
            int ecvtssds;                       /* -           SEQUENCE NUMBER INCREMENTED     @D3A */
         } _ecvtssdd;                           /* -           DOUBLE WORD USED TO COMPARE     @D3A */
         void *__ptr32 ecvt_customer_area_addr; /* Customer Area Address.                           */
         void *__ptr32 ecvtsrbt;                /* -           THE ADDRESS OF THE SSD          @D3A */
         void *__ptr32 ecvtdpqh;                /* Queue of DU-AL Pools (DPHs)     @D6C             */
         void *__ptr32 ecvttcre;                /* -           IEAVTCRE ENTRY POINT ADDRESS.   @L9A */
         unsigned char ecvtxcfg[16];            /* SYSPLEX CONFIGURATION           @L6A             */
         void *__ptr32 ecvtr078;                /* -           RESERVED. DO NOT USE.           @LAC */
         void *__ptr32 ecvtr07c;                /* -           RESERVED. DO NOT USE.           @LAA */
         void *__ptr32 ecvtscha;                /* -       THE ADDRESS OF IEAVSCHA.        @LBC     */
         void *__ptr32 ecvthfxs;                /* Address of IEAHFSXV             @0NA             */
         void *__ptr32 ecvtdlcb;                /* Address of DLCB (CSVDLCB)                        */
         void *__ptr32 ecvtnttp;                /* -           ADDRESS OF SYSTEM LEVEL         @LHA */
         void *__ptr32 ecvtsrbj;                /* SRB-mode enclave join           @NOA             */
         void *__ptr32 ecvtsrbl;                /* SRB-mode enclave leave          @NOA             */
         void *__ptr32 ecvtmsch;                /* -          THE ADDRESS OF SLM MESSAGE      @LNA  */
         void *__ptr32 ecvtcal;                 /* -          THE ADDRESS OF SLM COMMON AREA  @LNA  */
         unsigned char ecvtload[8];             /* -          EDITED MVS LOAD PARAMETER       @P1C  */
         unsigned char ecvtmlpr[8];             /* -           LOAD parameter used for this    @P1C */
         void *__ptr32 ecvttcp;                 /* -           Token used by TCP/IP            @02A */
         void *__ptr32 ecvthisnmt;              /* HISMT Service                   @A2A             */
         void *__ptr32 ecvtnvdm;                /* -           NETVIEW DM TCP ID BLOCK POINTER @D4C */
         unsigned char ecvtr0bc[4];             /* -           RESERVED. DO NOT USE.           @D4C */
         void *__ptr32 ecvtgrmp;                /* -           GRM DATA BLOCK POINTER          @LCA */
         void *__ptr32 ecvtwlm;                 /* -          WLM VECTOR TABLE POINTER        @LQC  */
         void *__ptr32 ecvtcsm;                 /* -           Pointer to Communication        @03A */
         void *__ptr32 ecvtctbl;                /* Customer anchor table.                           */
         void *__ptr32 ecvtpmcs;                /* STATUS SET,MC,PROCESS           @D5C             */
         void *__ptr32 ecvtpmcr;                /* STATUS RESET,MC,PROCESS         @D5C             */
         void *__ptr32 ecvtstx1;                /* STAX DEFER=YES,LINKAGE=BRANCH   @LDA             */
         void *__ptr32 ecvtstx2;                /* STAX DEFER=NO,LINKAGE=BRANCH    @LDA             */
         unsigned char ecvtslid[4];             /* -          CONTAINS THE SLIP PER TRAP ID   @LFA  */
         void *__ptr32 ecvtcsvt;                /* -           CSV TABLE.                      @LGA */
         void *__ptr32 ecvtasa;                 /* -           ASA TABLE.                      @LIA */
         void *__ptr32 ecvtexpm;                /* -       GETXSB SERVICE ROUTINE.         @LLA     */
         void *__ptr32 ecvtocvt;                /* -           ANCHOR FOR OpenMVS              @LKA */
         void *__ptr32 ecvtoext;                /* -           ANCHOR FOR OpenMVS              @LKA */
         void *__ptr32 ecvtcmps;                /* -       Address of the                  @P2A     */
         void *__ptr32 ecvtnucp;                /* -           Pointer to nucleus dataset      @P3A */
         void *__ptr32 ecvtxrat;                /* -           XES anchor table for branch     @LOA */
         void *__ptr32 ecvtpwvt;                /* -           Address of the Processor        @LPA */
         unsigned char ecvtclon[2];             /* -           1 or 2 character value used to  @LRA */
         unsigned char ecvtgmod;                /* GRS mode of operation           @LUA             */
         unsigned char ecvtlpdelen;             /* Length of LPDE                  @ACA             */
         void *__ptr32 ecvtducu;                /* -       DUCT update                     @A3A     */
         void *__ptr32 ecvtalck;                /* -       ALIAS check                     @A6A     */
         void *__ptr32 ecvtsxmp;                /* IEAMSXMP target. This field is  @A8A             */
         unsigned char ecvtr118[2];             /* -           RESERVED.                       @A8C */
         short int ecvtptim;                    /* Time value for Parallel Detach  @07A             */
         void *__ptr32 ecvtjcct;                /* -           Address of the JES              @LVA */
         void *__ptr32 ecvtlsab;                /* -        Pointer to Logger Services      @0LC    */
         void *__ptr32 ecvtetpe;                /* Addr of routine IEAVETPE.       @MLA             */
         void *__ptr32 ecvtsymt;                /* Address of the system static    @LXC             */
         void *__ptr32 ecvtesym;                /* Address of IEAVESYM routine.    @LXC             */
         struct
         {
            unsigned char ecvtflg1;    /* First miscellaneous flag        @LXA             */
            unsigned char _filler1[3]; /* @LXA                                             */
         } _ecvtflgs;                  /* Miscellaneous Flags             @P6C             */
         void *__ptr32 ecvtesy1;       /* Address of routine IEAVESY1.    @LXA             */
         void *__ptr32 ecvtpetm;       /* Addr of routine IEAVPETM        @MHA             */
         void *__ptr32 ecvtetpt;       /* Addr of routine IEAVETPT        @MHA             */
         void *__ptr32 ecvtenvt;       /* -           Pointer to Enclave Vector Table @LWA */
         int ecvtvser;                 /* Reserved for use by VSE         @P7C             */
         void *__ptr32 ecvtlsen;       /* Address of module IEAVLSEN      @04A             */
         void *__ptr32 ecvtdgnb;       /* Address of DGNB                 @D7A             */
         unsigned char ecvthdnm[8];    /* Hardware name of the processor  @LXA             */
         unsigned char ecvtlpnm[8];    /* LPAR name of the processor      @LXA             */
         unsigned char ecvtvmnm[8];    /* VM userid of the virtual        @LXA             */
         void *__ptr32 ecvtgrm;        /* Address of routine CRG52GRM     @M3C             */
         void *__ptr32 ecvtseif;       /* Address of routine CRG52SEI.    @M3C             */
         void *__ptr32 ecvtaes;        /* Address of routine IEAVEAES.    @05A             */
         void *__ptr32 ecvtrsmt;       /* Address of registration         @05A             */
         unsigned char ecvtmmem[16];   /* Exit manager name of the   @05A                  */
         void *__ptr32 ecvtipa;        /* Address of the Initialization   @LZA             */
         unsigned char ecvtmmet[16];   /* -          Exit Manager Token of the MVS   @M3A  */
         void *__ptr32 ecvtmmeq;       /* MVS Miscellaneous Event Exit    @M3A             */
         void *__ptr32 ecvtmmea;       /* Address of the MVS              @M3A             */
         void *__ptr32 ecvteaex;       /* Address of routine IEAVEAEX.    @05A             */
         void *__ptr32 ecvteaux;       /* Address of routine IEAVEAUX.    @M3A             */
         void *__ptr32 ecvtmmec;       /* Count of RMs registered with    @M3A             */
         void *__ptr32 ecvtipst;       /* Address of IPST                 @PAA             */
         void *__ptr32 ecvtrrsw;       /* Address of the RRS world object @M3A             */
         void *__ptr32 ecvtrrtt;       /* RRS EOT Resmgr address          @0AA             */
         void *__ptr32 ecvtrrmt;       /* RRS EOM Resmgr Address          @0AA             */
         void *__ptr32 ecvtpred;       /* Product Enable/Disable block    @LYA             */
         unsigned char ecvtcemt[16];   /* -          Exit Manager Token of the       @M4A  */
         void *__ptr32 ecvtceme;       /* Address of routine CTXEMGRE.    @M4A             */
         void *__ptr32 ecvtcemr;       /* Address of routine CTXCEMGR.    @M4A             */
         int ecvtpseq;                 /* Product sequence number.                         */
         unsigned char ecvtpown[16];   /* Product owner                   @LYA             */
         unsigned char ecvtpnam[16];   /* Product name.                   @LYA             */
         unsigned char ecvtpver[2];    /* Product version                 @LYA             */
         unsigned char ecvtprel[2];    /* Product release                 @LYA             */
         unsigned char ecvtpmod[2];    /* Product mod level               @LYA             */
         unsigned char ecvtpdvl;       /* Product development level.      @PNA             */
         unsigned char ecvtttfl;       /* Transaction Trace flags.        @MIA             */
         void *__ptr32 ecvtcurx;       /* Address of routine CTXCSURX.    @M4A             */
         void *__ptr32 ecvtctxr;       /* Addr of routine CTXRSMGR.       @M7A             */
         void *__ptr32 ecvtcrgr;       /* Addr of routine CRGRSMGR.       @M8A             */
         void *__ptr32 ecvtcsrb;       /* Addr of routine CTXSRB.         @MBA             */
         void *__ptr32 ecvtrem1;       /* Addr of routine CRGRREM1 entry  @M6A             */
         void *__ptr32 ecvtrem2;       /* Addr of routine CRGRREM2 entry  @M9A             */
         void *__ptr32 ecvtxfr3;       /* Addr of routine IEAVXFR3 entry  @PCC             */
         void *__ptr32 ecvtcicb;       /* @NYA                                             */
         void *__ptr32 ecvtdlpf;       /* Address of first CDE on dynamic @MCA             */
         void *__ptr32 ecvtdlpl;       /* Address of last CDE on dynamic  @MCA             */
         void *__ptr32 ecvtsrbr;       /* Return for T6EXIT RETURN=SRBSUSP                 */
         void *__ptr32 ecvtbcba;       /* Address of SOMObjects data structure             */
         unsigned char ecvtpidn[8];    /* PID number                      @MEA             */
         struct
         {
            void *__ptr32 ecvtrmdp; /* CRGREMD Parameter List Free Pool Ptr             */
            int ecvtrmds;           /* CRGREMD Parameter List Free Pool                 */
         } _ecvtrmd;                /* Double word for the CRGREMD                      */
         void *__ptr32 ecvtrsu1;    /* Addr of routine IEAVRSU1 (Resume                 */
         void *__ptr32 ecvtpest;    /* Address of the Pause Element Segment             */
         void *__ptr32 ecvtcdyn;    /* Context Services Dynamic Area   @NIC             */
         void *__ptr32 ecvtfcda;    /* @NYA                                             */
         unsigned char ecvteorm[8]; /* -           Potential real high storage address  */
         void *__ptr32 ecvtcbls;    /* Addr of IEAVCBLS (see IHACBLS)  @MMA             */
         void *__ptr32 ecvtrins;    /* Address of RRS installed function                */
         void *__ptr32 ecvtttca;    /* Address of Transaction Trace    @MMA             */
         void *__ptr32 ecvtlcxt;    /* Address of LCCXVT               @MMA             */
         unsigned char ecvtoesi[4]; /* -          When non-zero, orig SCCBMESI    @0BA  */
         unsigned char ecvtoxsb[4]; /* -          When non-zero, orig SCCBNXSB    @0BA  */
         void *__ptr32 ecvtestu;    /* SVC update service              @MMA             */
         void *__ptr32 ecvtrbup;    /* -          IEARBUP service                 @MMA  */
         unsigned char ecvtosai[4]; /* -          When non-zero, orig SCCBSAIX    @MMA  */
         void *__ptr32 ecvtpfa;     /* -          Address of PFA block.                 */
         void *__ptr32 ecvtcrdt;    /* Entry for RACF to get CDRACDTY bits              */
         void *__ptr32 ecvtctb2;    /* Customer anchor table 2                          */
         void *__ptr32 ecvtjaof;    /* Address of IEAVJAOF when not 0.         @0IA     */
         void *__ptr32 ecvtxpcb;
         unsigned char ecvtlpub[16];          /* -         IBM Publisher ID for ILM        @MNA   */
         unsigned char ecvtlpid[8];           /* -          IBM Product ID for ILM          @MNA  */
         unsigned char ecvtlvid[8];           /* -           IBM Version ID for ILM          @MNA */
         unsigned char ecvtlkln[4];           /* -           Length of IBM Key for ILM       @MNA */
         void *__ptr32 ecvtlkad;              /* -           Address of IBM Key for ILM      @MNA */
         unsigned char ecvtcachelinesize[2];  /* -  CPU Cache Line Size             @N3A          */
         unsigned char ecvtcachelinestartbdy; /* - CPU Cache Line Start Boundary   @N3A           */
         unsigned char ecvt_osprotect;        /* -      - When non-0, OSPROTECT system    @0JA    */
         void *__ptr32 ecvtrfpt;              /* -          Address of routine to update    @N5A  */
         short int ecvt_installed_cpu_hwm;    /* The highest CPU number currently                 */
         short int ecvt_installed_cpu_at_ipl; /* The highest CPU number installed                 */
         void *__ptr32 ecvtcrit;              /* -           Address of Common Resource      @NCA */
         double ecvttedvectortableaddr;       /* Pointer to the Timed Event      @NJA             */
         double ecvttedstoragebytesallocated; /* Amount of storage used       @NJA                */
         void *__ptr32 ecvtteds;              /* Pointer to the Timed Event      @NJA             */
         struct
         {
            unsigned char ecvtmmig_byte0; /* Machine Migration Byte 0        @NUA             */
            unsigned char _filler2[11];   /* Machine Migration Bytes 1-11    @NUA             */
         } _ecvtmmig;                     /* -          Machine Migration               @NUA  */
         struct
         {
            unsigned char ecvtosarxh[4];              /* -           SCCBSARX - High Half            @0EA */
            unsigned char ecvtosarxl[4];              /* -           SCCBSARX - Low Half             @0EA */
         } _ecvtosarx;                                /* -          When non-zero, orig SCCBSARX    @0EA  */
         unsigned char ecvt_hcwa[8];                  /* HCW                             @NMA             */
         void *__ptr32 ecvtslca;                      /* -          Owner: LE                       @MNA  */
         void *__ptr32 ecvtcpgum;                     /* IGVCPGUM                  @N3A                   */
         void *__ptr32 ecvtcpfrm;                     /* IGVCPFRM                  @N3A                   */
         void *__ptr32 ecvtcpgcm;                     /* IGVCPGCM                  @N3A                   */
         void *__ptr32 ecvt4qv1;                      /* IEAV4QV1                        @MQA             */
         void *__ptr32 ecvt4qv2;                      /* IEAV4QV2                        @MQA             */
         void *__ptr32 ecvt4qv3;                      /* IEAV4QV3                        @MQA             */
         void *__ptr32 ecvt4qv4;                      /* IEAV4QV4                        @MQA             */
         void *__ptr32 ecvt4qv5;                      /* IEAV4QV5                        @MQA             */
         void *__ptr32 ecvt4qv6;                      /* IEAV4QV6                        @MQA             */
         void *__ptr32 ecvt4qv7;                      /* IEAV4QV7                        @MQA             */
         void *__ptr32 ecvttenc;                      /* Timeused Enclave                @H1A             */
         void *__ptr32 ecvtscf;                       /* IEAVSCAF                        @MSA             */
         void *__ptr32 ecvttsth;                      /* IEAVTSTH                        @PJC             */
         void *__ptr32 ecvtstc5;                      /* -       STCKSYNC, AR MODE,              @MVA     */
         void *__ptr32 ecvtstc6;                      /* -       STCKSYNC, NON-AR MODE,          @MVA     */
         void *__ptr32 ecvtch1;                       /* IEAVECH1 Storage Check Service  @PLA             */
         void *__ptr32 ecvtch2;                       /* IEAVECH2 Storage Check Service  @PLA             */
         void *__ptr32 ecvtceab;                      /* CEAB                            @MYA             */
         void *__ptr32 ecvtaxrb;                      /* AXRB                            @MYA             */
         void *__ptr32 ecvtect;                       /* IEAVEECT service                @MYA             */
         void *__ptr32 ecvtfacl;                      /* Address of 2048-byte facility area               */
         short int ecvtmaxcoreid;                     /* When CvtProcAsCore is on, the maximum CPU        */
         short int ecvtnumcpuidsincore;               /* The maximum number of CPUs that can "fit" on     */
         void *__ptr32 ecvtntrm;                      /* Name/Token resource manager @   @0GA             */
         void *__ptr32 ecvtsdc;                       /* Owner: SDC                      @N2A             */
         void *__ptr32 ecvthiab;                      /* Anchor for Hardware                              */
         void *__ptr32 ecvthwip;                      /* Anchor Block for BCPii AS                        */
         void *__ptr32 ecvtscpin;                     /* Address of current SCPINFO data @NBA             */
         double ecvthp1;                              /* Pointer to Heap Pool 1 structure                 */
         short int ecvtmaxmpnumbytesinmask;           /* Maximum number of bytes a                        */
         short int ecvtphysicaltologicalmask;         /* "OR" this value with a                           */
         short int ecvtlogicaltophysicalmask;         /* "AND" this value                                 */
         unsigned char ecvtappflags;                  /* Application-set flags                            */
         unsigned char ecvtr37f;                      /* Reserved for future             @A1C             */
         void *__ptr32 ecvt_getsrbidtoken;            /* Address of the routine to return                 */
         void *__ptr32 ecvtxtsw;                      /* Address of "Cross-memory TCB or                  */
         void *__ptr32 ecvt_smf_cms_lockinst_addr;    /* Address of the SMF CMS                           */
         void *__ptr32 ecvt_enqdeq_cms_lockinst_addr; /* Address of the ENQ/DEQ                           */
         void *__ptr32 ecvt_latch_cms_lockinst_addr;  /* Address of the Latch CMS                         */
         void *__ptr32 ecvt_cms_lockinst_addr;        /* Address of the CMS                               */
         void *__ptr32 ecvthzrb;                      /* Address of the HZRB                              */
         void *__ptr32 ecvtgtz;                       /* Address of GTZ block                             */
         void *__ptr32 ecvtcpguc;                     /* IGVCPGUC                  @NXA                   */
         void *__ptr32 ecvtcpfrc;                     /* IGVCPFRC                  @NXA                   */
         void *__ptr32 ecvtcpgcc;                     /* IGVCPGCC                  @NXA                   */
         short int ecvt_installed_core_hwm;           /* The highest core number                          */
         short int ecvt_installed_core_at_ipl;        /* The highest core number                          */
         unsigned char ecvtlso[16];                   /* Leap second value in STCKE                       */
         unsigned char ecvtldto[16];                  /* Local time/date offset in                        */
         unsigned char ecvtizugsp[4];                 /* Address of z/OSMF Global Storage                 */
         unsigned char ecvtr3d4[12];                  /* Reserved                        @ABA             */
         struct
         {
            unsigned char ecvt_boostinfo_flags0;               /* @0KA                                             */
            unsigned char ecvt_boostinfo_sysparm_flags;        /* @0KA                                             */
            unsigned char ecvt_boostinfo_flags1;               /* @0KA                                             */
            unsigned char ecvt_boostinfo_sd_flags1;            /* @0KA                                             */
            short int ecvt_boostinfo_transientziipcores;       /* Number of zIIP                                   */
            unsigned char ecvtr3e6;                            /* @0MC                                             */
            unsigned char ecvt_boostlevel;                     /* 0: initial deliverable                    @0MA   */
            unsigned char ecvt_boostinfo_expected_endetod[16]; /* Time                                             */
         } _ecvt_boostinfo;                                    /* Valid only when CVTBoost is on  @0KA             */
         struct
         {
            int ecvt_rpboosts_num;                           /* Number of recovery-process boost                 */
            int ecvt_rpboosts_num_ignored;                   /* Number of recovery-process boost                 */
            unsigned char ecvt_rp_duration[8];               /* Total duration for the life of the               */
            unsigned char ecvt_rp_boostinfo_flags1;          /* @0MA                                             */
            unsigned char ecvt_rpboosts_requestor_id;        /* The requestor ID associated with                 */
            unsigned char ecvtr40a[2];                       /* @0MA                                             */
            void *__ptr32 ecvt_rpboosts_numbyrequestor_addr; /* Address of an                                    */
            unsigned char ecvtr410[8];                       /* @0MA                                             */
         } ;                               /* Recovery process boost support. @0MA             */
         unsigned char ecvtr418[32];                         /* Reserved                        @0MA             */
         __extension__ double ecvtend[0];                    /* End of the ECVT.                @M4A             */
      };
   };
};
#define ecvt_length 0x0438
/* Values for field "ecvtios1" */
#define ecvtchsc 0x80 /* -           RESERVED FOR IBM USE            @L7A */

/* Values for field "ecvtcnz" */
#define ecvtwtov 0x80 /* -           Allow Verbose messages          @0FA */

/* Values for field "ecvtaloc" */
#define ecvtwarn 0x80 /* -           Warn about allocations          @09A */
#define ecvtfail 0x40 /* -           Fail allocations                @09A */

/* Values for field "ecvtocvt" */
#define ecvtomvs 0x80 /* If on, OpenMVS is up and        @LMA             */

/* Values for field "ecvtgmod" */
#define ecvtgnon 0 /* GRS operating with option NONE. @LUA             */
#define ecvtgrng 1 /* GRS operating in ring mode.     @LUA             */
#define ecvtgsta 2 /* GRS operating in star mode.     @M1A             */

/* Values for field "ecvtflg1" */
#define ecvtclnu 0x80 /* When set, this flag indicates   @LXA             */
#define ecvtpmac 0x40 /* Serialization: None.            @MOA             */

/* Values for field "ecvtttfl" */
#define ecvtttrc 0x80 /* Transaction Trace has been      @MIA             */
#define ecvttatf 0x40 /* If set on, TTrace is not active @MIA             */
#define ecvttesf 0x20 /* If set on, TTrace is not active @MIA             */
#define ecvttgmf 0x10 /* If set on, TTrace is not active @MIA             */
#define ecvttabt 0x08 /* If set on, TTrace is not active @MKA             */

/* Values for field "ecvtmmig_byte0" */
#define ecvtmmig_edat2 0x80 /* @NUA                                             */
#define ecvtmmig_tx 0x40    /* Never on as of z/OS 2.4         @AGC             */
#define ecvtmmig_ri 0x20    /* @NUA                                             */
#define ecvtmmig_vef 0x10   /* Vector Extension Facility       @A5A             */
#define ecvtmmig_gsf 0x08   /* @A9A                                             */
#define ecvtmmig_diag1 0x04 /* Diagnostic for IBM use only     @AFA             */
#define ecvtmmig_diag2 0x02 /* Diagnostic for IBM use only     @AFA             */

/* Values for field "ecvtceab" */
#define ecvtceat 0x80 /* CEA has terminated              @MZA             */

/* Values for field "ecvtaxrb" */
#define ecvtaxrt 0x80 /* AXR has terminated              @MZA             */

/* Values for field "ecvtappflags" */
#define ecvtstcksyncreplaced 0x80 /* A product has replaced system                    */

/* Values for field "ecvthzrb" */
#define ecvthzrt 0x80 /* RTD has terminated              @NLA             */

/* Values for field "ecvt_boostinfo_flags0" */
#define ecvt_ziipboost_active 0x80    /* @0KA                                             */
#define ecvt_speedboost_active 0x40   /* @0KA                                             */
#define ecvt_iplboosts_activated 0x20 /* All IPL boosts to be                             */
#define ecvt_sdboosts_activated 0x10  /* All Shutdown boosts to be                        */
#define ecvt_rpboosts_activated 0x08  /* All RP boosts to be                              */
#define ecvt_boostclass 0x07          /* See Ecvt_BoostClass_xxx                          */

/* Values for field "ecvt_boostinfo_sysparm_flags" */
#define ecvt_sysparm_ziipboost 0x80  /* According to the availability                    */
#define ecvt_sysparm_speedboost 0x40 /* According to the availability and                */

/* Values for field "ecvt_boostinfo_flags1" */
#define ecvt_iplziipboost_endedbyerror 0x80  /* @0KA                                             */
#define ecvt_iplspeedboost_endedbyerror 0x40 /* @0KA                                             */
#define ecvt_iplboosts_endedbytimer 0x08     /* @0KA                                             */
#define ecvt_iplboosts_endedbypgm 0x04       /* @0KA                                             */
#define ecvt_iplboosts_endedbyshutdown 0x02  /* @0KA                                             */
#define ecvt_iplboosts_endedbyerror 0x01     /* @0KA                                             */

/* Values for field "ecvt_boostinfo_sd_flags1" */
#define ecvt_sdziipboost_endedbyerror 0x80  /* @0KA                                             */
#define ecvt_sdspeedboost_endedbyerror 0x40 /* @0KA                                             */
#define ecvt_sdboosts_endedbytimer 0x08     /* @0KA                                             */
#define ecvt_sdboosts_endedbypgm 0x04       /* @0KA                                             */
#define ecvt_sdboosts_endedbyerror 0x01     /* @0KA                                             */

/* Values for field "ecvt_boostlevel" */
#define ecvt_boostlevel_v0 0  /* Initial deliverable                     @0MA     */
#define ecvt_boostlevel_v1 1  /* Ecvt_BoostInfo_V1 may be examined       @0MA     */
#define ecvt_boostlevel_max 1 /* Maximum level of support. This may      @0MA     */

/* Values for field "ecvt_rp_boostinfo_flags1" */
#define ecvt_rpboosts_last_endedbytimer 0x08    /* The last RPBoost(s) ended                        */
#define ecvt_rpboosts_last_endedbyshutdown 0x02 /* The last RPBoost(s) ended                        */
#define ecvt_rpboosts_last_endedbyerror 0x01    /* The last RPBoost(s) ended                        */

/* Values for field "ecvtend" */
#define ecvt_max_highestcpuid 0xFF         /* The highest                                      */
#define ecvt_max_cpumasksizeinbits 0x100   /* The                                              */
#define ecvt_max_cpumasksizeinbytes 0x20   /* The                                              */
#define ecvt_zosv2r1_highestcpuid 255      /* The highest physical CPU ID allowed              */
#define ecvt_zosv2r1_cpumasksizeinbits 256 /* The number of bits needed to                     */
#define ecvt_zosv2r1_cpumasksizeinbytes 0x20
#define ecvt_zosr11_highestcpuid 99               /* The highest physical CPU ID allowed              */
#define ecvt_zosr11_cpumasksizeinbits 128         /* The number of bits needed to                     */
#define ecvt_zosr11_cpumasksizeinbytes 0x10       /* The                                              */
#define ecvt_boostclass_mask 0x07                 /* @0KA                                             */
#define ecvt_boostclass_ipl 0x01                  /* @0KA                                             */
#define ecvt_boostclass_shutdown 0x02             /* @0KA                                             */
#define ecvt_boostclass_rp 0x03                   /* @0MA                                             */
#define ecvt_rpbreq_not_identified 0              /* @0MA                                             */
#define ecvt_rpbreq_sysplex_partitioning 1        /* @0MA                                             */
#define ecvt_rpbreq_cf_structure_recov 2          /* @0MA                                             */
#define ecvt_rpbreq_cf_datasharing_member_recov 3 /* @0MA                                             */
#define ecvt_rpbreq_hyperswap 4                   /* @0MA                                             */

#define ecvtcaa 0x58 /* @A4A                                             */
