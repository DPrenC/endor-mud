/* Kha-mino del norte :-)
   Gorthem Nov 2000 */

#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("la torre de la Frontera de Kha-annu");

SetIntLong(
"Dentro de la torre no hay gran cosa, esta torre es mas administrativa "
"que defensiva. Aqui hay un escritorio, una cuantas sillas de todos los "
"tamaños colocadas a ambos lados de la estancia, . Hay una escalera que sube "
"por la pared hasta el piso superior.\n");

 SetIndoors(1);

 SetIntBright(35);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele al aire limpio de las montañas.\n");

 AddDetail(({"escritorio"}),
 "Es un bonito escritorio que tiene un libro encima junto con una pluma y un "
 "tintero. El libro parece una especie de registro.\n");

 AddExit("este",(CAMINO_NORTE+"caminor16"));
 AddExit("arriba",(CAMINO_NORTE+"torre1b"));

}