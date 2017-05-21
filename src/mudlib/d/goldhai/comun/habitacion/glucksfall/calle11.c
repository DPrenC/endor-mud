#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetIntShort("la avenida Djorn");
  SetLongWrap(
    "Te encuentras en una pequeña plaza al Sur de Glucksfall, bastante "
    "sucia y vieja pero no creo que veas nada mucho mejor en esta ciudad. "
    "Si quieres puedes continuar caminando por la avenida Djorn en dirección "
    "Sur y Oeste, o si lo prefieres puedes ir al Sudeste y cruzar la torre "
    "para llegar a un pequeño puerto."
    );
  SetIndoors(0);

 AddItem(PNJ("glucksfall/kainoak"),REFRESH_DESTRUCT);

  AddExit("oeste","calle8");
  AddExit("sur","calle10");
  AddExit("sudeste","torre5");
  SetLocate("Glucksfall");
}
