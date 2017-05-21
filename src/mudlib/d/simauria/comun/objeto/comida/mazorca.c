/*   mazorca.c
     Creado por : Nemesis
     Fecha 3-Dic-97
*/
#include <properties.h>
inherit FOOD;

create() {
    ::create();
    SetShort("una mazorca");
    SetLong("Es una mazorca de ma�z.\n");
    AddId(({"maiz", "ma�z", "mazorca", "mazorca de ma�z", "mazorca de maiz"}));
    SetFoodKind("food");
    SetFoodMsgs("Te comes una mazorca entera, y sin mantequilla ni nada.\n");
    SetFoodStuff(15);
    SetWeight(100);
    SetFoodHeal(10);
    SetSize(P_SIZE_SMALL);
    SetValue(30);
}
