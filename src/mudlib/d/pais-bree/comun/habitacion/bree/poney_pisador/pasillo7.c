/*
Fichero: pasillo7.c
Autor: aul�
Fecha: 31/03/2013
Descripci�n:  pasillos de la posada. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/bpasillo";
create()
{
    ::create();
    	SetIntShort("un pasillo");
    	    SetIndoors(1);
    SetIntBright(20);
     AddExit("oeste", "./h7");
     AddExit("norte", "./pasillo6");
     AddExit("sur", "./pasillo8");
     AddDoor("oeste", "la puerta del oeste",
     "Es una s�lida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n",
     ({"puerta", "oeste", "o", "puerta oeste"}));	 
    }