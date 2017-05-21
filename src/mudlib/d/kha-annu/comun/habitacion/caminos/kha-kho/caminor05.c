/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el camino  del Norte");

SetIntLong(
"El camino asciende hacia el sur y comienza a rodear una montaña, parece que "
"se haya puesto en medio. Aqui hay un monton de arboles rodeando el camino.\n"
"Al norte el camino continua entre dos colinas, un poco mas llano.\n");
 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele a naturaleza.\n");

 AddDetail(({"arbol","arboles"}),
 "Algunos arboles rodean el camino, segun desciende este aumenta la vegetacion.\n");

 // AddItem(MONS+"guardia2",REFRESH_DESTRUCT,1);

 AddExit("sudeste",(CAMINO_NORTE+"caminor04"));
 AddExit("norte",(CAMINO_NORTE+"caminor06"));

  //AddReadMsg(({"roca","inscripcion"}),
  //"Lees en la roca:\n");

 SetLocate("camino_norte");
 }