#include "./path.h"
#include <colours.h>
#include <moving.h>
inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("la posada del Dragón Azul");
    SetIntLong("Esta parte de la posada es únicamente para el descanso de los viajeros, y "
        "queda terminantemente prohibido usar las habitaciones para otro tipo de actividades "
        "que no sea la de recuperarse.\n");
    SetIntBright(70);
    SetIndoors(1);
    SetLocate("ciudad de Kha-annu");
    AddDetail(({"alfombra","gran alfombra"}),"La alfombra cubre el pasillo y seguramente las "
        "habitaciones.\n");
    AddDetail(({"escalera","escaleras"}),"Están construidas en piedra y cubiertas por la "
        "alfombra.\nLlevan al primer piso.\n");
    AddExit("pasillo","pasillo1");
    AddExit("abajo","posada");
}
