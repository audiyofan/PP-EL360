*--------------------------------
.SUBCKT TRSSECFB2K4 1 2 3 4 5 6 PARAMS:
+Lprim = 13.2 ; inductance totale du primaire en henrys
+Zpp=2400 ; impédance primaire 
+Zhp=10 ; impédance HP
+Kc = 0.30 ; rapport en % du nombre de spire pour l'enroulement de cathode (0<Kc<1) généralement 10%
+Rprim=74 ; résistance totale du primaire y compris l'enroulement cathode
+Rsec=.65 ; résistance du secondaire
+Lfp=3.6m ; inductance de fuite ramenée au primaire en Henry
+Ca1=180p ; capacité parasite enroulement d'anode
+Cc1=305p ; capacité parasite enroulement de cathode

LP1 7 2 {Lprim/2+Lprim*Kc*Kc/2-Lprim*Kc}
LP2 6 8 {Lprim*Kc*Kc/2}
LP3 9 5 {LPRIM*Zhp/Zpp}
RP1 1 7 {Rprim*(1-Kc)}
RP2 8 3 {Rprim*Kc}
RS 9 4 {Rsec}
KALL LP1 LP2 LP3 {SQRT(1-Lfp/Lprim)} ; {coeff de couplage}
c1 1 6 {Ca1}
c3 6 3 {Cc1}
.ENDS

