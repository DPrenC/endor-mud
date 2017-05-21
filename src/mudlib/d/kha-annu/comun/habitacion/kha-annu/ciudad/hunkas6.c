#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Hunkas");
   SetIntLong(
"La calle Hunkas es una de las calles secundarias de la ciudad. Pasa por la "
"trasera de las escuelas de Metalurgia e Ingenieria. La calle continua hacia "
"el norte y el sur.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"hunkas7");
  AddExit("sur",CIUDAD+"hunkas5");

  SetLocate("Kha-annu");
}
