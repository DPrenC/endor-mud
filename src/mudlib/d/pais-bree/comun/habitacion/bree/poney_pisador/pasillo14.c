/*
Fichero: pasillo14.c
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
    AddExit("este", "./pasillo13");
     AddExit("norte", "./h18");
     AddExit("sur", "./h17");
     AddExit("oeste", "./pasillo15");
     AddDoor("norte", "la puerta del norte",
     "Es una sólida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n",
     ({"puerta", "norte", "n", "puerta norte"}));
     AddDoor("sur", "la puerta del sur",
     "Es una sólida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n",
     ({"puerta", "sur", "s", "puerta sur"})); 
    }