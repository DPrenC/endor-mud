/*
Fichero: c1_pajar2.c
Autor: aulë
Fecha: 12/10/2014
Descripción: pajar de la granja
*/
#include "./path.h"
inherit BREE_ROOM;

create()
{
    ::create();
    	SetIntShort("el pajar");
    	SetIntLong(
"Esta zona del pajar está especialmente llena de paja que llega casi hasta las gruesas vigas "
"inclinadas del tejado. Al sur un ventanuco da sobre el tejado del establo y en la pared "
"del oeste hay una baja puerta cuadrada.\n");
    	
    	 SetIntNoise("Oyes  el susurro del viento entre las tejas y los suaves bisbiseos de la paja.\n");-
 SetIntSmell("Huele a paja seca.\n");
 SetIndoors(1);
AddExit("norte", "./c1_pajar1");
AddExit("oeste", "./c1_piso2");
AddDoor("oeste", "una puertecita",
"Es una puertecita baja y estrecha  con un pequeño pasador de bronce para asegurarla.\n",
({"o", "puerta o", "oeste", "puerta oeste", "puerta"}));
}