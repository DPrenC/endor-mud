/*=============================================================*
 |          << GOLDHAI.Bosque Wald [w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 27-08-98            |
 |             Ultima Modificacion........ 08-10-98            |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit ROOM;

create()
{
 ::create();
 SetIntShort("un puente sobre el Cashigan");
 SetIntLong("\
Te encuentras sobre un pequenyo puente de madera que atraviesa el río Cashigan\n\
de orilla a orilla. El agua fluye por debajo de ti formando una especie de\n\
rapidos entre las rocas. Sera mejor que no permanezcas mucho tiempo sobre el\n\
puente ya que da la sensacion de que no vaya a aguantar tu peso, asi que\n\
lo mejor es que lo cruzaras en direccion Este u Oeste.\n");

 SetIntNoise("Oyes el crujir de las tablas de madera a tus pies.\n");
 AddDetail(({"río","arroyo","agua","río cashigan","cashigan"}),
"Es el río Cashigan que recorre la isla Goldhai de norte a sur. Su caudal\n\
de agua es bastante grande y dada la distancia que hay entre ambas orillas\n\
te resulta practicamente imposible atravesarlo.\n");
 AddDetail(({"puente"}),
"Es un maltrecho puente de madera que une ambas orillas del río Cashigan.\n\
La humedad y el paso del tiempo han hecho mella y parece que el puente se\n\
vaya a romper en cualquier momento, asi que sera mejor que cruces rapido.\n");
 AddDetail(({"madera","tablas","tabla","tablas de madera","tabla de madera"}),
"Son un monton de tablas de madera vieja unidas con cuerdas.\n");

 AddExit("este",BATALLA("borde_rio2"));
 AddExit("oeste",BWALD("borde_rio5"));

 SetExplorable(1);
 SetLocate("bosque Wald");
}

