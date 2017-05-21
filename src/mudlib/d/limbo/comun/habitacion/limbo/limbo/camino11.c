/*
DESCRIPCION  : Camino que conduce a la torre de Wizards
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino11.c
MODIFICACION : 14-01-97 [angor] Creacion.
*/

#include "./path.h"
#include <moving.h>
#include <sounds.h>
inherit ROOM;


int bajarcueva(){

write("Con mucho cuidado, comienzas a descender por las resbaladizas rocas del\n");
write("acantilado. Avanzas lentamente ante el peligro de resbalar y caer al mar.\n");
write("Tras un rato descendiendo entre rocas, alcanzas la boca de una cueva.\n");

say(TP->QueryName()+" se acerca al borde del acantilado, mira hacia abajo, y "
 "comienza a descender con cuidado por él.\n",TP);

tell_room(LIMBO("cueva00"),TP->QueryName()+" llega tras descender por el acantilado.\n");

TP->move(LIMBO("cueva00"),M_SILENT);
return 1;
}

create() {
  ::create();
  SetIntShort("el camino hacia la torre de Wizards, junto al mar.");
  SetIntLong(
"Tras avanzar a traves del bosque, se alcanza la costa este de la isla Limbo. "
"El oleaje choca estrepitosamente sobre las rocas que forman el alto acantilado "
"de la costa. Al este, en medio del mar sobre un peñasco, se alza la esbelta "
"torre de los Wizards. Un largo puente parte del acantilado y permite acceder "
"a la torre. En medio de las rocas del borde del acantilado, agitadas por el "
"viento, crecen unas pequeñas hierbas de color verde.\n");

AddDetail(({"puente","largo puente"}),
  "El puente conecta el borde del acantilado con la torre de los Wizards. Está "
  "hecho de piedra y se apoya firmemente sobre varios altos arcos que se hunden "
  "apoyándose en el fondo del mar.\n");

 AddDetail(({"acantilado","acantilados"}),
  "La isla acaba abruptamente en un alto acantilado rocoso a cuyos pies choca "
  "furiosamente el oleaje. Será mejor no aproximarse mucho, el suelo está "
  "húmedo y una caida podría ser fatal.\n");

   AddDetail(({"rocas","rocas del borde","rocas con plantas"}),
  "Unas pequeñas hierbas verdes crecen entre las rocas del borde del acantilado. "
  "Las plantas se agarran con fuerza entre las rocas para poder resistir las "
  "rachas de viento que las agitan con violencia.\n");

   AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"torre de wizards","torre de Wizards","torre","Torre"}),
  "La torre de los Wizards es un edificio construido sobre una roca al "
  "este de la isla Limbo. En ella trabajan y se reunen los wizards, seres "
  "que ayudan a los dioses a crear este mundo, y además se encuentran una "
  "serie de servicios para resolver problemas, tales como la Justicia, que "
  "surjan con o entre los jugadores de Simauria.\n");

 SetIntNoise("Las olas rompen una y otra vez contra la base del acantilado.\n");
 SetIntSmell("Huele a mar.\n");
 SetLocate("isla Limbo");
 SetIndoors(0);

 AddExit("oeste",LIMBO("camino06"));
 AddExit("este",LIMBO("bridge01"));
 AddExit("abajo",SF(bajarcueva));
 HideExit("abajo",1);
 SetSoundEnvironment(SND_AMBIENTES("olas"), 10);
 AddItem(HERBS("hierba_curativa"), REFRESH_REMOVE);
}

