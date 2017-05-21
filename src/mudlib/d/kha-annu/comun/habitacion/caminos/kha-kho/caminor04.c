/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el camino  del Norte");

SetIntLong(
"Rodeando una montaña, el camino desciende hacia el norte y asciende hacia el "
"sur, pero no puedes ver que hay porque la montaña te tapa la vista. Eso si, al "
"norte el camino se pierde entre montañas y colinas, pobladas de arboles "
"en su parte mas bajas.\n");
 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele a naturaleza.\n");

 AddDetail(({"arbol","arboles"}),
 "Algunos arboles rodean el camino, segun desciende este aumenta la vegetacion.\n");

 // AddItem(MONS+"guardia2",REFRESH_DESTRUCT,1);

 AddExit("sur",(CAMINO_NORTE+"caminor03"));
 AddExit("noroeste",(CAMINO_NORTE+"caminor05"));

  //AddReadMsg(({"roca","inscripcion"}),
  //"Lees en la roca:\n");

 SetLocate("camino_norte");
 }