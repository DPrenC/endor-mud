/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el camino  del Norte");

SetIntLong(
"Te encuentras en un mirardor del camino, desde aqui puedes ver, majestuosas, "
"las cumbres de la cordillera de Kha-annu. Algunos de estos picos estan "
"cubiertos de nieve y adornan todacia mas si se puede, el paisaje.\n"
"El camino desciende por la cara norte de la montaña, sepenteando entre los "
"valles que forman las laderas de las montañas. Al sur, parece que el camino "
"termina. En una roca, junto al camino, hay una inscripcion.\n");

 SetIndoors(0);

 SetIntBright(30);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele a naturaleza.\n");

 //AddDetail(({"arbol","roble"}),
 //"Es un gran roble.\nEsta partido en dos por un rayo.\n");

 // AddItem(MONS+"guardia2",REFRESH_DESTRUCT,1);

 AddExit("sur",("/players/izet/workroom"));
 AddExit("norte",(CAMINO_NORTE+"caminor02"));

  AddReadMsg(({"roca","inscripcion"}),
  "Lees en la roca:\n" //
  "\n" //
  "                          BIENVENIDO A KHA-ANNU VIAJERO\n"  //
  "                         LOS AMIGOS PROBARAN LA CERVEZA,\n" //
  "                              LOS ENEMIGOS EL ACERO\n");    //

 SetLocate("camino_norte");
 }