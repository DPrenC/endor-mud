#include "./path.h"
#include <skills.h>
#include <properties.h>


inherit NPC;

create() {
 ::create();
seteuid(getuid());
 SetStandard("un gigante","gigante",([GC_LUCHADOR:40+random(5)]),GENERO_MASCULINO);
 SetIds(({"gigante"}));
 SetShort("un gigante");
 SetAlign(-10);
 SetWhimpy(0); // O mata o muere
// SetKillXP(QueryKillXP()/2+QueryLevel()*QueryLevel()*100);
 AddItem(ARMA("espada-larga"),REFRESH_REMOVE,SF(wieldme));
 AddItem(ARMA("espada-larga"),REFRESH_REMOVE,SF(wieldme));
 SetAggressive(1);
}

//mixed SetCombatDelay(int time, string s) { return ::SetCombatDelay(to_int(time/2),s);}