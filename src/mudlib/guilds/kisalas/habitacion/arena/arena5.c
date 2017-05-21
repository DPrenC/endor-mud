/****************************************************************************
Fichero: arena5.c
Autor: Kastwey
Fecha: 19/02/2006
Descripci�n: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();

    SetIntLong("Est�s en la parte m�s sure�a de la isla. La tierra se inclina en "
               "suave pendiente, hasta morir en la horilla del lago. Esta "
               "especie de playa se extiende en direcci�n este, mientras que "
               "por las otras direcciones te adentras en el bosque.\n");

    AnadeDetalleLago("sur");

    AddExit("este","arena6");
    AddExit("norte","arena7");
    AddExit("nordeste","arena8");
    AddExit("noroeste","arena4");

}


