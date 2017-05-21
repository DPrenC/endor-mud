/*
DESCRIPCION : Puente que conduce a la torre de los Wizards
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/puente00.c
MODIFICACION : 14-01-97 [angor] Creacion.
*/

#include "./path.h"
inherit LIMBO("bridge");


create() {
  ::create();
  SetIntShort("el puente hacia la Torre de la Magia");
  SetIntLong(
"Te encuentras en el inicio de un puente que conduce hasta la Torre de la "
"Magia. A medida que te acercas, una sensación de peligro se interna en tu "
"mente, previniendote de aproximarte hacia la torre. Unos altos acantilados "
"son salvados por el paso de este puente, y en su fondo las olas rompen contra "
"las rocas.\n");

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

 AddExit("oeste",LIMBO("camino11"));
 AddExit("este",LIMBO("bridge02"));

}

