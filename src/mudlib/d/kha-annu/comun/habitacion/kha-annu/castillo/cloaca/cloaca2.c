// Coded by Kayra.
// Modificado por Izet@Simauria para implementar a las minas de Kha-annu.

#include "./path.h"
inherit KHA_ROOM;
#include "sticks.h"

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntLong("El corredor es algo más estrecho aquí. No ves nada aparte de tus manos y tu "
        "nariz.\n");
    SetIndoors(1);
    SetIntBright(30);
    AddDetail("suelo", "Ves restos de comida por el suelo.\n");
    AddExit("norte",CLOACAS+"cloaca3");
    AddExit("sur",CLOACAS+"cloaca1");
}
