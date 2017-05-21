/*********************************************************/
//		"spirit"
//	esp�ritus invocados por los shamanes
//		11-12-01: Kodex-> creaci�n
//		11-12-01: Kodex-> �ltima modificaci�n
/*********************************************************/

#include <properties.h>
#include "./path.h"
#include <rooms.h>
#include <gremios.h>


inherit NPC;


create()
{
::create();
SetStandard("esp�ritu","orco",([GC_LUCHADOR: random(5)+ 26]),GENERO_MASCULINO);
SetMaxHP(100);
SetHP(100);
SetShort("un esp�ritu orco");
SetLong(W("Es el esp�ritu de un orco, apenas puedes distinguirle."
" Parece una de las malignas obras de los "
"chamanes orcos, despertar a los esp�ritus de su descanso eterno.\n"));
SetIds(({"orco","espiritu","esp�ritu"}));
SetAggressive(0);
SetAlign(-150);
SetCorpse(OBJETO_AZMODAN("craneo"));
}

public varargs void Die(mixed silent)
{
tell_room(environment(TO),"Un cr�neo orco cae al suelo.\n");
SetWeight(1500);
AddId(({"craneo"}));
AddId(({"cr�neo"}));
AddId(({"cr�neo orco"}));
AddId(({"craneo orco"}));
RemoveId(({"orco"}));
RemoveId(({"espiritu"}));
RemoveId(({"esp�ritu"}));
::Die(silent);
}
