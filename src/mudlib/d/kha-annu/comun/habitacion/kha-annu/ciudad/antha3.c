#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Antharax");
   SetIntLong(
"Esta es la calle comercial de Kha-annu. Muy cerca, hacia el oeste, queda la "
"tienda de armas. Varias farolas iluminan el lugar.\n");

  AddDetail(({"farolas","farola"}),
  "Puedes deducir que su unica funcion es la de iluminar la calle.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("este",CIUDAD+"antha4");
  AddExit("oeste",CIUDAD+"antha2");

  SetLocate("Kha-annu");
}
