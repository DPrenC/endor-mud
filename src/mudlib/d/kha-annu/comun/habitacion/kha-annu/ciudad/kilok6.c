#include "path.h"
inherit KHA_ROOM;

create() {
  ::create();
  SetIntShort("la calle Kilok.");
  SetIntLong(
"Te encuentras en la calle Kilok. La calle sigue hacia el norte y al sur.\n"
"Unas grandes faroles hechas de hierro forjado se encargan de iluminar la "
"calle. Hacia el norte un puente cruza el caudaloso río del cual las "
"fuentes de la ciudad toman su agua. El castillo Kha-annu se encuentra ahora "
"al oeste. Mas hacia el norte queda el distrito de forjas y armerias.\n");

  SetIndoors(1);
  SetIntBright(100);
  AddDetail(({"farol","faroles","grandes faroles","gran farol"}),
"Son grandes faroles situados a izquierda y derecha de las calles.\n");
  AddDetail("puente",
"Al norte puedes ver un puente de madera. No tiene nada en especial.\n");
  AddDetail(({"río","río kilok","kilok"}),
"El río esta hacia el norte, y un puente de madera permite cruzar sobre el.\n");
  AddDetail(({"castillo","castillo Kha-annu","castillo de Kha-annu"}),
"Puedes ver la parte baja del enorme castillo Kha-annu hacia el este.\n");

  AddExit("norte","./ptekilok");
  AddExit("sur","./kilok5");
}
