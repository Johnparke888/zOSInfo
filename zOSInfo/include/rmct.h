#pragma once 
/*
* 
* Descriptive Name: System resources manager control table
* Macro ID:IRARMCT
* DSECT name:RMCT
* Eye-catcher ID: RMCT
* Offset:  0
* Length:  4
* Residency: (Residence - above 16M)
* Size:1024 bytes 
* Pointed to by:
* CVTOPCTP field of the CVT data area
* 
* Function:
* The rmct serves as the origin to locate system
* resources manager tables and entry points. The rmct
* locates the scheduling / routing information used to
* invoke the required processing for the various system
* resources manager functions.
* 
* z/OS: z/OS MVS Data Areas Volume 3 (ITK - RQE)
* © Copyright IBM Corp. 1988, 2020
*/

struct rmct
{
   unsigned char rmctname[4]; /* -           block identification                    */
   void *__ptr32 rmctcct;     /* -            cpu management control table           */
   void *__ptr32 rmctict;     /* -            i/o management control table           */
   void *__ptr32 rmctmct;     /* -            storage management control table       */
   void *__ptr32 rmctrmpt;    /* -           ctl algorithm parameter table           */
   void *__ptr32 rmctrmca;    /* -           ctl algorithm control area              */
   void *__ptr32 rmctwmst;    /* -              addr of wlm specification table      */
   void *__ptr32 rmctsrbc;    /* -       tcb/srb code in int         @ya08710        */
   void *__ptr32 rmctwmct;    /* -              wlm mode control table          @l6c */
   void *__ptr32 rmctrmpd;    /* -              addr of resources manager perf data  */
   void *__ptr32 rmctrmex;    /* -           routine exiting vector table            */
   void *__ptr32 rmctrmsb;    /* -           subroutine calling vector table         */
   void *__ptr32 rmcteppa;    /* -        prtl analysis entry table                  */
   void *__ptr32 rmctepdt;    /* -        user action entry table                    */
   void *__ptr32 rmctepat;    /* -        algorithm entry table                      */
   void *__ptr32 rmctlsct;    /* -           logical swap control table  @g50ipjh    */
   int rmctadjc;              /* -              adjustment factor for cpu rate       */
   void *__ptr32 rmctitt;     /* -       Addr of the Sysevent Characteristic         */
   int _filler1;              /* -              Reserved                    @LSRMLKC */
   void *__ptr32 rmctltt;     /* lock trace table address        @L6C                */
   void *__ptr32 rmcteppr;    /* -        process rate dependent entry table         */
   void *__ptr32 rmctwast;    /* -              addr of wmst for set ips    @g741pgm */
   void *__ptr32 rmct15f;     /* Address of 15f abend       @me28751a                */
   void *__ptr32 rmcttmqe;    /* -       scheduled rtne queue header addr            */
   int rmctaqct;              /* -              action queue member count            */
   void *__ptr32 rmctaqhd;    /* -        action queue forward pointer               */
   void *__ptr32 rmctwtqe;    /* -        wait - queue header block address          */
   void *__ptr32 rmctlsqe;    /* -        log swap wait queue header addr @h5a       */
   void *__ptr32 rmctotqe;    /* -        out - queue header block address           */
   void *__ptr32 rmctinqe;    /* -        in - queue header block address            */
   int rmcttbs;               /* -              starting time base for time of day   */
   int rmcttod;               /* -              time of day - syst rsrc mgr invoke   */
   double rmcttoc;            /* -              time of century - 64bit binary nmb   */
   unsigned char rmctala[4];  /* -      algorithm request accumulator field          */
   unsigned char rmctalr[4];  /* -      immediate algorithm request field            */
   void *__ptr32 rmctrqsv;    /* -           addr of req srv data area   @z40bpch    */
   unsigned char rmctflgs;    /* -      processing control flags    @lcmptmc         */
   unsigned char _filler2;    /* -      override condition flags                     */
   unsigned char rmcttape;    /* (opt parm) tape selection:        @g741pgs          */
   unsigned char rmctflg2;    /* -      processing flags           @g744pjc          */
   void *__ptr32 rmcttelm;    /* -       resources manager timing element            */
   int rmctcpid;              /* -              res manager cell pool id    @g860pjc */
   double rmcttoci;           /* -              clock read area - 64bit binary nmb   */
   void *__ptr32 rmctoucb;    /* -        preassembled model oucb                    */
   void *__ptr32 rmctouxb;    /* -        interposed dummy ouxb                      */
   void *__ptr32 rmctsrbt;    /* -        resources manager srb table                */
   void *__ptr32 rmctdmdt;    /* -              addr of domain table        @z40bpch */
   void *__ptr32 rmctdmde;    /* -              addr of last dmn tab entry  @z40bpch */
   short int rmctdmnc;        /* -              number of domains           @z40bpch */
   short int rmctscsq;        /* -              speed change sequence no    @wlmpifa */
   int _filler3;              /* -              reserved                   @me22326c */
   int _filler4;              /* -              reserved                   @me22326c */
   int _filler5;              /* -              reserved                   @me22326c */
   int rmctcpub;              /* -              cpu adjusting factor excluding       */
   int rmctcpu;               /* -              cpu service coefficient         @l6c */
   int rmctmso;               /* -              mso service coefficient         @l6c */
   int rmctioc;               /* -              ioc service coefficient         @l6c */
   void *__ptr32 rmcticst;    /* -              icsc table addr             @g742pss */
   int rmctcpmp;              /* -              cpu adjusting factor - if this       */
   void *__ptr32 rmctrct;     /* -            address of rct              @g742pgm   */
   double rmctbrqe;           /* -              basic reporting queue       @g742pjc */
   double rmcterqe;           /* -              extended reporting queue    @g742pjc */
   double rmctupdq;           /* -              update queue                @g742pjc */
   void *__ptr32 rmcttrad;    /* -              xacn rpting q 1st page ptr  @g742pjc */
   int rmcttrpc;              /* -              xacn rpting page count      @g742pjc */
   void *__ptr32 rmcticsp;    /* -           xacn description table      @g743pss    */
   void *__ptr32 rmctrspl;    /* -           rspl address                @g743pss    */
   unsigned char rmctcsb;     /* -      rmct compare/swap bit       @za70182         */
   unsigned char rmctrsvb;    /* -      reserved                    @za70182         */
   short int rmctshdl;        /* -           length of srm stack header (must        */
   void *__ptr32 rmctptch;    /* -       patch area adress           @g81opjc        */
   void *__ptr32 rmctcmct;    /* channel meas cntl table     @g860p26                */
   void *__ptr32 rmctesct;    /* ext store criteria table                            */
   void *__ptr32 rmctepbg;    /* -           epat beginning             @g50ipss     */
   int _filler6;              /* -              reserved                    @me09921 */
   void *__ptr32 rmctpagp;    /* -              system paging block pointer     @l5a */
   int rmctelet;              /* Executed long enough threshold for                  */
   int rmctsrb;               /* -              SRB service coefficient         @L6A */
   int rmctiter;              /* iteration number                @L6A                */
   int rmctsmc;               /* sample monitoring control block                     */
   int rmctdfqf;              /* address of first oucb on deferred                   */
   int rmctdfql;              /* address of last oucb on deferred                    */
   int rmctsmfb;              /* Pointer to SMF99 Buffer         @L6A                */
   void *__ptr32 rmctepdb;    /* First RMEP on EPDT              @L6C                */
   int rmctsmfs;              /* Address of last SMF99 SRB       @L6A                */
   int rmctrsda;              /* Address of RSD List             @L8A                */
   int rmctench;              /* System Encb Queue header        @L7A                */
   int rmctencl;              /* System Encb Queue trailer       @L7A                */
   int rmctsrru;              /* Address of Sysplex Router Registered                */
   int rmctdsfc;              /* Number of times sending sysplex                     */
   int rmctgrss;              /* Address of Generic Resource Selected                */
   int rmctle55;              /* -              Last saved for ENF 55       @WLMPENH */
   int rmctswmb;              /* Address of Subsystem Work                           */
   int rmctrcts;              /* Timestamp (time of day in 1.048576                  */
   int rmctipat;              /* Internal policy activation                          */
   int rmctx3;                /* Address of RMCT Extention 3 @LPOWSMA                */
   int rmctx2;                /* Address of RMCT Extention 2                         */
   union {
      double rmctx1;               /* Mapped by IRARMCTX          @WLMPESM */
      unsigned char rmctx1c4[128]; /* Cache Line 4                @ME08717 */
   };
   unsigned char rmctx1c5[128];     /* Cache Line 5                @ME08717                */
   unsigned char rmctx1c6[128];     /* Cache Line 6                @ME08717                */
   unsigned char rmctx1c7[128];     /* Cache Line 7                @ME08717                */
   unsigned char rmctx1c8[128];     /* Cache Line 8                @ME08717                */
   __extension__ double rmctend[0]; /* -                END OF RMCT                        */
};

/* Values for field "rmctflgs" */
#define rmctmfa 0x80  /* -              MEASUREMENT FACILITY ACTIVE          */
#define rmctcps1 0x40 /* CAP SWITCH                  @Z40BPSS                */
#define rmctics 0x20  /* CONTROL MEMBER DEFINED      @G742PJC                */
#define rmctinit 0x10 /* -              SRM INITIALIZATION WAS PERFORMED     */
#define rmctrept 0x08 /* -              NON-TSO REPORTING ACTIVE   @G741PJC  */
#define rmctstw 0x04  /* -              SET HAS STOPPED WAR COLLECTION       */
#define rmctfrsv 0x02 /* -              Reserved                  @ME22326C  */
#define rmctwlm 0x01  /* -              WLM mode is always active  @LCMPTMC  */

/* Values for field "_filler2" */
#define rmctrep1 0x80 /* -              Reactivation of the in storage       */
#define rmctmfs 0x40  /* -              RMF ACTIVE,SET  RCVD       @G742PGM  */
#define rmctcnsw 0x20 /* -            COUNT NON-SWAPPABLES IN CMPL @G742PGM  */
#define rmctclst 0x10 /* -           COUNT EACH COMMAND IN A CLIST @G743PGM  */
#define rmctrtso 0x08 /* -           TSO TRXNAME REPORTING ACTIVE  @G744PGS  */
#define rmctdmti 0x04 /* -              Set to reinitialize the domain       */
#define rmctokcp 0x02 /* -              This bit is set so that next time    */
#define rmctrep2 0x01 /* -              Reactivation of the in storage       */

/* Values for field "rmcttape" */
#define rmctsltn 0x80 /* -              NEXT HIGHEST               @G741PGS  */
#define rmctsltr 0x40 /* -              RANDOM                     @G741PGS  */
#define rmctsltl 0x20 /* -              LOWEST ADDRESS             @G741PGS  */
#define rmctsltf 0x10 /* -              FIRST DEVICE IN LIST       @G741PGS  */

/* Values for field "rmctflg2" */
#define rmctovfl 0x40 /* -              OVERFLOW OCCURED           @ZA45676  */
#define rmctuntr 0x20 /* -              Real time period durations are       */
#define rmctsrng 0x10 /* -              Send empty SRRU to systems     @P3C  */
#define rmctsqmr 0x08 /* -              Schedule queue manager               */

/* Values for field "rmctcsb" */
#define rmctutqe 0x80 /* -           SRM TQE IS PAST DUE         @ZA70182    */
#define rmctsimt 0x40 /* -              PASSAGE OF TIME HAS BEEN SIMULATED   */
#define rmctnobq 0x20 /* -              NO BASIC RPTING Q ELEMNTS       @H5C */
#define rmctnoeq 0x10 /* -              NO EXTND RPTING Q ELEMNTS       @H5C */
#define rmcttpp 0x08  /* -              SRM TIMER POP PENDING       @ZA78879 */
#define rmctstgf 0x04 /* -              VIO journaling dataset failure       */
#define rmctwsmf 0x02 /* -              Write SMF 99 records            @L6A */
#define rmctssmf 0x01 /* -              SRB to write SMF99 records has       */

/* Values for field "rmctend" */
#define rmctlen 0x400 /* -      LENGTH OF RMCT                               */

#define rmctbrqh 0xE8 /* HEADER                      @G742PJC                */
#define rmctbrqc 0xEC /* USE COUNT                   @G742PJC                */
#define rmcterqh 0xF0 /* HEADER                      @G742PJC                */
#define rmcterqc 0xF4 /* USE COUNT                   @G742PJC                */
#define rmctupqh 0xF8 /* HEADER                      @G742PJC                */
#define rmctupqc 0xFC /* USE COUNT                   @G742PJC                */
