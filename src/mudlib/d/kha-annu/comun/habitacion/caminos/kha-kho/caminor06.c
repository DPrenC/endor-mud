/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el camino  del Norte");

SetIntLong(
"El camino discurre entre dos colinas de escarpadas laderas. Parece un buen "
"sitio para una emboscada. El camino continua al norte y al sur.\n");
 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele a naturaleza.\n");

 AddDetail(({"arbol","arboles"}),
 "Algunos arboles rodean el camino, segun desciende este aumenta la vegetacion.\n");
 AddExit("nordeste",(CAMINO_NORTE+"caminor07"));
 AddExit("sur",(CAMINO_NORTE+"caminor05"));
 AddItem(MONS2+"kobold1",REFRESH_DESTRUCT,1);
 AddItem(MONS2+"kobold1",REFRESH_DESTRUCT,1);
  //AddReadMsg(({"roca","inscripcion"}),
  //"Lees en la roca:\n");

 SetLocate("camino_norte");
 }