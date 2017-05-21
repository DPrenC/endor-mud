
#include "./path.h"
inherit NPC;
#include <properties.h>
create ()
{
    ::create();
    SetStandard("una mujer","humano",7+random(5),GENERO_FEMENINO);
    SetShort("una mujer");
    SetLong("Es una mujer de Gorat. Se afana con una dedicación extraordinaria "
    "en sus labores diarias, parece muy ocupada.\n");
    SetWhimpy(QueryHP()/4);
    AddId(({"humana","ciudadana","mujer"}));
    SetCitizenship("gorat");
    InitChats(2,({
          "La mujer te dice: No tengo tiempo ahora\n",
        "La mujer sigue con sus cosas.\n"}));

}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras) {

    if(QueryHP()==QueryMaxHP())
        write("La mujer llora: Por favor, no me mates.\n");

    return ::DoDamage(damage, type, gentle, &xtras);
}
