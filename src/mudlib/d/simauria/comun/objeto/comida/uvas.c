#include <properties.h>
inherit FOOD;

create(){
    ::create();
    SetFoodKind("food");
    SetFoodMsgs("Te comes un rácimo de uvas.\n");
    SetFoodStuff(11);
    SetFoodHeal(6);
    SetShort("un rácimo de uvas");
    SetLong("Es un apetitoso rácimo de uvas verdes.\n");
    AddId(({"uva", "uvas", "rácimo de uvas", "rácimo", "racimo", "racimo de uvas",
    "racimo de uva", "rácimo de uva"}));
    SetWeight(120);
    SetValue(35);
    } // Create
