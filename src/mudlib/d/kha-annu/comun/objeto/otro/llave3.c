/* [Woo] Modificado */

#include "./path.h"
#include <properties.h>

inherit THING;

create() {
 ::create();
 SetIds(({"llave3_l","llave","llave de la habitacion lujosa"}) );
 SetAds(({"una","la"}));
 SetShort("la llave de la habitación lujosa");
 SetLong(
"Ves un precioso llavero tallado de madera, del que prende una llave de oro macizo.\n"
"El tallado en la madera representa un enano forjando un hacha.\n");
 SetWeight(200);
 SetValue(70);
 Set(P_NODROP,
 "El posadero se enfadaría mucho contigo si tirases la llave.\n");
 Set(P_NOGIVE, "¡Nunca! El posadero se enfadaría muchísimo.\n");
}
