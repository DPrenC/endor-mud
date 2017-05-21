
#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit SIM_ROOM;
create () {
    ::create();
  SetLocate("Gorat");
  SetIntShort("la calle principal de Gorat");
  SetIntLong("Estás casi al final de la calle principal del pequeño pueblo de Gorat.\n "
  "La calle continúa recta y larga hacia el oeste donde comienza en el puerto. "
  "En el norte tienes el banco, mientras que al sur te encuentras con el ayuntamiento "
  "del pueblo.\n");
    SetIndoors(0);
    AddExit("este", "./callep7");
    AddExit("oeste","./callep5");
    AddExit("norte","../tiendas/bancoh");
    AddExit("sur","../tiendas/ayuntamiento");
    AddDoor("norte", "la puerta del banco",
    "Es la puerta para entrar al banco.\n",
    ({"puerta del banco", "puerta del norte", "puerta"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddDoor("sur", "la puerta del ayuntamiento",
    "La puerta para entrar al edificio del ayuntamiento.\n",
    ({"puerta", "puerta del sur", "puerta del ayuntamiento"}),
    ([P_DOOR_CLOSE_TIME : ({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE})]));
    AddItem(GORPNJ("mujer"), REFRESH_DESTRUCT, d2());
    AddItem(GORPNJ("ciudadan"), REFRESH_DESTRUCT, d2());
}
