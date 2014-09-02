*--------------------------------
* Model basé sur le Partridge P4160/1
*--------------------------------
.SUBCKT TRSUL5K 1 2 3 4 5 6 7 PARAMS:
+Lprim = 160 ; inductance totale du primaire entre plaques en henrys
+Zpp=5000 ; impédance primaire entre plaques
+Zhp=15 ; impédance HP
+Kg2 = 0.40 ; rapport des prises de G2 par rapport au pt central (0<KE<1)
+Rprim=80 ; résistance totale du primaire entre plaques
+Rsec=.51 ; résistance du secondaire
+Lfp=8m ; inductance de fuite ramenée au primaire en Henry
+Ca1=60p ; capacité parasite enroulement d'anode1
+Ca2=60p ; capacité parasite enroulement d'anode2
+Ce1=310p ; capacité parasite enroulement d'écran1
+Ce2=310p ; capacité parasite enroulement d'écran2

LP1 8 6 {Lprim/4+Lprim*Kg2*Kg2/4-Lprim*Kg2/2}
LP2 6 5 {Lprim*Kg2*Kg2/4}
LP3 5 7 {Lprim*Kg2*Kg2/4}
LP4 7 9 {Lprim/4+Lprim*Kg2*Kg2/4-Lprim*Kg2/2}
LP5 4 10 {Lprim*Zhp/Zpp}
RP1 1 8 {Rprim/2}
RP2 2 9 {Rprim/2}
RS 10 3 {Rsec}
KALL LP1 LP2 LP3 LP4 LP5 {SQRT(1-Lfp/Lprim)} ; {coeff de couplage}
c1 1 8 {Ca1}
c2 2 9 {Ca2}
c3 6 5 {Ce1}
C4 5 7 {Ce2}
.ENDS

