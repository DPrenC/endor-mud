#include "path.h"
#include <guild.h>
#include <combat.h>


inherit NPC;

create() {
  object ob;
       ::create();
  SetStandard("un kobold","kobold",([GC_LUCHADOR: 3]),GENDER_MALE);
  SetShort("Un kobold");
  SetLong("Es un feo kobold que te mira con ojos saltones.\n");
  SetAlign(-200);
  SetIds(({"kobold"}));
  SetAds(({"el"}));
  SetHands( ({ ({"mano derecha",0,2}),({"mano izquierda",1,2}) }) );

  InitChats(1,({
    "El kobold gruñe.\n",
    "El kobold emite sonidos extraños.\n",
    "El kobold te mira fijamente con sus ojos saltones.\n"}));

 ob=clone_object("/std/weapon");
 ob->SetStandard(WT_MAZA, 6, P_SIZE_MEDIUM, M_MADERA);
 ob->AddId("garrote");
 ob->SetShort("Garrote");
 ob->SetLong("Es un queño garrote con una piedra atravesada.\n");
 AddItem(ob,REFRESH_REMOVE,SF(wieldme));

 ob=clone_object("std/armour");
 ob->SetStandard(AT_TROUSERS, 2, P_SIZE_MEDIUM, M_CUERO);
 ob->AddId("taparrabos");
 ob->SetShort("Taparrabos de cuero");
 ob->SetLong("Un taparrabos de cuero andrajoso para cubrir las partes intimas.\n");
 AddItem(ob,REFRESH_REMOVE,SF(wearme));

}

private int Es_Kobold(object mon)
{
	if((mon->QueryRace()=="kobold") && mon!=TO)
	return 1;
	else
	return 0;
}

DoDamage(int dmg)
{

int i;

object *npcs;

npcs = filter(deep_inventory(environment(TO)),SF(Es_Kobold));

if(sizeof(npcs))
for(i=0;i<sizeof(npcs);i++)
npcs[i]->Kill(TP || PO);
return ::DoDamage(dmg);

}

