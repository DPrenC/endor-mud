/*   chorizo.c
     Creado por : Blackrider
     Fecha 2-11-97
*/

#include <mud.h>
inherit "/std/food";

create() {
::create();
SetShort("un chorizo");
SetLong("Es un chorizo rojo picante.\n");
AddId("chorizo");
SetFoodKind("food");
SetFoodMsgs(({"NyaMMMM.... B..... uaHHHHH\n"}));
SetFoodStuff(15);
SetWeight(50);
SetValue(3);
}
