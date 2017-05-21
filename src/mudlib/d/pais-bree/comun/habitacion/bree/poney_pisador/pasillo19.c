/*
Fichero: pasillo19.c
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
     AddExit("norte", "./h24");
     AddExit("sur", "./pasillo18");
     AddExit("oeste", "./h23");
     AddExit("este", "./pasillo20");
     AddDoor("norte", "la puerta del norte",
     "Es una s�lida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n",
     ({"puerta", "norte", "n", "puerta norte"}));
     AddDoor("oeste", "la puerta del oeste",
     "Es una s�lida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n",
     ({"puerta", "oeste", "o", "puerta oeste"})); 
    }