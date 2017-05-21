/*   licencia de pescar
     Creado por : Cheto
     Fecha : 16-Nov-98
*/

#include <properties.h>
inherit THING;

create() {
::create();
SetShort("licencia para pescar");
SetLong("Es una licencia de pescar, necesaria para pescar en Simauria.\n");
AddId(({"licencia","qlicencia"}));
Set(P_NOGIVE, 1);
Set(P_NODROP, 1);
Set(P_NOSELL,1);
SetWeight(100);
SetValue(50);
Set(P_NOSELL,1);
}
