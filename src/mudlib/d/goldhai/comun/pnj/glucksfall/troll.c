#include "./path.h"
#include <skills.h>
#include <properties.h>
inherit NPC;

create () {
  ::create();
seteuid(getuid());
 SetStandard("un troll","troll",([GC_LUCHADOR:40+random(5)]),GENERO_MASCULINO);
 SetIds(({"troll"}));
 SetShort("un troll");
 SetAlign(-20);
 SetWhimpy(0); // O mata o muere
 SetAggressive(1);

 AddItem(ARMA("maza_madera"),REFRESH_REMOVE,SF(wieldme));
 AddItem(ARMA("maza_madera"),REFRESH_REMOVE,SF(wieldme));
}

//mixed SetCombatDelay(int time, string s) { return ::SetCombatDelay(to_int(time/2),s);}