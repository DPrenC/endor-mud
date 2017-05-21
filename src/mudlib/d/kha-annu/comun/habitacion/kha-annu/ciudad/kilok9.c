#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Kilok");
   SetIntLong(
"Sigues por la calle Kilok, el puente que cruza el río no esta muy lejos si vas "
"hacia el sur, despues de doblar el pequenyo recodo hacia el oeste.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"avcastle11");
  AddExit("oeste",CIUDAD+"kilok8");

  SetLocate("Kha-annu");
}
