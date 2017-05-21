/* Coded by Yandros to AURORA MUD.
   Modificado por [i] Izet@Simauria para implementar a Nightfall(tm).
Ultima modificacion: 5 Oct, 1997.
*/

#include "path.h"
inherit KHA_ROOM;
#include "ruidos.h"

create() {
   ::create();
SetIntShort("el este del patio");

SetIntLong(
"Estas en la zona este del patio. Las grandes columnas invaden el patio, y los "
"mismos arcos las unen. Continuando hacia el este termina el patio y comienza "
"un corredor que conduce a unas grandes escaleras.\n");

SetIndoors(0);
SetIntBright(80);

AddExit("norte", PISO1+"patio6");
AddExit("sur", PISO1+"patio8");
AddExit("oeste", PISO1+"patio2");
AddExit("este", PISO1+"stair2");

AddDetail(({"arco","arcos"}),
"Los arcos unen las enormes columnas de este patio.\n");
AddDetail(({"columna","columnas"}),
"Inmensas columnas se alzan sobre toda la superficie del patio. Tienen unos "
"viejos y extranyos grabados que no puedes descifrar.\n");
}