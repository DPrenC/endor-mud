#include "./path.h"
#include <skills.h>
#include <properties.h>


inherit NPC;

create() {
 ::create();
seteuid(getuid());
 SetStandard("un kainoak","kainoak",([GC_LUCHADOR:40+random(5)]),GENERO_MASCULINO);
 SetIds(({"kainoak"}));
 SetShort("un kainoak");
 SetAlign(-50);
 SetDex(TO->QueryDex()+5);
 SetStr(TO->QueryStr()-5);
 SetWhimpy(0); // O mata o muere

 AddItem(ARMA("espada-larga"),REFRESH_REMOVE,SF(wieldme));
 AddItem(ARMA("espada-larga"),REFRESH_REMOVE,SF(wieldme));
 AddItem(ARMA("espada-larga"),REFRESH_REMOVE,SF(wieldme));
 AddItem(ARMA("espada-larga"),REFRESH_REMOVE,SF(wieldme));

 SetAggressive(1);

}

//mixed SetCombatDelay(int time, string s) { return ::SetCombatDelay(to_int(time/2),s); }