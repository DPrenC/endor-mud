/*   polvo.c
     Creado por : Nemesis
     Fecha 19-Abr-2001 19:08:12 CEST
     Notas: Un simple puñado de polvo
*/

#include <properties.h>

inherit THING;

create() {
::create();
SetShort("Un montón de polvo");
SetLong("Simplemente un puñado de polvo.\n");
SetWeight(2);
Set(P_NOSELL,1);
AddId(({"polvo","puñado de polvo","montón de polvo"}));
}
