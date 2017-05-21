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
        "apetecería vivir aquí.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("¡Qué silencio!\n");
    SetIntSmell("Yo de ti no olería. Apesta.\n");
    AddDetail(({"reja"}),"Está tapada por una chapa.\n");
    AddExit("sur","./5pas");
    AddDoor("sur","la puerta del pasillo",
        "Es una puerta de hierro que tiene una pequeña reja.\n",
        ({"puerta","puerta del pasillo","puerta de pasillo"}),
        ([P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("las mazmorras");
}
