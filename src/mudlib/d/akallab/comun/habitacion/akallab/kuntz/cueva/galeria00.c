/*
DESCRIPCION  : Galeria en las cavernas Troll
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cuevas/galeria00.c
MODIFICACION : 21-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("una galería subterránea");
  SetIntLong(
      "Estas en una galleria subterranea que avanza por las estranyas de esta montanya. "
      "El suelo esta humedo debido al agua que se filtra desde el techo. Al este de "
      "aqui ves como la galeria acaba junto a lo que parece ser un lago subterraneo y "
      "al oeste alcanza una caverna de la cual provienen voces.\n");

  AddDetail(({"caverna"}), "Queda al oeste. Desde aqui no puedes ver gran cosa\n");
  AddDetail(({"lago"}), "Queda al este. Desde aqui no puedes ver gran cosa\n");
  AddDetail(({"suelo"}), "Esta humedecido por el agua que gotea del techo.\n");
  AddDetail(({"techo"}), "Ves como el agua subterranea gotea desde el.\n");

 SetIntNoise("Oyes el goteo del agua y voces al oeste.\n");
 SetIntSmell("Huele.... a troll!!.\n");
 SetLocate("cavernas Troll en Kuntz");
 SetIndoors(1);
 SetIntBright(0);

 AddExit("este",K_CUEVA("cueva04"));
 AddExit("oeste",K_CUEVA("caverna00"));
 AddItem(PNJ("k_cueva/guardia"), REFRESH_DESTRUCT);
}
