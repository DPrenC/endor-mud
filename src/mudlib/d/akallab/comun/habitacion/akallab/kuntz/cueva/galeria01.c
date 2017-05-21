/*
DESCRIPCION  : Galeria en las cavernas Troll
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cuevas/galeria01.c
MODIFICACION : 21-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>



inherit ROOM;

//los PNJ no salen de las cuevas
int ir_e()
{
if (TP->QueryIsPlayer()) return TP->move(K_CAMINO("kuntz_04"),M_GO);
  return 1;
}

create() {
  ::create();
 SetIntShort("una galería subterránea");
  SetIntLong(
      "Estas en una galleria subterranea que avanza por las estranyas de esta montanya. "
      "El suelo esta humedo debido al agua que se filtra desde el techo. Al suroeste de "
      "aqui ves como la galeria acaba junto a lo que parece ser un lago subterraneo. Al "
      "este se filtra algo de luz entre unos arbustos que parecen ocultar lo que debe "
      "ser una salida al exterior.\n");

  AddDetail(({"lago"}), "Queda al suroeste. Desde aqui no puedes ver gran cosa\n");
  AddDetail(({"suelo"}), "Esta humedecido por el agua que gotea del techo.\n");
  AddDetail(({"techo"}), "Ves como el agua subterranea gotea desde el.\n");

  AddDetail(({"arbustos"}),
      "Un monton de arbustos se ha amontonado en el extremo de la galeria. Pese a ello "
      "algo de la luz del exterior se cuela a traves de ellos. Seguramente los troll "
      "los utilizan para ocultar la entrada de la cueva desde el exterior.\n");

 SetIntNoise("Oyes el goteo del agua y voces al oeste.\n");
 SetIntSmell("Huele.... a troll!!.\n");
 SetLocate("cavernas Troll en Kuntz");
 SetIndoors(1);
 SetIntBright(0);

 AddExit("este",SF(ir_e));
 AddExit("suroeste",K_CUEVA("cueva01"));
}
