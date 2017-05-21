/*
DESCRIPCION  : puente sobre el arroyo del bosque de Morak
FICHERO      : camino09.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("camino");

create()
{
    ::create();
   SetIntShort("un puente sobre el arroyo del bosque de Morak");
    SetIntLong("Te encuentras sobre un puente de piedra. Esta vieja, baja, "
        "ancha y maciza construcción de piedra permite cruzar a las carretas "
        "sobre el pedregoso cauce del arroyo que, atravesando el bosque, "
        "baja desde las montañas de la cordillera de Kova al norte del valle. "
        "Observas cómo el torrente de agua del arroyo avanza rápido e "
        "impetuoso por su irregular cauce.\n");
#include "arroyo.h"
    AddDetail(({"puente"}),"El puente es una vieja, baja, ancha y maciza "
        "construcción de piedra. Bajo su único arco discurre el agua del "
        "arroyo que, desde las montañas del norte, cruza el bosque.\n");
    AddExit("oeste",BOSQUE_MORAK("camino08"));
}
