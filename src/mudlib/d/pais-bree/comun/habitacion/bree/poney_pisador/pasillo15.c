/*
Fichero: pasillo15.c
Autor: aulë
Fecha: 31/03/2013
Descripción:  pasillos de la posada. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/bpasillo";
create()
{
    ::create();
    	SetIntShort("un pasillo");
    	    SetIndoors(1);
    SetIntBright(20);
     AddExit("norte", "./pasillo16");
     AddExit("sur", "./h19");
     AddExit("oeste", "./h20");
     AddExit("este", "./pasillo14");
     AddDoor("sur", "la puerta del sur",
     "Es una sólida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n",
     ({"puerta", "sur", "s", "puerta sur"}));
     AddDoor("oeste", "la puerta del oeste",
     "Es una sólida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n",
     ({"puerta", "oeste", "o", "puerta oeste"})); 
    }