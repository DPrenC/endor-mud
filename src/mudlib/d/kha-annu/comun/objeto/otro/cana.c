/* [Woo] Modificada */

#include "./path.h"
#include <properties.h>



inherit THING;

create() {
 ::create();
 SetIds(({"canya","canya de pescar","ca�a","ca�a de pescar"}));
 SetAds(({"una","la","de pesca"}));
 SetShort("una ca�a de pescar");
 SetLong(
"Es una simple ca�a de pescar. Tiene el anzuelo. Quiz�s puedas pescar alg�n\n"
"pececito dorado con ella.\n");

 SetWeight(1000);
 SetValue(10);
 Set(P_NOSELL,1);
}
