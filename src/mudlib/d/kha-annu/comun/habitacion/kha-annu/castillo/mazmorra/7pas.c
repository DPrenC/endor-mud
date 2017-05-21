#include "./path.h"
#include <properties.h>
#include <materials.h>
#include <sounds.h>

inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el pasillo de las celdas");
    SetIntLong("Avanzas hasta la primera celda, que está al oeste.\nPuedes ver que hay mas "
        "puertas en el pasillo, al sur hay una esquina.\n");
    SetIndoors(1);
    SetIntNoise("No oyes nada, excepto tu respiración.\n");
    SetIntSmell("Un hilillo de humedad se cuela por tu nariz.\n");
    AddDetail(({"muro","muros"}), "Tienen una pinta muy sólida, no crees que puedas "
        "atravesarlos.\n");
    AddExit("norte",("8pas"));
    AddExit("sur",("6esquina"));
    AddExit("oeste","./celda4");
    AddDoor("oeste","la puerta de la celda",
        "Es una puerta de hierro, muy parecida al resto, pero no tiene rejas.\n",
        ({"puerta","puerta de celda","puerta de la celda"}),2,
        ([P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("Kha-annu");
}
