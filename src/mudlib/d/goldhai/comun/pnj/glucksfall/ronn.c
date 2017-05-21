#include "./path.h"
#include <skills.h>
#include <properties.h>



inherit NPC;

create () {
  ::create();
seteuid(getuid());
 SetStandard("Ronn","gigante",([GC_NINGUNO:60]),GENERO_MASCULINO);
 SetIds(({"gigante"}));
 SetShort("Ronn, el tendero");
 SetAlign(-10);
 SetWhimpy(0); // O mata o muere
 SetAggressive(0);

 AddItem(ARMA("hacha_combate3"),REFRESH_REMOVE,SF(wieldme));
 AddItem(ARMA("cuchillo_cocina"),REFRESH_REMOVE,SF(wieldme));
}

//mixed SetCombatDelay(int time, string s) { return ::SetCombatDelay(to_int(time/3),s);}