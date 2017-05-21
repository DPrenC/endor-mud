/*********************************************************/
//		"spirit"
//	espíritus invocados por los shamanes
//		11-12-01: Kodex-> creación
//		11-12-01: Kodex-> última modificación
/*********************************************************/

#include <properties.h>
#include "./path.h"
#include <rooms.h>
#include <gremios.h>


inherit NPC;


create()
{
::create();
SetStandard("espíritu","orco",([GC_LUCHADOR: random(5)+ 26]),GENERO_MASCULINO);
SetMaxHP(100);
SetHP(100);
SetShort("un espíritu orco");
SetLong(W("Es el espíritu de un orco, apenas puedes distinguirle."
" Parece una de las malignas obras de los "
"chamanes orcos, despertar a los espíritus de su descanso eterno.\n"));
SetIds(({"orco","espiritu","espíritu"}));
SetAggressive(0);
SetAlign(-150);
SetCorpse(OBJETO_AZMODAN("craneo"));
}

public varargs void Die(mixed silent)
{
tell_room(environment(TO),"Un cráneo orco cae al suelo.\n");
SetWeight(1500);
AddId(({"craneo"}));
AddId(({"cráneo"}));
AddId(({"cráneo orco"}));
AddId(({"craneo orco"}));
RemoveId(({"orco"}));
RemoveId(({"espiritu"}));
RemoveId(({"espíritu"}));
::Die(silent);
}
