*-----------------------------------------------------------------------
* Filename:		6F12P.inc  30/10/2011
* Simulator:		LTspice
* Device type:		Pentode
* Device model:		6F12P
*
* Author:		DDLM
* Date:			30/10/2011
* Copyright:		Copyleft
* 
* The following parameters are not modelled:
*
*   (1) Heater
*   
*
* Please note that this model is provided "as is" and
* no warranty is provided in respect of its suitability
* for any application.
*
* This model is provided for educational and non-profit use.
*
* 
* Pins   A  Anode
*        S  Screen
*        G  Grid
*        K  Cathode
*
*-----------------------------------------------------------------------

.SUBCKT 6F12PTEST A S G K

*
* Calculate reduction in mu when Vg < -3V
*
Emu	mu	0	VALUE={LIMIT(V(G,K),-3,999)+LIMIT(V(G,K)+3,-999,0)*0.714}
*
* Calculate contribution to cathode current
*
Eat	at	0	VALUE={0.636*ATAN(V(A,K)/4.0)}
* le paramètre 4.0 gère la montée +/- rapide du coude 
* au plus il est faibel au plus le coude se rapproche de 90° et des faible niveau de Va
Egs	gs	0	VALUE={LIMIT(V(S,K)/57+V(mu)*1.32+1,0,1E6)}
* le paramètre 57 gère l'écrassement des courbes vers 0 ma
Egs2	gs2	0	VALUE={PWRS(V(gs),2.1)}
* le paramètre 2.1 gère l'écartement des courbes selon VG
Ecath  	cc    	0 	VALUE={V(gs2)*V(at)}
*
* Calculate anode current
*
Ga     	A     	K     	VALUE={22E-4*V(cc)}
*
* Calculate screen current
*
Escrn	sc	0	VALUE={V(gs2)*(1.7-V(at))}
* le paramètre 1.7 gère l'écartement des courbes du courant d'écran
Gs     	S     	K	VALUE={0.5E-3*V(sc)}
*
* Grid current modeling
*
RG      G       4       1K
D1      4       K       DX
.MODEL DX D(IS=1N RS=1 CJO=10PF TT=1N)
*
* Capacitances
*
Cg1	G	K	3.8p
Cak	A	K	5.3p
Cg1a	G	A	0.05p

.ENDS
