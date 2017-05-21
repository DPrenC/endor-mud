/*
DESCRIPCION  : Galeria en las cavernas Troll
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cuevas/galeria03.c
MODIFICACION : 18-11-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
  SetIntShort("una galería subterránea");
  SetIntLong(
  "Estas en una galleria subterranea que avanza por las estranyas de esta "
    "montanya. El suelo esta humedo debido al agua que se filtra desde el "
	"techo. Al norte de aqui ves como la galeria acaba en una cueva en la "
	"que parece haber un lago subterraneo.\n");

  AddDetail(({"cueva"}), "Queda al norte.\n");
  AddDetail(({"lago"}), "Queda al norte. Desde aqui no puedes ver gran cosa.\n");
  AddDetail(({"suelo"}), "Esta humedecido por el agua que gotea del techo.\n");
  AddDetail(({"techo"}), "Ves como el agua subterranea gotea desde el.\n");

 SetIntNoise("Oyes el goteo del agua y voces al oeste.\n");
 SetIntSmell("Huele.... a troll!!.\n");
 SetLocate("cavernas Troll en Kuntz");
 SetIndoors(1);
 SetIntBright(0);

 AddExit("norte",K_CUEVA("cueva03"));
 AddExit("este",K_CUEVA("galeria16"));
 AddExit("suroeste",K_CUEVA("galeria09"));
}
