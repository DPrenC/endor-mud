#include <mud.h>
#include <money.h>
#include <combat.h>
#include <properties.h>
#include <rooms.h>

inherit NPC;

object arma;

create() {
  ::create();
SetName("Dulan");
AddAdjective("fuerte");
AddId("herrero");
SetNoGet(1);
SetShort("el herrero Dulan.");
SetLong("El Herrero es un engendro de la naturaleza, repleto de músculos y tatuajes sugestivos...\n");
SetRace("humano");
SetWeight(100000);
SetLevel(20);
SetStr(25);
SetDex(22);
SetGender(1);// 1 masculino, 2 femenino
SetAlign(0);
SetMaxHP(90);
SetHP(90);
arma=clone_object("/std/weapon");
arma->SetStandard(WT_MAZA, 12, P_SIZE_MEDIUM, M_ACERO);
arma->Set(P_SHORT, "un martillo pesado");
arma->Set(P_LONG, "Un enorme martillo de acero, fuerte y eficaz.\n");
AddItem(arma, REFRESH_REMOVE, SF(wieldme));

}

