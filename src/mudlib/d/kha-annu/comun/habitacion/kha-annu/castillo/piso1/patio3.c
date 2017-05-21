/* Coded by Yandros to AURORA MUD.
   Modificado por [i] Izet@Simauria, para adaptar a Nightfall.
   2, Oct 1997.
*/
#include "path.h"
inherit KHA_ROOM;

create() {
   ::create();

SetIntShort("el nordeste del patio");
SetIntLong(
"Estas en la parte nordeste del patio. Unas grandes columnas se alzan ante ti "
"y uniendolas ves unos decorativos arcos. Hacia el sudeste ves una portal que "
"parece conducir a unas escaleras que suben a las habitaciones reales del "
"palacio; mientras que al nordeste se alza una de las torres de defensa del "
"Castillo Kha-annu.\n");

SetIntBright(70);
SetIndoors(0);

AddExit("sur", PISO1+"patio4");
AddExit("este", PISO1+"patio1");
AddExit("noroeste", PISO1+"patio10");

AddDetail(({"arco","arcos"}),
"Los arcos unen las enormes columnas de este patio.\n");
AddDetail(({"columna","columnas"}),
"Inmensas columnas se alzan sobre toda la superficie del patio. Tienen unos "
"viejos y extranyos grabados que no puedes descifrar.\n");
}