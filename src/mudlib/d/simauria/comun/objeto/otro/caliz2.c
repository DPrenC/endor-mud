/*   caliz2
     Creado por : Cheto
     Fecha : 28-Nov-2001
*/

#include <properties.h>
inherit THING;

create() {
::create();
SetShort("caliz tallado");
SetLong(
"Es un caliz de vídrio con una base de un material extraño. "
"Ves que el vidrio del caliz está tallado con unas runas.\n" );
AddId(({"caliz2q","copa","caliz","cáliz"}));
Set(P_NODROP, 1);
Set(P_NOSELL,1);
Set(P_NOGET,1);
SetWeight(50);
SetValue(50000);
Set(P_NOSELL,1);
}
