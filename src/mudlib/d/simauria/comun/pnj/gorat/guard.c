
#include "./path.h"
#include <properties.h>
#include <colours.h>

inherit NPC;
inherit GUARD;

create ()
{
    "*"::create();
    SetStandard("un guardia","humano",20+random(5),GENERO_MASCULINO);
    SetShort("un guardia");
    SetLong("Es un guardia de Gorat. En el pueblo no suele haber muchos problemas, "
    "pero aún así se mantiene una guardia bastante bien entrenada, este parece "
    "un soldado raso, porque no tiene galones en su armadura.\n");
    AddId(({"humano","guardia","soldado","soldado raso"}));
    SetCitizenship("gorat");
    switch(d6()){
        case 1..4:
            AddItem("/obj/armas/espada_larga",REFRESH_REMOVE,SF(wieldme));
            break;
        case 5..6:
            AddItem("/obj/armas/latigo",REFRESH_REMOVE,SF(wieldme));
            break;
    }

        AddItem(PROT("coraza"),REFRESH_REMOVE,SF(wearme));
    InitChats(2,({
          "El guardia dice: No armes bronca mientras estés aquí.\n",
        "El guardia dice: Si armas bronca te las veras conmigo.\n"}));

    InitAChats(4,({
    "El guardia grita: "+TC_YELLOW+"Por la ley."+TC_GREEN+"\n",
    "El guardia dice: "+TC_YELLOW+"No deberías haber hecho eso."+TC_GREEN+"\n"}));
}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras) {
    if(QueryHP()==QueryMaxHP())
        write("El guardia grita: ¡POR LA LEY!\n");

    return ::DoDamage(damage, type, gentle, &xtras);
}
