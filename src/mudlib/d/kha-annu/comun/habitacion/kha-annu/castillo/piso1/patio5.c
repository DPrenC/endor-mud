/* Coded by Yandros to AURORA MUD.
   Modificado por [i] Izet@Simaria, para implementar al Castillo Kha-annu.
   4, Oct 1997.
*/

#include "path.h"
#include <properties.h>
#include <materials.h>
inherit KHA_ROOM;

create() {
   ::create();
SetIntShort("el suroeste del patio");

SetIntLong(
"Te encuentras en la parte suroeste del patio. Ves como unos decorativos arcos "
"unen las inmensas columnas que se reparten por el patio. Hacia el oeste "
"comienza un corredor que lleva a las escaleras las cuales conducen a las "
"habitaciones reales situadas en la segunda planta del Castillo Kha-annu.\n");

    SetIndoors(0);
    SetIntBright(80);
    AddExit("norte", PISO1+"patio4");
    AddExit("sudeste", PISO1+"vigila");
    AddExit("oeste",PISO1+"bano");
    AddDoor("oeste","la puerta de los baños",
        "Es una pequeña puerta de madera , bastante descuidada, que conduce a "
            "los baños.\n",
        ({"puerta","puerta de madera","puerta pequeña","puerta pequenya",
            "puerta de baños","puerta de banyos"}),2,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED,P_DOOR_DEFAULT_IN_RESET:1]));

AddDetail(({"arco","arcos"}),
"Los arcos unen las enormes columnas de este patio.\n");
AddDetail(({"columna","columnas"}),
"Inmensas columnas se alzan sobre toda la superficie del patio. Tienen unos "
"viejos y extranyos grabados que no puedes descifrar.\n");
}