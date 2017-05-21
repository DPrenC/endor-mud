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

 AddDetail(({"r�o","arroyo","agua","r�o cashigan","cashigan"}),
"Es el r�o Cashigan que recorre la isla Goldhai de norte a sur. Su caudal\n\
de agua es bastante grande y dada la distancia que hay entre ambas orillas\n\
te resulta practicamente imposible atravesarlo.\n");

 AddExit("este",BWALD("puente2"));
 AddExit("oeste",BWALD("borde_rio5"));

 SetLocate("bosque Wald");
}

