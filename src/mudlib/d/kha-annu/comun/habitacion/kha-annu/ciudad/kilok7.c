#include "path.h"
inherit KHA_ROOM;

create() {
  ::create();
  SetIntShort("la calle Kilok.");
  SetIntLong(
"Te encuentras en la calle Kilok. La calle sigue hacia el norte y al sur.\n"
"Unas grandes farolas hechas de hierro forjado se encargan de iluminar la "
"calle. Desde esta posicion puedes ver el puente sobre el río que provee "
"de agua a la ciudad. El castillo Kha-annu esta hacia el este, y el "
"distrito de gremios queda hacia el sur.\n");
  SetIndoors(1);
  SetIntBright(100);
  AddDetail(({"farolas","grandes farolas"}),
"Son grandes farolas situadas a izquierda y derecha de la calle.\n");
  AddDetail(({"puente"}),
"Al sur puedes ver un puente de madera. No tiene nada en especial.\n");
  AddDetail(({"río","río kilok","kilok"}),
"El río esta hacia el sur, y un puente de madera permite cruzar sobre el.\n");
  AddDetail(({"castillo","castillo Kha-annu","castillo de Kha-annu"}),
"Puedes ver la parte baja del enorme castillo de Kha-annu hacia el oeste\n");
  AddExit("sur","./ptekilok");
  AddExit("norte","kilok8");
}
