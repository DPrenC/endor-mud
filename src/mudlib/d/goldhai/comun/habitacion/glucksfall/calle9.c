#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetIntShort("la avenida Djorn");
  SetLongWrap(
    "Estás en la parte más sureña de la avenida Djorn. Desde aquí contemplas toda "
    "la avenida y te parece enorme. En el Suroeste hay una entrada a la torre sur "
    "de Glucksfall."
    );
  SetIndoors(0);
  AddExit("norte","calle8");
  AddExit("este","calle10");
  AddExit("suroeste","torre4");
  SetLocate("Glucksfall");
}
