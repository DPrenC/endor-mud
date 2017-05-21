/*
Fichero: pasillo18.c
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
     AddExit("norte", "./pasillo19");
     AddExit("sur", "./pasillo17");
     AddExit("oeste", "./h22");
     AddDoor("oeste", "la puerta del oeste",
     "Es una sólida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n",
     ({"puerta", "oeste", "o", "puerta oeste"})); 
    }