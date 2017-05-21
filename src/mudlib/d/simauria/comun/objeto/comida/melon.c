/*   melon.c

     Creado por : Blackrider

     Fecha 1-11-97

*/
#include <properties.h>
inherit FOOD;

create() {

    ::create();

    SetShort("un melón");
    SetLong("Es un melón verde y gordito.\n");
    AddId(({"melon", "melón", "melón verde", "melon verde"}));
    SetFoodKind("food");
    SetFoodMsgs(({"Crunch.... spuchrh\n"}));
    SetFoodStuff(10);
    SetFoodHeal(10);
    SetWeight(1150);
    SetValue(70);
    SetSize(P_SIZE_SMALL);
}

