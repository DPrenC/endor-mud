/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el camino  del Norte");

SetIntLong(
"El camino se empina considerablemente y tienes que hacer un esfuerzo para "
"continuar por el con normalidad, tanto para subir como para no caerte rodando "
"al bajar. Al sur, el camino asciende, al nosrte desciende.\n");
 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("No huele demasiado bien.\n");

 //AddDetail(({"arbol","arboles"}),
 //"Algunos arboles rodean el camino, segun desciende este aumenta la vegetacion.\n");
 AddExit("norte",(CAMINO_NORTE+"caminor10"));
 AddExit("sur",(CAMINO_NORTE+"caminor08"));
  //AddReadMsg(({"roca","inscripcion"}),
  //"Lees en la roca:\n");

 SetLocate("camino_norte");
}