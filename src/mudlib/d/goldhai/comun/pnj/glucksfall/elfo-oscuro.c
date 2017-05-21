#include "./path.h"
#include <skills.h>
#include <properties.h>


inherit NPC;

create () {
 ::create();
seteuid(getuid());
 SetStandard("un elfo oscuro","elfo-oscuro",([GC_LUCHADOR:40+random(5)]),GENERO_MASCULINO);
 SetIds(({"elfo","elfo oscuro"}));
 SetShort("un elfo oscuro");
 SetAlign(-70);
 SetWhimpy(0); // O mata o muere
// SetKillXP(QueryKillXP()/2+QueryLevel()*QueryLevel()*100);
 AddItem(PROT("escudo_acero2"),REFRESH_REMOVE,SF(wearme));
 AddItem(ARMA("espada_corta"),REFRESH_REMOVE,SF(wieldme));
 SetAggressive(1);
 AddItem(PROT("botas-negras"),REFRESH_REMOVE,SF(wearme));
}

//mixed SetCombatDelay(int time, string s) { return ::SetCombatDelay(to_int(time/2),s); }