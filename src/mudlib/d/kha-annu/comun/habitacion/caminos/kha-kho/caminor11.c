/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el camino  del Norte");

SetIntLong(
"Continuas por el camino del norte de Kha-annu, sabes que al sur, al final del "
"camino se encuentra la ciudad de Kha-annu, al norte esta el puesto fronterizo "
"que marca el territorio de los enanos, pero antes justo al norte de aqui hay "
"una pequeña depresion por donde baja el camino. Al sur el camino asciende.\n");
 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele al aire limpio de las montañas.\n");

 //AddDetail(({"arbol","arboles"}),
 //"Algunos arboles rodean el camino, segun desciende este aumenta la vegetacion.\n");
 AddExit("noroeste",(CAMINO_NORTE+"cruce"));
 AddExit("sudeste",(CAMINO_NORTE+"caminor10"));
  //AddReadMsg(({"roca","inscripcion"}),
  //"Lees en la roca:\n");

 SetLocate("camino_norte");
}