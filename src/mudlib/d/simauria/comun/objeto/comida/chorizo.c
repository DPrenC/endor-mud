/*   chorizo.c
     Creado por : Blackrider
     Fecha 2-11-97
*/
#include <properties.h>
inherit FOOD;

create() {
    ::create();
    SetShort("un chorizo");
    SetLong("Es un chorizo rojo picante.\n");
  AddId(({"chorizo", "chorizo rojo", "chorizo picante"}));
    SetFoodKind("food");
    SetFoodMsgs(({"NyaMMMM.... B..... uaHHHHH\n"}));
    SetFoodStuff(10);
    SetFoodHeal(10);
    SetWeight(150);
    SetSize(P_SIZE_SMALL);
    SetValue(60);
}
