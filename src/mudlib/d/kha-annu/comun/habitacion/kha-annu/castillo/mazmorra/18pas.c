#include "path.h"
#include <properties.h>
#include <materials.h>
#include <sounds.h>

inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el pasillo de las celdas");
    SetIntLong("Continúas hasta la siguiente puerta.\nEs como las anteriores puertas, nada de "
        "especial. El muro está totalmente desnudo.\nAl norte ves una especie de jaula en el "
            "corredor y al sur otra puerta del pasillo.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("No oyes nada en especial.\n");
    SetIntSmell("Huele a ... ¿Nada?. Siempre la humedad.\n");
    AddDetail(({"muro","muros"}),"Están totalmente desnudos, y son demasiado sólidos para "
        "atravesarlos.\n");
    AddExit("norte",("17pas"));
    AddExit("sur",("19pas"));
    AddExit("este","./celda13");
    AddDoor("este","la puerta de la celda",
        "Es una puerta de hierro totalmente lisa.\n",
        ({"puerta","puerta de celda","puerta de la celda"}),2,
        ([P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("las mazmorras");
}
