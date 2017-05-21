/*
Fichero: c1_pajar1.c
Autor: aul�
Fecha: 12/10/2014
Descripci�n: pajar de la granja
*/
#include "./path.h"
inherit BREE_ROOM;
#include <moving.h>
public int ir_arriba(){
    write("Te aferras a los lados de la estrecha escalera y bajas por los travesa�os hasta el pajar.\n\n");
    say(CAP(TNAME)+"  se aferra con fuerza a la estrecha escalera y desaparece por el agujero del suelo.\n");
        tell_room(HABITACION+"bree/c1_establo1", CAP(TNAME)+ " desciende por una escalera de mano hasta el suelo.\n");
    TP->move( HABITACION+"bree/c1_establo1", M_GO);
return 1;
}

create()
{
    ::create();
    	SetIntShort("el pajar");
    	SetIntLong(
    	"El pajar del establo se extiende hacia el sur, con el techo bajo descendiendo "
    	"hacia la pared del este, de forma que junto al muro hay que agacharse para caminar.\n"
    	"Todo est� repleto de grandes montones de paja seca para alimentar al ganado y "
    	"multitud de telara�as polvorientas unen las ennegrecidas vigas de madera que "
    	"sustentan el tejado. Por un hueco del suelo de tablas desciende una estrecha "
    	"escalera de mano. En la pared del sur una abertura cuadrada da hacia el jard�n de "
    	"la casa y permite meter la paja que se transporta en carro hasta aqu�.\n");
    	
    	 SetIntNoise("Oyes  el susurro del viento entre las tejas y los suaves bisbiseos de la paja.\n");-
 SetIntSmell("Huele a paja seca.\n");
 SetIndoors(1);
AddExit("sur", "./c1_pajar2");
AddExit("abajo", SF(ir_arriba));
}