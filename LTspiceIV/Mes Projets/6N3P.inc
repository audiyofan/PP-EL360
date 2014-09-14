.subckt 6N3P 1 6 3
+ params: mu=40.9 ex=1.71 kg1=825 kp=126 kvb=708 rgi=2000 vct=.01
+ ccg=2.3p cgp=1.3p ccp=1.3p
e1 7 0 value=
+{v(1,3)/kp*log(1+exp(kp*(1/mu+v(2,3)/sqrt(kvb+v(1,3)*v(1,3)))))}
re1 7 0 1g
g1 1 3 value= {(pwr(v(7),ex)+pwrs(v(7),ex))/kg1}
rcp 1 3 1g
c1 2 3 {ccg}
c2 1 2 {cgp}
c3 1 3 {ccp}
r1 2 5 {rgi}
v1 5 6 {vct}
d3 6 3 dx
.model dx d(is=1n rs=1 cjo=1pf tt=1n)
.ends


