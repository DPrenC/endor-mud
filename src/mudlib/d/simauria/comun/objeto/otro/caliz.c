/*   caliz
     Creado por : Cheto
     Fecha : 28-Nov-2001
*/

#include <properties.h>
inherit THING;

create() {
::create();
SetShort("caliz");
SetLong(
"Es un caliz de v�drio con una base de un material extra�o.\n" );
AddId(({"calizq","copa","caliz","c�liz"}));
Set(P_NODROP, 1);
Set(P_NOSELL,1);
Set(P_NOGET,1);
SetWeight(50);
SetValue(500);
Set(P_NOSELL,1);
}
