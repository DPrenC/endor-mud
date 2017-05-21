/*
DESCRIPCION  : (modelo) La Gran Caverna Troll en el desfiladero de kuntz
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna.c
MODIFICACION : 21-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

int piso; // nivel de la caverna;

create() {
  string str;

  ::create();
  if (!piso) piso=0;
  SetIntShort("la gran caverna");

  switch(random(3)){
  case 0: str="Te encuentras en ";break;
  case 1: str="Te hallas en ";break;
  case 2: str="Estas en ";break;
  }

  switch(piso){
  case 0:
    str+="el suelo de la Gran Caverna de los troll, una gigantesca cueva "
         "de varios pisos de altura cuyas paredes estan plagadas de agujeros donde viven "
         "troll. Varias escaleras permiten subir y bajar entre sus distintos niveles. El "
         "suelo de la caverna esta humedo y lleno de altas estalagmitas.\n"; break;
  case 1:
    str+="el nivel medio de la Gran Caverna de los troll, una gigantesca "
         "cueva de varios pisos de altura cuyas paredes estan plagadas de agujeros donde "
         "viven troll. Varias escaleras permiten subir y bajar entre distintos niveles.\n";break;
  case 2:
    str+="el nivel superior de la Gran Caverna de los troll, una "
         "gigantesca cueva de varios pisos de altura cuyas paredes estan plagadas de "
         "agujeros donde viven troll. Varias escaleras permiten subir y bajar entre sus "
         "distintos niveles. Observas que del techo cuelgan impresionantes estalactitas.\n";break;
  }
  SetIntLong(str);

  AddDetail(({"cuevas","cueva"}),
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
}
