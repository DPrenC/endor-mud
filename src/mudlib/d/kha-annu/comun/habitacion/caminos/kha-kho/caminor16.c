/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el puesto fronterizo de Kha-annu");

SetIntLong(
"Estas en la frontera del reino de Kha-annu, el puesto fronterizo. Hasta aqui "
"es donde llegan las caravanas, apartir de aqui tendras que seguir a pie.\n"
"Al este y al oeste hay dos torres que controlan el acceso al reino. Al norte "
"se extiende un valle que si quieres visitar tendras que hacer lo en caravana.\n");
 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele al aire limpio de las montañas.\n");

 //AddDetail(({"arbol","arboles"}),
 //"Algunos arboles rodean el camino, segun desciende este aumenta la vegetacion.\n");
 AddExit("este",(CAMINO_NORTE+"torre2"));
 AddExit("oeste",(CAMINO_NORTE+"torre1"));
 AddExit("sur",(CAMINO_NORTE+"caminor15"));
  //AddReadMsg(({"roca","inscripcion"}),
  //"Lees en la roca:\n");

 SetLocate("camino_norte");
}