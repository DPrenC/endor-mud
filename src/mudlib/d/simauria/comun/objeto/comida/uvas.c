#include <properties.h>
inherit FOOD;

create(){
    ::create();
    SetFoodKind("food");
    SetFoodMsgs("Te comes un r�cimo de uvas.\n");
    SetFoodStuff(11);
    SetFoodHeal(6);
    SetShort("un r�cimo de uvas");
    SetLong("Es un apetitoso r�cimo de uvas verdes.\n");
    AddId(({"uva", "uvas", "r�cimo de uvas", "r�cimo", "racimo", "racimo de uvas",
    "racimo de uva", "r�cimo de uva"}));
    SetWeight(120);
    SetValue(35);
    } // Create
