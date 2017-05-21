/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el camino  de la frontera");

SetIntLong(
"El camino culmina una colina, desde la que puedes ver un cruze al suroeste.\n"
"Al noreste el camino desciende entre colinas y bosques y se pierde en la "
"lejania. Aqui no hay mucho mas interesante, excepto que las montañas empiezan "
"a rodearte.\n");
 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele al aire limpio de las montañas.\n");

 //AddDetail(({"arbol","arboles"}),
 //"Algunos arboles rodean el camino, segun desciende este aumenta la vegetacion.\n");
 AddExit("suroeste",(CAMINO_NORTE+"cruce"));
 AddExit("nordeste",(CAMINO_NORTE+"caminor13"));
  //AddReadMsg(({"roca","inscripcion"}),
  //"Lees en la roca:\n");

 SetLocate("camino_norte");
}