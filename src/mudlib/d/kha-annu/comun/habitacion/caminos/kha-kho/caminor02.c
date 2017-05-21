/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el camino  del Norte");

SetIntLong(
"El camino continua por la ladera de la montaña, algunos arboles rodean el "
"camino, inclinados hacia la parte baja de la montaña. Al norte el camino "
"desciende montaña abajo. Al sur asciende abruptamente durante un largo trecho.\n");
 SetIndoors(0);

 SetIntBright(30);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele a naturaleza.\n");

 AddDetail(({"arbol","arboles"}),
 "Algunos arboles rodean el camino, segun desciende este aumenta la vegetacion.\n");

 // AddItem(MONS+"guardia2",REFRESH_DESTRUCT,1);

 AddExit("nordeste",(CAMINO_NORTE+"caminor03"));
 AddExit("sur",(CAMINO_NORTE+"caminor01"));

  //AddReadMsg(({"roca","inscripcion"}),
  //"Lees en la roca:\n");

 SetLocate("camino_norte");
 }