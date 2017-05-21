/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el camino  de la frontera");

SetIntLong(
"Estas en la frontera del reino de Kha-annu. Aqui las colinas empiezan a "
"crecer alrededor y en direccion sur. Al norte, sobre dos colinas hay dos "
"torres. Las montañas quedan al suroeste, detras de un pequeño bosque.\n");
 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele al aire limpio de las montañas.\n");

 //AddDetail(({"arbol","arboles"}),
 //"Algunos arboles rodean el camino, segun desciende este aumenta la vegetacion.\n");
 AddExit("suroeste",(CAMINO_NORTE+"caminor14"));
 AddExit("norte",(CAMINO_NORTE+"caminor16"));
  //AddReadMsg(({"roca","inscripcion"}),
  //"Lees en la roca:\n");

 SetLocate("camino_norte");
}