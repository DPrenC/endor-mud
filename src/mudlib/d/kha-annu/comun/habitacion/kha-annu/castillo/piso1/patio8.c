/* Coded by Yandros to AURORA MUD.
   Modificado por [i] Izet@Simauria para implementar a Nightfall (tm).
   Ultima modificacion: 5 Oct, 1997.
*/
#include "path.h"
inherit KHA_ROOM;
#include "ruidos.h"

create() {
   ::create();
SetIntShort("el sudeste del patio");

SetIntLong(
"Estas en la parte sudeste del patio. La superficie del patio esta poblada por "
"las inmensas columnas y los arcos que las unen. Hacia el este empieza un "
"corredor que conduce a las escaleras que suben a la segunda planta del Castillo "
"Kha-annu.\n");

SetIntBright(80);

AddExit("norte", PISO1+"patio7");
AddExit("este", PISO1+"lavand");
AddExit("suroeste", PISO1+"vigila");

AddDetail(({"arco","arcos"}),
"Los arcos unen las enormes columnas de este patio.\n");
AddDetail(({"columna","columnas"}),
"Inmensas columnas se alzan sobre toda la superficie del patio. Tienen unos "
"viejos y extranyos grabados que no puedes descifrar.\n");
}