/*
Fichero: c1_establo2.c
Autor: aulë
Fecha: 12/10/2014
Descripción: establo de la granja
*/
#include "./path.h"
inherit BREE_ROOM;

create()
{
    ::create();
    	SetIntShort("el establo");
    	SetIntLong(
    	"Este largo establo recorre toda la parte norte de la casa y está dividido en "
    	"distintas zonas para los diferentes animales. Un largo comedero de piedra sucia "
    	"de restos grasientos y un barrizal de paja y excrementos dan idea de que esta zona  "
    	"está ocupada por cerdos.  El techo de vigas y tablones de madera "
    	"sucia y oscurecida por el tiempo se apoya sobre gruesos muros de piedras "
    	"irregulares que también forman el piso del establo. Un estrecho canalillo de "
    	"piedra y argamasa canaliza los orines de los animales hacia el exterior.\n");
    	 SetIntNoise("Oyes  movimientos, mugidos, cacareos y demás sonidos propios de los animales.\n");-
 SetIntSmell("Huele a estiércol de distintos tipos, paja seca, orines y animales");
 SetIndoors(1);
AddExit("norte", "./c1_establo1");
AddExit("sur", "./c1_establo3");
}