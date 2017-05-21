 /* [Woo] Modificada */
#include "./path.h"
#include <properties.h>

inherit THING;

create() {
 ::create();
 SetIds(({"llave1_s","llave","llave de la habitación simple","llave de la habitacion simple"}));
 SetAds(({"una","la"}));
 SetShort("la llave de la habitación simple");
 SetLong(
"Es una llave de la que cuelga una enorme figura de hierro representando\n"
"el cuerpo del posadero. Parece muy pesada.\n"
);
 SetWeight(1000);
 SetValue(30);
 Set(P_NODROP,
 "El posadero se enfadaria mucho contigo si tirases la llave.\n");
 Set(P_NOGIVE, "Nunca! El posadero se enfadaria muchisimo.\n");
}
