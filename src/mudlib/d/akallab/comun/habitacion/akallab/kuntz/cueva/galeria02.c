/*
DESCRIPCION  : Galeria en las cavernas Troll
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cuevas/galeria02.c
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
	"techo. Al sudeste de aqui ves como la galeria acaba en una cueva en la "
	"que parece haber un lago subterraneo.\n");

  AddDetail(({"cueva"}), "Queda al sudeste.\n");
  AddDetail(({"lago"}), "Queda al sudeste. Desde aqui no puedes ver gran cosa.\n");
  AddDetail(({"suelo"}), "Esta humedecido por el agua que gotea del techo.\n");
  AddDetail(({"techo"}), "Ves como el agua subterranea gotea desde el.\n");

 SetIntNoise("Oyes el goteo del agua y voces al oeste.\n");
 SetIntSmell("Huele.... a troll!!.\n");
 SetLocate("cavernas Troll en Kuntz");
 SetIndoors(1);
 SetIntBright(0);

 AddExit("sudeste",K_CUEVA("cueva02"));
 //AddExit("oeste",K_CUEVA("caverna00"));
 //AddItem(PNJ("k_cueva/guardia"), REFRESH_DESTRUCT);
}
