* This is the potentiometer
*....._____
* 1--|_____|--2
*..........|
* 3
*
.SUBCKT Potentiometre 1 2 3
.param w=limit(wiper,1m,.999)
R0 1 3 {Rtot*(1-w)}
R1 3 2 {Rtot*(w)}
.ENDS 