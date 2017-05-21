/*
Fichero: pasillo12.c
Autor: aulë
Fecha: 31/03/2013
Descripción:  pasillos de la posada. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/bpasillo";
#include <moving.h>


public int ir_arriba(){
    write("Subes las escaleras de madera hasta la planta superior.\n"
     "Algunos escalones crujen y chirrían.\n");
    say(CAP(TNAME)+"  sube las escaleras hacia la planta superior mientras los "
    "escalones crujen y chirrían.\n");
    tell_room(HABITACION+"bree/poney_pisador/pasillo13", CAP(TNAME)+ " llega subiendo "
    "las escaleras desde el piso inferior.\n");
            TP->move( HABITACION+"bree/poney_pisador/pasillo13", M_SILENT);
    return 1;
}

create()
{
    ::create();
    	SetIntShort("un pasillo, junto a una escalera");
    	   SetIntLong(QueryIntLong()+"En esta zona del pasillo una amplia escalera de madera "
   "comunica este piso con la tercera planta de la posada.\n");
      AddDetail("escalera",
   "Una gran escalera hecha en su totalidad de madera que asciende a la planta "
   "superior. Peldaños y barandilla están bien pulidos y barnizados.\n");

    	    SetIndoors(1);
    SetIntBright(20);
     AddExit("norte", "./h14");
     AddExit("sur", "./h13");
     AddExit("oeste", "./pasillo11");
     AddExit("arriba", SF(ir_arriba));
     AddDoor("norte", "la puerta del norte",
     "Es una sólida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n",
     ({"puerta", "norte", "n", "puerta norte"}));
     AddDoor("sur", "la puerta del sur",
     "Es una sólida puerta de madera antigua pero bien cuidada con una cerradura y una "
     "reluciente manilla de bronce.\n",
     ({"puerta", "sur", "s", "puerta sur"})); 
    }