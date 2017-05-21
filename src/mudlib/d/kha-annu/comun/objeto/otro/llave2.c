/* [Woo] Modificado */
#include "./path.h"
#include <properties.h>

inherit THING;

create() {
 ::create();
 SetIds(({"llave2_n","llave","llave de la habitacion normal"}) );
 SetAds(({"una","la"}));
 SetShort("la llave de la habitación normal");
 SetLong(
"Es una llave de plata, de la que cuelga un pesado pomo de bronce, representando\n"
"el escudo de la posada.\n"
);
 SetWeight(600);
 SetValue(50);
 Set(P_NODROP,
 "El posadero se enfadaria mucho contigo si tirases la llave.\n");
 Set(P_NOGIVE, "¡Nunca! El posadero se enfadaría muchisimo.\n");
}
