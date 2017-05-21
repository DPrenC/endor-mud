/*
DESCRIPCION : Mankson
FICHERO     : /d/simauria/comun/pnj/simauria/berat/mankson.c
MODIFICACION: 4-11-99 [Icaro];9-2-00[Maler]quitaos retonos de carro;
sustituido /std/npc por NPC;juas este pabo es inmortal, modifico el for
pa q se le pueda matar;le meto un if al whirte(pelea) pa q solo salga una vez
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <combat.h>
#include <properties.h>
inherit NPC;

create() {
    ::create();

    SetStandard("Mankson", "humano", 19, GENDER_MALE);
    AddId(({"borracho","hombre","mankson"}));
    SetShort("Mankson");
    SetLong("Es Mankson, un cliente asiduo de 'la serpiente marina' parece bastante "
    "fuerte y muy poco sociable.\n");
    SetAlcohol(100);
    SetCitizenship("berat");
    InitChats(4,({
    "Mankson exclama: ¡Marinerito ¿donde has dejado tu barquita?!\n",
    "Mankson te mira fijamente y te pregunta queres pelea?.\n",
    "Mankson se hacerca a la barra, se toma un chupito y vuelve a su mesa\n",
    "Mankson se acerca a ti, te amenaza con una silla y se va riendose entre dientes.\n"}));
}
private int Es_Npc(object mon) {
  return (mon->QueryIsNPC() && mon!=TO);
}

public varargs int DoDamage (int dmg, int type, int gentle, mixed xtras) {
  int i;
  object *npcs;

  npcs = filter(deep_inventory(environment(TO)),SF(Es_Npc));

  if(sizeof(npcs)) {
    for(i=0;i<sizeof(npcs);i++){
      npcs[i]->Kill(TP || PO);
    }//finalizo el for AQUI [maler]
  }
  if(TO->QueryHP()==TO->QueryMaxHP()) write("Alguien grita: ¡PELEA!\n");
  return ::DoDamage(dmg, type, gentle, xtras);
}
