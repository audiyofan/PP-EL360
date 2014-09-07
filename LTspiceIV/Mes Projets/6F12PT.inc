.SUBCKT 6F12PT  1 2 3 ; P G C (Triode) 07 Nov 2004
+ PARAMS: MU=523.74  EX= 1.039  KG1=  13.5  KP=384.91 
+ KVB= 300.0  VCT=  0.00 RGI=4500
+ CCG=4.6P  CGP=1.6P CCP=0.26P
E1 7 0 VALUE=
+{V(1,3)/KP*LOG(1+EXP(KP*(1/MU+(V(2,3)+VCT)/SQRT(KVB+V(1,3)*V(1,3)))))}
RE1 7 0 1G
G1 1 3 VALUE={(PWR(V(7),EX)+PWRS(V(7),EX))/KG1}
RCP 1 3 1G    ; TO AVOID FLOATING NODES IN MU-FOLLOWER
C1 2 3 {CCG}  ; CATHODE-GRID; 
C2 2 1 {CGP}  ; GRID-PLATE; 
C3 1 3 {CCP}  ; CATHODE-PLATE; 
D3 5 3 DX     ; FOR GRID CURRENT
R1 2 5 {RGI}  ; FOR GRID CURRENT
.MODEL DX D(IS=1N RS=1 CJO=10PF TT=1N)
.ENDS