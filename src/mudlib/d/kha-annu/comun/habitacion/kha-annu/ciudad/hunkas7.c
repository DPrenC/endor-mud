#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Hunkas");
   SetIntLong(
"La calle Hunkas transcurre paralela al muro occidental del Castillo de "
"Kha-annu. Siguiendo por esta calle puedes llegar a la parte trasera de las "
"escuelas de Metalurgua e Ingenieria. Al norte queda la Avenida del Castillo.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"avcastle2");
  AddExit("sur",CIUDAD+"hunkas6");

  SetLocate("Kha-annu");
}
