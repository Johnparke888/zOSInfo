#pragma once
/*
 * Common name: Prefixed Save Area
 * Macro ID:IHAPSA
 * DSECT name:PSA
 * Eye-catcher ID: None
 * Residency: Below 16 MB line
 * Size:PSA -- X'1000' bytes
 * Pointed to by:
 * The PSA maps the storage that starts at location 0 for the related processor.
 *
 * Function:
 * Maps fixed hardware and software storage locations for the related processor.
 *
 * z/OS: z/OS MVS Data Areas Volume 3 (ITK - RQE)
 * © Copyright IBM Corp. 1988, 2020
 *
 */


struct psa
{
   union {
      unsigned char flcippsw[8]; /* -         IPL PSW                */
      double flcesame;           /* FLCE 0x: defined by architecture */
      struct
      {
         unsigned char flcrnpsw[4]; /* -RESTART NEW PSW (AFTER IPL)        MDC001          */
         void *__ptr32 _filler1;    /* -  SECOND HALF OF RESTART NEW PSW     MDC128        */
         struct
         {
            unsigned char flcropsw[8]; /* -      RESTART OLD PSW (AFTER IPL)                  */
         } ;                   /* -         IPL CCW1                                  */
         struct
         {
            void *__ptr32 flccvt;      /* -    ADDRESS OF CVT (AFTER IPL).      @G50EP9A      */
            unsigned char _filler2[4]; /* -      RESERVED (AFTER IPL)  (MDC431)   @ZM48214    */
         } ;                   /* -         IPL CCW2                                  */
         unsigned char flceopsw[8];    /* -      EXTERNAL OLD PSW                             */
         unsigned char flcsopsw[8];    /* -      SVC OLD PSW.  THIS OFFSET FIXED BY           */
         unsigned char flcpopsw[8];    /* -      PROGRAM CHECK OLD PSW                        */
         unsigned char flcmopsw[8];    /* -      MACHINE CHECK OLD PSW                        */
         unsigned char flciopsw[8];    /* -      INPUT/OUTPUT OLD PSW                         */
         unsigned char _filler3[8];    /* -      RESERVED                         @G860PXK    */
         struct
         {
            unsigned char _filler4[4]; /* -      1st 4 bytes are 0                    @H3A    */
            void *__ptr32 flccvt2;     /* -    ADDRESS OF CVT - USED BY DUMP                  */
         } ;                   /* -      8-byte CVT address                   @H3A    */
         unsigned char _filler5[4];    /* -      RESERVED                         @G860PXH    */
         unsigned char _filler6[4];    /* -      RESERVED - FLCTRACE DELETED DUE TO           */
         unsigned char flcenpsw[4];    /* -EXTERNAL NEW PSW                                   */
         void *__ptr32 _filler7;       /* -  SECOND HALF OF EXTERNAL NEW PSW                  */
         unsigned char flcsnpsw[4];    /* -SVC NEW PSW                                        */
         void *__ptr32 _filler8;       /* -  SECOND HALF OF SVC NEW PSW                       */
         unsigned char flcpnpsw[4];    /* - PROGRAM CHECK NEW PSW, DISABLED FOR @02C          */
         void *__ptr32 _filler9;       /* -  SECOND HALF OF PROGRAM CHECK NEW PSW             */
         unsigned char flcmnpsw[4];    /* -MACHINE CHECK NEW PSW              MDC003          */
         void *__ptr32 _filler10;      /* -  SECOND HALF OF MACHINE CHECK NEW PSW             */
         unsigned char flcinpsw[4];    /* -INPUT/OUTPUT NEW PSW                               */
         void *__ptr32 _filler11;      /* -  SECOND HALF OF I/O NEW PSW                       */
         int psaeparm;                 /* -         EXTERNAL INTERRUPTION PARAMETER  @G871A9A */
         struct
         {
            short int psaspad;  /* -         ISSUING PROCESSOR'S PHYSICAL ADDRESS      */
            short int flceicod; /* -         EXTERNAL INTERRUPTION CODE                */
         } ;            /* -           EXTENDED PSW DATA STORED ON EXTERNAL    */
         struct
         {
            unsigned char _filler12; /* -      RESERVED - SET TO ZERO                       */
            char flcsvilc;           /* -       SVC INSTRUCTION LENGTH COUNTER - NUMBER     */
            short int flcsvcn;       /* -         SVC INTERRUPTION CODE - SVC NUMBER.       */
         } ;                 /* -           EXTENDED PSW DATA STORED ON SVC         */
         struct
         {
            unsigned char _filler13; /* -      RESERVED - SET TO ZERO                       */
            char flcpiilc;           /* -       PROGRAM INTERRUPT LENGTH COUNTER - NUMBER   */
            struct
            {
               char psaeecod; /* -       EXCEPTION-EXTENSION CODE.            @03C   */
               char psapicod; /* -       8-BIT INTERRUPT CODE.  THIS OFFSET FIXED    */
            } ;       /* -           PROGRAM INTERRUPTION CODE               */
            struct
            {
               unsigned char _filler14[3]; /* -                                           @L8A    */
               struct
               {
                  unsigned char flcteab3; /* -      LAST BYTE OF TEA.                    @L8A    */
               } ;                  /* -      Data exception code for PI 7         @LRA    */
            } ;                     /* -      TRANSLATION EXCEPTION ADDRESS.  THIS @L8C    */
         } ;                      /* -         EXTENDED PSW FOR PROGRAM INTERRUPT MDC086 */
         unsigned char _filler15;         /* -      RESERVED - SET TO ZERO                       */
         unsigned char flcmcnum;          /* -      MONITOR CLASS NUMBER                         */
         unsigned char flcpercd;          /* -      PROGRAM EVENT RECORDING CODE                 */
         unsigned char flcatmid;          /* -      ATM ID                               @LSA    */
         void *__ptr32 flcper;            /* -         PER ADDRESS - ESA/390            @G860PXK */
         unsigned char _filler16;         /* -      RESERVED - SET TO ZERO                       */
         unsigned char flcmtrcd[3];       /* -      MONITOR CODE (ESA/390)                       */
         unsigned char flctearn;          /* -      CONTAINS THE ACCESS REGISTER NUMBER  @L8C    */
         unsigned char flcperrn;          /* -      CONTAINS THE PER STORAGE ACCESS      @L8A    */
         unsigned char _filler17;         /* -      RESERVED.                            @LSC    */
         unsigned char flcarch;           /* -      Architecture information             @LSA    */
         unsigned char psampl[4];         /* -      Used only prior to z/Architecture    @MFC    */
         unsigned char _filler18[16];     /* -     RESERVED (ESA/390)               @G860PVB     */
         struct
         {
            unsigned char flcsid[4];  /* -      SUBSYSTEM ID                     @G860PVB    */
            unsigned char flciofp[4]; /* -      I/O INTERRUPTION PARAMETER       @G860PVB    */
         } ;                  /* -         I/O INFORMATION CODE             @G860PVB */
         unsigned char _filler19[8];  /* -     RESERVED                             @LRC     */
         struct
         {
            unsigned char flcfacl0;     /* Byte 0 of FLCFACL                    @LVA           */
            unsigned char flcfacl1;     /* Byte 1 of FLCFACL                    @LVA           */
            unsigned char flcfacl2;     /* Byte 2 of FLCFACL                    @LVA           */
            unsigned char flcfacl3;     /* Byte 3 of FLCFACL                    @LVA           */
            unsigned char flcfacl4;     /* Byte 4 of FLCFACL                    @PHA           */
            unsigned char flcfacl5;     /* Byte 5 of FLCFACL                    @PHA           */
            unsigned char flcfacl6;     /* Byte 6 of FLCFACL                    @PHA           */
            unsigned char flcfacl7;     /* Byte 7 of FLCFACL                    @PHA           */
            unsigned char flcfacl8;     /* Byte 8 of FLCFACL                    @M4A           */
            unsigned char flcfacl9;     /* Byte 9 of FLCFACL                    @PPA           */
            unsigned char _filler20[6]; /* -      RESERVED                             @PPC    */
         } ;                     /* -     Facilities List. See FaclBytes0To15           */
         unsigned char flcfacle[16];    /* -     Facilities List bytes 16-31. See     @MMA     */
         unsigned char flcmcic[8];      /* -      MACHINE-CHECK INTERRUPTION CODE  @G860PVB    */
         unsigned char _filler21[8];    /* -      RESERVED - SET TO ZERO           @ZMC2173    */
         void *__ptr32 flcfsa;          /* -         FAILING STORAGE ADDRESS          @G860PXK */
         unsigned char _filler22[4];    /* -      RESERVED - SET TO ZERO           @G860PXK    */
         unsigned char flcfla[16];      /* -     FIXED LOGOUT AREA. SIZE FIXED BY     @L9C     */
         unsigned char flcrv110[16];    /* -     RESERVED.                            @L9A     */
         int flcarsav[16];              /* -     ACCESS REGISTER SAVE AREA            @L9A     */
         unsigned char flcfpsav[32];    /* -     FLOATING POINT REGISTER SAVE AREA             */
         int flcgrsav[16];              /* -       GENERAL REGISTER SAVE AREA                  */
         int flccrsav[16];              /* -       CONTROL REGISTER SAVE AREA                  */
         struct
         {
            unsigned char psapsa[4]; /* -    CONTROL BLOCK ACRONYM IN EBCDIC                */
            short int psacpupa;      /* -         PHYSICAL CPU ADDRESS (CHANGED DURING ACR) */
            short int psacpula;      /* -         LOGICAL CPU ADDRESS                       */
         } ;                 /* -           END OF HARDWARE ASSIGNMENTS             */
         void *__ptr32 psapccav;     /* -         VIRTUAL ADDRESS OF PCCA                   */
         void *__ptr32 psapccar;     /* -         REAL ADDRESS OF PCCA                      */
         void *__ptr32 psalccav;     /* -         VIRTUAL ADDRESS OF LCCA                   */
         void *__ptr32 psalccar;     /* -         REAL ADDRESS OF LCCA                      */
         void *__ptr32 psatnew;      /* -         TCB pointer. Field maintained for code    */
         void *__ptr32 psatold;      /* -         Pointer to current TCB or zero if in SRB  */
         void *__ptr32 psaanew;      /* ASCB pointer.  Field maintained for code            */
         void *__ptr32 psaaold;      /* -         Pointer to the home (current) ASCB.  @LQC */
         struct
         {
            unsigned char psasup1;                      /* -      FIRST BYTE OF PSASUPER                       */
            unsigned char psasup2;                      /* -      SECOND BYTE OF PSASUPER                      */
            unsigned char psasup3;                      /* -      THIRD BYTE OF PSASUPER                       */
            unsigned char psasup4;                      /* -      FOURTH BYTE OF PSASUPER                      */
         } psasuper;                                    /* -         SUPERVISOR CONTROL WORD.         @G50EP9A */
         unsigned char psarv22c[9];                     /* -     RESERVED                             @xxC     */
         unsigned char psa_workunit_cbf_atdisp[2];      /* @MHA                                                */
         unsigned char psarv237;                        /* -     RESERVED                             @MKC     */
         unsigned char psa_workunit_procclassatdisp[2]; /* -                          @MCA                     */
      };
      unsigned char flceippsw[8]; /* FLCE 0x: IPL PSW                 */
      struct
      {
         unsigned char _filler23[8];
         unsigned char flceiccw1[8];  /* FLCE 8x: IPL CCW1                            */
         unsigned char flceiccw2[8];  /* FLCE 10x: IPL CCW1                           */
         unsigned char flcer018[104]; /* FLCE 18x: reserved                           */
         unsigned char flceeparm[4];  /* FLCE 80x: External interruption parameter    */
         unsigned char flcecpuad[2];  /* FLCE 84x: CPU address                        */
         unsigned char flceeicode[2]; /* FLCE 86x: External interruption code         */
         struct
         {
            struct
            {
               unsigned char _filler24; /* FLCE 88x: Reserved                           */
               struct
               {
                  unsigned char _filler25;
               } ;               /* FLCE 89x: SVC interruption length code       */
            } ;            /* FLCE 88x:                                    */
            unsigned char flcesicode[2]; /* FLCE 8Ax: SVC interruption code              */
         } ;                    /* FLCE 88x: Additional SVC interruption data   */
         struct
         {
            struct
            {
               unsigned char _filler26; /* FLCE 8Cx: Reserved                           */
               struct
               {
                  unsigned char _filler27;
               } ;    /* FLCE 8Dx: Program interruption length code   */
            } ; /* FLCE 8Cx:                                    */
            struct
            {
               unsigned char flcepicode0; /* FLCE 8Ex: Exception extension code           */
               struct
               {
                  unsigned char _filler28;
               } ; /* FLCE 8Fx: 8-bit interruption code            */
            } ;     /* FLCE 8Ex: Program interruption code          */
         } ;         /* FLCE 8Cx: Additional Program interruption    */
         struct
         {
            unsigned char _filler29[3];
            struct
            {
               unsigned char flcevxc; /* FLCE 93x: Vector exception code for PI 1B    */
            } flcedxc;                /* FLCE 93x: Data exception code for PI 7       */
         } flcepiinformation;         /* FLCE 90x:                                    */
         unsigned char flcemcnum[2];  /* FLCE 94x: Monitor class number               */
         struct
         {
            struct
            {
               unsigned char _filler30;
            } ; /* FLCE 96x: Byte 0                              */
            struct
            {
               unsigned char _filler31;
            } ; /* FLCE 97x: PER addressing and translation mode */
         } ;     /* FLCE 96x: PER code                            */
         struct
         {
            unsigned char flceperw0[4]; /* FLCE 98x: PER address word 0                 */
            void *__ptr32 flceperw1;    /* FLCE 9Cx: PER address word 1                 */
         } ;                     /* FLCE 98x: PER address                        */
         struct
         {
            unsigned char _filler32;
         } ;               /* FLCE A0x: Exception access ID (The AR number */
         unsigned char flceperaid; /* FLCE A1x: PER access ID (the access register */
         unsigned char flceopacid; /* FLCE A2x:                                    */
         struct
         {
            unsigned char _filler33;
         } ;           /* FLCE A3x: Architecture mode ID (See FLCARCH  */
         void *__ptr32 flcempl; /* FLCE A4x: MPL address                        */
         struct
         {
            struct
            {
               unsigned char _filler34[6];
               struct
               {
                  unsigned char _filler35;
               } ; /* FLCE AEx: Byte 6 of FlceTEA                  */
               struct
               {
                  unsigned char _filler36;
               } ; /* FLCE AFx: Byte 7 of FlceTEA                  */
            } ;     /* FLCE A8x: Translation exception address      */
         } ;       /* FLCE A8x: Translation exception              */
         unsigned char _filler37[394];
      };
      struct
      {
         unsigned char _filler38[168];
         struct
         {
            unsigned char _filler39[6];
            short int flceteasn; /* FLCE AEx: ASN                    */
         } flceteasninfo;        /* FLCE A8x: ASN Info               */
         unsigned char _filler40[394];
      };
      struct
      {
         unsigned char _filler41[168];
         struct
         {
            unsigned char _filler42[4];
            int flcepcnum;                 /* FLCE ACx: PC#. Bits 0-10 are 0, bit 11 is 1, */
         } ;                   /* FLCE A8x: PC Info                            */
         unsigned char flcemonitorcode[8]; /* FLCE B0x: Monitor Code                     */
         unsigned char flcessid[4];        /* FLCE B8x: Subsystem ID word                */
         unsigned char flceiointparm[4];   /* FLCE BCx: I/O interruption parameter       */
         unsigned char flceiointid[4];     /* FLCE C0x: I/O interruption ID              */
         unsigned char flcer0c4[4];        /* FLCE C4x: Reserved                         */
         struct
         {
            struct
            {
               unsigned char _filler43;
            } flcefacilitieslistbyte0; /* FLCE C8x                                   */
            struct
            {
               unsigned char _filler44;
            } ; /* FLCE C9x                                   */
            struct
            {
               unsigned char _filler45;
            } ; /* FLCE CAx                                   */
            struct
            {
               unsigned char _filler46;
            } ; /* FLCE CBx                                   */
            struct
            {
               unsigned char _filler47;
            } ; /* FLCE CCx                                   */
            struct
            {
               unsigned char _filler48;
            } ; /* FLCE CDx                                   */
            struct
            {
               unsigned char _filler49;
            } ; /* FLCE CEx                                   */
            struct
            {
               unsigned char _filler50;
            } ; /* FLCE CFx                                   */
            struct
            {
               unsigned char _filler51;
            } ; /* FLCE D0x bits 64-71                        */
            struct
            {
               unsigned char _filler52;
            } ;             /* FLCE D1x bits 72-79                        */
            unsigned char flcefacilitieslistbytea; /* FLCE D2x                                   */
            unsigned char flcefacilitieslistbyteb; /* FLCE D3x                                   */
            unsigned char flcefacilitieslistbytec; /* FLCE D4x                                   */
            unsigned char flcefacilitieslistbyted; /* FLCE D5x                                   */
            unsigned char flcefacilitieslistbytee; /* FLCE D6x                                   */
            unsigned char flcefacilitieslistbytef; /* FLCE D7x                                   */
         } ;                     /* FLCE C8x: Facilities list stored by STFLE. */
         unsigned char flcefacilitieslist1[16];    /* FLCE D8x: Facilities list stored by STFLE. */
         unsigned char flcemcic[8];                /* FLCE E8x: Machine check interruption code  */
         unsigned char flcemcice[4];               /* FLCE F0x: Machine check interruption code  */
         unsigned char flceedcode[4];              /* FLCE F4x: External damage code             */
         unsigned char flcefsa[8];                 /* FLCE F8x: Failing storage address          */
         unsigned char flceemfctrarrayaddr[8];     /* FLCE 100x: The enhanced monitor facility   */
         int flceemfctrarraysize;                  /* FLCE 108x: The enhanced monitor facility   */
         int flceemfexceptioncnt;                  /* FLCE 10Cx: The enhanced monitor facility   */
         unsigned char flcebea[8];                 /* FLCE 110x: Breaking event address          */
         unsigned char flcer118[8];                /* FLCE 118x: Reserved                        */
         unsigned char flceropsw[16];              /* FLCE 120x: Restart old PSW                 */
         unsigned char flceeopsw[16];              /* FLCE 130x: External old PSW                */
         unsigned char flcesopsw[16];              /* FLCE 140x: SVC old PSW                     */
         unsigned char flcepopsw[16];              /* FLCE 150x: Program old PSW                 */
         unsigned char flcemopsw[16];              /* FLCE 160x: Machine check old PSW           */
         unsigned char flceiopsw[16];              /* FLCE 170x: I/O old PSW                     */
         unsigned char flcer180[32];               /* FLCE 180x: reserved                        */
         unsigned char flcernpsw[16];              /* FLCE 1A0x: Restart new PSW                 */
         unsigned char flceenpsw[16];              /* FLCE 1B0x: External new PSW                */
         unsigned char flcesnpsw[16];              /* FLCE 1C0x: SVC new PSW                     */
         unsigned char flcepnpsw[16];              /* FLCE 1D0x: Program new PSW                 */
         unsigned char flcemnpsw[16];              /* FLCE 1E0x: Machine check new PSW           */
         unsigned char flceinpsw[16];              /* FLCE 1F0x: I/O new PSW                     */
         unsigned char _filler53[58];
      };
      struct
      {
         unsigned char _filler54[568];
         unsigned char psa_workunit_procclassatdisp_byte0; /* @MCA                             */
         unsigned char psa_workunit_procclassatdisp_byte1; /* @MCA                             */
         unsigned char psaprocclass[2];                    /* -     PROCESSOR WUQ Offset.      */
      };
      struct
      {
         unsigned char _filler55[570];
         unsigned char psa_bylpar_procclass[2]; /* - PROCESSOR WUQ Offset.            @H5A */
      };
      struct
      {
         unsigned char _filler56[570];
         unsigned char psaprocclass_byte0; /* @H4A                             */
         unsigned char psaprocclass_byte1; /* @H4A                             */
      };
      struct
      {
         unsigned char _filler57[570];
         unsigned char psa_bylpar_procclass_byte0; /* @H5A                                                   */
         unsigned char psa_bylpar_procclass_byte1; /* @H5A                                                   */
         unsigned char psaptype;                   /* -      PROCESSOR TYPE INDICATOR             @H1A       */
         unsigned char psails;                     /* -      INTERRUPT HANDLER LINKAGE STACK      @L9C       */
         unsigned char psalsvci[2];                /* -      LAST SVC ISSUED ON THIS PROCESSOR    @L6A       */
         unsigned char psaflags;                   /* -      SYSTEM FLAGS                         @LOA       */
         unsigned char psarv241[10];               /* RESERVED FOR FUTURE USE - SC1C5.     @LOC              */
         unsigned char psascaff;                   /* $$SCAFFOLD                                             */
         void *__ptr32 psalkcrf;                   /* LINKAGE STACK POINTER SAVE AREA.     @D4A              */
         unsigned char psampsw[8];                 /* - SETLOCK MODEL PSW                                    */
         unsigned char psaicnt[8];                 /* -      Instruction count at last (re)dispatch          */
         int psatclin;                             /* -            STOSM PSASLSA,X'00' INSTRUCTION      @P5A */
         int psaintin;                             /* -            STOSM PSASLSA,X'00' INSTRUCTION      @P5A */
         int psaipcin;                             /* -            STOSM PSASLSA,X'00' INSTRUCTION      @P5A */
         int psaems2s;                             /* -            STOSM PSASLSA,X'00' INSTRUCTION      @P5A */
         int psastosm;                             /* -            STOSM PSASLSA,X'00' INSTRUCTION.     @P5A */
         int psahlhis;                             /* -         SAVE AREA FOR PSAHLHI              MDC050    */
         unsigned char psarecur;                   /* -      RESTART FLIH RECURSION INDICATOR.  IF           */
         unsigned char psarssm;                    /* -      STNSM AREA FOR IEAVERES              @L5C       */
         unsigned char psasnsm2;                   /* -      STNSM AREA FOR IEAVTRT1 (MDC470) @G65RP9A       */
         unsigned char psartm1s;                   /* -      BITS 0-7 OF THE CURRENT PSW ARE  @G383P9A       */
         void *__ptr32 psalwtsa;                   /* -         REAL ADDRESS OF SAVE AREA USED WHEN  @LHC    */
         struct
         {
            struct
            {
               void *__ptr32 psadispl; /* -  GLOBAL DISPATCHER LOCK  (MDC315) @G50DP9A           */
               void *__ptr32 psaasml;  /* -         AUXILIARY STORAGE MANAGEMENT (ASM) LOCK      */
               void *__ptr32 psasalcl; /* -  SPACE ALLOCATION LOCK  (MDC316)  @G50DP9A           */
               void *__ptr32 psaiossl; /* -         IOS SYNCHRONIZATION LOCK           MDC010    */
               void *__ptr32 psarsmdl; /* -         ADDRESS OF THE RSM DATA SPACE LOCK   @LBC    */
               void *__ptr32 psaiosul; /* -         IOS UNIT CONTROL BLOCK LOCK        MDC005    */
               void *__ptr32 psarsmql; /* -         RSMQ lock                            @MIA    */
               void *__ptr32 psarv29c; /* -         RESERVED FOR LOCK EXPANSION          @LDC    */
               void *__ptr32 psarv2a0; /* -         RESERVED FOR LOCK EXPANSION          @LDC    */
               void *__ptr32 psatpacl; /* -         TCAM'S TPACBDEB LOCK               MDC009    */
               void *__ptr32 psaoptl;  /* -   OPTIMIZER LOCK  (MDC317)         @G50DP9A          */
               void *__ptr32 psarsmgl; /* -         RSM GLOBAL LOCK                  @G860PXH    */
               void *__ptr32 psavfixl; /* VSM FIXED SUBPOOLS LOCK          @G860PXH              */
               void *__ptr32 psaasmgl; /* -         ASM GLOBAL LOCK                  @G860PXH    */
               void *__ptr32 psarsmsl; /* -         RSM STEAL LOCK                   @G860PXH    */
               void *__ptr32 psarsmxl; /* -         RSM CROSS MEMORY LOCK            @G860PXH    */
               void *__ptr32 psarsmal; /* -         RSM ADDRESS SPACE LOCK           @G860PXH    */
               void *__ptr32 psavpagl; /* VSM PAGEABLE SUBPOOLS LOCK       @G860PXH              */
               void *__ptr32 psarsmcl; /* RSM COMMON LOCK                  @G860PXK              */
               void *__ptr32 psarvlk2; /* RESERVED FOR LOCK EXPANSION      @G860PXH              */
            } ;                /* -        SPIN LOCKS TABLE                 @G860PXH     */
            struct
            {
               void *__ptr32 psarsml;  /* RSM GLOBAL FUNCTION/RECOVERY                           */
               void *__ptr32 psatrcel; /* TRACE BUFFER MANAGEMENT LOCK     @G860PXH              */
               void *__ptr32 psaiosl;  /* -   IOS LOCK                             @D3C          */
               void *__ptr32 psarvlk4; /* -         RESERVED FOR LOCK EXPANSION      @G50NP9A    */
            } ;                /* SHARED EXCLUSIVE LOCKS TABLE     @G860PXH              */
            struct
            {
               void *__ptr32 psacpul;  /* CPU TABLE LOCKS                  @G860PXH              */
               void *__ptr32 psarvlk5; /* -         RESERVED FOR LOCK EXPANSION      @G50NP9A    */
            } ;                /* SPECIAL LOCKS TABLE              @G860PXH              */
            struct
            {
               void *__ptr32 psacmsl;  /* -         CROSS MEMORY SERVICES LOCK                   */
               void *__ptr32 psalocal; /* -         LOCAL LOCK                                   */
               void *__ptr32 psarvlk6; /* -         RESERVED FOR LOCK EXPANSION      @G50NP9A    */
            } psaclht4;                /* SUSPEND LOCKS TABLE              @G860PXH              */
         } ;                    /* -       CPU LOCKS TABLE  (MDC314)        @G860PXH      */
         void *__ptr32 psalcpua;       /* -         LOGICAL CPU ADDRESS FOR LOCK INSTRUCTION.    */
         struct
         {
            struct
            {
               unsigned char psaclhs1; /* -      FIRST BYTE OF PSACLHS. (MDC384)  @G860PXH       */
               unsigned char psaclhs2; /* -      SECOND BYTE OF PSACLHS. (MDC385) @G860PXH       */
               unsigned char psaclhs3; /* -      THIRD BYTE OF PSACLHS  (MDC386)  @G50EP9A       */
               unsigned char psaclhs4; /* -      FOURTH BYTE OF PSACLHS  (MDC392) @G50EP9A       */
            } ;                 /* -           CPU LOCKS HELD STRING              MDC122  */
         } ;                    /* -           HIGHEST LOCK HELD INDICATOR.     @G50EP9A  */
         void *__ptr32 psalita;        /* -  ADDRESS OF LOCK INTERFACE TABLE. @ZM48253           */
         unsigned char psastor8[8];    /* -      8-BYTE value for master's STO        @LSA       */
         int psacr0;                   /* -         SAVE AREA FOR CONTROL REGISTER 0             */
         unsigned char psamchfl;       /* -      MCH RECURSION FLAGS                             */
         unsigned char psasymsk;       /* -      THIS FIELD WILL BE USED IN CONJUNCTION          */
         unsigned char psaactcd;       /* -      ACTION CODE SUPPLIED BY OPERATOR     @LHC       */
         unsigned char psamchic;       /* -      MCH INITIALIZATION COMPLETE FLAGS  MDC098       */
         void *__ptr32 psawkrap;       /* -         REAL ADDRESS OF VARY CPU PARAMETER LIST      */
         void *__ptr32 psawkvap;       /* -         VIRTUAL ADDRESS OF VARY CPU PARAMETER        */
         short int psavstap;           /* -         WORK AREA FOR VARY CPU             MDC108    */
         short int psacpusa;           /* -         PHYSICAL CPU ADDRESS (STATIC)  (MDC131)      */
         int psastor;                  /* -         MASTER MEMORY'S SEGMENT TABLE ORIGIN         */
         unsigned char psaidawk[90];   /* -     WORK SAVE AREA FOR private                       */
         short int psaret;             /* -            BSM 0,14 BRANCH RETURN TO CALLER     @P5A */
         short int psaretcd;           /* -            BSM 0,14 BRANCH RETURN TO CALLER     @P5A */
         unsigned char psaval[2];      /* -          Virtual Architecture Level. Bits 0-11       */
         struct
         {
            struct
            {
               void *__ptr32 psacstk;  /* -         ADDRESS OF CURRENTLY USED FUNCTIONAL         */
               void *__ptr32 psanstk;  /* -         ADDRESS OF NORMAL FRR STACK        MDC062    */
               void *__ptr32 psasstk;  /* -         ADDRESS OF SVC-I/O-DISPATCHER FRR STACK      */
               void *__ptr32 psassav;  /* -         ADDRESS OF INTERRUPTED STACK SAVED BY        */
               void *__ptr32 psamstk;  /* -         ADDRESS OF MCH FRR STACK           MDC067    */
               void *__ptr32 psamsav;  /* -         ADDRESS OF INTERRUPTED STACK SAVED BY        */
               void *__ptr32 psapstk;  /* -         ADDRESS OF PROGRAM CHECK FLIH FRR STACK      */
               void *__ptr32 psapsav;  /* -         ADDRESS OF INTERRUPTED STACK SAVED BY        */
               void *__ptr32 psaestk1; /* -         ADDRESS OF EXTERNAL FLIH FRR STACK FOR       */
               void *__ptr32 psaesav1; /* -         ADDRESS OF INTERRUPTED STACK SAVED BY        */
               void *__ptr32 psaestk2; /* -         ADDRESS OF EXTERNAL FLIH FRR STACK FOR       */
               void *__ptr32 psaesav2; /* -         ADDRESS OF INTERRUPTED STACK SAVE BY         */
               void *__ptr32 psaestk3; /* -         ADDRESS OF EXTERNAL FLIH FRR STACK FOR       */
               void *__ptr32 psaesav3; /* -         ADDRESS OF INTERRUPTED STACK SAVED BY        */
               void *__ptr32 psarstk;  /* -         ADDRESS OF RESTART FLIH FRR STACK  MDC077    */
               void *__ptr32 psarsav;  /* -         ADDRESS OF INTERRUPTED STACK SAVED BY        */
            } psasvte;                /* -        RECOVERY STACK VECTOR TABLE        MDC065     */
         } ;                    /* -        RECOVERY STACK VECTOR TABLE        MDC064     */
         unsigned char psalwpsw[8];    /* -      PSW OF WORK INTERRUPTED WHEN A       @LHC       */
         double psarv3c8;              /* Reserved                             @M8C              */
         void *__ptr32 psatstk;        /* -         ADDRESS OF RTM RECOVERY STACK.               */
         void *__ptr32 psatsav;        /* -         ADDRESS OF ERROR STACK SAVED BY RTM  @L7A    */
         void *__ptr32 psaastk;        /* -         ADDRESS OF ACR FRR STACK.            @L7A    */
         void *__ptr32 psaasav;        /* -         ADDRESS OF INTERRUPT STACK SAVED BY  @L7A    */
         unsigned char psartpsw[8];    /* -      RESUME PSW FOR RTM SETRP RETRY       @L7A       */
         unsigned char psarv3e8[8];    /* -      RESERVED                             @L7C       */
         unsigned char psasfacc[4];    /* - SETFRR ABEND COMPLETION CODE USED WHEN               */
         int psalsfcc;                 /* -            L  1,PSASFACC INSTRUCTION TO LOAD    @P5A */
         short int psasvc13;           /* -            AN SVC 13 INSTRUCTION                @P5A */
         unsigned char psafpfl;        /* -      See LCCAFPFL                         @MEC       */
         unsigned char psainte;        /* -      FLAGS FOR CPU TIMER  (MDC466)    @ZM48078       */
         int psartm1r;                 /* -            STOSM PSARTM1S,X'00' INSTRUCTION     @P5A */
         unsigned char psarv400[8];    /* -      Reserved                             @LVC       */
         void *__ptr32 psaatcvt;       /* -         ADDRESS OF VTAM ATCVT.  INITIALIZED BY       */
         void *__ptr32 psawtcod;       /* -         WAIT STATE CODE LOADED               @LHC    */
         void *__ptr32 psascwa;        /* -         ADDRESS OF SUPERVISOR CONTROL CPU            */
         void *__ptr32 psarsmsa;       /* -         ADDRESS OF RSM CPU RELATED WORK              */
         unsigned char psascpsw[4];    /* - MODEL PSW                                            */
         void *__ptr32 _filler58;      /* -         MODEL PSW SECOND HALF  (MDC325)  @G50DP9A    */
         unsigned char psasmpsw[4];    /* - SRB DISPATCH PSW  (MDC326)      @G50DP9A             */
         void *__ptr32 _filler59;      /* -         DISPATCH PSW SECOND HALF                     */
         unsigned char psapcpsw[16];   /* =     TEMPORARY OLD PSW STORAGE FOR PROGRAM            */
         unsigned char psarv438[8];    /* =     Reserved                             @M8C        */
         unsigned char psamcx16[16];   /* -     MCH exit PSW16                       @M8A        */
         unsigned char psarsp16[16];   /* -     Resume PSW field for restart interrupt           */
         unsigned char psapswsv16[16]; /* -     PSW SAVE AREA FOR DISPATCHER AND ACR @M8A        */
      };
      struct
      {
         unsigned char _filler60[1120];
         double _filler61;          /* -           Part of PSAPSWSV16                   @M8C */
         unsigned char psapswsv[8]; /* -      PSW SAVE AREA FOR DISPATCHER AND ACR           */
         unsigned char psacput[8];  /* -      SUPERVISOR CPU TIMER SAVE AREA                 */
         struct
         {
            unsigned char psapcfb1;  /* -      FUNCTION VALUE  (MDC484)         @G383P9A      */
            unsigned char psapcfb2;  /* -      FUNCTION FLAGS  (MDC491)         @G383P9A      */
            unsigned char psapcfb3;  /* -      RECURSION FLAGS  (MDC494)        @G383P9A      */
            unsigned char psapcfb4;  /* -      RECURSION FLAGS                                */
         } ;                 /* -           PROGRAM FLIH RECURSION           @G383P9A */
         short int psapcps2;         /* -         PASID AT TIME OF SECOND LEVEL    @G383P9A   */
         unsigned char psarv47e[2];  /* -      RESERVED                         @G860PXK      */
         unsigned char psapcwka[24]; /* -     Work area for PC FLIH. Must be                  */
         short int psapcps3;         /* -         PASID AT TIME OF THIRD LEVEL     @G383P9A   */
         short int psapcps4;         /* -         PASID AT TIME OF FOURTH LEVEL               */
         struct
         {
            unsigned char _filler62; /* -      RESERVED - FIRST BYTE OF PSAMODEW              */
            unsigned char psamflgs;  /* -      SECOND BYTE OF PSAMODEW (MDC604) @G383P9A      */
            unsigned char psamodeh;  /* -      SECOND HALFWORD OF PSAMODEW.     @G383P9A      */
            unsigned char psamode;   /* -      SYSTEM MODE INDICATOR AND DISPLACEMENT         */
         } ;                 /* -           Word label to address PSAMODE.       @LPC */
         unsigned char _filler63[3]; /* -      RESERVED                         @G860PXK      */
         unsigned char psastnsm;     /* -      STNSM TARGET USED BY EXIT PROLOGUE             */
         int psalkjw;                /* -         LOCAL LOCK RELEASE SRB JOURNAL   @G383P9A   */
         struct
         {
            int psafzero;        /* -         FULLWORD OF ZERO     (MDC612)    @G383P9A   */
            int _filler64;       /* -         FULLWORD OF ZERO     (MDC612)    @G383P9A   */
         } ;             /* -           DOUBLEWORD OF ZERO   (MDC612)    @G383P9A */
         int psalkjw2;           /* -         CMS LOCK RELEASE JOURNAL WORD.   @G383P9A   */
         void *__ptr32 psalkpt;  /* -   SETLOCK TEST,TYPE=HIER                            */
         void *__ptr32 psalaa;   /* -      LE Anchor Area. Owner: LE            @LVA      */
         void *__ptr32 psalit2;  /* -  POINTER TO THE EXTENDED LOCK         @LDA          */
         void *__ptr32 psaecltp; /* -   POINTER TO THE EXTENDED CURRENT      @LDA         */
         struct
         {
            unsigned char psalheb0;    /* -      BYTE 0 OF THE CURRENT LOCK HELD      @LDA      */
            unsigned char psalheb1;    /* -      BYTE 1 OF THE CURRENT LOCK HELD      @LDA      */
            unsigned char psalheb2;    /* -      BYTE 2 OF THE CURRENT LOCK HELD      @LDA      */
            unsigned char psalheb3;    /* -      BYTE 3 OF THE CURRENT LOCK HELD      @LDA      */
         } ;                   /* -           CURRENT LOCKS HELD STRING EXTENSION  @LDA */
         unsigned char psarv4c8[8];    /* -    RESERVED FOR FUTURE LOCK EXPANSION.  @LDA        */
         unsigned char psarv4d0[144];  /* -    RESERVED.                            @0KC        */
         unsigned char psadiag560[36]; /* -     Diagnostic data for IBM use only     @0KA       */
         unsigned char psarv584[4];    /* -      RESERVED.                            @0KA      */
         unsigned char psahwfb;        /* -      HARDWARE FLAG BYTE.                  @L3A      */
         unsigned char psacr0cb;       /* -      CR0 CONTROL BYTE USED BY PROTPSA MACRO         */
         unsigned char psarv58a[2];    /* -      RESERVED                             @PJC      */
         int psacr0sv;                 /* -         CR0 SAVE AREA USED BY PROTPSA MACRO         */
         int psapccr0;                 /* -         PROGRAM CHECK FLIH CR0 SAVE AREA            */
         int psarcr0;                  /* -         RESTART FLIH CR0 SAVE AREA                  */
         struct
         {
            short int psatkn;                    /* -         CURRENT STACK TOKEN     (MDC610) @G383P9A   */
            short int psaasd;                    /* -         CURRENT STACK ADDRESS SPACE                 */
            int psasel;                          /* -         CURRENT STACK ELEMENTS ADDRESS              */
         } ;                              /* -           CURRENT STACK CONTROL WORD FOR SRB'S AND  */
         unsigned char psaskpsw[4];              /* PCLINK STACK/UNSTACK MODEL PSW                        */
         void *__ptr32 psaskps2;                 /* -         PCLINK PSW ADDRESS      (MDC604) @G383P9A   */
         void *__ptr32 psacpcls;                 /* -      PCLINK WORKAREA - CURRENT STACK      @L9C      */
         unsigned char psarv5ac[4];              /* -      RESERVED.                            @L9A      */
         void *__ptr32 psascfs;                  /* -      ADDRESS OF THE SUPERVISOR CONTROL    @L8C      */
         void *__ptr32 psapawa;                  /* -      ADDRESS OF PC/AUTH WORK AREA.        @L8A      */
         unsigned char psascfb;                  /* -      SUPERVISOR CONTROL FLAG BYTE.        @L1A      */
         unsigned char psarv5b9[3];              /* -      RESERVED                             @PJC      */
         unsigned char psacr0m1[4];              /* MASK OF CR0 WITH EXTERNAL MASK BITS  @0HC             */
         unsigned char psacr0m2[4];              /* MASK OF CR0 WITH ONLY EXTERNAL MASK  @0HC             */
         unsigned char psarv5c4[4];              /* -      RESERVED                             @MAA      */
         unsigned char psa_cr0emaskoffextint[8]; /* Mask of bits to turn                                  */
         unsigned char psa_cr0emaskonextint[8];  /* Mask of bits to turn                                  */
         struct
         {
            unsigned char psa_cr0esavearea_hw[4]; /* High word save area for high word of                  */
            unsigned char psa_cr0esavearea_lw[4]; /* Low word save area for low word of                    */
         } psa_cr0esavearea;                      /* Save area for grande CR0         @MAA                 */
         unsigned char psa_windowworkarea[16];    /* WorkArea for IEAMWIN                @0IA              */
      };
      struct
      {
         unsigned char _filler65[1504];
         unsigned char psa_windowtoddelta[8]; /* Difference in TOD values - used in */
         unsigned char _filler66[8];
      };
      struct
      {
         unsigned char _filler67[1504];
         unsigned char psa_windowtoddelta_hw[4]; /* High word area for difference in TOD                   */
         unsigned char psa_windowtoddelta_lw[4]; /* Low word area for difference in TOD                    */
         unsigned char _filler68[8];
         unsigned char psa_windowlastopentod[8]; /* TOD when IEAMWIN last opened a window                  */
         unsigned char psa_windowcurrenttod[8];  /* TOD when IEAMWIN last checked to open                  */
         unsigned char psarv600[80];             /* -     RESERVED                             @0IC        */
         double psa_time_on_cp;                  /* -      Current SRB's accumulated CPU time   @0CA       */
         double psatime;                         /* -         CURRENT SRB'S ACCUMULATED CPU TIME   @01C    */
         int psasrsav;                           /* -        ADDRESS OF CURRENT FRR STACK     @G383P9A     */
         unsigned char psaesc8[12];              /* -     Save area for IEAVESC8               @LPA        */
         unsigned char psadexmw[8];              /* -         Work area for dispatcher CR3/4       @LVC    */
         unsigned char psadsars[64];             /* -     DISPATCHER ACCESS REGISTER SAVE AREA @L9C        */
         double psa_pcflih_trace_interrupt_cput; /* - Trace interrupt CPU timer saved                      */
         double psadtsav;                        /* -            CPU TIMER VALUE AT LAST DISPATCH,    @01C */
      };
      struct
      {
         unsigned char _filler69[1728];
         unsigned char psaff6c0[8]; /* INITIALIZE FIELD PSADTSAV     @ZMC3284        */
         struct
         {
            struct
            {
               int psadsins; /* -        DISPATCHER Secondary ASTE Inst# S/A  @LVA  */
               struct
               {
                  short int psadpkm; /* -        DISPATCHER PROGRAM KEY MASK SAVE AREA      */
                  short int psadsas; /* -        DISPATCHER SECONDARY ASID SAVE AREA        */
               } ;           /* -        PKM and SASID                        @LVA  */
            } ;               /* -           DISPATCHER CONTROL REGISTER 3 SAVE AREA */
            struct
            {
               int psadpins; /* -        DISPATCHER Primary ASTE Inst# S/A    @LVA  */
               struct
               {
                  short int psadax;          /* -        DISPATCHER  AUTHORIZATION        @G383P9A  */
                  short int psadpas;         /* -        DISPATCHER PRIMARY ASID SAVE     @G383P9A  */
               } ;                   /* -        AX and PASID                         @LVA  */
            } ;                       /* -           DISPATCHER CONTROL REGISTER 4 SAVE AREA */
         } ;                         /* -         DISPATCHER CONTROL REGISTER 3 AND 4       */
         double psa_time_on_zcbp_normalized; /* - Current SRB's accumulated CPU               */
         struct
         {
            unsigned char _filler70[8];
         } ; /* END FIRST SET OF ASSIGNED FIELDS @G383PXU     */
      };
      struct
      {
         unsigned char _filler71[1760];
         unsigned char psarv6e0[192]; /* -    RESERVED                             @MTC       */
         double psaecvt;              /* Address of ECVT                      @M3A            */
         double psaxcvt;              /* Address of XCVT                      @M3A            */
         unsigned char psadatlk[48];  /* -    AREA FOR DAT-OFF ASSIST LINKAGE CODE            */
         void *__ptr32 psadatof;      /* -         REAL STORAGE ADDRESS OF THE DAT-OFF        */
         int psadatln;                /* -        LENGTH OF THE DAT-OFF INDEX TABLE           */
         unsigned char psarv7e8[4];   /* -          RESERVED FOR SYSTEM TRACE.       @G860PXK */
      };
      struct
      {
         unsigned char _filler72[2024];
         unsigned char psaff7e8[4]; /* INITIALIZE FIELD PSARV7E8     @ZMC3284           */
         unsigned char psatrace;    /* -      SYSTEM TRACE FLAGS.              @G860PXK */
         unsigned char psarv7ed[3]; /* -      RESERVED FOR SYSTEM TRACE.           @PJC */
         void *__ptr32 psatbvtr;    /* -         REAL ADDRESS OF SYSTEM TRACE BUFFER    */
         void *__ptr32 psatbvtv;    /* -         VIRTUAL ADDRESS CORRESPONDING TO       */
         void *__ptr32 psatrvt;     /* -  ADDRESS OF SYSTEM TRACE VECTOR                */
         void *__ptr32 psatot;      /* -  ADDRESS OF SYSTEM TRACE OPERAND               */
         struct
         {
            unsigned char _filler73[8];
         } ; /* START SECOND SET OF ASSIGNED     @G383PXU        */
      };
      struct
      {
         unsigned char _filler74[2048];
         struct
         {
            int psacdsae;                      /* CALLDISP REGISTER 14 SAVE AREA   @G383PXU         */
            int psacdsaf;                      /* CALLDISP REGISTER 15 SAVE AREA   @G383PXU         */
            int psacdsa0;                      /* CALLDISP REGISTER 0  SAVE AREA   @G383PXU         */
            int psacdsa1;                      /* CALLDISP REGISTER 1  SAVE AREA   @G383PXU         */
         } ;                           /* CALLDISP REGISTER SAVE AREA FOR  @G860PXK         */
         int psagspsw;                         /* GLOBAL SCHEDULE SYSTEM MASK SAVE @ZA63674         */
         int psagsrgs;                         /* GLOBAL SCHEDULE REGISTER SAVE    @ZA63674         */
         void *__ptr32 psa_masterasterealaddr; /* @MUC                                              */
         int psasv01r;                         /* IEAVTRG1 register 1 save area.       @PAA         */
         int psasv14r;                         /* IEAVTRG1 register 14 save area.      @PAA         */
         int psaems2r;                         /* -        REGISTER SAVE AREA                       */
         struct
         {
            int psatrgr0;            /* -        TRACE REGISTER 0 SAVE AREA.      @G860PXH */
            int psatrgr1;            /* -        TRACE REGISTER 1 SAVE AREA.      @G860PXH */
            int psatrgr2;            /* -        TRACE REGISTER 2 SAVE AREA.      @G860PXH */
            int psatrgr3;            /* -        TRACE REGISTER 3 SAVE AREA.      @G860PXH */
            int psatrgr4;            /* -        TRACE REGISTER 4 SAVE AREA.      @G860PXH */
            int psatrgr5;            /* -        TRACE REGISTER 5 SAVE AREA.      @G860PXH */
            int psatrgr6;            /* -        TRACE REGISTER 6 SAVE AREA.      @G860PXH */
            int psatrgr7;            /* -        TRACE REGISTER 7 SAVE AREA.      @G860PXH */
            int psatrgr8;            /* -        TRACE REGISTER 8 SAVE AREA.      @G860PXH */
            int psatrgr9;            /* -        TRACE REGISTER 9 SAVE AREA.      @G860PXH */
            int psatrgra;            /* -        TRACE REGISTER 10 SAVE AREA.     @G860PXH */
            int psatrgrb;            /* -        TRACE REGISTER 11 SAVE AREA.     @G860PXH */
            int psatrgrc;            /* -        TRACE REGISTER 12 SAVE AREA.     @G860PXH */
            int psatrgrd;            /* -        TRACE REGISTER 13 SAVE AREA.     @G860PXH */
            int psatrgre;            /* -        TRACE REGISTER 14 SAVE AREA.     @G860PXH */
            int psatrgrf;            /* -        TRACE REGISTER 15 SAVE AREA.     @G860PXH */
         } ;                 /* -       TRACE REGISTER SAVE AREA.        @G860PXH  */
         unsigned char psatrsv1[4];  /* -     Trace Save 1                         @M8A   */
         unsigned char psatrsvs[4];  /* -     Trace Save for SLIP/PER              @M8A   */
         unsigned char psatrsv2[8];  /* -     Trace Save 2                         @M8A   */
         unsigned char psarv878[40]; /* -     RESERVED.                            @M8A   */
         unsigned char psagsavh[8];  /* -     Register save area used by           @09C   */
         unsigned char psagsav[64];  /* -         REGISTER SAVE AREA USED BY              */
      };
      struct
      {
         unsigned char _filler75[2216];
         unsigned char psaff8a8[64]; /* INITIALIZE FIELD PSAGSAV      @ZMC3284             */
         int psascrg1;               /* -        GLOBAL SCHEDULE REGISTER SAVE AREA        */
         int psascrg2;               /* -        GLOBAL SCHEDULE REGISTER SAVE AREA        */
         int psagpreg[3];            /* -       REGISTER SAVE AREA FOR SVC FLIH            */
         int psarsreg;               /* -        RESTART FLIH REGISTER SAVE       @G860PXK */
         int psapcgr8;               /* -        PROGRAM FLIH REGISTER 8 SAVE AREA         */
         int psapcgr9;               /* -        PROGRAM FLIH REGISTER 9 SAVE AREA         */
         struct
         {
            int psapcgra; /* -        PROGRAM FLIH REGISTER 10 SAVE AREA        */
            int psapcgrb; /* -        PROGRAM FLIH REGISTER 11 SAVE AREA        */
         } ;      /* PROGRAM FLIH REG 10-11 SAVE AREA     @LSA          */
         struct
         {
            int psalkr0;            /* -        IEAVELK REGISTER 0 SAVE AREA     @G860PXK */
            int psalkr1;            /* -        IEAVELK REGISTER 1 SAVE AREA     @G860PXK */
            int psalkr2;            /* -        IEAVELK REGISTER 2 SAVE AREA     @G860PXK */
            int psalkr3;            /* -        IEAVELK REGISTER 3 SAVE AREA     @G860PXK */
            int psalkr4;            /* -        IEAVELK REGISTER 4 SAVE AREA     @G860PXK */
            int psalkr5;            /* -        IEAVELK REGISTER 5 SAVE AREA     @G860PXK */
            int psalkr6;            /* -        IEAVELK REGISTER 6 SAVE AREA     @G860PXK */
            int psalkr7;            /* -        IEAVELK REGISTER 7 SAVE AREA     @G860PXK */
            int psalkr8;            /* -        IEAVELK REGISTER 8 SAVE AREA     @G860PXK */
            int psalkr9;            /* -        IEAVELK REGISTER 9 SAVE AREA     @G860PXK */
            int psalkr10;           /* -        IEAVELK REGISTER 10 SAVE AREA    @G860PXK */
            int psalkr11;           /* -        IEAVELK REGISTER 11 SAVE AREA    @G860PXK */
            int psalkr12;           /* -        IEAVELK REGISTER 12 SAVE AREA    @G860PXK */
            int psalkr13;           /* -        IEAVELK REGISTER 13 SAVE AREA    @G860PXK */
            int psalkr14;           /* -        IEAVELK REGISTER 14 SAVE AREA    @G860PXK */
            int psalkr15;           /* -        IEAVELK REGISTER 15 SAVE AREA    @G860PXK */
         } ;                 /* -        IEAVELK REGISTER SAVE AREA       @G860PXK */
         unsigned char psaslsa[72]; /* -         SINGLE LEVEL SAVE AREA USED BY DISABLED  */
      };
      struct
      {
         unsigned char _filler76[2384];
         unsigned char psaff950[72]; /* INITIALIZE FIELD PSASLSA       @ZMC3284         */
         unsigned char psajstsa[64]; /* -     SAVE AREA FOR JOB STEP TIMING        @H1A */
      };
      struct
      {
         unsigned char _filler77[2456];
         unsigned char psaff998[64]; /* INITIALIZE FIELD PSAJSTSA         @H1A    */
         struct
         {
            unsigned char _filler78[8];
         } ; /* END SECOND SET OF ASSIGNED           @H1M */
      };
      struct
      {
         unsigned char _filler79[2520];
         struct
         {
            int psaslkr0;                        /* -        IEAVESLK REGISTER 0 SAVE AREA        @P4A */
            int psaslkr1;                        /* -        IEAVESLK REGISTER 1 SAVE AREA        @P4A */
            int psaslkr2;                        /* -        IEAVESLK REGISTER 2 SAVE AREA        @P4A */
            int psaslkr3;                        /* -        IEAVESLK REGISTER 3 SAVE AREA        @P4A */
            int psaslkr4;                        /* -        IEAVESLK REGISTER 4 SAVE AREA        @P4A */
            int psaslkr5;                        /* -        IEAVESLK REGISTER 5 SAVE AREA        @P4A */
            int psaslkr6;                        /* -        IEAVESLK REGISTER 6 SAVE AREA        @P4A */
            int psaslkr7;                        /* -        IEAVESLK REGISTER 7 SAVE AREA        @P4A */
            int psaslkr8;                        /* -        IEAVESLK REGISTER 8 SAVE AREA        @P4A */
            int psaslkr9;                        /* -        IEAVESLK REGISTER 9 SAVE AREA        @P4A */
            int psaslkra;                        /* -        IEAVESLK REGISTER 10 SAVE AREA       @P4A */
            int psaslkrb;                        /* -        IEAVESLK REGISTER 11 SAVE AREA       @P4A */
            int psaslkrc;                        /* -        IEAVESLK REGISTER 12 SAVE AREA       @P4A */
            int psaslkrd;                        /* -        IEAVESLK REGISTER 13 SAVE AREA       @P4A */
            int psaslkre;                        /* -        IEAVESLK REGISTER 14 SAVE AREA       @P4A */
            int psaslkrf;                        /* -        IEAVESLK REGISTER 15 SAVE AREA       @P4A */
         } psaslksa;                             /* -        IEAVESLK REGISTER SAVE AREA          @P4A */
         unsigned char psa_setlocki_savearea[8]; /* SETLOCKI Register save area       @MSA             */
         int psa_lastlogcpuheldlock;             /* When waiting to obtain a spin lock, the            */
         unsigned char psarva24[24];             /* -     RESERVED                             @MSC    */
         unsigned char psascsav[64];             /* IEAVESC0 save area                   @P7A          */
         unsigned char psasflgs;                 /* Schedule flags                       @P8A          */
         unsigned char psamiscf;                 /* Miscellaneous flags                  @LVA          */
         unsigned char psarva7e[2];              /* Reserved for future use - SC1C5      @LVC          */
         unsigned char psarva80[188];            /* -    RESERVED                             @P8C     */
         void *__ptr32 psagsch7;                 /* -  ENABLED GLOBAL SCHEDULE ENTRY                   */
         void *__ptr32 psagsch8;                 /* -  DISABLED GLOBAL SCHEDULE ENTRY                  */
         void *__ptr32 psalsch1;                 /* -  ENABLED SCHEDULE ENTRY POINT                    */
         void *__ptr32 psalsch2;                 /* -  DISABLED SCHEDULE ENTRY POINT                   */
         void *__ptr32 psasvt;                   /* -  ADDRESS OF SUPERVISOR VECTOR TABLE              */
         void *__ptr32 psasvtx;                  /* Address of Supervisor Vector Table   @LNC          */
         struct
         {
            void *__ptr32 psaffrr;     /* Fast FRR address.  This field is     @PSC          */
            void *__ptr32 psaffrrs;    /* Fast FRR stack.  This field is       @PSA          */
         } psafafrr;                   /* Fast FRR fields.  These fields are for             */
         unsigned char psarvb5c[36];   /* -     Reserved                             @PSC    */
         unsigned char psarvb80[1112]; /* -  Reserved                             @0LC       */
      };
      struct
      {
         unsigned char _filler80[2944];
         unsigned char psastak[1112];    /* -  Do not use.                          @0LC          */
         unsigned char psarvfd8[40];     /* -    Reserved                             @PJC        */
         __extension__ double psaend[0]; /* -           END OF PSA            (MDC612)   @G383P9A */
      };
   };
};
#define psa_length 0x1000
/* Values for field "flcsvilc" */
#define flcsilcb 0x07 /* -        SIGNIFICANT BITS IN ILC FIELD - LAST      */

/* Values for field "flcpiilc" */
#define flcpilcb 0x07 /* -        SIGNIFICANT BITS IN ILC FIELD - LAST      */

/* Values for field "psapicod" */
#define psapiper 0x80 /* -        PER INTERRUPT OCCURRED             MDC089 */
#define psapimc 0x40  /* -        MONITOR CALL INTERRUPT OCCURRED    MDC090 */
#define psapipc 0x3F  /* -        AN UNSOLICITED PROGRAM CHECK HAS          */

/* Values for field "_filler14" */
#define flcteaxm 0x80 /* -      IF 0 FLCTEA IS RELATIVE TO THE PRIMARY      */

/* Values for field "flcteab3" */
#define flcsopi 0x04        /* -      Suppression on protection flag       @LQA   */
#define flctstdp 0x00       /* -      IF 1, THE PRIMARY STD WAS USED.      @L8A   */
#define flctstda 0x01       /* -      IF 1, THE STD WAS AR QUALIFIED.      @L8A   */
#define flctstds 0x02       /* -      IF 1, THE SECONDARY STD WAS USED.    @L8A   */
#define flctstdh 0x03       /* -      IF 1, THE HOME STD WAS USED.         @L8A   */
#define flcteacl 0x7FFFF000 /* Mask to leave only TEA address       @LSA          */

/* Values for field "flcatmid" */
#define flcpswb4 0x80 /* PSW.4 part of ATMID                  @LSA          */

/* Values for field "flcarch" */
#define psazarch 0x01 /* -      z/Architecture                       @LSA   */
#define psaesame 0x01 /* -      z/Architecture                       @LSA   */

/* Values for field "flcfacl0" */
#define flcfn3 0x80   /* -     N3 installed                         @LVA    */
#define flcfzari 0x40 /* -     z/Architecture installed             @LVA    */
#define flcfzara 0x20 /* -     z/Architecture active                @LVA    */
#define flcfaslx 0x02 /* -     ASN & LX reuse facility installed    @LVA    */

/* Values for field "flcfacl1" */
#define flcfedat 0x80 /* DAT features                         @0BA          */
#define flcfsrs 0x40  /* Sense-running-status                 @LZA          */
#define flcfsske 0x20 /* Cond. SSKE instruction installed     @0AA          */
#define flcfctop 0x10 /* STSI-enhancement                     @LYA          */

/* Values for field "flcfacl2" */
#define flcfetf2 0x80 /* Extended Translation facility 2      @LVA          */
#define flcfcrya 0x40 /* Cryptographic assist                 @LVA          */
#define flcfld 0x20   /* Long Displacement facility           @LVA          */
#define flcfldhp 0x10 /* Long Displacement High Performance   @LVA          */
#define flcfhmas 0x08 /* HFP Multiply Add/Subtract            @LVA          */
#define flcfeimm 0x04 /* Extended immediate when z/Arch       @LVA          */
#define flcfetf3 0x02 /* Extended Translation Facility 3 when @LVA          */
#define flcfhun 0x01  /* HFP unnormalized extension           @LVA          */

/* Values for field "flcfacl3" */
#define flcfet2e 0x80 /* ETF2-enhancement                   031215          */
#define flcfstkf 0x40 /* STCKF-enhancement                    @PIA          */
#define flcfet3e 0x02 /* ETF3-enhancement                   040512          */
#define flcfect 0x01  /* ECT-facility                         @LXA          */

/* Values for field "flcfacl4" */
#define flcfcssf 0x80 /* Compare-and-swap-and-store           @LXA          */
#define flcfcsf2 0x40 /* Compare-and-swap-and-store 2         @LXA          */
#define flcfgief 0x20 /* General-Instructions-Extension       @M0A          */
#define flcfocm 0x01  /* Obsolete CPU-measurement facility. Use             */

/* Values for field "flcfacl5" */
#define flcffpse 0x40 /* Floating-point-support enhancement   @PMA          */
#define flcfdfp 0x20  /* Decimal-floating-point               @PMA          */
#define flcfdfph 0x10 /* Decimal-floating-point high performance            */
#define flcfpfpo 0x08 /* PFPO instruction                   070424          */

/* Values for field "flcfacl8" */
#define flcfcaai 0x40 /* Crypto AP-Queue adapter interruption @M5A          */
#define flcfcmc 0x10  /* CPU-measurement counter facility     @M4A          */
#define flcfcms 0x08  /* CPU-measurement sampling facility    @M4A          */
#define flcfsclp 0x04 /* Possible future enhancement          @M7A          */
#define flcfaisi 0x02 /* AISI facility                        @PPA          */
#define flcfaen 0x01  /* AEN  facility                        @PPA          */

/* Values for field "flcfacl9" */
#define flcfais 0x80 /* AIS  facility                        @PPA          */

/* Values for field "psasup1" */
#define psaio 0x80    /* -        I/O FLIH                                  */
#define psasvc 0x40   /* -        SVC FLIH                                  */
#define psaext 0x20   /* -        EXTERNAL FLIH                             */
#define psapi 0x10    /* -        PROGRAM CHECK FLIH                        */
#define psalock 0x08  /* -        LOCK ROUTINE                              */
#define psadisp 0x04  /* -        DISPATCHER                                */
#define psatctl 0x02  /* -        TCTL RECOVERY FLAG  (MDC310)     @Z40FP9A */
#define psatype6 0x01 /* -        TYPE 6 SVC IN CONTROL  (MDC311)  @Z40FP9A */

/* Values for field "psasup2" */
#define psaipcri 0x80 /* -        REMOTE IMMEDIATE SIGNAL SERVICE ROUTINE   */
#define psasvcr 0x40  /* -        SUPER FRR USES FOR SVC FLIH      @ZMC3227 */
#define psasvcrr 0x20 /* -        SVC RECOVERY RECURSION INDICATOR.         */
#define psaacr 0x04   /* -        AUTOMATIC CPU RECONFIGURATION (ACR) IN    */
#define psartm 0x02   /* -        RECOVERY TERMINATION MONITOR (RTM) IN     */
#define psalcr 0x01   /* -        USED BY RTM TO SERIALIZE CALLS OF    @L5C */

/* Values for field "psasup3" */
#define psaiosup 0x80 /* -        IF ON, A MAINLINE IOS COMPONENT SUCH AS   */
#define psaspr 0x10   /* -        SUPER FRR IS ACTIVE  (MDC305)    @ZA02995 */
#define psaesta 0x08  /* -        SVC 60 RECOVERY ROUTINE ACTIVE            */
#define psarsm 0x04   /* -        REAL STORAGE MANAGER (RSM) ENTERED FOR    */
#define psaulcms 0x02 /* -        LOCK MANAGER UNCONDITIONAL LOCAL OR       */
#define psaslip 0x01  /* -        IEAVTSLP RECURSION CONTROL BIT            */

/* Values for field "psasup4" */
#define psaldwt 0x80 /* -        BLWLDWT IS IN CONTROL TO LOAD A      @LHC */
#define psasmf 0x40  /* -        SMF SUSPEND/RESET     (MDC599)   @G743PBB */
#define psaesar 0x20 /* -        SUPERVISOR ANALYSIS ROUTER IS ACTIVE @L5C */
#define psamch 0x10  /* -        Machine Check Handler is active.     @PKA */

/* Values for field "flceinpsw" */
#define flcesame_len 0x200
#define cvtptr 16 /* -          ABSOLUTE ADDRESS OF POINTER TO CVT      */

/* Values for field "psaprocclass_byte1" */
#define psaprocclass_cp 0x00     /* Standard CP. 0 is offset to SWUQ     @H4A          */
#define psaprocclass_zcbp 0x02   /* zCBP.                                @MTA          */
#define psaprocclass_zaap 0x02   /* zAAP.                                @H4A          */
#define psaprocclass_ziip 0x04   /* zIIP.                                @H5A          */
#define psaprocclass_sup 0x04    /* zIIP.                                @H4A          */
#define psaprocclassindex_cp 0   /* CP ProcClass index                   @0JA          */
#define psaprocclassindex_zcbp 1 /* zCBP ProcClass index                 @MTA          */
#define psaprocclassindex_zaap 1 /* zAAP ProcClass index                 @0JA          */
#define psaprocclassindex_ziip 2 /* zIIP ProcClass index                 @0JA          */
#define psaprocclassindex_max 2  /* Max ProcClass index                  @0JA          */
#define psaprocclassconverter 2  /* Procclass conversion factor          @0EA          */
#define psamaxprocclass 4        /* PSA Max procclass                    @0EA          */
#define psamaxprocclassindex 0x02

/* Values for field "psaptype" */
#define psaifa 0x40          /* Indicates Special Processor          @H3C          */
#define psa_bylpar_zcbp 0x40 /* @MTA                                               */
#define psa_bylpar_zaap 0x40 /* @H5A                                               */
#define psa_bylpar_ifa 0x40  /* @H5A                                               */
#define psazcbpds 0x20       /* zCBP that is different speed than CP @MTA          */
#define psaifads 0x20        /* zAAP (IFA) that is different                       */
#define psadscrp 0x10        /* Discretionary Processor              @LYA          */
#define psaziip 0x08         /* zIIP                                 @H4A          */
#define psa_bylpar_ziip 0x08 /* @H5A                                               */
#define psasup 0x08          /* zIIP                                 @H4A          */
#define psa_bylpar_sup 0x08  /* @H5A                                               */
#define psaziipds 0x04       /* zIIP that is different speed than CP @H4A          */
#define psasupds 0x04        /* zIIP that is different speed than CP @H4A          */

/* Values for field "psails" */
#define psailsio 0x80 /* -      THE I/O FLIH IS USING THE            @L9A   */
#define psailsex 0x40 /* -      THE EXTERNAL FLIH IS USING THE       @L9A   */
#define psailspc 0x20 /* -      THE PROGRAM FLIH IS USING THE        @L9A   */
#define psailsds 0x10 /* -      THE DISPATCHER IS USING THE          @L9A   */
#define psailsrs 0x08 /* -      THE RESTART FLIH IS USING THE        @L9A   */
#define psailsor 0x04 /* -      EXIT IS USING THE INTERRUPT HANDLER  @LAA   */
#define psailst6 0x02 /* -      TYPE 6 SVC IS USING THE INTERRUPT    @D2A   */
#define psailslk 0x01 /* -      THE INTERRUPT HANDLER LINKAGE STACK  @D4A   */

/* Values for field "psaflags" */
#define psaaeit 0x80 /* -      ADDRESSING ENVIRONMENT IS IN         @LOA   */
#define psatx 0x08   /* Equivalent to CVTTX                  @MBA          */
#define psatxc 0x04  /* Equivalent to CVTTXC                 @MBA          */

/* Values for field "psascaff" */
#define psaemema 0x80 /* $$SCAFFOLD: z/Architecture                         */

/* Values for field "psampsw" */
#define psapiom 0x02 /* INPUT/OUTPUT INTERRUPT MASK      @G860PXK          */
#define psapexm 0x01 /* EXTERNAL INTERRUPT MASK          @G860PXK          */

/* Values for field "psarsmcl" */
#define psalks1 0x13 /* COUNT OF LOCKS IN CLHT1 (19)         @MJC          */

/* Values for field "psarsml" */
#define psarsmex 0x80 /* -        BIT 0 OF PSARSML. IF ON, THE RSM          */

/* Values for field "psatrcel" */
#define psatrcex 0x80 /* -        BIT 0 OF PSATRCEL. IF ON THE TRACE        */

/* Values for field "psaiosl" */
#define psaiosex 0x80 /* -        BIT 0 OF PSAIOSL. IF ON THE IOS      @D3A */
#define psalks2 3     /* COUNT OF LOCKS IN CLHT2              @D3C          */

/* Values for field "psacpul" */
#define psalks3 1 /* COUNT OF LOCKS IN CLHT3          @G860PXH          */

/* Values for field "psalocal" */
#define psalks4 2 /* COUNT OF LOCKS IN CLHT4          @G860PXH          */

/* Values for field "psaclhs1" */
#define psacpuli 0x80 /* -        CPU LOCK INDICATOR               @G860PXH */
#define psasum 0x10   /* -        SUMMARY BIT. IF ON, AT LEAST ONE     @LDA */
#define psarsmli 0x08 /* -        RSM LOCK INDICATOR               @G860PXH */
#define psatrcei 0x04 /* -        TRACE LOCK INDICATOR             @G860PXH */
#define psaiosi 0x02  /* -        IOS LOCK INDICATOR                   @D3A */

/* Values for field "psaclhs2" */
#define psarsmci 0x10 /* -        RSM COMMON LOCK INDICATOR        @G860PXK */
#define psarsmgi 0x08 /* -        RSM GLOBAL LOCK INDICATOR        @G860PXH */
#define psavfixi 0x04 /* -        VSM FIX LOCK INDICATOR           @G860PXH */
#define psaasmgi 0x02 /* -        ASM GLOBAL LOCK INDICATOR        @G860PXH */
#define psarsmsi 0x01 /* -        RSM STEAL LOCK INDICATOR         @G860PXH */

/* Values for field "psaclhs3" */
#define psarsmxi 0x80 /* -        RSM CROSS MEMORY LOCK INDICATOR  @G860PXH */
#define psarsmai 0x40 /* -        RSM ADDRESS SPACE LOCK INDICATOR @G860PXH */
#define psavpagi 0x20 /* -        VSM PAGE LOCK INDICATOR          @G860PXH */
#define psadspli 0x10 /* -        DISPATCHER LOCK INDICATOR                 */
#define psaasmli 0x08 /* -        ASM LOCK INDICATOR  (MDC388)     @G50EP9A */
#define psasalli 0x04 /* -        SPACE ALLOCATION LOCK INDICATOR           */
#define psaiosli 0x02 /* -        IOS SYNCHRONIZATION LOCK INDICATOR        */
#define psarsmdi 0x01 /* -        RSM DATA SPACE LOCK INDICATOR        @LBA */

/* Values for field "psaclhs4" */
#define psaiouli 0x80 /* -        IOS UCB LOCK INDICATOR  (MDC393) @G50EP9A */
#define psarsmqi 0x40 /* -        RSMQ lock indicator                  @MIA */
#define psatpali 0x08 /* -        TPACBDEB LOCK INDICATOR (MDC397) @G50EP9A */
#define psasrmli 0x04 /* -        SYSTEM RESOURCE MANAGER (SRM) LOCK        */
#define psacmsli 0x02 /* -        CROSS MEMORY SERVICES LOCK INDICATOR      */
#define psalclli 0x01 /* -        LOCAL LOCK INDICATOR  (MDC400)   @G50EP9A */

/* Values for field "psafpfl" */
#define psabfp 0x10 /* Additional FP status is being saved  @MEC          */
#define psavss 0x08 /* VRs are being saved                  @MEC          */
#define psagsf 0x04 /* GSF controls are being saved         @MQA          */

/* Values for field "psainte" */
#define psanuin 0x80 /* -        CPU TIMER CANNOT BE USED                  */

/* Values for field "psapcfb1" */
#define psapcmc 0x01  /* -        MC INTERRUPT      (MDC605)       @G383P9A */
#define psapcpf 0x02  /* -        PAGE FAULT                       @G383P9A */
#define psapcps 0x03  /* -        PER/SPACE SWITCH INTERRUPT       @G383PXU */
#define psapcad 0x04  /* -        ADDRESSING EXCEPTION  (MDC488)   @G383P9A */
#define psapctr 0x05  /* -        TRANSLATION EXCEPTION  (MDC489)  @G383P9A */
#define psapcpc 0x06  /* -        PROGRAM CHECK  (MDC490)          @G383P9A */
#define psapctrc 0x07 /* -        TRACE INTERRUPT                  @G860PXK */
#define psapcaf 0x08  /* -        NEW VALUE FOR PROGRAM INTERRUPT      @03A */
#define psapcls 0x09  /* -        LINKAGE STACK INTERRUPT FUNCTION     @L8A */
#define psapcart 0x0A /* -        ACCESS REGISTER TRANSLATION          @L8A */
#define psapcdpf 0x0B /* -        DISABLED PAGE/SEGMENT FAULT          @LCA */
#define psapcdar 0x0C /* -        DISABLED ART PIC X'2B' FUNCTION      @LCA */
#define psapcprt 0x0D /* -        Protection exception function value  @LQA */
#define psapcmax 0x0D /* -        MAXIMUM VALID FUNCTION VALUE         @LQC */

/* Values for field "psapcfb2" */
#define psapctrr 0x80 /* -        TRACE INTERRUPT RECURSION        @YA01102 */
#define psapcmt 0x40  /* -        TRACE RECURSION FLAG  (MDC493)   @G383P9A */

/* Values for field "psapcfb3" */
#define psapcp1 0x80  /* -        FIRST LEVEL PROGRAM CHECK        @G383P9A */
#define psapcp2 0x40  /* -        SECOND LEVEL PROGRAM CHECK       @G383P9A */
#define psapcde 0x20  /* -        DAT ERROR CONDITION  (MDC497)    @G383P9A */
#define psapclv 0x10  /* -        0=REGISTERS IN LCCA, 1=REGISTERS @G383P9A */
#define psapcp3 0x08  /* -        THIRD LEVEL PROGRAM CHECK        @G383P9A */
#define psapcp4 0x04  /* -        FOURTH LEVEL PROGRAM CHECK       @G383P9A */
#define psapcpfr 0x02 /* -        RECURSIVE PAGE FAULT INDICATOR       @LAA */
#define psapcavr 0x01 /* -        RECURSIVE ASTE VALIDITY INDICATOR    @LCA */

/* Values for field "psapcfb4" */
#define psapcdnv 0x80 /* -        DUCT validity indicator              @PBA */
#define psapclsr 0x40 /* -        IEAVLSIH has invoked IARPTEPR and    @PEA */

/* Values for field "psamflgs" */
#define psanss 0x80   /* -        ENABLED UNLOCKED TASK WITH FRR   @G383P9A */
#define psaprsrb 0x40 /* -        Preemptable-class SRB                @LPA */

/* Values for field "psamode" */
#define psataskm 0x00 /* -        TASK MODE VALUE  (MDC338)        @G50DP9A */
#define psasrbm 0x04  /* -        SRB MODE VALUE  (MDC339)         @G50DP9A */
#define psawaitm 0x08 /* -        WAIT MODE VALUE  (MDC340)        @G50DP9A */
#define psadispm 0x10 /* -        DISPATCHER MODE VALUE  (MDC342)  @G50DP9A */
#define psapsrbm 0x20 /* -        PSEUDO SRB MODE FLAG BIT.  THIS BIT MAY   */

/* Values for field "psalheb0" */
#define psablsdi 0x80 /* -        BMFLSD LOCK INDICATOR.               @LGA */
#define psaxdsi 0x40  /* -        XCFDS LOCK INDICATOR.                @LEA */
#define psaxresi 0x20 /* -        XCFRES LOCK INDICATOR.               @LEA */
#define psaxqi 0x10   /* -        XCFQ LOCK INDICATOR.                 @LEA */
#define psaeseti 0x08 /* -        ETRSET LOCK INDICATOR.               @LFA */
#define psaixsci 0x04 /* -        IXLSCH LOCK INDICATOR.               @LMC */
#define psaixshi 0x02 /* -        IXLSHR LOCK INDICATOR.               @LMC */
#define psaixdsi 0x01 /* -        IXLDS LOCK INDICATOR.                @LLA */

/* Values for field "psalheb1" */
#define psaixlli 0x80 /* -        IXLSHELL LOCK INDICATOR.             @LMC */
#define psauluti 0x40 /* -        IOSULUT LOCK INDICATOR.              @LJA */
#define psaixlri 0x20 /* -        IXLREQST LOCK INDICATOR.             @05A */
#define psawlmri 0x10 /* -        WLMRES LOCK INDICATOR                @LRA */
#define psawlmqi 0x08 /* -        WLMQ LOCK INDICATOR.                 @LRA */
#define psacntxi 0x04 /* -        CONTEXT LOCK INDICATOR               @LRA */
#define psaregsi 0x02 /* -        REGSRV LOCK INDICATOR.               @LRA */
#define psassdli 0x01 /* -        SSD LOCK INDICATOR.                  @LTA */

/* Values for field "psalheb2" */
#define psagrsli 0x80 /* -        GRSINT lock indicator                @M1A */
#define psamisli 0x40 /* -        MISC lock indicator                  @MGA */
#define psapslk1 0x40 /* -        n/a                                  @MGC */
#define psadnu2 0x20  /* -        n/a                                  @MGA */
#define psapnlk1 0x20 /* -        n/a                                  @MGC */
#define psadnu3 0x10  /* -        n/a                                  @MGA */
#define psaiolk1 0x10 /* -        n/a                                  @MGC */
#define psadnu4 0x08  /* -        n/a                                  @MGA */
#define psapxlk1 0x08 /* -        n/a                                  @MGC */
#define psadnu5 0x04  /* -        n/a                                  @MGA */
#define psadrlk3 0x04 /* -        n/a                                  @MGC */
#define psadrlk2 0x02 /* -        HCWDRLK2 lock indicator              @M6A */
#define psadrlk1 0x01 /* -        HCWDRLK1 lock indicator              @M6A */

/* Values for field "psalheb3" */
#define psasrmei 0x80 /* -        SRMENQ lock indicator                @M9A */
#define psassdgi 0x40 /* -        SSDGROUP lock indicator              @MLA */

/* Values for field "psacr0cb" */
#define psaenabl 0x10 /* -        TO ENABLE PSA PROTECTION                  */
#define psadsabl 0x00 /* -        TO DISABLE PSA PROTECTION                 */

/* Values for field "psacr0sv" */
#define psacr0en 0x10 /* -        IF 0, PSA PROTECT DISABLED.  IF 1, PSA    */
#define psacr0ed 0x80 /* DAT features. Bit is in PSACR0SV+1   @0BA          */
#define psacr0al 0x08 /* -        IF 1, ASN & LX Reuse facility is          */
#define psacr0fp 0x04 /* -        IF 1, extended floating point is          */
#define psacr0vi 0x02 /* -        IF 1, vector instructions are             */

/* Values for field "psarcr0" */
#define psarpen 0x10 /* -        IF 0, PSA PROTECT DISABLED.  IF 1, PSA    */

/* Values for field "psascfb" */
#define psaiopr 0x80             /* -        INDICATES IF INTERRUPTED TASK SHOULD @L1A */
#define psaiorty 0x40            /* -        I/O FLIH RECOVERY FLAG. IF 1,        @L5A */
#define psa_lockspinentered 0x20 /* -   Set whenever supervisor spins for a            */

/* Values for field "psatrace" */
#define psatroff 0x80 /* -        IF ON, SYSTEM TRACE SUSPENDED ON THIS     */

/* Values for field "psasflgs" */
#define psaschda 0x80      /* Schedule is active                   @LPA          */
#define psamcha 0x40       /* Machine Check is active              @06A          */
#define psarsta 0x20       /* Restart is active                    @06A          */
#define psaegra 0x10       /* Global Recovery is active            @06A          */
#define psartma 0x08       /* Selected RTM functions are active    @06A          */
#define psadontgetweb 0x04 /* A WEB or WEBQLOCK is held. IEAVESC0                */

/* Values for field "psamiscf" */
#define psaalr 0x80 /* Equivalent to CVTALR                 @LVA          */

#define flc 0x00
#define iplpsw 0x00    /* --- ALIAS                                          */
#define exopsw 0x18    /* --- ALIAS                                          */
#define svcopsw 0x20   /* --- ALIAS                                          */
#define piopsw 0x28    /* --- ALIAS                                          */
#define mcopsw 0x30    /* --- ALIAS                                          */
#define ioopsw 0x38    /* --- ALIAS                                          */
#define exnpsw 0x58    /* --- ALIAS                                          */
#define svcnpsw 0x60   /* --- ALIAS                                          */
#define pinpsw 0x68    /* --- ALIAS                                          */
#define mcnpsw 0x70    /* --- ALIAS                                          */
#define ionpsw 0x78    /* --- ALIAS                                          */
#define excode 0x86    /* --- ALIAS                                          */
#define svcilc 0x89    /* --- ALIAS                                          */
#define svcnum 0x8A    /* --- ALIAS                                          */
#define piilc 0x8D     /* --- ALIAS                                          */
#define picode 0x8E    /* --- ALIAS                                          */
#define ieatcbp 0x218  /* -      ALIAS                                       */
#define psaipcsm 0x269 /* - LABEL FOR SYSTEM MASK USED IN ABOVE              */
#define psaems2m 0x26D /* - LABEL OF SYSTEM MASK USED IN ABOVE               */
#define psastssm 0x271 /* - LABEL FOR SYSTEM MASK USED IN ABOVE              */
#define psartm1m 0x3FD /* - LABEL FOR SYSTEM MASK USED IN                    */
