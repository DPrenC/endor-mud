#include "./path.h"
#include <skills.h>
#include <properties.h>


inherit NPC;

create () {
  ::create();
seteuid(getuid());
 SetStandard("Sapor","troll",([GC_LUCHADOR:60]),GENERO_MASCULINO);
 SetIds(({"sapor","troll"}));
 SetShort("Sapor el guerrero");
 SetAlign(-100);
 SetWhimpy(0); // O mata o muere

 AddItem(ARMA("maza_hierro"),REFRESH_REMOVE,SF(wieldme));
 AddItem(ARMA("maza_hierro"),REFRESH_REMOVE,SF(wieldme));
 AddItem(PROT("botas-negras"),REFRESH_REMOVE,SF(wearme));
 AddItem(PROT("coraza-acero"),REFRESH_REMOVE,SF(wearme));
 AddItem(PROT("guantes-metal"),REFRESH_REMOVE,SF(wearme));
 SetAggressive(2);
}

//mixed SetCombatDelay(int time, string s) { return ::SetCombatDelay(to_int(time/3),s);}