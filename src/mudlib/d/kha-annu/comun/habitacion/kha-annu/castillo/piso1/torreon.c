#include "path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>

inherit KHA_ROOM;

create() {
    ::create();
    SetIntShort("el torreón del castillo");
    SetIntLong("Has entrado en el gran torreón del castillo de Kha-annu. Las "
        "paredes están hechas de puro granito y unas enormes antorchas "
        "iluminan unas escaleras de caracol que suben a lo alto de la torre.\n"
        "Sientes frío aquí.\n");
    SetIntBright(90);
    SetIndoors(1);
    AddExit("arriba", PISO1+"torreon1");
    AddExit("norte", PISO1+"patio2");
    AddDoor("norte","la puerta del patio",
        "Es una puerta de madera sin trabajar.\nConduce al patio.\n",
        ({"puerta","puerta de patio","puerta del patio","puerta de madera"}), GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));
    AddDetail(({"vela","velas","antorcha","antorchas"}),"Unas grandes "
        "antorchas sujetas en las paredes iluminan el torreón.\n");
    AddDetail(({"pared","paredes"}),"Las paredes son antiguas, pero sólidas y "
        "resistentes.\n");
    AddDetail(({"escalera","escaleras"}),"Unas estrechas escaleras de "
        "caracol recorren de arriba a abajo este enorme torreón.\n");
}
