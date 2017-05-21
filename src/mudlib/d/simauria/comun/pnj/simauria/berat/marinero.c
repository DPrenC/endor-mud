/*
DESCRIPCION : marinero
FICHERO     : /d/simauria/comun/pnj/simauria/berat/marinero.c
MODIFICACION: 4-11-99 [Icaro];9-6-00[Maler]eliminados los retornos de carro;
Sustituido /std/npc por NPC;incluyo el path.h;juas este pabo es inmortal,
modifico el for pa q se le pueda matar, procedo a modificar el for en TODOS
los pnjs con dodamage;modifico el write(pelea) pa q solo salga la primera vez
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
inherit NPC;
create() {
    ::create();
    SetStandard("un marinero","humano",15+random(5),GENERO_MASCULINO);
    SetShort("un marinero");
    SetLong("Es uno de los muchos marineros que hay en Berat.\n");
    AddId(({"hombre","marinero","humano"}));
    SetCitizenship("berat");
    if(d2()==1)
        AddItem("/obj/money",REFRESH_REMOVE,
        (["Money":(["oro":d4()])]));
}
private int Es_Npc(object mon)
     {
       if(mon->QueryIsNPC() && mon!=TO)
         return 1;
        return 0;
     }

     DoDamage(int dmg)
     {
        int i;
        object *npcs;

        npcs =
     filter(deep_inventory(environment(TO)),SF(Es_Npc));

        if(sizeof(npcs))
          for(i=0;i<sizeof(npcs);i++){
           npcs[i]->Kill(TP || PO);}
           if(TO->QueryHP()==TO->QueryMaxHP()) write("Alguien grita: ¡PELEA!\n");
	 ::DoDamage(dmg);
	 }
