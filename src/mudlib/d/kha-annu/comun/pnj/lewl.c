/* Creado por [I] Izet@Simauria.
   Ratas debiluchas para newbies.
   [Woo] Modificado
*/


#include "path.h"
#include <properties.h>

inherit KBASE;

create() {
  ::create();
  SetStandard("Lewl","enano",1,GENDER_MALE);
   SetShort("Lewl, el encargado");
  SetLong(
"Es un enano bastante viejo. Te esta mirando por encima de las gafas.\n"
);
  SetAggressive(0);
  SetAlign(0);
  SetWhimpy(0);
SetIds(({"lewl","encargado",}));
  InitAChats(8,({
   "Lewl, se esconde detrás del mostrador.\n",
    "Lewl grita pidiendo socorro.\n"
  }));

}

public varargs void Die(mixed silent) {
    tell_room(environment(TO),
"Lewl cae inconsciente al suelo, y se desangra.\n"
);
   ::Die(silent);
}
