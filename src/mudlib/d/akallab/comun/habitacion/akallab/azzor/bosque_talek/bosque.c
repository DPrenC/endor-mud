/*
DESCRIPCION  : Habitacion base del bosque de Talek
FICHERO      : bosque.c
MODIFICACION : 11-02-99 [Angor@Simauria] Creacion
               19-02-00 [Angor@Simauria] Uso de bosque_base
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_BASE;

create()
{
    SetNombreBosque("de Talek");
    ::create();
   AddDetail(({"bosque","bosque de Talek"}),"Es un inmenso bosque que se "
        "extiende en la parte suroeste del valle de Azzor, hasta el mismo "
        "pie de las montañas. Es un bosque denso y algo sombrío. El Camino "
        "del Este lo atraviesa de este a oeste.\n");
    SetLocate("bosque de Talek");
}
