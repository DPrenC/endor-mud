/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("la torre de la Frontera de Kha-annu");

SetIntLong(
"Esta torre es donde estan los guardias. La sala contiene un par de sillas "
"una mesa y un camastro. Hay algunas armas decorativas colocadas por la pared.\n"
"Hay una escalera que sube por la pared hasta el piso superior.\n");

 SetIndoors(1);

 SetIntBright(35);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele a compañerismo.\n");

 AddDetail(({"armas"}),
 "Son decorativas, no parece que puedas usarlas.\n");
 AddExit("oeste",(CAMINO_NORTE+"caminor16"));
 AddExit("arriba",(CAMINO_NORTE+"torre2b"));

}