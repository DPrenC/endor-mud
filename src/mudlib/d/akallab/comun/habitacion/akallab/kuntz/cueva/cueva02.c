/*
DESCRIPCION  : Cavernas Troll en el desfiladero de kuntz
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cuevas/cueva02.c
MODIFICACION : 21-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
 SetPreIntShort("junto a");
 SetIntShort("un lago subterráneo");
  SetIntLong(
    "Te hallas en la parte norte de una gran cueva subterranea. Del alto techo de la "
      "cueva cuelgan impresionantes estalactitas y el suelo esta totalmente inundado "
      "por un pequenyo lago subterraneo, que no parece tener mucha profundidad. En el "
      "centro del lago hay una pequenya isla con un monolito. Una galeria parte desde "
      "aqui hacia el noroeste.\n");

  AddDetail(({"monolito"}),
      "Es un extranyo objeto que se halla en la pequenya isla del lago. No sabes de "
      "donde puede haber venido ni por que esta ahi.\n");

  AddDetail(({"estalactita","estalactitas"}),
      "Son como gigantescos pinchos de roca que cuelgan del techo de la cueva. Son "
      "producidas cuando el agua subterranea de la montanya gotea desde el techo de la "
      "cueva, dejando alli las sales minerales que transporta.\n");

  AddDetail(({"cueva"}),QueryIntLong());

  AddDetail(({"lago"}),
      "En el suelo de la cueva se ha formado un pequenyo lago subterraneo poco profundo "
      "debido al agua subterranea que gotea desde el techo. En medio de el se alza una "
      "pequenya isla.\n");

  AddDetail(({"isla"}),
      "Es una pequenya elevacion del suelo de la cueva que se alza por encima del nivel "
      "del agua del lago. Sobre ella hay un monolito.\n");

 SetIntNoise("Oyes el goteo del agua.\n");
 SetIntSmell("Huele.... a troll!!.\n");
 SetLocate("cavernas Troll en Kuntz");
 SetIndoors(1);
 SetIntBright(0);

 AddExit("sur",K_CUEVA("monolito"));
 AddExit("sudeste",K_CUEVA("cueva01"));
 AddExit("suroeste",K_CUEVA("cueva04"));
 AddExit("noroeste",K_CUEVA("galeria02"));
}