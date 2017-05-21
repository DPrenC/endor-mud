/* Coded by Yandros to AURORA MUD.
   Modificado por [i] Izet@Simauria para implementar en Nightfall(tm).
   Ultima modificacion: 4, Sep 1997.
*/

#include "path.h"
inherit KHA_ROOM;

create() {
   ::create();
SetIntShort("el noreste del patio");

SetIntLong(
"Estas en la parte noreste del patio. Las columnas unidas por los preciosos "
"arcos tallados a mano se dispersan por toda la superficie del patio. Hacia el "
"sudeste ves un portal que conduce a las escaleras de subida a las habitaciones reales "
"del palacio y al noreste se alza una de las torres defensivas del Castillo "
"Kha-annu.\n");

SetIndoors(0);

SetIntBright(80);
AddExit("sur", PISO1+"patio7");
AddExit("oeste", PISO1+"patio1");
AddExit("nordeste", PISO1+"patio9");

AddDetail(({"arco","arcos"}),
"Los arcos unen las enormes columnas de este patio.\n");
AddDetail(({"columna","columnas"}),
"Inmensas columnas se alzan sobre toda la superficie del patio. Tienen unos "
"viejos y extranyos grabados que no puedes descifrar.\n");
}