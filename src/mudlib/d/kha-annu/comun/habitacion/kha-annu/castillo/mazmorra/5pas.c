#include "./path.h"
#include <properties.h>
#include <materials.h>
#include <sounds.h>

inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el pasillo de las celdas");
    SetIntLong("Avanzas hasta la siguiente puerta, que también queda al norte.\nAl este queda "
        "el pasillo con mas celdas, al oeste parece que hay una esquina. Los muros no tienen "
        "ni un desperfecto.\n");
    SetIndoors(1);    
    SetIntBright(10);
    SetIntNoise("Oyes ruidos en la celda que queda a el este.\n");
    SetIntSmell("Huele bastante mal, parece que viene del este.\n");
    AddDetail(({"muro","muros"}),"Son muros perfectos, como toda la mazmorra.\n");
    AddDetail(({"reja"}),"Está tapada, no puedes ver nada.\n");
    AddExit("este","./4pas");
    AddExit("oeste","./6esquina");
    AddExit("norte","./celda3");
    AddDoor("norte","la puerta de la celda",
        "Es una puerta de hierro que tiene una pequenya reja.\n",
        ({"puerta","puerta de celda","puerta de la celda"}),2,
        ([P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("las mazmorras");
}
