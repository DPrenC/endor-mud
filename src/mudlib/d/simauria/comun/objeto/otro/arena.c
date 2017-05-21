/*   arena de playa
     Creado por : Cheto
     Fecha : 16-Nov-98
*/

#include <properties.h>
inherit THING;

create() {
::create();
SetShort("Arena de playa");
SetLong(
"Es arena de la playa del islote de Gorat, tiene un color especialmente\n"
"blanco, es una arena tremendamente fina.\n");
AddId(({"arenaq","arena","arena de playa"}));
Set(P_NODROP, 1);
Set(P_NOSELL,1);
SetWeight(10);
SetValue(50);
Set(P_NOSELL,1);
}
