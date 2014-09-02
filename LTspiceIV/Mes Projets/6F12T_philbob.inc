*-------------------------------------------------------------------------------------
*     6F12T    [modele Norman Koren parametres philbob]
*-------------------------------------------------------------------------------------
.subckt 6F12T_philbob 1 2 3;(anode grille cathode)
+ params:
+ mu  = 137.721
+ ex  = 1.60508
+ kg1 = 55.4076
+ kp  = 593.725
+ kvb = 11210.8
+ ccg = 4.6e-12
+ cgp = 1.6e-12
+ ccp = 2.6e-13
+ rgi = 4500
e1 7 0 value=
+{v(1,3)/kp*log(1+exp(kp*(1/mu+v(2,3)/sqrt(kvb+v(1,3)*v(1,3)))))}
re1 7 0 1g
g1 1 3 value= {(pwr(v(7),ex)+pwrs(v(7),ex))/kg1}
rcp 1 3 1g
c1 2 3 {ccg}
c2 1 2 {cgp}
c3 1 3 {ccp}
r1 2 5 {rgi}
d3 5 3 dx
.model dx d(is=1n rs=1 cjo=10pf tt=1n)
.ends
*-------------------------------------------------------------------------------------
