/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("la torre de la Frontera de Kha-annu");

SetIntLong(
"Este piso de la torre contiene una habitacion para los guardias, varios "
"camastros estan repartidos por la estancia, un par de armarios y unas "
"escupideras. Una escalera por la pared lleva al piso inferior y al superior.\n");

 SetIndoors(1);

 SetIntBright(25);

 SetIntNoise("Oyes ruidos en el piso inferior.\n");
 SetIntSmell("Huele a compañerismo.\n");

 AddDetail(({"camastro","camastros"}),
 "Son unos camatros de madera con un colchon de plumas. Sin duda los guardias "
 "duermen a gusto.\n");

 AddDetail(({"armarios","armario"}),
 "So unos pequeños armarios que no miden mas de un metro y medio, hechos de "
 "perfecta madera. Estan cerrados a cal y canto.\n");
 AddExit("abajo",(CAMINO_NORTE+"torre2"));
 AddExit("arriba",(CAMINO_NORTE+"torre2c"));
}