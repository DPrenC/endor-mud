
#include "./path.h"
#include <properties.h>

inherit NPC;

create(){
::create();
SetStandard("un hobbit", "hobbit", 10, GENDER_MALE);
SetShort("un joven hobbit");
SetLong("Es un joven hobbit de la comarca que est� paseando alegremente.\n");
AddId("mediano");
    SetSmell("Huele a tabaco.\n");
    InitChats(3, ({"un joven hobbit te sonr�e.\n",
        "un joven hobbit se rasca la barriga.\n"}));
}
