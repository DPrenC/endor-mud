/*   arena de playa
     Creado por : Cheto
     Fecha : 16-Nov-98
*/

#include <properties.h>
inherit THING;

create() {
::create();
SetShort("LLama imperecedera");
SetLong(
"Es una antorcha que contiene la llama imperecedera encendida\n"
"ten cuidado no se apague o tendrás que volver a conseguirla.\n");
AddId(({"llamaq","llama","llama imperecedera"}));
Set(P_NODROP, 1);
Set(P_NOSELL,1);
SetWeight(10);
SetValue(50);
Set(P_NOSELL,1);
}
