/*
DESCRIPCION  : Suelo de la Gran Caverna Troll en el desfiladero de kuntz
FICHERO      : /d/akallab/comun/habitacion/akallab/kuntz/cueva/suelo01.c
MODIFICACION : 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el suelo de la gran caverna");
  SetIntLong(
      "Estas en el suelo de la Gran Caverna. Desde aqui tienes una vision casi completa "
      "de esta impresionante caverna que se extiende sobre tu cabeza. Te encuentras en "
      "medio de una multitud de altas estalagmitas que han crecido aqui en el suelo de "
      "la caverna debido al agua que constantemente gotea desde el techo.\n");

  AddDetail("techo",
      "Esta bastante alto y de el cuelgan multitud de impresionantes estalacticas.\n");

  AddDetail(({"cuevas","cueva","agujeros"}),
      "Hay una gran cantidad de pequenyas cuevas talladas en las paredes de la Gran "
      "Caverna. Es en ellas donde viven los troll.\n");

  AddDetail(({"repisas","repisa","nivel","niveles","terraza","terrazas"}),
      "Los troll han tallado la roca en la Gran Caverna de forma que se ensanche a "
      "medida que se eleva, generando asi varios niveles o terrazas de forma parecida a "
      "como se cultiva en la ladera de una montanya. Para pasar de un nivel a otro se "
      "emplean escaleras de madera.\n");

  AddDetail(({"escaleras","escalera"}),
      "Ves varias escaleras de madera a lo largo de la caverna que permiten subir y "
      "bajar de una a otra repisa de los ditintos niveles. Son toscas pero resistentes.\n");

  AddDetail(({"estalactita","estalactitas"}),
      "Son como gigantescos pinchos de roca que cuelgan del techo de la caverna. Son "
      "producidas cuando el agua subterranea de la montanya gotea desde el techo de la "
      "caverna, dejando alli las sales minerales que transporta.\n");

  AddDetail(({"estalagmita","estalagmitas"}),
      "Son como gigantescos pinchos de roca que se elevan desde el suelo de la caverna. "
      "Son producidas cuando el agua subterranea gotea desde el techo de la caverna, "
      "depositando las sales minerales que lleva disueltas en el lugar donde cae.\n");

  AddDetail(({"caverna","gran caverna","Caverna","Gran Caverna"}),QueryIntLong());

 SetIntNoise("Oyes el goteo del agua.\n");
 SetIntSmell("Huele.... a troll!!.\n");
 SetLocate("cavernas Troll en Kuntz");
 SetIndoors(1);
 SetIntBright(0);

 AddExit("oeste",K_CUEVA("suelo00"));
 AddExit("sur",K_CUEVA("suelo03"));
 AddExit("norte",K_CUEVA("caverna15"));
 AddExit("este",K_CUEVA("caverna08"));
}
