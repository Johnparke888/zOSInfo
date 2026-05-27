#pragma once
/*
* 
* Descriptive name - system resources manager cpu management control table
* Macro Id: IRACCT
* DSECT Name: CCT
* Pointed to by: RMCTCCT field of the RMCT data area
* Serialization; SRH lock
* Length : 400 bytes
* Function: Contains processor usage information for use by SRM processor module
* © Copyright IBM Corp. 1977, 2019

*/

struct cct
{
   unsigned char cctcct[4]; /* -          acronym in ebcdic -cct-                  */
   int cccapmet;            /* -     minimum user execution interval for           */
   int cccapsct;            /* -              count of samples taken in irarmap1   */
   int cccmnsin;            /* -           minimum interval for computing          */
   int cctssrbf;            /* -              ssrb-related failure count      @p3c */
   short int cccapldp;      /* -              dp for undispatched apg users        */
   short int ccvenqen;      /* -              count of enclaves with an            */
   short int cccaplen;      /* -              length of mtw groups - 1    @g50ipss */
   short int cccentct;      /* -              Count of entries to IRARMAP1 used    */
   int cccmxmtw;            /* CCCTTSH in service units * 16K @L4C                 */
   short int _filler1;      /* Reserved                   @WLMPIFA                 */
   short int ccvdasct;      /* @PN72473                                            */
   short int cccttup;       /* Task time slice per UP     @WLMPIFA                 */
   short int cccwtup;       /* Wait time slice per UP     @WLMPIFA                 */
   short int ccvcrmen;      /* -              Number of enclaves promoted for      */
   short int ccvcrmct;      /* -              Number of users non-swappable for    */
   int cccrsv5;             /* @L3C                                                */
   int cccrsv6;             /* @L3C                                                */
   short int cccttshc;      /* Task time slice high ceiling for                    */
   short int cccttsm;       /* Task time slice max             @L5C                */
   int cccittsh;            /* Initial Task Time Slice High value                  */
   int ccvsigpb;            /* SIGP base count             @LVCMDAC                */
   short int cccmaxql;      /* Maximum queue length            @P1C                */
   short int cccsigpr;      /* SIGP threshold to adjust queue  @P1A                */
   short int cccmttwl;      /* Low MTTW in microsecs to adjust                     */
   short int cccmttwh;      /* High MTTW in microsecs to adjust                    */
   int ccvrbswt;            /* -              RECENT BASE SYSTEM WAIT TIME         */
   int cccawmt;             /* ALTERNATE WAIT MANAGEMENT TIME @01C                 */
   int ccvrbstd;            /* -              RECENT BASE TIME OF DAY              */
   int ccvinsct;            /* XES support                    @P2C                 */
   int ccvmtwb;             /* -              AWM time base for MTTW calc    @P1C  */
   union {
      int ccvejst; /* -              no longer used (but traceable       */
      int ccvwtdb; /* -              AWM wait dispatch ct base  @LVCMDAC */
   };
   int cccawmts;             /* -              AWM time for SUPs          @WLMPSUP  */
   short int _filler2;       /* -             reserved                   @WLMPIFA   */
   short int ccvutilp;       /* -             SYSTEM CPU UTILIZATION                */
   short int cccrsv16;       /* @L3C                                                */
   short int ccvlgfmc;       /* -             AVERAGE AVAILABLE FRAME COUNT         */
   short int ccvenqct;       /* -              NO. OF USERS NON SWAPPABLE FOR       */
   short int ccvcpuct;       /* -              NUMBER OF ONLINE CPUS                */
   short int ccvrcpct;       /* -              Number online regular CPS   @WLMPSUP */
   short int _filler3;       /* -              reserved                    @WLMPSUP */
   void *__ptr32 cccmpatp;   /* Address of array of instruction                     */
   short int ccvifact;       /* -              Number of online IFAs       @WLMPIFA */
   short int ccvutila;       /* -             processor utilization       @WLMPSUP  */
   int ccvrbawt;             /* -              Recent base CP+IFA wait time@PJK1692 */
   short int ccvsupct;       /* -              Number of online SUPs       @WLMPSUP */
   short int ccvceccp;       /* Total CPU count of the basic                        */
   int cccawmti;             /* -              AWM time for IFAs           @WLMPSUP */
   int ccvrbuwt;             /* -              Recent base SUP wait time   @WLMPSUP */
   int ccvrbiwt;             /* -              Recent base IFA wait time   @PJK1692 */
   short int ccvutili;       /* -              IFA utilization             @PJK1692 */
   short int ccvutils;       /* -              SUP utilization             @WLMPSUP */
   unsigned char cctflg1;    /* -                                                   */
   unsigned char cctflg2;    /* -              PROCESSOR TYPE FLAGS          @H2C   */
   unsigned char cctflg3[2]; /* -             RESERVED                      @H2A    */
   int cccttsh;              /* Task time slice max to rotate @L5A                  */
   int cccttsl;              /* Task time slice low           @D4A                  */
   int cccwtsh;              /* Wait task time slice high     @D4A                  */
   int cccwtsl;              /* Wait task time slice low      @D4A                  */
   int cccbrt;               /* Base real time for reduced                          */
   int ccvawmwt;             /* ccvawmwt                  @lvcmdac                  */
   char cctcdfcn;            /* -            chap down function code   @g50ipss     */
   char cctcdtsg;            /* -            time slice group number   @g50ipss     */
   short int cctcdtsc;       /* -              count of users in time slice group   */
   void *__ptr32 cctcdptr;   /* -              next list address or zero @g50ipss   */
   char cctcufcn;            /* -            chap up function code     @g50ipss     */
   char cctcutsg;            /* -            time slice group number   @g50ipss     */
   short int cctcutsc;       /* -              count of users in time slice group   */
   void *__ptr32 cctcuptr;   /* -              next list address or zero @g50ipss   */
   int cccapdiv;             /* -              dp computation divisor      @zmd0131 */
   int cccsigur;             /* -  (opt parm)  significant mtw in micros   @zmd0131 */
   int cccaplte;             /* -              time of last entry to irarmap1 in    */
   int cccrscpa;             /* -              cpu adjustment factor for the        */
   int cccpropf;             /* -              cpu timing proportion factor that    */
   int cccsxslf;             /* -              the excessive spin length factor     */
   int cccfxslf;             /* -              the excessive spin length factor     */
   int cccrsv18;             /* -              reserved                       @01c  */
   int cccrsv20;             /* -              reserved                       @01c  */
   short int ccvwscl1;       /* -              the number of times the cl1 routine  */
   short int cccwscnt;       /* -              workload skewing threshold           */
   int ccvwsbtd;             /* -              base time of day for workload        */
   int ccvwsrrm;             /* -              rate of recursive mode dispatches    */
   int ccvwsbrm;             /* -              base count of recursive mode         */
   int cccwsrlo;             /* -             low threshold for the rate of         */
   int cccwsrhi;             /* -             high threshold for the rate of        */
   int cccwstch;             /* -              constant amount to raise or          */
   union {
      double cccend; /* -                end of cct constants       @g812pjc */
      struct
      {
         int cccottsh;                   /* Task time high bound        @LVCMDAC                 */
         int cccottsl;                   /* Task time low bound         @LVCMDAC                 */
         int cccowtsh;                   /* Wait time high bound        @LVCMDAC                 */
         int cccowtsl;                   /* Wait time low bound         @LVCMDAC                 */
         int cccoitth;                   /* Initial task time slice high@LVCMDAC                 */
         short int cccottsc;             /* IFA task time slice high    @LVCMDAC                 */
         short int cccottsm;             /* IFA Task time slice max     @LVCMDAC                 */
         int ccvwsb;                     /* Base short wait time slices @LVCMDAC                 */
         int ccvwsub;                    /* Base unproductive short wait@LVCMDAC                 */
         int ccttrate;                   /* Promote event rate. This is  @LBLOCK                 */
         short int cctinthd;             /* Swapped-in address space starvation                  */
         short int cccrsv09;             /* -              reserved                     @LBLOCK  */
         short int ccttrpct;             /* 1/1000s of a CP for promote slices.                  */
         short int ccteffcp;             /* -              LPAR's effective CP.         @LBLOCK  */
         int cctrc100;                   /* -              Counts CP Utilization = 100% @LBLOCK  */
         int cctrcdsp;                   /* -              Counts calls to dispatcher   @LBLOCK  */
         int cctrcuse;                   /* -              Counts used promotes         @LBLOCK  */
         int cctrcwtr;                   /* -              Counts waiters for promote   @LBLOCK  */
         int ccttrtod;                   /* -              Last promote event timestamp in       */
         int ccttruse;                   /* -              Number of dispatchable units that     */
         int ccttrdpc;                   /* -              same as CCTRCUSE but is not reset,    */
         int ccttrblc;                   /* -              same as CCTRCWTR but is not reset,    */
         int ccttrcpm;                   /* counts how often blocked workload                    */
         int cccttsmh;                   /* Max Task time slice in HD mode @OA26272A             */
         int ccvwsdb;                    /* -         Base for short wait dispatch count         */
         int cccrsv23;                   /* -              reserved                              */
         int cccrsv24;                   /* -              reserved                              */
         int cccrsv25;                   /* -              reserved                              */
         int cccrsv26;                   /* -              reserved                              */
         int cccrsv27;                   /* -              reserved                              */
         int cccrsv28;                   /* -              reserved                              */
         int cccrsv29;                   /* -              reserved                              */
         int cccrsv30;                   /* -              reserved                              */
         int cccrsv31;                   /* -              reserved                              */
         int cccrsv32;                   /* -              reserved                              */
         int cccrsv33;                   /* -              reserved                              */
         int cccrsv34;                   /* -              reserved                              */
         int cccrsv35;                   /* -              reserved                              */
         int cccrsv36;                   /* -              reserved                              */
         __extension__ double ccvend[0]; /* -                END OF CCT                          */
      };
   };
};

/* Values for field "cctflg1" */
#define cctawma 0x40 /* -              ALTERNATE WAIT MGMT TIMING ALLOWED */
#define ccttsup 0x20 /* -              TS GROUP CHAPPED UP       @G50IPSS */

/* Values for field "cctflg2" */
#define cctrelcp 0x80 /* -              THIS PROCESSOR MODEL HAS RELATED   */
#define cctnofcp 0x40 /* -              THIS RELATED TYPE OF PROCESSOR     */
#define cctfpmt 0x20  /* -              Full preemption if bit is on @D4A  */
#define cctsmpok 0x10 /* -              When on indicates that a sample    */
#define cctnejst 0x08 /* -              When on indicates that the         */
#define cctcaltr 0x04 /* -              When on indicates promote event    */
#define cctuchck 0x02 /* -              Utilization check was run the last */

/* Values for field "ccvend" */
#define cctlen 0x190 /* -        LENGTH OF CCT                            */
