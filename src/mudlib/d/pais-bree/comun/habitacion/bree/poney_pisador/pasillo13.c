/*
Fichero: pasillo13.c
Autor: aulë
Fecha: 31/03/2013
Descripción:  pasillos de la posada. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/bpasillo";
#include <moving.h>

public int ir_abajo(){
    write("Bajas las escaleras de madera hasta el segundo piso.\n"
     "Algunos escalones crujen y chirrían.\n");
    say(CAP(TNAME)+"  baja las escaleras hacia la planta inferior mientras los "
    "escalones crujen y chirrían.\n");
        tell_room(HABITACION+"bree/poney_pisador/pasillo12", CAP(TNAME)+ " llega bajando "
    "las escaleras desde el piso superior.\n");

    TP->move( HABITACION+"bree/poney_pisador/pasillo12", M_SILENT);
return 1;
}


create()
{
    ::create();
    	SetIntShort("un pasillo, junto a una escalera");
    	   SetIntLong(QueryIntLong()+"En esta zona del pasillo una amplia escalera de madera "
   "comunica este piso con  la segunda planta de la posada.\n");
      AddDetail("escalera",
   "Una gran escalera hecha en su totalidad de madera que desciende a la planta "
   "inferior. Peldaños y barandilla están bien pulidos y barnizados.\n");

    	    SetIndoors(1);
    SetIntBright(20);
     AddExit("norte", "./h16");
     AddExit("sur", "./h15");
     AddExit("oeste", "./pasillo14");
     AddExit("abajo", SF(ir_abajo));
     AddDoor("norte", "la puerta del norte",
     "Es una sólida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n",
     ({"puerta", "norte", "n", "puerta norte"}));
     AddDoor("sur", "la puerta del sur",
     "Es una sólida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n",
     ({"puerta", "sur", "s", "puerta sur"}));
}