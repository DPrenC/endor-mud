/*   arena de playa
     Creado por : Cheto
     Fecha : 16-Nov-98
*/

#include <properties.h>
inherit THING;

create() {
::create();
SetShort("Vidrio soplado");
SetLong(
"Es un vidrio soplado con forma de copa, es realmente hermoso, pero\n"
"parece inacabado, necesitas mas elementos para completar\n"
"la copa."
"\n");
AddId(({"vidrioq","vidrio"}));
Set(P_NOGIVE, 1);
Set(P_NODROP, 1);
Set(P_NOSELL,1);
Set(P_NOGET,1);
SetWeight(50);
SetValue(500);
Set(P_NOSELL,1);
}
