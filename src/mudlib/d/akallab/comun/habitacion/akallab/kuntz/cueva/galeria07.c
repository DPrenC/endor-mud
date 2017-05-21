/*
DESCRIPCION  : Galeria en las cavernas Troll
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cuevas/galeria07.c
MODIFICACION : 17-11-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
  SetIntShort("una galería subterránea");
  SetIntLong(
  "Estas en una galleria subterranea que avanza por las estranyas de esta "
    "montanya. El suelo esta algo humedo debido al agua que se filtra desde "
	"las grietas del techo. Al sudeste de aqui se abre lo que parece ser "
	"una gran caverna de la cual provienen voces.\n");

  AddDetail(({"caverna"}), "Queda al sudeste. Desde aqui no puedes ver gran cosa.\n");
  AddDetail(({"suelo"}), "Esta humedecido por el agua que gotea del techo.\n");
  AddDetail(({"techo","grietas"}),
    "El agua subterranea de la montanya se filtra por las grietas del "
	  "techo de la galeria goteando luego hasta el suelo.\n");

 SetIntNoise("Oyes el goteo del agua y voces al sudeste.\n");
 SetIntSmell("Huele.... a troll!!.\n");
 SetLocate("cavernas Troll en Kuntz");
 SetIndoors(1);
 SetIntBright(0);

 //AddExit("nordeste",K_CUEVA("caverna03"));
 AddExit("sudeste",K_CUEVA("caverna22"));
 AddItem(PNJ("k_cueva/guardia"), REFRESH_DESTRUCT);
}
