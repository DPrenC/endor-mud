#include "./path.h"
#include <properties.h>
#include <materials.h>
#include <sounds.h>

inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el pasillo de las celdas");
    SetIntLong("Las puertas empiezan a parecerte todas iguales.\nVes que te aproximas a otro "
        "recodo.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("Unos quejidos de mujer parecen salir de la celda.\n");
    SetIntSmell("Aquí también huele bastante mal.\n");
    AddDetail(({"reja"}),"Parece que hay alguien en las sombras de la celda.\n");
    AddExit("norte",("10esqui"));
    AddExit("sur",("8pas"));
    AddExit("oeste","./celda6");
    AddDoor("oeste","la puerta de la celda",
        "Es una puerta de hierro, con una pequeña reja.\n",
        ({"puerta","puerta de celda","puerta de la celda"}),2,
        ([P_DOOR_TRANSPARENCY:1,P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("las mazmorras");
}
