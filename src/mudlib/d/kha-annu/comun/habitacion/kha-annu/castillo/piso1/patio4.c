/* Coded by Yandros to AURORA MUD.
   Modificado por [i] Izet@Simauria para implementar en Nightfall.
   2, Oct 1997.
 */
#include "path.h"
inherit KHA_ROOM;
#include "ruidos.h"

create() {
   ::create();

SetPreIntShort("a");
SetIntShort("el oeste del patio");
SetIntLong(
"Has llegado a la parte oeste del patio. Siempre ves columnas alzandose ante "
"ti y los mismos lujosos arcos uniendolas. Continuando hacia el oeste, termina "
"el patio y empieza un corredor que conduce a las escaleras hacia el segundo "
"piso del Castillo Kha-annu.\n");

SetIntBright(70);

AddExit("norte", PISO1+"patio3");
AddExit("sur", PISO1+"patio5");
AddExit("oeste", PISO1+"stair1");
AddExit("este", PISO1+"patio2");

AddDetail(({"arco","arcos"}),
"Los arcos unen las enormes columnas de este patio.\n");
AddDetail(({"columna","columnas"}),
"Inmensas columnas se alzan sobre toda la superficie del patio. Tienen unos "
"viejos y extranyos grabados que no puedes descifrar.\n");
}