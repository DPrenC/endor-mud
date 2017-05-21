#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetIntShort("la avenida Djorn");
  SetLongWrap("Vas andando por la avenida Djorn que recorre la ciudad desde "
  "la parte norte a la sur. Al oeste tienes la salida de "
  "la misma, y al este un local que parece cerrado.");

  SetIndoors(0);
  AddExit("norte","calle2");
  AddExit("sur","calle4");
  AddExit("oeste","entrada");

 AddDetail(({"este","local este","local"}),
           "Es un local sin ningún distintivo en la fachada. Esta cerrado.\n");
 AddItem(PNJ("glucksfall/orco"),REFRESH_DESTRUCT);

  SetLocate("Glucksfall");
}
