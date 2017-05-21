/*=============================================================*
 |          << GOLDHAI.Bosque Wald [w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 27-08-98            |
 |             Ultima Modificacion........ 27-08-98            |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit ROOM;

create()
{
 ::create();
 SetIntShort("un puente sobre el Cashigan");
 SetIntLong("Puente sobre el Cashigan.\n");

 AddDetail(({"río","arroyo","agua","río cashigan","cashigan"}),
"Es el río Cashigan que recorre la isla Goldhai de norte a sur. Su caudal\n\
de agua es bastante grande y dada la distancia que hay entre ambas orillas\n\
te resulta practicamente imposible atravesarlo.\n");

 AddExit("este",BATALLA("borde_rio2"));
 AddExit("oeste",BWALD("puente1"));

 SetLocate("bosque Wald");
}

