/*   polvo.c
     Creado por : Nemesis
     Fecha 19-Abr-2001 19:08:12 CEST
     Notas: Un simple pu�ado de polvo
*/

#include <properties.h>

inherit THING;

create() {
::create();
SetShort("Un mont�n de polvo");
SetLong("Simplemente un pu�ado de polvo.\n");
SetWeight(2);
Set(P_NOSELL,1);
AddId(({"polvo","pu�ado de polvo","mont�n de polvo"}));
}
