/* Coded by Yandros to AURORA MUD.
   Modificado por [i] Izet@Simauria, 29-Sep-1997.
   Modificado por woo ya que no iba del todo bien.
Modificado por Yalin, adaptado al nuevo sistema de puertas, y corregido el
sangrado y los acentos, melones. 21/04/2007.
*/

#include "path.h"
#include <properties.h>
#include <materials.h>
inherit KHA_ROOM;

create() {
    ::create();
    SetIntShort("el centro del patio");
    SetIntLong("Estás justo en medio del patio del Castillo de Kha-annu. "
        "Desde aquí puedes ver el cielo y elevándose hacia él las dos torres "
        "de guardia y la torre central del palacio.\n");
    SetIntBright(80);
    AddExit("norte", PISO1+"patio1");
    AddExit("este", PISO1+"patio7");
    AddExit("oeste", PISO1+"patio4");
    AddExit("sur", PISO1+"torreon");
    AddDoor("sur","la puerta del torreón",
        "Es una gruesa puerta de madera sin tallar, que conduce al torreón.\n",
        ({"puerta","puerta gruesa","puerta de madera","puerta de torreon",
            "puerta del torreon","puerta de torreón","puerta del torreón"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));
    AddDetail(({"jardin","jardines"}), "Un precioso jardín queda al norte.\n");
    AddDetail(({"arco","arcos"}), "Los arcos sólo unen las columnas del "
        "patio.\n");
    AddDetail(({"columna","columnas"}),"Unas inmensas columnas se alzan por "
        "toda la superficie del patio.\nTienen escritos viejos grabados que "
        "no puedes descifrar.\n");
}
