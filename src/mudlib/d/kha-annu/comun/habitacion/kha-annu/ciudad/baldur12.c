#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la esquina de Kilok con Baldur");
   SetIntLong(
"Esta es la calle Kilok, por la que puedes cruzar el río que nace en las "
"montanyas de Kha-annu. El oeste queda la calle Baldur y la trasera de la "
"posada del Dragon Rojo.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"kilok1");
   AddExit("oeste",CIUDAD+"baldur11");

  SetLocate("Kha-annu");
}