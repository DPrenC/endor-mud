
#include "./path.h"
#include <properties.h>

inherit NPC;

create(){
    ::create();
    SetStandard("un hobbit", "hobbit", 10, GENDER_MALE);
    SetShort("un hobbit aventurero");
    AddId("mediano");
    SetLong("Un joven hobbit aventurero que pasea tranquilamente por estos caminos de Aman.\n");

}
