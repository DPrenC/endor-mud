/* Coded by Yandros to Aurora MUD.
   Modificado por [i] Izet@Simauria, para implementar a Nightfall(tm).
   Ultima modificacion: 10 Otc, 1997.
 */
#include "path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>

inherit KHA_ROOM;

create() {
   ::create();
SetIntShort("la torre del Noroeste, planta baja");
SetIntLong(
"Has entrado a la Torre del Noroeste del Castillo Kha-annu. Esta torre, como "
"la Torre del Nordeste, es usada como defensa a los posibles ataques al "
"castillo. Unas escaleras conducen a la parte alta de la torre donde hay "
"situado un puesto de vigilancia.\n");

SetIntBright(100);

SetIndoors(1);

    AddExit("arriba", PISO1+"torre2_2");
    AddExit("sur",PISO1+"patio10");
    AddDoor("sur","la puerta del pattio",
        "Es la puerta que conduce al patio del castillo. Es muy gruesa, y "
            "está hecha de madera.\n",
        ({"puerta","puerta de patio","puerta del patio","puerta de madera",
        "puerta gruesa"}), GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));

AddDetail(({"escalera","escaleras"}),
"Unas viejas escaleras conducen al puesto de vigilancia de arriba.\n");
AddDetail("torre","Estas en la Torre Noroeste.\n");
}
