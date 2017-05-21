#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetIntShort("la avenida Djorn");
  SetLongWrap(
    "Estás en la Avenida Djorn que recorre de Norte a Sur la ciudad. Puedes ir "
    "en dirección Norte, Sur o Este para continuar andando por ella o bien salir "
    "de Glucksfall por el Oeste, donde se encuentra la puerta sur."
    );
  SetIndoors(0);
  AddExit("norte","calle7");
  AddExit("sur","calle9");
  AddExit("este","calle11");
  AddExit("oeste","entrada_sur");

 AddItem(PNJ("glucksfall/drex"),REFRESH_DESTRUCT);

  SetLocate("Glucksfall");
}
