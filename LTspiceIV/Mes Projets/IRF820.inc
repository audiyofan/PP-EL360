.subckt IRF820 D G S
.model mosfet NMOS( Rg=7 VTO=3.81 RS=0.06816 KP=2.149 RD=2.3567 lambda=0.0127 RG=15 IS=1p  CBD=6.97n )
.model diode D( IS=3.50e-13 RS=0.0343 TT=1.657e-06)
M1 D G S S mosfet
D1 S D Diode
Cgs G S 3.18E-10
.ends
