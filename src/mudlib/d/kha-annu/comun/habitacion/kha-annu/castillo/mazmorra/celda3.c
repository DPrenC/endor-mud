#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("una celda");
    SetIntLong("La celda no es gran cosa, tiene un camastro al fondo y una escupidera. No te "
        "apetecer�a vivir aqu�.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("�Qu� silencio!\n");
    SetIntSmell("Yo de ti no oler�a. Apesta.\n");
    AddDetail(({"reja"}),"Est� tapada por una chapa.\n");
    AddExit("sur","./5pas");
    AddDoor("sur","la puerta del pasillo",
        "Es una puerta de hierro que tiene una peque�a reja.\n",
        ({"puerta","puerta del pasillo","puerta de pasillo"}),
        ([P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("las mazmorras");
}
