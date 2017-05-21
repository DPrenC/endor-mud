
inherit NPC;
inherit GUARD;

#include "./path.h"
#include <properties.h>
#include <colours.h>
#include <moving.h>

create ()
{
    "*"::create();
    SetStandard("un sargento","humano",26+d6(),GENERO_MASCULINO);
    SetShort("un sargento");
    SetLong("Es uno de los guardias de Gorat. En el pueblo no suele haber muchos problemas, "
    "pero aún así se mantiene una guardia bastante bien entrenada, este parece "
    "un sargento, por los galones que ves en su armadura.\n");
    SetDex(QueryDex()+d6());
    SetStr(QueryStr()+d6());
    SetIVision(0);
    AddId(({"humano","guardia","sargento"}));
    SetGoChance(80);
    AddWalkZones(({BETWA "gorat", CNS("puerto")}));
    SetCitizenship("gorat");
    switch(d6()){
        case 1..5:
            AddItem("/obj/armas/espada_larga",REFRESH_REMOVE,SF(wieldme),
            ([P_LONG: "Es una espada larga de acero. Su empuñadura de buena calidad "
                "y su reluciente hoja afilada por ambas partes, le hacen ser un "
                "arma respetable.\n"]));
            break;
        case 6:
            AddItem("/obj/armas/mangual_pesado",REFRESH_REMOVE,SF(wieldme));
            break;
    }

    AddItem(PROT("coraza"),REFRESH_REMOVE,SF(wearme));
    InitChats(2,({
          "El sargento dice: No armes bronca mientras estés aquí.\n",
        "El sargento dice: Si armas bronca te las verás conmigo.\n"}));

    InitAChats(4,({
    "El sargento grita: "+TC_BLUE+"Por la ley."+TC_GREEN+"\n",
    "El sargento dice: "+TC_BLUE+"No deberías haber hecho eso"+TC_GREEN+".\n"}));
}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras) {
    int i,j;
    object     ob;

    if(QueryHP()==QueryMaxHP())
    {
        j=2;
        write("El sargento grita: ¡A MI LA GUARDIA!\n");
        write(j+" guardias salen a defender a su sargento.\n");
        for(i=0;i<j;i++)
        {
            ob=clone_object(GORPNJ("guard"));
            ob->move(environment(TO), M_SILENT);
        }
    }
    return ::DoDamage(damage, type, gentle, &xtras);
}
