/*   melon.c

     Creado por : Blackrider

     Fecha 1-11-97

*/
#include <properties.h>
inherit FOOD;

create() {

    ::create();

    SetShort("un mel�n");
    SetLong("Es un mel�n verde y gordito.\n");
    AddId(({"melon", "mel�n", "mel�n verde", "melon verde"}));
    SetFoodKind("food");
    SetFoodMsgs(({"Crunch.... spuchrh\n"}));
    SetFoodStuff(10);
    SetFoodHeal(10);
    SetWeight(1150);
    SetValue(70);
    SetSize(P_SIZE_SMALL);
}

