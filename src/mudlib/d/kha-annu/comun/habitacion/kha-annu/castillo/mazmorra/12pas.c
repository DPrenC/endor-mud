#include "./path.h"
#include <properties.h>
#include <materials.h>
#include <sounds.h>

inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el pasillo de las celdas");
    SetIntLong("Continúas hasta la siguiente puerta. Hay otra celda al norte.\nVes mas puertas "
        "al este y al oeste.\nHay unas manchas de sangre muy seca en la pared.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("No oyes nada, lo que se dice nada.\n");
    SetIntSmell("Empiezas a acostumbrarte a la humedad.\n");
    AddDetail(({"manchas","sangre","mancha"}),"Quedan restos de sangre en la pared, parece que "
        "hubiera habido una lucha por aquí.\n");
    AddExit("este",("13pas"));
    AddExit("oeste",("11pas"));
    AddExit("norte","./celda8");
    AddDoor("norte","la puerta de la celda",
        "Es una puerta de hierro totalmente lisa.\n",
        ({"puerta","puerta de celda","puerta de la celda"}),2,
        ([P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("las mazmorras");
}
