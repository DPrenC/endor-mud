/* Coded by Yandros to Aurora MUD.
   Modificado por [i] Izet@Simauria para implementar a Nightfall(tm).
   Ultima modificacion: 5 Oct, 1997.
*/

#include "path.h"
#include <properties.h>
#include <materials.h>
inherit KHA_ROOM;

create() {
   ::create();
SetIntShort("el noroeste del patio");
SetIntLong(
"Estas en la parte noroeste del patio. En esta parte no hay columnas ni arcos.\n\
Hacia el sudoeste puedes ver un portal que conduce a las escaleras hacia el "
"segundo piso del palacio, y ante ti se alza una de las torres de defensa del "
"castillo Kha-annu.\n");

SetIntBright(80);

    AddExit("sudeste", PISO1+"patio3");
    AddExit("norte",PISO1+"torre2_1");
    AddDoor("norte","la puerta de la torre",
        "Es una gruesa puerta de madera que comunica el patio con una de las torres.\n",
        ({"puerta","puerta gruesa","puerta de madera","puerta de torre"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));

AddDetail("escaleras",
"Solo son las escaleras de caracol que suben a la torre. No tienen nada en "
"especial.\n");
AddDetail(({"arco","arcos"}),
"Los arcos unen las enormes columnas de este patio.\n");
AddDetail(({"columna","columnas"}),
"Inmensas columnas se alzan sobre toda la superficie del patio. Tienen unos "
"viejos y extranyos grabados que no puedes descifrar.\n");
}