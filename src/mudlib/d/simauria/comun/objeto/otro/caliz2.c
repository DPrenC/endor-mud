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
"Es un caliz de v�drio con una base de un material extra�o. "
"Ves que el vidrio del caliz est� tallado con unas runas.\n" );
AddId(({"caliz2q","copa","caliz","c�liz"}));
Set(P_NODROP, 1);
Set(P_NOSELL,1);
Set(P_NOGET,1);
SetWeight(50);
SetValue(50000);
Set(P_NOSELL,1);
}
