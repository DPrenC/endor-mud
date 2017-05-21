#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Hunkas");
   SetIntLong(
"La calle Hunkas transcurre paralela al muro occidental del Castillo de "
"Kha-annu. Siguiendo por esta calle puedes llegar a la parte trasera de las "
"escuelas de Metalurgia e Ingenieria. Al sur queda la Avenida Grimly.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"hunkas2");
  AddExit("sur",CIUDAD+"grimly2");

  SetLocate("Kha-annu");
}
