/*   arena de playa
     Creado por : Cheto
     Fecha : 16-Nov-98
*/

#include <properties.h>
inherit THING;

create() {
::create();
SetShort("metal sin forma");
SetLong(
"Es un trozo de piedra de un material metálico muy vistoso "
"y tremendamente valioso.\n"
"\n");
AddId(({"metalq","metal"}));
Set(P_NODROP, 1);
Set(P_NOSELL,1);
Set(P_NOGET,1);
SetWeight(50);
SetValue(500);
Set(P_NOSELL,1);
}
