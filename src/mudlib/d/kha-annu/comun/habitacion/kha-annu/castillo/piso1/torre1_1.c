/* Coded by Yandros to Aurora MUD.
   Modificado por [i] Izet@Simauria, para implementar a Nightfall(tm).
   Ultima modificacion: 10 Otc, 1997.
 */
#include "path.h"
#include <door.h>
#include <sounds.h>
#include <properties.h>


inherit KHA_ROOM;

create() {
   ::create();
SetIntShort("la torre del Nordeste, planta baja");
SetIntLong(
"Has entrado a la Torre del Nordeste del Castillo Kha-annu. Esta torre, como "
"la Torre del Noroeste, es usada como defensa a los posibles ataques al "
"castillo. Unas escaleras conducen a la parte alta de la torre donde hay "
"situado un puesto de vigilancia.\n");

SetIntBright(100);

SetIndoors(1);

    AddExit("arriba", PISO1+"torre1_2");
    AddExit("sur",PISO1+"patio9");
    AddDoor("sur","la puerta del patio",
        "Esta puerta comunica la torre en que te hallas con el patio del "
        "castillo.\nEs de madera, y muy gruesa.\n",
        ({"puerta","puerta de patio","puerta del patio"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));

AddDetail(({"escalera","escaleras"}),
"Unas viejas escaleras conducen al puesto de vigilancia de arriba.\n");
AddDetail("torre","Estas en la Torre Noroeste.\n");
}
