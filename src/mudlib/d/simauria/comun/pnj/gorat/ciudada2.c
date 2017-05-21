
#include "./path.h"
inherit NPC;
#include <properties.h>
create ()
{
    ::create();
    SetStandard("un ciudadano","humano",10+random(5),GENERO_MASCULINO);
    SetShort("un ciudadano noble");
    SetLong("Es un ciudadano de Gorat, parece que es un hombre noble y acomodado. "
    "Pasea por el pueblo con los aires de grandeza de los que son superiores.\n");
    SetWhimpy(QueryHP()/2);
    AddId(({"humano","ciudadano","ciudadano noble","noble"}));
    AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["oro":d3(),"platino":random(2)])]));
    SetCitizenship("gorat");
    InitChats(2,
          "El noble dice: Aparta, chusma\n",
          "El noble te ignora.\n");

}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras) {
    if(QueryHP()==QueryMaxHP())
        write("El noble grita: ¡¿Cómo osas?!\n");

    return ::DoDamage(damage, type, gentle, &xtras);
}
