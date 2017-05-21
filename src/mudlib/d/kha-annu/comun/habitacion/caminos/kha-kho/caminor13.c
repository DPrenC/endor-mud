/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el camino  de la frontera");

SetIntLong(
"Los arboles te rodean en la ladera de una colina, formando un pequeño bosque.\n"
"Al suroeste el camino se eleva, al noreste el camino desciende entre colinas "
"y pequeños bosques.\n");
 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele al aire limpio de las montañas.\n");

 //AddDetail(({"arbol","arboles"}),
 //"Algunos arboles rodean el camino, segun desciende este aumenta la vegetacion.\n");
 AddExit("suroeste",(CAMINO_NORTE+"caminor12"));
 AddExit("nordeste",(CAMINO_NORTE+"caminor14"));
  //AddReadMsg(({"roca","inscripcion"}),
  //"Lees en la roca:\n");

 SetLocate("camino_norte");
}