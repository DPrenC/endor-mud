/*
DESCRIPCION  : Habitacion base del bosque de Morak
FICHERO      : bosque.c
MODIFICACION : 18-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_BASE;

create()
{
    SetNombreBosque("de Morak");
    ::create();
   AddDetail(({"bosque","bosque de Morak"}),"Es un bosque de mediano tamaño "
        "que se extiende en la parte norte del valle de Azzor, hasta el "
        "mismo pie de la cordillera de Kova. Es un bosque no muy denso del "
        "que los orcos, principalmente los del cercano pueblo de Gaddaro, "
        "extraen madera. Al norte del bosque, al pie de las montañas, se "
        "halla una cantera.\n");
    SetLocate("bosque de Morak");
}
