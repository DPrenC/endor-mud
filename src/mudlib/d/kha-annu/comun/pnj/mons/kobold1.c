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
  seteuid(getuid(TO));
  SetAlign(-200);
  SetIds(({"kobold"}));
  SetAds(({"el"}));
  SetHands( ({ ({"mano derecha",0,2}),({"mano izquierda",1,2}) }) );
  SetWeight(36000);

  InitChats(1,({
    "El kobold gruñe.\n",
    "El kobold emite sonidos extraños.\n",
    "El kobold te mira fijamente con sus ojos saltones.\n"}));

 ob=clone_object("/std/weapon");
 ob->SetStandard(WT_MAZA, 6, P_SIZE_MEDIUM, M_MADERA);
 ob->AddId("garrote");
 ob->SetShort("garrote");
 ob->SetLong("Es un queño garrote con una piedra atravesada en la punta.\n");
 AddItem(ob,REFRESH_REMOVE,SF(wieldme));

 ob=clone_object("std/armour");
 ob->SetStandard(AT_TROUSERS, 2, P_SIZE_MEDIUM, M_CUERO);
 ob->AddId("taparrabos");
 ob->SetShort("taparrabos de cuero");
 ob->SetLong("Un taparrabos de cuero andrajoso para cubrir las partes intimas.\n");
 AddItem(ob,REFRESH_REMOVE,SF(wearme));

}

// llama a unos kobolds mas cuando se muere
// gracias a izet y a uzi por aguantarme
public varargs void Die(mixed silent)
{
int i,n;
object npc;
write("El kobold emite un chillido estridente que resuena por todas partes.\n");
n=random(6);

for(i=0;i<n;i++)
{
         npc=clone_object(MONS2+"kobold2");
          npc->move(environment(TP));
           npc->Kill(TP || PO);
}
	::Die(silent);

}
