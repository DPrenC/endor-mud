/*   melon.c
     Creado por : Blackrider
     Fecha 1-11-97
*/

#include "path.h"
inherit "/std/food";

create() {
::create();
SetShort("un melon");
SetLong("Es un melon bastante apetitoso.\n");
AddId("melon");
SetFoodKind("food");
SetFoodMsgs(({"Crunch.... spuchrh\n"}));
SetFoodStuff(10);
SetWeight(150);
SetValue(1);
}
