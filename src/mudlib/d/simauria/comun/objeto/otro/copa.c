/*   arena de playa
     Creado por : Cheto
     Fecha : 16-Nov-98
*/

#include <properties.h>
inherit THING;

create() {
::create();
SetShort("copa");
SetLong(
"Es una copa de vidrio, realmente hermosa, realizada en vidrio soplado\n"
"con una base de un extraño metal tallado a mano.\n");
AddId(({"copaq","copa"}));
Set(P_NODROP, 1);
Set(P_NOSELL,1);
Set(P_NOGET,1);
SetWeight(50);
SetValue(500);
Set(P_NOSELL,1);
}
