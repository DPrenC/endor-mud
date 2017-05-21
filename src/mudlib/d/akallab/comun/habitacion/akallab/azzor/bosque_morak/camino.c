/*
DESCRIPCION  : (tipo) camino a traves del bosque de Morak
FICHERO      : camino.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create()
{
    ::create();
   SetIntShort("un camino a través del bosque de Morak");
    SetIntLong("Camino a través del bosque de Morak.\n");
    AddDetail(({"bosque","morak","Morak","bosque de Morak","bosque de morak"}),
        "El bosque de Morak es un bosque de mediano tamaño que se extiende "
        "en la parte norte del valle de Azzor, hasta el mismo pie de la "
        "cordillera de Kova. Es un bosque no muy denso del que los orcos, "
        "principalmente los del cercano pueblo de Gaddaro, extraen madera. "
        "Al norte del bosque, al pie de las montañas se halla una cantera.\n");
    AddDetail(({"cantera"}),"Al norte de este bosque de Morak, al pie de la "
        "cordillera de Kova, se halla una cantera de la que los orcos "
        "extraen rocas.\n");
    AddDetail(({"camino"}),QueryIntLong());
    SetIntNoise("Sopla una suave brisa desde el sur.\n");
    SetIntSmell("Hueles el fresco aroma del campo.\n");
    SetLocate("valle de Azzor");
    SetIndoors(0);
}
