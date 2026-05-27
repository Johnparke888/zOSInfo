#pragma once
/*
* Common name: physical configuration communication area
Macro ID: IHAPCCA
DSECT name: PCCA
Owning component:
RECONFIGURATION (SC1CZ)
Eye-catcher ID: PCCA
Offset: 0
Length: 4
Storage attributes:
Subpool: 245
Key: 0
Size: 584 BYTES
Pointed to by: PCCAV... field of the PCCAVT data area
PSAPCCAV field of the PSA data area
PSAPCCAR field of the PSA data area
PCCAEMSA field of the PCCA data area (receiving routine)
Serialization: DISABLEMENT
Function: contains information about the physical facilities
associated with each processor in the system

z/OS: z/OS MVS Data Areas Volume 3 (ITK - RQE)
© Copyright International Business Machines Corporation 1988, 2020.
*/
#ifndef __MVS__
#define __ptr32
#endif

struct pcca
{
   unsigned char pccapcca[4]; /* -    control block acronym in ebcdic 'PCCA'              */

   union {
      unsigned char pccacpid[12];

      struct
      {
         unsigned char version_code[2];                 /* - version code              */
         unsigned char logical_partition_identifier[2]; /* - logical partition id      */
         unsigned char cpu_serial_number[4];            /* - cpu serial number         */
         unsigned char cpu_model_number[4];             /* - cpu model number          */
      };
   };
      short int pccacpua;     /* -         physical cpu address                     */
      short int pccacafm;     /* -         bit mask corresponding to physical cpu   */
      void *__ptr32 pccatqep; /* -         tqe pointer                              */
      void *__ptr32 pccapsav; /* -         virtual address of psa                   */
      void *__ptr32 pccapsar; /* -         absolute address of psa                  */

      unsigned char pccaisce; /* -         interrupt sub-classes to enable  @g860p22 */
      unsigned char _filler2[3];

      unsigned char pccaiscm;   /* -        interruption subclass mask       @g860p22    */
      unsigned char pccacr6[3]; /* -         low-order three bytes of cr 6    @g860p22     */
      union {
         unsigned char _filler[32]; /* -         interrupt subclass flags         @g860p22     */
         struct
         {
            int pccaslih;       /* -         number of entries to the i/o slih@g860pvb   */
            int pccastpi;       /* -         number of tpi with cc=1          @g860pvb   */
            int pccaxslf;       /* -         excessive spin length factor.        @p1c   */
            int pccarspr;       /* -         relative speed (x4096) of this       @p1c   */
            short int pccatrda; /* -         trap data                            @03a */
       
            unsigned char pccatrfl; /* -          trap flag                            @03a   */
            unsigned char _filler3; /* -          reserved                             @03a   */

            void *__ptr32 pccarv88;               /* -            reserved                                 */
            unsigned char pcca_partialcpumask[8]; /* 64-bit partial cpu bit mask, use with                 */
         };
      };
   short int pcca_tqeaid;        /* Value of TQEAID when PCCATQEP non-0. @05A           */
   short int pccarv91;           /* Reserved                             @05C           */
   void *__ptr32 pccarv92;       /* -            reserved                               */
   void *__ptr32 pccarv93;       /* -            reserved                               */
   void *__ptr32 pccarv94;       /* -            reserved                               */
   void *__ptr32 pccarv95;       /* -            reserved                               */
   void *__ptr32 pccarv96;       /* -            reserved                               */
   void *__ptr32 pccarv97;       /* -            reserved                               */
   void *__ptr32 pccarv98;       /* -            reserved                               */
   void *__ptr32 pccarv99;       /* -            reserved                               */
   void *__ptr32 pccarv9a;       /* -            reserved                               */
   void *__ptr32 pccarv9b;       /* -            reserved                               */
   void *__ptr32 pccarv9c;       /* -            reserved                               */
   void *__ptr32 pccarv9d;       /* -            reserved                               */
   void *__ptr32 pccarv9e;       /* -            reserved                               */

   unsigned char pccatmfl; /* -      first byte of pccatmst                       */
   unsigned char pccatode; /* -      tod clock error flags                        */
   unsigned char pccacce;  /* -      flags for clock comparator                   */
   unsigned char pccainte; /* -      flags for cpu timer                          */
   int pccarpb;         /* -         external call sigp buffer                 */

   unsigned char pccarisp;            /* -      CONTAINS PARALLEL/SERIAL REQUEST             */
   unsigned char pccaems2;            /* -      SECOND BYTE OF PCCAEMSI                      */
   unsigned char pccaems3;            /* -      THIRD BYTE OF PCCAEMSI                       */
   unsigned char pccarmsb;            /* -      CONTAINS RMS INDICATOR                       */
   void *__ptr32 pccaemsp;            /* -         REMOTE IMMEDIATE SIGNAL PARAMETER ADDRESS */
   void *__ptr32 pccaemse;            /* -         REMOTE IMMEDIATE SIGNAL RECEIVING ROUTINE */
   void *__ptr32 pccaemsa;            /* -         PCCA ADDRESS OF THE RECEIVING ROUTINE     */
   void *__ptr32 pccapwav;            /* -         VIRTUAL ADDRESS OF MCH PROCESSOR WORK     */
   void *__ptr32 pccapwar;            /* -         REAL ADDRESS OF MCH PROCESSOR WORK AREA   */
   void *__ptr32 pccalrbv;            /* -         VIRTUAL ADDRESS OF MCH LOGREC BUFFER      */
   void *__ptr32 pccalrbr;            /* -         REAL ADDRESS OF MCH LOGREC BUFFER         */
   unsigned char pccarios[208];       /* -       RESERVED FOR IOS USE             @G860PVB   */
   union {
      unsigned char _filler11[207]; /* -         interrupt subclass flags         @g860p22     */
      struct
      {
         unsigned char pccaattr;                 /* -      PROCESSOR ATTRIBUTES             @G47AN9A    */
         unsigned char pccamfa;                  /* -      MALFUNCTION ALERT FLAGS              @02A    */
         unsigned char pccaacrn;                 /* -      CAUSE OF ACR                         @D2A    */
         unsigned char pccarcff;                 /* Reconfig flags. Serialized by @L2A                  */
         unsigned char pcca_physical_cpuid;      /* Valid only when not LPAR or when                    */
         unsigned char _filler5;                 /* RESERVED                             @H3C           */
         unsigned char pccaprocclass[2];         /* The class of processor for this CPU.                */
         unsigned char pccar180[2];              /* Reserved                             @LAC           */
         short int pcca_cpu_address_mask_offset; /* THE BYTE OFFSET INTO A FULL CPU                     */
         unsigned char _filler10[196];           /* -    RESERVED                             @L8C      */
      };
   };

};

/* Values for field "_filler1" */
#define pccasmch 0x80 /* -        A SOFTWARE-SIMULATED MACHINE CHECK        */

/* Values for field "pccatmfl" */
#define pccainit 0x80 /* -        ENTRY HAS BEEN INITIALIZED                */
#define pccasync 0x40 /* -        CLOCK OUT OF SYNCHRONIZATION              */
#define pccavkil 0x20 /* -        CONFIG CPU SHOULD BE CANCELLED            */
#define pccamcc 0x10  /* -        PROCESSING FOR PERMANENTLY DAMAGED CLOCK  */
#define pccamint 0x08 /* -        PROCESSING FOR CPU TIMER MUST BE DONE     */
#define pccarv02 0x04 /* -  RESERVED                                        */
#define pccarv03 0x02 /* -  RESERVED                                        */
#define pccarv04 0x01 /* -  RESERVED                                        */

/* Values for field "pccatode" */
#define pccanutd 0x80 /* -        CLOCK CANNOT BE USED                      */
#define pccanftd 0x40 /* -        CLOCK SHOULD NOT BE RESET                 */
#define pccacttd 0x3F /* -        ERROR COUNT (6 BITS)                      */

/* Values for field "pccacce" */
#define pccanucc 0x80 /* -        CLOCK COMPARATOR CANNOT BE USED           */
#define pccanfcc 0x40 /* -        CLOCK COMPARATOR SHOULD NOT BE RESET      */
#define pccactcc 0x3F /* -        ERROR COUNT (6 BITS)                      */

/* Values for field "pccainte" */
#define pccanuin 0x80 /* -        CPU TIMER CANNOT BE USED                  */
#define pccanfin 0x40 /* -        CPU TIMER SHOULD NOT BE RESET             */
#define pccactin 0x3F /* -        ERROR COUNT (6 BITS)                      */

/* Values for field "pccarpb" */
#define pccaswth 0x80 /* SWITCH REQUEST                   @G860P22          */
#define pccaioqc 0x40 /* IOQ compresseion request             @L5C          */
#define pccarqck 0x20 /* RQCHECK REQUEST                  @G860P22          */
#define pccagtfr 0x10 /* GTF REQUEST                      @G860P22          */
#define pccaiose 0x08 /* I/O enable/disable request           @L5C          */
#define pccamode 0x04 /* MODE REQUEST                     @G860P22          */
#define pccastcp 0x02 /* STOPCP REQUEST                       @D3C          */
#define pccamems 0x01 /* MEMSWT REQUEST                   @G860P22          */
#define pccappsa 0x80 /* PrimePSA request                     @L6A          */

/* Values for field "pccarisp" */
#define pccaparl 0x80 /* -        PARALLEL REQUEST                          */
#define pccaserl 0x40 /* -        SERIAL REQUEST                            */
#define pccabcst 0x20 /* -        BROADCAST REQUEST                    @LBC */
#define pccarv07 0x10 /* -  RESERVED                                        */
#define pccarv08 0x08 /* -  RESERVED                                        */
#define pccarv09 0x04 /* -  RESERVED                                        */
#define pccarv10 0x02 /* -  RESERVED                                        */
#define pccarv11 0x01 /* -  RESERVED                                        */

/* Values for field "pccaems2" */
#define pccaserp 0x80 /* -        SERIAL PENDING INDICATOR         @G64UP9A */
#define pccarv13 0x40 /* -  RESERVED                                        */
#define pccarv14 0x20 /* -  RESERVED                                        */
#define pccarv15 0x10 /* -  RESERVED                                        */
#define pccarv16 0x08 /* -  RESERVED                                        */
#define pccarv17 0x04 /* -  RESERVED                                        */
#define pccarv18 0x02 /* -  RESERVED                                        */
#define pccarv19 0x01 /* -  RESERVED                                        */

/* Values for field "pccaems3" */
#define pccaserf 0x80 /* -  SERIAL REQUEST FAILED            @G860P22       */
#define pccarv21 0x40 /* -  RESERVED                                        */
#define pccarv22 0x20 /* -  RESERVED                                        */
#define pccarv23 0x10 /* -  RESERVED                                        */
#define pccarv24 0x08 /* -  RESERVED                                        */
#define pccarv25 0x04 /* -  RESERVED                                        */
#define pccarv26 0x02 /* -  RESERVED                                        */
#define pccarv27 0x01 /* -  RESERVED                                        */

/* Values for field "pccarmsb" */
#define pccarv28 0x80 /* -  RESERVED                                        */
#define pccarv29 0x40 /* -  RESERVED                                        */
#define pccarv30 0x20 /* -  RESERVED                                        */
#define pccarv31 0x10 /* -  RESERVED                                        */
#define pccarv32 0x08 /* -  RESERVED                                        */
#define pccarv33 0x04 /* -  RESERVED                                        */
#define pccarv34 0x02 /* -  RESERVED                                        */
#define pccarms 0x01  /* -        SIGP WAS ISSUED VIA RMS                   */

/* Values for field "pccaattr" */
#define pccacpum 0x80         /* -        INDICATOR THAT DEAD CPU HAD A MALFUNCTION */
#define pccaio 0x40           /* -        PROCESSOR HAS I/O CAPABILITY     @G47AN9A */
#define pccanpfa 0x20         /* -        WHEN SET, PAGE FAULT ASSIST SHOULD NOT    */
#define pccar101 0x10         /* -  RESERVED                         @G47AN9A       */
#define pccar102 0x08         /* -  RESERVED                         @G47AN9A       */
#define pccaziip 0x04         /* -  zIIP                                 @H3A       */
#define pcca_bylpar_ziip 0x04 /* -  zIIP                                 @H4A       */
#define pccasup 0x04          /* -  zIIP                                 @H3A       */
#define pcca_bylpar_sup 0x04  /* -  zIIP                                 @H4A       */
#define pccadscr 0x02         /* -        Discretionary Processor              @L7C */
#define pccaifa 0x01          /* -        Special Processor                    @H2C */
#define pcca_bylpar_zcbp 0x01 /* -                                       @LEA       */
#define pcca_bylpar_zaap 0x01 /* -                                       @H4A       */
#define pcca_bylpar_ifa 0x01  /* -                                        @H2C      */

/* Values for field "pccamfa" */
#define pccasmfa 0x80 /* -        SIMULATED MALFUNCTION ALERT          @02A */

/* Values for field "pccaacrn" */
#define pccakukn 0x00 /* UNKNOWN ERROR                        @D2A          */
#define pccakmfa 0x01 /* MALFUNCTION ALERT, CPU CHECKSTOPPED  @D2A          */
#define pccakipt 0x02 /* INSTRUCTION PROCESSING DAMAGE        @D2A          */
#define pccaksdt 0x03 /* SYSTEM DAMAGE THRESHOLD              @D2A          */
#define pccakivt 0x04 /* INVALID REGISTER OR PSW THRESHOLD    @D2A          */
#define pccaktct 0x05 /* TIME OF DAY CLOCK DAMAGE THRESHOLD   @D2A          */
#define pccakptt 0x06 /* PROCESSOR TIMER DAMAGE THRESHOLD     @D2A          */
#define pccakcct 0x07 /* CLOCK COMPARATOR DAMAGE THRESHOLD    @D2A          */
#define pccakpst 0x08 /* PRIMARY SYNC DAMAGE THRESHOLD        @D2A          */
#define pccakadt 0x09 /* ETR ATTACHMENT DAMAGE THRESHOLD      @D2A          */
#define pccakslt 0x0A /* SWITCH TO LOCAL THRESHOLD            @D2A          */
#define pccakesl 0x0B /* EXCESSIVE SPIN LOOP                  @D2A          */
#define pccaktcf 0x0C /* TOD CLOCK SYNCHRONIZATION FAILURE    @D2A          */
#define pccakdat 0x0D /* MALFUNCTION OF DAT HARDWARE          @D2A          */
#define pccakscf 0x0E /* TOD CLOCK COULD NOT BE SYNCHRONIZED  @D2A          */
#define pccakume 0x0F /* UNRECOVERABLE MACHINE ERROR          @D2A          */
#define pccakfhs 0x10 /* The CPU failed to handle the STP                   */
#define pccakmcf 0x11 /* The master CPU processing an STP                   */
#define pccakpir 0x12 /* Recursive program checks             @P5A          */
#define pccakpcm 0x13 /* Program check during MCH processing  @P5A          */
#define pccakmrm 0x14 /* Multiple restarts during MCH processing            */
#define pccakrmc 0x15 /* Recursive machine checks             @P5A          */

/* Values for field "pccarcff" */
#define pccacwlm 0x80 /* CPU on/offline initiated by WLM      @L2A          */

#define pcca_cpu_address_mask32 0x40 /* 32-bit                                             */
#define pcca_cpu_affinity_mask 0x40  /* 16-bit mask                                        */
#define pccaend 0x248                /* End of PCCA                                        */
