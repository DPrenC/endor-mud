/*
Fichero: pasillo4.c
Autor: aulë
Fecha: 31/03/2013
Descripción:  pasillos de la posada.
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/bpasillo";
#include <moving.h>

public int ir_arriba(){
    write("Subes las escaleras de madera hasta el tercer piso.\n"
     "Algunos escalones crujen y chirrían.\n");
    say(CAP(TNAME)+"  sube las escaleras hacia la planta superior mientras los "
    "escalones crujen y chirrían.\n");
        tell_room(HABITACION+"bree/poney_pisador/pasillo21", CAP(TNAME)+ " llega subiendo "
    "las escaleras desde el piso inferior.\n");
    TP->move( HABITACION+"bree/poney_pisador/pasillo21", M_GO);
return 1;
}

public int ir_abajo(){
    write("Bajas las escaleras de madera hasta la planta inferior.\n"
     "Algunos escalones crujen y chirrían.\n");
    say(CAP(TNAME)+"  baja las escaleras hacia la planta inferior mientras los "
    "escalones crujen y chirrían.\n");
        tell_room(HABITACION+"bree/poney_pisador/pasillo3", CAP(TNAME)+ " llega bajando "
    "las escaleras desde el piso superior.\n");
    TP->move( HABITACION+"bree/poney_pisador/pasillo3", M_GO);
    return 1;
}

create()
{
    ::create();
    	SetIntShort("un pasillo, junto a unas escaleras");
   SetIntLong(QueryIntLong()+"En esta zona del pasillo una amplia escalera de madera "
   "comunica este piso con la tercera y la primera planta de la posada.\n");
      AddDetail("escalera",
   "Una gran escalera hecha en su totalidad de madera que comunica este piso con los "
   "otros dos de la posada. Peldaños y barandilla están bien pulidos y barnizados.\n");

    	    SetIndoors(1);
    SetIntBright(20);
     AddExit("oeste", "./pasillo5");
     AddExit("norte", "./h1");
     AddExit("abajo", SF(ir_abajo));
     AddExit("sur", "./h2");
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