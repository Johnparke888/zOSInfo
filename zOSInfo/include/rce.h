#pragma once
/*
 * Common name: RSM Control and Enumeration Area
 * Macro ID: IARRCE
 * DSECT name: RCE
 * Eye-catcher ID: RCE
 * Offset: 0
 * Length: 4
 * Storage
 * attributes:
 * Virtual Storage: Yes
 * Subpool: Extended Nucleus
 * Key: 0
 * Data Space: No
 * Residency: Above 16 megabytes virtual
 * Size: RCE -- X'0580' bytes -1408 bytes
 * Created by: IARMR
 * Pointed to by: CVTRCEP field of the CVT data area
 * Serialization: Field dependent
 * Function: The RCE contains system wide counts and control
 * information used by RSM, and other components that
 * interface with RSM, such as SRM, VSM, Etc.
 */

#ifndef __MVS__
#define __ptr32
#endif

struct rce
{
   unsigned char rceid[4]; /* rce control block id                */
   int rcepool;            /* total number of frames in 4k units  */
   int rcebelpl;           /* the same as rcepool except that     */
   int rcemaxfx;           /* fixed frame threshold. srm is       */
   int rcedeffx;           /* all suspendable frame requests are  */
   short int rcerpbex;     /* minimum number of rpbs which should */
   unsigned char rcehrtpp; /* high real threshold percentage      */
   unsigned char rcehrtpn; /* high real threshold percentage      */
   int rceafclo;           /* afq low threshold. srm is notified  */
   int rceafcok;           /* afq satisfactory theshold. srm is   */
   int rcersqa;            /* number of times a reserved sqa      */
   int rcedfrs;            /* number of times a deferred request  */
   int _filler1;           /* no longer used as of hbb77b0        */
   int rcespfr;            /* number of frames made available by  */
   int rcevioru;           /* number of times a vio data set page */
   int rcetotrc;           /* total number of times a page was    */
   int rcecomrc;           /* number of common area pages which   */
   int rcelparc;           /* number of plpa and plpa directory   */
   int rcepbafl;           /* preferred below available frame     */
   int rcetotpi;           /* total number of pages paged- in     */
   int rcecompi;           /* number of common area pages         */
   int rcelpapi;           /* number of plpa and plpa directory   */
   int rceswppi;           /* total number of pages requiring i/o */
   int rceviopi;           /* total number of vio pages paged-in  */
   int rcetotpo;           /* total number of pages paged- out    */
   int rcecompo;           /* number of common area pages         */
   int rceswppo;           /* total number of pages requiring i/o */
   int rceviopo;           /* total number of vio pages (excludes */
   union {
      unsigned char rcewlm[4]; /* Work Load Manager related fields */
      struct
      {
         unsigned char rceestts; /* Expanded STorage Time Stamp Set by  */
         unsigned char rceestb1; /* Expanded STorage UIC delimiter 1 -  */
         unsigned char rceestb2; /* Expanded STorage UIC delimiter 2 -  */
         unsigned char rceestb3; /* Expanded STorage UIC delimiter 3 -  */
         int rceviome;           /* NUMBER OF VIO DATA SET PAGES MOVED  */
         int rceviore;           /* NUMBER OF VIO DATA SET PAGES READ   */
         int rceviomg;           /* NUMBER OF VIO DATA SET PAGES        */
         int rcetotfx;           /* TOTAL NUMBER OF PAGES CURRENTLY     */
         int rcebelfx;           /* THE SAME AS RCETOTFX EXCEPT THAT    */
         void *__ptr32 rcerax;   /* ADDRESS OF COMMON RAX               */
         int rcepbafc;           /* TOTAL NUMBER OF FRAMES CURRENTLY ON */
         int rceafc;             /* Total number of frames in 4k units  */
         int rcedfc;             /* TOTAL NUMBER OF FRAME PAIRS ON THE  */
         int rcepagmv;           /* NUMBER OF TIMES A PAGE WAS MOVED    */
         int rceaec;             /* TOTAL NUMBER OF EXTENDED STORAGE    */
         int rceaeclo;           /* ESTE LOW THRESHOLD. (ESA Mode Only, */
         int rceaecok;           /* ESTE SATISFACTORY THRESHOLD. (ESA   */
         int rceespl;            /* THE TOTAL NUMBER OF EXTENDED        */
         void *__ptr32 rceesinu; /* THE NUMBER OF IN USE EXTENDED       */
         void *__ptr32 rceeswrt; /* THE NUMBER OF PAGES WRITTEN OUT TO  */
         void *__ptr32 rceesrea; /* THE NUMBER OF PAGES READ FROM       */
         int rcegroup;           /* THE MAXIMUM NUMBER OF FRAMES THAT   */
         int rcecombi;           /* Common Blocked Page in Count        */
         int rcemvbel;           /* NUMBER OF PAGES MOVED TO SATISFY    */
         int _filler2;           /* Not used                            */
         int rcewraps;           /* A TOKEN REPRESENTING THE LATEST     */
         int rcenwsp;            /* TOTAL NUMBER OF CHANGED NON-WORKING */
         int rcenwss;            /* TOTAL NUMBER OF CHANGED NON-WORKING */
         int rcenwsf;            /* TOTAL NUMBER OF CHANGED NON-WORKING */
         int rcewsprp;           /* NUMBER OF PRIMARY WORKING SET PAGES */
         int rcewsdne;           /* NUMBER OF PRIMARY WORKING SET PAGES */
         int rcelpabi;           /* PLPA Blocked Page in Count          */
         int rcedrips;           /* NUMBER OF DREF PAGES IN PROCESSOR   */
         int _filler3;           /* Not used                            */
         int rcedbfrm;           /* NUMBER OF DOUBLE FRAME PAIRS        */
         void *__ptr32 rcedrirs; /* NUMBER OF DREF PAGES IN REAL        */
         void *__ptr32 rcelsirs; /* NUMBER OF LSQA PAGES IN REAL        */
         int rceret;             /* TARGET NUMBER OF EXPANDED STORAGE   */
         void *__ptr32 rcemigai; /* NUMBER OF FRAMES MIGRATION DID NOT  */
         int rcewsact;           /* NUMBER OF WORK/SAVE AREAS ON THE    */
         int rcewsam;            /* MINIMUM NUMBER OF WSAS ON THE       */
         int rcehspew;           /* TOTAL NUMBER OF HIPERSPACE PAGES    */
         int rcehsper;           /* TOTAL NUMBER OF HIPERSPACE PAGES    */
         int rcehspem;           /* TOTAL NUMBER OF HIPERSPACE PAGES    */
         int rcehsppo;           /* TOTAL NUMBER OF HIPERSPACE PAGES    */
         int rcehsppi;           /* TOTAL NUMBER OF HIPERSPACE PAGES    */
         int rcestabl;           /* TOTAL NUMBER OF FIXED PAGES IN      */
         int rcefxstl;           /* NUMBER OF FIXED PAGES IN LOGICALLY  */
         short int rcefrv1;      /* FRAME UIC RANGE VALUE 1 SET BY SRM  */
         short int rcefrv2;      /* FRAME UIC RANGE VALUE 2 SET BY SRM  */
         short int rcefrv3;      /* FRAME UIC RANGE VALUE 3 SET BY SRM  */
         short int rcefrv4;      /* RESERVED for RSM                    */
         int rcebppie;           /* NUMBER OF BLOCKED PAGES PAGED IN    */
         int rcebppia;           /* NUMBER OF BLOCKED PAGES PAGED IN    */
         int rcebpste;           /* NUMBER OF BLOCKED PAGES PAGED OUT   */
         int rcebpsta;           /* NUMBER OF BLOCKED PAGES STOLEN TO   */
         int rceblpie;           /* NUMBER OF BLOCKS OF PAGES PAGED IN  */
         int rceblpia;           /* NUMBER OF BLOCKS OF PAGES PAGED IN  */
         int rceblste;           /* NUMBER OF BLOCKS OF PAGES PAGED OUT */
         int rceblsta;           /* NUMBER OF BLOCKS OF PAGES PAGED IN  */
         int rceespi;            /* NUMBER OF PAGES FAULTED IN FROM     */
         int rceesst;            /* NUMBER OF PAGES STOLEN TO EXPANDED  */
         int rceflags;           /* FLAGS (serialized by the SRM lock   */
      };
      struct
      {
         unsigned char _filler4[228];
         unsigned char rceflags1;
         unsigned char rceflags2;
         unsigned char rceflags3;
         unsigned char rceflags4;
         unsigned char rceprtdw[8]; /* Structure name for PRA           */
      };
      struct
      {
         unsigned char _filler5[232];
         void *__ptr32 rceprtbl;    /* Beginning of PRA                 */
         void *__ptr32 rceprcur;    /* Pointer to available PRA slot    */
         void *__ptr32 rcekre;      /* Reserved -- do not use           */
         short int rcefixb1;        /* COUNT OF THE TIMES FRAMES WERE   */
         short int rcefixb2;        /* COUNT OF THE TIMES FRAMES WERE   */
         unsigned char rcestlti[8]; /* CPU time for pref steal in CPU   */
      };
      struct
      {
         unsigned char _filler6[248];
         int _filler7;             /* first word of timer, used to        */
         int _filler8;             /* second word of timer, used to       */
         int rcetotsg;             /* Total number of shared page groups  */
         int rcesginr;             /* Total number of shared page groups  */
         int rcesgine;             /* Total number of shared page groups  */
         int rcesgaux;             /* Total number of auxiliary storage   */
         int rcetotsf;             /* Total number of shared page groups  */
         int rcebelsf;             /* Total number of shared page groups  */
         int rcespquo;             /* Storage isolation quota for central */
         int rcespgpi;             /* Number of page-ins from auxiliary   */
         int rcespgpo;             /* Number of page-outs to auxiliary    */
         int rceesspi;             /* Number of page-ins from expanded    */
         int rceesspo;             /* Number of page-outs to expanded     */
         unsigned char rcefbv[16]; /* STRUCTURE NAME for the shared       */
      };
      struct
      {
         unsigned char _filler9[300];
         int rcefbv1;              /* NUMBER OF FRAMES IN UIC INTERVAL 1  */
         int rcefbv2;              /* NUMBER OF FRAMES IN UIC INTERVAL 2  */
         int rcefbv3;              /* NUMBER OF FRAMES IN UIC INTERVAL 3  */
         int rcefbv4;              /* NUMBER OF FRAMES IN UIC INTERVAL 4  */
         void *__ptr32 rcetotsm;   /* Total number of shared pages that   */
         int rcepaafc;             /* Available above the line preferred  */
         int rcepfcok;             /* Preferred frame shortage threshold  */
         int rceviomr;             /* NUMBER OF VIO DATA SET PAGES MOVED  */
         int rceviorr;             /* NUMBER OF VIO DATA SET PAGES READ   */
         int rcecsare;             /* NUMBER OF CSA PAGES BACKED IN REAL  */
         int rcelpare;             /* NUMBER OF PLPA/MLPA PAGES BACKED IN */
         int rcelpafx;             /* NUMBER OF PLPA/MLPA PAGES THAT ARE  */
         int rcesqafx;             /* NUMBER OF SQA/FIXED-CSA PAGES IN    */
         int rcedrefr;             /* NUMBER OF SQA DREF PAGES IN REAL    */
         int rcephafc;             /* Number of available preferred HIGH  */
         int rceqdafc;             /* Number of available quad frame      */
         unsigned char rceqfail;   /* Number of consecutive calls to Quad */
         unsigned char rcedefqf;   /* Default number of Quad Frame groups */
         unsigned char rcersv2[2]; /* Reserved                            */
         int rcenbafc;             /* TOTAL NUMBER OF FRAMES CURRENTLY ON */
         int rcenaafc;             /* Available nonpreferred above frame  */
         int rcenhafc;             /* Number of available nonpreferred    */
         int rceqsafc;             /* Number of available quad single     */
         int rceabvfx;             /* Number of pages fixed between 16M   */
         int rceqdfrm;             /* Number of quad groups that are      */
         int rceqdthr;             /* Threshhold number of available quad */
         int rceabvpl;             /* Same as RCEPOOL, but only counts    */
         int rcestecb;
         unsigned char _filler10[3];
      };
      struct
      {
         unsigned char _filler11[404];
         int rcehsprw;                 /* TOTAL NUMBER OF HIPERSPACE PAGES   */
         int rcehsprr;                 /* TOTAL NUMBER OF HIPERSPACE PAGES   */
         int rcepftal;                 /* Alet for the PFT CADS - 0 for ESA  */
         unsigned char rceqdsz[8];     /* Initial size of the quad area. May */
         int rceprmct;                 /* Count of the number of non-nucleus */
         short int rcebelowlow;        /* Low on below 16Meg real            */
         short int rcebelowok;         /* Ok on below 16Meg real             */
         short int rceabovelow;        /* Low on 16M-2G real                 */
         short int rceaboveok;         /* Ok on 16M-2G real                  */
         unsigned char rceflagsabn[4]; /* Flags serialized by CS             */
      };
      struct
      {
         unsigned char _filler12[436];
         unsigned char rceflgs5;
         unsigned char rce_srmsaysreason; /* Reason why SRM reset the         */
         unsigned char rceflgs7;
         unsigned char rceflgs8;
         unsigned char rcelvshrstrt[8]; /* Lowest Virtual address of high   */
      };
      struct
      {
         unsigned char _filler13[440];
         unsigned char rcelvlprlim[8];  /* Lowest Virtual address of high   */
         unsigned char rcelvhprstrt[8]; /* Lowest virtual address of high   */
      };
      struct
      {
         unsigned char _filler14[448];
         unsigned char rcelvshrlim[8];   /* Lowest virtual address of high      */
         int rceminhvfrm;                /* Min number of PFTEs on High Virtual */
         int rcemaxhvfrm;                /* Max number of PFTEs on High Virtual */
         int rcestbrk;                   /* Paging system is overloaded when    */
         short int rcecadsused;          /* Number of CADS ASTES in use         */
         short int rcecadshw;            /* Max CADS ASTES in use during this   */
         short int rcecadslost;          /* Number of lost CADS ASTES (Not on   */
         unsigned char _filler15[2];     /* Unused                              */
         void *__ptr32 rce_tghas_;       /* Address of the "Give Him Another    */
         unsigned char rcelvshrpages[8]; /* Number of high virtual shared       */
      };
      struct
      {
         unsigned char _filler16[480];
         unsigned char _filler17[4];
         int rcelvshrpages31;             /* Number of high virtual shared       */
         unsigned char rcelvshrgbytes[8]; /* high water mark for number of       */
         int rcelvshrnmomb;               /* number of shared memory objects     */
         int rcegetframedeferthreshold;   /* Suspend suspendable getframe        */
         unsigned char rcehvshrinreal[8]; /* Number of high virtual shared pages */
      };
      struct
      {
         unsigned char _filler18[504];
         unsigned char _filler19[4];
         int rcehvshrinreal31;              /* Number of high virtual shared pages */
         unsigned char rcehvshrauxslots[8]; /* Number of auxiliary storage slots   */
      };
      struct
      {
         unsigned char _filler20[512];
         unsigned char _filler21[4];
         int rcehvshrauxslots31;           /* Number of auxiliary storage slots   */
         unsigned char rcehvshrpageins[8]; /* Number of high virtual shared pages */
      };
      struct
      {
         unsigned char _filler22[520];
         unsigned char _filler23[4];
         int rcehvshrpageins31;             /* Number of high virtual shared pages */
         unsigned char rcehvshrpageouts[8]; /* Number of high virtual shared pages */
      };
      struct
      {
         unsigned char _filler24[528];
         unsigned char _filler25[4];
         int rcehvshrpageouts31;                     /* Number of high virtual shared pages */
         int rcenumofgetmainrequests;                /* Total number of getmain requests    */
         int rcepgsbackedongtmnreqs;                 /* Total number of pages backed during */
         int rcenumoffixrequests;                    /* Total number of fix requests that   */
         int rcenumframesfx;                         /* Total number of frames that were    */
         int rce1streffaults;                        /* Total number of first reference     */
         int rcenon1streffaults;                     /* Total number of non-first reference */
         unsigned char rcersv4[4];                   /* RESERVED FOR HBB7709                */
         int rcesttot;                               /* TOTAL NUMBER OF FIXED PAGES IN      */
         int rcemaxframescpuq;                       /* Target number of 4k frames on CPU   */
         int rcefqsplitlim;                          /* Number of frames on a frame queue   */
         unsigned char _filler26[24];                /* Reserved                            */
         unsigned char rcenumoffravailablebyswap[8]; /* Number of frames that will be made  */
      };
      struct
      {
         unsigned char _filler27[600];
         int _filler28;                          /* Reserved                         */
         int rcenumoffravailablebyswap31;        /* 31-bit field                     */
         unsigned char rcemaxframestoexamine[8]; /* Number of frames to examine in   */
      };
      struct
      {
         unsigned char _filler29[608];
         int _filler30;                     /* Reserved                            */
         int rcemaxframestoexamine31;       /* 31-bit field                        */
         unsigned char rcepercentstolen[8]; /* Percent of frames we expect to have */
      };
      struct
      {
         unsigned char _filler31[616];
         int _filler32;                  /* Reserved                           */
         int rcepercentstolen31;         /* 31-bit field                       */
         void *__ptr32 rceglruseghdrptr; /* Pointer to the Global LRU Segment  */
         int rcefxabvstl;                /* NUMBER OF FIXED PAGES IN LOGICALLY */
         int rcefxtotstl;                /* NUMBER OF FIXED PAGES IN LOGICALLY */
         int rcestabv;                   /* TOTAL NUMBER OF FIXED PAGES IN     */
         struct
         {
            unsigned char _filler33;
         } rcersv5; /* RESERVED FOR HBB7720               */
      };
      struct
      {
         unsigned char _filler34[640];
         unsigned char rcelargememoryobjects[8]; /* Number of fixed 1M memory objects */
      };
      struct
      {
         unsigned char _filler35[640];
         unsigned char _filler36[4];
         int rcelargememoryobjects31;
         unsigned char rcelargepagesbackedinreal[8]; /* Number of fixed 1M pages in use. */
      };
      struct
      {
         unsigned char _filler37[648];
         unsigned char _filler38[4];
         int rcelargepagesbackedinreal31;
         unsigned char rcereconlfasize[8]; /* Size of the Reconfigurable fixed 1M */
      };
      struct
      {
         unsigned char _filler39[656];
         unsigned char _filler40[4];
         int rcereconlfasize31;
         unsigned char rcenonreconlfasize[8]; /* The maximum number of            */
      };
      struct
      {
         unsigned char _filler41[664];
         unsigned char _filler42[4];
         int rcenonreconlfasize31;
         unsigned char rcereconlfaused[8]; /* Number of 1MB frames in the      */
      };
      struct
      {
         unsigned char _filler43[672];
         unsigned char _filler44[4];
         int rcereconlfaused31;
         unsigned char rcenonreconlfaused[8]; /* Number of non- reconfigurable fixed */
      };
      struct
      {
         unsigned char _filler45[680];
         unsigned char _filler46[4];
         int rcenonreconlfaused31;
         int _filler47;                     /* Reserved for HBB77B0                */
         int rcelfavailgroups;              /* Count of available 1M frame groups  */
         int rcelsafc;                      /* Count of available single large     */
         int rcelargeused1mhwm;             /* High water mark (largest value ever */
         int rcelargeused4khwm;             /* High-Water mark of the number of    */
         unsigned char rcersv6[60];         /* RESERVED FOR HBB7740                */
         unsigned char rcehvcommonstrt[8];  /* Lowest Virtual address for the high */
         unsigned char rcehvcommonend[8];   /* Highest Virtual address for the     */
         unsigned char rcehvcommonpages[8]; /* Number of high virtual common       */
      };
      struct
      {
         unsigned char _filler48[784];
         int _filler49;
         int rcehvcommonpages31;               /* Number of 64-bit common memory   */
         unsigned char rcehvcommonhwmbytes[8]; /* High Water Mark for number of    */
         unsigned char rcehvcommonnmomb[8];    /* Number of 64-bit common memory   */
         unsigned char rcehvcommoninreal[8];   /* Number of 64-bit common memory   */
      };
      struct
      {
         unsigned char _filler50[808];
         int _filler51;
         int rcehvcommoninreal31;              /* Number of 64-bit common memory   */
         unsigned char rcehvcommonauxslots[8]; /* Number of 64-Bit common memory   */
      };
      struct
      {
         unsigned char _filler52[816];
         int _filler53;
         int rcehvcommonauxslots31;              /* Number of 64-bit common memory   */
         unsigned char rcehvcommonpagesfixed[8]; /* Number of 64-Bit common memory   */
      };
      struct
      {
         unsigned char _filler54[824];
         int _filler55;
         int rcehvcommonpagesfixed31;           /* Number of 64-bit common memory     */
         unsigned char rcehvcommonpagesdref[8]; /* Number of 64-Bit common DREF pages */
      };
      struct
      {
         unsigned char _filler56[832];
         int _filler57;
         int rcehvcommonpagesdref31;                    /* Number of 64-bit common DREF pages  */
         int rceenableincrshared;                       /* Enable increment used in IAXXR      */
         int rceenableincrdedicated;                    /* Enable increment used in IAXXR      */
         unsigned char rceplsz[8];                      /* Initial pageable large area size.   */
         unsigned char rcepmmss[8];                     /* Number of failed attempts to back   */
         unsigned char rceplsid[8];                     /* Number of system-initiated          */
         unsigned char rceplrid[8];                     /* Number of request-initiated         */
         int rcepmafc;                                  /* Number of available 1M frames in    */
         int rceplhwm;                                  /* High water mark for the number of   */
         int rcepsafc;                                  /* Number of available pageable large  */
         int rcersv3;                                   /* Reserved for HBB7750                */
         unsigned char rceplfailedsincelastcoalesce[8]; /* Last count of total number of       */
         int rceplfrm;                                  /* Number of pageable large frame      */
         int rcensafc;                                  /* Number of available pageable large  */
         unsigned char rcersv7[16];                     /* Reserved for HBB7750                */
         int rcelargeused4k;                            /* Number of fixed large frames used   */
         int rceunownedcommonlargeobjects;              /* Number of common large memory       */
         unsigned char rceunownedcommonlargepages[8];   /* Number of common large pages whose  */
         int rcehvcommonobjectsfixed1m;                 /* Number of 64-Bit common large       */
         int rcelargeusedpl;                            /* Number of fixed large frame used to */
         int rceplxrm;                                  /* Number of pageable large frame      */
         int rcenmafc;                                  /* Number of available pageable large  */
         unsigned char rcenmmss[8];                     /* Number of failed attempts to back   */
         unsigned char rcesgauxscm[8];                  /* Number of shared page groups backed */
         unsigned char rcehvshrauxscm[8];               /* Number of High Virtual Shared pages */
         unsigned char rcehvcommonauxscm[8];            /* Number of High Virtual Common pages */
         unsigned char rcetotpidasd[8];                 /* Total page-ins from DASD. Excludes  */
         unsigned char rcetotpiscm[8];                  /* Total page-ins from SCM Excludes    */
         unsigned char rcetotpodasd[8];                 /* Total page-outs to DASD. Excludes   */
         unsigned char rcetotposcm[8];                  /* Total page-outs to SCM. Excludes    */
         unsigned char _filler58[24];                   /* Reserved for HBB7780                */
         unsigned char rcehvcommonpages1m[8];           /* Number of 64-Bit common memory 1M   */
         unsigned char rcehvcommonpagesfixed1m[8];      /* Number of 64-Bit common memory 1M   */
         unsigned char rcetotpo1m[8];                   /* Total page-outs for 1M pages.       */
         unsigned char rcetotpi1m[8];                   /* Total page-ins for 1M pages.        */
         unsigned char rcetotpo1mscm[8];                /* Total page outs for 1M pages to     */
         unsigned char rcetotpi1mscm[8];                /* Total page-ins of 1M pages from     */
         unsigned char rcecompo1m[8];                   /* Number of 64-bit common memory 1M   */
         unsigned char rcecompi1m[8];                   /* Number of 64-bit common memory 1M   */
         unsigned char rce_freemainedframes[8];         /* Number of freemained frames in all  */
         int rce_ffregiontargetinit;                    /* Initial value of Rax_FFRegionTarget */
         int rce_ffhightargetinit;                      /* Initial value of Rax64_FFHighTarget */
         unsigned char rcersv8[8];                      /* Reserved for HBB7780                */
         int rcephpool;                                 /* Total preferred high frame pool     */
         int rcelargeallocatedpl;                       /* Number of Fixed Large Pages         */
         int rcepltotal;                                /* Total Number of 1M frames in the    */
         int rcelargeusedplhwm;                         /* High-Water mark of the number of    */
         unsigned char rce2gmemoryobjects[8];           /* Number of 2G Memory Objects         */
      };
      struct
      {
         unsigned char _filler59[1152];
         unsigned char _filler60[4];
         int rce2gmemoryobjects31;
         unsigned char rce2gpagesbackedinreal[8]; /* Number of 2G pages backed in real */
      };
      struct
      {
         unsigned char _filler61[1160];
         unsigned char _filler62[4];
         int rce2gpagesbackedinreal31;
         unsigned char rce2gnonreconlfasize[8]; /* Size of the Non-Reconfigurable 2G */
      };
      struct
      {
         unsigned char _filler63[1168];
         unsigned char _filler64[4];
         int rce2gnonreconlfasize31;
         unsigned char rce2gnonreconlfaused[8]; /* Number of 2G frames in the       */
      };
      struct
      {
         unsigned char _filler65[1176];
         unsigned char _filler66[4];
         int rce2gnonreconlfaused31;
         int rce2ghwm;                          /* High water mark for the number of   */
         int rce_maxmempools;                   /* Number of mempools that RSM should  */
         unsigned char rceglru64seghdrptr[8];   /* Pointer to the 64-bit Global LRU    */
         int rcerequestednumpcie1mpages;        /* Number of 1M pages requested for    */
         int rce_quadqueueafc;                  /* Number of available quad frame      */
         int rce_octoafc;                       /* Number of available octo frame      */
         int rce_octoframesinuse;               /* Number of octo frame groups in-use  */
         int rce_octoframesinusehwm;            /* High water mark for the number of   */
         int rce_pdatquadcount;                 /* Number of PDAT frames used for Quad */
         int rce_pdatpagetablecount;            /* Number of 4k PDAT frames used for   */
         unsigned char rcersv10[68];            /* Reserved for JBB778H                */
         unsigned char rce64ptr[8];             /* Pointer to 64-bit RCE extension     */
         __extension__ unsigned char rceend[0]; /* KEEP RCE A MULTIPLE OF 8 BYTES      */
      };
   };
};

/* Values for field "rceflags1" */
#define rcefixab 0x80            /* SRM SAYS GO TO EXTRA EFFORT TO      */
#define rcessinh 0x40            /* Self steal is inhibitted (set by    */
#define rcenorcf 0x20            /* Indicates that there is no          */
#define rcercfex 0x10            /* Indicates that reconfigurable       */
#define rcepiook 0x08            /* Indicates that SRM finds there is   */
#define rcefauxs 0x04            /* Indicates that there is a aux       */
#define rceuse2gto32gareaok 0x02 /* Indicates that the Use2gTo32gArea   */
#define rceukcr 0x01             /* Indicates that there are user key   */

/* Values for field "rceflags2" */
#define rceraspinitialized 0x80 /* Rsm address space has initialized   */
#define rcescmblockmanagerenabled 0x40
#define rcescmblockmanagerdamaged 0x20   /* NOTE: this bit is the only bit in   */
#define rcestoragestatusgoodatipl 0x10   /* Indicates that storage is known to  */
#define rceoa51864applied 0x08           /* Indicates APAR OA51864 is applied   */
#define rce_inoriginenabled 0x04         /* Indicates IARV64 INORIGIN Support   */
#define rce_sensitivesupportapplied 0x02 /* IARV64, IARCP64, IARST64            */
#define rce_changeattributeapplied 0x01  /* REQUEST=CHANGEATTRIBUTE is          */

/* Values for field "rceflags3" */
#define rcesubspacev64 0x80    /* 64-bit Subspaces are supported.     */
#define rcev64countpages 0x40  /* IARV64 COUNTPAGES request Supported */
#define rcefeat3enab 0x20      /* RSM feature3 enabled - SCM          */
#define rcepageablelarge 0x10  /* Pageable Large supported.           */
#define rcefeat5enab 0x08      /* Feature5 enabled                    */
#define rcesoffenab 0x04       /* SCM Offline enabled                 */
#define rceinclude1mafc 0x02   /* Feature to include the fixed 1M     */
#define rcev64commonguard 0x01 /* IARV64 Changeguard for common area  */

/* Values for field "rceflags4" */
#define rceoa44207applied 0x80              /* Indicates APAR OA44207 is applied   */
#define rceoa44436applied 0x40              /* Indicates APAR OA44436 is applied   */
#define rceoa46291applied 0x20              /* Indicates APAR OA46201 is applied   */
#define rce_use2gto64genable 0x08           /* Indicates that Use2gto64g is        */
#define rce_targetmaybereadonlyenabled 0x04 /* Indicates IARVSERV                  */
#define rcev64countdiscard 0x02             /* IARV64 Countpages supports          */
#define rce_oa51647applied 0x01             /* The EXECUTABLE=NO support added by  */

/* Values for field "rcestecb" */
#define rcestorageinitecbw 0x80 /* ECB Waiting bit                     */
#define rcestorageinitecbp 0x40 /* ECB Posted bit                      */

/* Values for field "rceflgs5" */
#define rcescmevacinprogress 0x80            /* Indicate SCM storage evacuation is  */
#define rcerealframesinitialized 0x40        /* Indicates that all online real      */
#define rce_srmsayskeepfreemainedframes 0x20 /* Indicates whether RSM should        */
#define rce_noipteenable 0x10                /* Indicates that the NOIPTE feature   */
#define rce_noiptehighenable 0x08            /* Indicates that the NOPITE feature   */
#define rce_aslrenabled 0x07                 /* ASLR enablement flags               */
#define rce_aslr24enabled 0x04               /* Indicates that 24-bit storage is    */
#define rce_aslr31enabled 0x02               /* Indicates that 31-bit storage is    */
#define rce_aslr64enabled 0x01               /* Indicates that 64-bit storage is    */

/* Values for field "rce_srmsaysreason" */
#define rce_srmsaysreasonfxs 0x80           /* The system is in a pageable storage */
#define rce_srmsaysreasonafq 0x40           /* The system is in a available        */
#define rce_srmsaysreasonconfigoffline 0x20 /* Real storage is being               */

/* Values for field "rceflgs7" */
#define rce_userkeycommonusage 0x80         /* Indicates user key common storage   */
#define rce_userkeycommonusagesinceipl 0x40 /* Indicates user key common           */
#define rce_aslr24wasonceenabled 0x20       /* Indicates that 24-bit ASLR was      */
#define rce_aslr31wasonceenabled 0x10       /* Indicates that 31-bit ASLR was      */

/* Values for field "rceend" */
#define rce_len 0x580
