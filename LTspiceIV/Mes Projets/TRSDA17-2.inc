*--------------------------------
.SUBCKT TRSDA17-2 1 2 3 4 5 PARAMS:
+Lprim = 317 ; inductance totale du primaire entre plaques en henrys
+Zpp=7000 ; impédance primaire entre plaques
+Zhp=6 ; impédance HP
+Kp = 0.33 ; rapport des prises sur l'enroulement primaire par rapport au pt central (0<KE<1)
* attention pour les utiliser il faut modifier le symbole et rajouter les pin 6 et 7 ainsi
* qu'un label P1 et P2 et rajouter ci-dessus les pin 6 et 7 dans la ligne SUBCKT ....
+Rprim=160 ; résistance totale du primaire entre plaques
+Rsec=.35 ; résistance du secondaire
+Lfp=12m ; inductance de fuite ramenée au primaire en Henry
+Ca1=79p ; capacité parasite enroulement d'anode1
+Ca2=79p ; capacité parasite enroulement d'anode2
+Ce1=300p ; capacité parasite enroulement d'écran1
+Ce2=300p ; capacité parasite enroulement d'écran2

LP1 8 6 {Lprim/4+Lprim*Kp*Kp/4-Lprim*Kp/2}
LP2 6 5 {Lprim*Kp*Kp/4}
LP3 5 7 {Lprim*Kp*Kp/4}
LP4 7 9 {Lprim/4+Lprim*Kp*Kp/4-Lprim*Kp/2}
LP5 10 4 {LPRIM*Zhp/Zpp}
RP1 1 8 {Rprim/2}
RP2 2 9 {Rprim/2}
RS 10 3 {Rsec}
KALL LP1 LP2 LP3 LP4 LP5 {SQRT(1-Lfp/Lprim)} ; {coeff de couplage}
c1 1 8 {Ca1}
c2 2 9 {Ca2}
c3 6 5 {Ce1}
C4 5 7 {Ce2}
.ENDS

