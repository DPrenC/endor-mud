/*
DESCRIPCION  : Cavernas Troll en el desfiladero de kuntz
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cuevas/monolito.c
MODIFICACION : 21-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  object ob;
  ::create();
  SetIntShort("una isla en el lago");
  SetIntLong(
      "Estas sobre una pequenya isla en medio de un lago subterraneo. El lago se halla "
      "en el interior de una gran cueva de cuyo alto techo ves colgar impresionantes "
      "estalactitas. El lago que te rodea no parece tener mucha profundidad y supones "
      "que se ha formado por el agua subterranea que gotea desde el techo. Ves varias "
      "galerias subterraneas que llegan a la cueva. Te parece oir ruido desde el oeste.\n");

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

 AddExit("este",K_CUEVA("cueva01"));
 AddExit("oeste",K_CUEVA("cueva04"));
 AddExit("sur",K_CUEVA("cueva03"));
 AddExit("norte",K_CUEVA("cueva02"));

 ob=clone_object("/obj/monolito");
 ob->SetRaza("troll");
 ob->move(TO);
 AddItem(OTRO("en_obras"),REFRESH_ALWAYS,3);
}
