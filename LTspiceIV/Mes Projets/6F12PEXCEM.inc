* Vacuum Tube Modeling Version 1
*

*
* AUTHOR: Totof
*
*
* 
* *
* Copyleft 2011
*
* liste des paramètres et ce que j'en ai déduit
* G = modifie la pente avant le coude pour les courbes d'anodes
* MU = modifie la pente après le coude pour les courbes d'anodes
* MU12 = modifie la hauteur du courant d'anode
* E1 = modifie l'écartement des courbes de courant d'anode 
* K1 = modifie l'angle du coude du courant d'anode
* K2 = ?
* k3 = modifie l'écartement des courbes avant le coude pour les courbes d'anodes
* k4 =  modifie la hauteur du courant d'écran
* K5 =  modifie la valeur maxi du courant d'écran pour les faibles valeurs de Va
* K6 = modifie l'angle du coude du courant d'écran
* K = modifie l'écartement des courbes de courant d'écran




.SUBCKT 6F12PEXCEM 1 2 3 4
* Anode G2 G1 Cathode
X1 1 2 3 4 PENTH1 G=.126m MU=15000 MU12=35.1 E1=3.87 k1=140.2 k2=2.1 k3=0.6 k4=65.6 k5=18.8 k6=12.8 K=1.300m
X2 3 4 Igrid ALPHA=.02m BETA=.1U
C2 1 4 5.5P
C3 3 1 .05P
C5 3 4 4P
RF1 1 4 200MEG
RF2 3 4 50MEG
RF3 2 4 100MEG
.ENDS





**************************************
**Modèle mathématique issu de EXCEM **
**************************************



******************
.SUBCKT PENTH1 A G2 G1 C

* Terme d'ecran
B1 10 0 V=IF(V(A,C)>0,(V(G2,C)/{MU12})*(V(A,C)-({k3}*V(G1,C)))/((V(G2,C)/{k1})+V(A,C)),0)

* Total
B2 A C I={G}*((V(G1,C)+V(10,0))+(V(A,C)/({MU}*(1-(V(G1,C)/{k2})))))**{E1}

* Calcul du courant d'ecran
B6 12 0 V=IF(V(G2,C)>0,(V(G1,C)+(V(G2,C)/{k4})),0)
B7 G2 C I={K}*(V(12,0)**1.5)*((V(A,C)+{k5})/(V(A,C)+{k6}))**3
.ENDS

******************
.SUBCKT Igrid G1 C
* Courant grille
B4 6 0 V=IF(V(G1,C)>0,{ALPHA}*V(G1,C)**1.5,{BETA}/-(V(G1,C)-.1))
B5 G1 C I=V(6,0)
.ENDS
******************

