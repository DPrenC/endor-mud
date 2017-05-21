/****************************************************************************
Fichero: arena6.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
    SetIntLong("Aquí la isla se adentra un poco en el lago, creando un saliente "
               "natural que se extiende en dirección oeste. La tierra, forma "
               "una ligera pendiente, que da a parar al agua. Hacia el resto "
               "de direcciones te adentras más en el bosque.\n");

    AnadeDetalleLago("sur");

    AddExit("oeste","arena5");
    AddExit("norte","arena8");
    AddExit("noroeste","arena7");

}


