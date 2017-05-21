/* [Woo] Modificada */

#include "./path.h"
#include <properties.h>



inherit THING;

create() {
 ::create();
 SetIds(({"canya","canya de pescar","caña","caña de pescar"}));
 SetAds(({"una","la","de pesca"}));
 SetShort("una caña de pescar");
 SetLong(
"Es una simple caña de pescar. Tiene el anzuelo. Quizás puedas pescar algún\n"
"pececito dorado con ella.\n");

 SetWeight(1000);
 SetValue(10);
 Set(P_NOSELL,1);
}
