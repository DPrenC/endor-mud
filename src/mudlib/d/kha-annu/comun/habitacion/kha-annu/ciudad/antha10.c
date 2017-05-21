#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Antharax");
   SetIntLong(
"La calle sigue en direccion este y oeste. Al sur puedes ver un callejon que "
"cruza hasta la Avenida del Castillo. Las antorchas siguen iluminando la calle.\n");

  AddDetail(({"callejon"}),
  "Esta mas oscuro que la calle, y desde aqui no puedes percibir gran cosa.\n");

  AddDetail(({"antorchas","antorcha","farolas","farola"}),
  "Proporcionan luz artificial a todas las calles de Kha-annu.\n");
   SetIntBright(80);
   SetIndoors(1);

  AddExit("sur",CIUDAD+"callejon10");
  AddExit("este",CIUDAD+"antha11");
  AddExit("oeste",CIUDAD+"antha9");

  SetLocate("Kha-annu");
}
