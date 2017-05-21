/* Kha-mino del norte :-)
   Gorthem Nov 2000 */

// Aqui hay que rastrear para poder ir al este.

#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el camino  del Norte");

SetIntLong(
"Aqui el camino se ensancha, y esta rodeado de un monton de arbustos y maleza, "
"que estan un poco estropeados, como si hubiera habido mucha actividad aqui.\n"
"El camino continua al norte y al suroeste, aqui entre dos colinas.\n");
 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("No huele demasiado bien.\n");

 //AddDetail(({"arbol","arboles"}),
 //"Algunos arboles rodean el camino, segun desciende este aumenta la vegetacion.\n");
 AddExit("norte",(CAMINO_NORTE+"caminor09"));
 AddExit("suroeste",(CAMINO_NORTE+"caminor07"));
  //AddReadMsg(({"roca","inscripcion"}),
  //"Lees en la roca:\n");

 SetLocate("camino_norte");
}