#include "./path.h"
#include <skills.h>
#include <properties.h>



inherit NPC;

create() {
 ::create();
seteuid(getuid());
 SetStandard("un orco","orco",([GC_LUCHADOR:40+random(5)]),GENERO_MASCULINO);
 SetIds(({"orco"}));
 SetShort("un orco");
 SetAlign(-170);
 SetWhimpy(0); // O mata o muere
 SetAggressive(1);

 AddItem(ARMA("hacha_combate"),REFRESH_REMOVE,SF(wieldme));
 AddItem(PROT("yelmo_orco"),REFRESH_REMOVE,SF(wearme));
 AddItem(PROT("escudo_orco"),REFRESH_REMOVE,SF(wearme));
 AddItem(PROT("botas-negras"),REFRESH_REMOVE,SF(wearme));
 AddItem(PROT("coraza-acero"),REFRESH_REMOVE,SF(wearme));
 AddItem(PROT("guantes-metal"),REFRESH_REMOVE,SF(wearme));
}

//mixed SetCombatDelay(int time, string s) { return ::SetCombatDelay(to_int(time/2),s);}