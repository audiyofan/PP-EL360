*--------------------------------
.SUBCKT TRSSEUL 1 2 3 4 5 PARAMS:
+Lprim = 24 ; inductance totale du primaire en henrys
+Zpp=3500 ; impédance primaire
+Zhp=8 ; impédance HP
+Ke = 0.50 ; rapport de la prise écran par rapport au pt central (0<Ke<1)
+Rprim=120 ; résistance totale du primaire 
+Rsec=.32 ; résistance du secondaire
+Lfp=7.7m ; inductance de fuite ramenée au primaire en Henry
+Ca1=191p ; capacité parasite enroulement d'anode
+Ce1=530p ; capacité parasite enroulement d'écran

LP1 6 2 {Lprim/2+Lprim*Ke*Ke/2-Lprim*Ke}
LP2 7 3 {Lprim*Ke*Ke/2}
LP3 8 4 {LPRIM*Zhp/Zpp}
RP1 1 6 {Rprim*(1-Ke)}
RP2 2 7 {Rprim*Ke}
RS 8 5 {Rsec}
KALL LP1 LP2 LP3 {SQRT(1-Lfp/Lprim)} ; {coeff de couplage}
c1 1 6 {Ca1}
c3 2 3 {Ce1}
.ENDS

