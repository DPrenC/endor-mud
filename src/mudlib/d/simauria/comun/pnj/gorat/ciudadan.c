
#include "./path.h"
inherit NPC;
#include <properties.h>
create ()
{
    ::create();
    SetStandard("un pescador","humano",9+random(5),GENERO_MASCULINO);
    SetShort("un pescador");
    SetLong("Es un ciudadano de Gorat, parece que vive de la pesca y que en este "
    "preciso momento se está tomando un descanso de su duro trabajo.\n");
    AddId(({"humano","ciudadano","pescador", "hombre"}));
    SetCitizenship("gorat");
    InitChats(2,
          ({"El pescador dice: Estoy tan cansado.....\n",
        "El pescador bosteza.\n"}));

}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras) {
    if(QueryHP()==QueryMaxHP())
        write("El pescador grita: asesinooo\n");

    return ::DoDamage(damage, type, gentle, &xtras);
}
