#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Hunkas");
   SetIntLong(
"Sigues caminando por la misma calle, cuyas únicas direcciones de salida son "
"hacia el norte y hacia el sur. El muro del castilloqueda al oeste.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"hunkas4");
  AddExit("sur",CIUDAD+"hunkas2");

  SetLocate("Kha-annu");
}
