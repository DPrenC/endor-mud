/*   base de la copa
     Creado por : Cheto
     Fecha : 28-Nov-2001
*/

#include <properties.h>
inherit THING;

create() {
::create();
SetShort("base de la copa");
SetLong(
"Es una base para un cáliz tallado a mano, realmente hermoso\n"
"y tremendamente valioso.\n" );
AddId(({"baseq","base", "base de la copa"}));
Set(P_NODROP, 1);
Set(P_NOSELL,1);
Set(P_NOGET,1);
SetWeight(50);
SetValue(500);
Set(P_NOSELL,1);
}
