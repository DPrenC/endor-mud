#include "./path.h"
#include <moving.h>
#include <rooms.h>
#include <properties.h>

inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("una celda");
    SetIntLong("La celda no es gran cosa, tiene un camastro al fondo y una escupidera. Ves "
        "restos de Uggly por todas partes, parece que no iba al baño muy a menudo.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("No oyes nada.\n");
    SetIntSmell("Menudo olor a Mierda!!!.\n");
    AddDetail(({"reja"}),"No puedes ver más que la madera que forma el "
        "reverso del cartel que se ve desde fuera.\n");
    AddDetail(({"cama","camastro"}),"Esto esta lleno de mierda entre la paja. "
        "¿Por qué serán tan guarros los orcos?\n");
    AddExit("sur","./4pas");
    AddDoor("sur","la puerta del pasillo",
        "Es una puerta de hierro que tiene una pequeña reja.\n",
        ({"puerta","puerta de pasillo","puerta del pasillo"}));
    AddItem(MONS+"uggly",REFRESH_DESTRUCT,1);
    SetLocate("las mazmorras");
}
