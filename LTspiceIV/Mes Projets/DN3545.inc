*
*   MARCH 07, 2000
*  
*   COMPOSITE MODEL FOR DN3545 
*
.SUBCKT DN3545 1 2 3 4 
*
* NODE 1 = DRAIN
* NODE 2 = GATE
* NODE 3 = SOURCE
* NODE 4 = BODY
*
MOS1 11 2 3 4 ND_DMOS  L=2.5E-06  W=58E-3  
JFET 1 3 11 JMOD 1   
DBODY 4 1 DMOS 
R 1 11 1E+6 
*
.MODEL ND_DMOS NMOS 
+ LEVEL=3        UO=307         VTO=-1.829     NFS=5.0E+11 
+ TOX=5E-08      NSUB=3.59E+15  NSS=0          VMAX=5E+04 
+ RS=1E-06       RD=1E-06       RSH=5000       CGDO=1.96E-9 
+ CGSO=1.5E-09   CGBO=0         CBD=4.0E-11    CBS=1.0E-15 
+ MJ=0.5003      MJSW=0.33      IS=5E-13       PB=0.4507 
+ FC=0.5         XJ=1.2E-05     LD=0           DELTA=0 
+ THETA=0        ETA=1.0E-6     KAPPA=1.0E-6  
*
.MODEL DMOS D 
+ IS=281.0E-15   N=0.950        RS=2.5 
+ BV=450         IBV=1.0E-3     TT=1.0E-6 
*
.MODEL JMOD NJF 
+ VTO=-3.5       BETA=0.100     IS=281E-15 
+ RD=9.0         LAMBDA=0 
.ENDS 