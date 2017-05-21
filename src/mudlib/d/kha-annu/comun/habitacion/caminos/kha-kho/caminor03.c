/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el camino  del Norte");

SetIntLong(
"Rodeando una montaña, el camino desciende hacia el norte y asciende hacia el "
"sur, donde encuentra el mazizo central de la cordillera de Kha-annu.\n"
"Algunos dan sobra a los viajeros cuando sale el sol.\n");
 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele a naturaleza.\n");

 AddDetail(({"arbol","arboles"}),
 "Algunos arboles rodean el camino, segun desciende este aumenta la vegetacion.\n");

 // AddItem(MONS+"guardia2",REFRESH_DESTRUCT,1);

 AddExit("suroeste",(CAMINO_NORTE+"caminor02"));
 AddExit("norte",(CAMINO_NORTE+"caminor04"));

  //AddReadMsg(({"roca","inscripcion"}),
  //"Lees en la roca:\n");

 SetLocate("camino_norte");
 }