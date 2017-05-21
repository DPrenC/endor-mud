/****************************************************************************
Fichero: arena_base.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena base para el gremio de las Kisalas
****************************************************************************/

#include "path.h"
#include <gremios.h>
#include <nightday.h>
#include <moving.h>

inherit ROOM;

private string escuchar()
{
    switch(QueryServer()->QueryState())
    {
        case ND_NIGHT:
        case ND_PREDAWN:
             return "Escuchas el canto de los grillos, el ulular del viento entre "
                    "los árboles, y a lo lejos, el ocasional aullido de algún lobo.\n";
             break;
        case ND_DAWN:
             return "Escuchas el canto de algunos pájaros, cada vez más, a medida "
                    "que la mañana avanza y van despertando.\n";
                    break;
        case ND_SUNRISE:
        case ND_PRENOON:
        case ND_DAY:
             return "Escuchas una mezcla de ruidos: los pájaros, el susurro del viento, "
                    "el grito de algún animal al ser apresado por otro animal... Lo "
                    "normal de un bosque en plena actividad.\n";
             break;
        case ND_PREFALL:
        case ND_FALL:
             return "Escuchas algún que otro grillo cantar, SE nota que la noche ya "
                    "está cerca.\n";
             break;
        case ND_PRENIGHT:
             return "Escuchas el susurro del viento, y algunos sonidos extraños "
                    "que no eres capaz de definir. Todo el bosque te da la sensación de "
                    "algo contenido, como si fuese a ocurrir algo que romperá "
                    "esta extraña calma.\n";
             break;
    }
    return "No escuchas nada.\n"; // [Nyh] Para evitar el warning de no return
}

create()
{
    ::create();
    SetIntShort("el bosque de entrenamiento de las Kisalas");
    SetIntNoise(SF(escuchar));
    SetLocate("la zona de entrenamiento de las Kisalas");
    SetIndoors(0);
}

public int allow_enter(int method, mixed extra)
{
    object prev = PO;
    if (!prev || !interactive(prev)) return ::allow_enter(method, extra);
    if (prev->QueryGuild()!=GC_KISALAS && !query_wiz_level(prev))
    {
      tell_object(prev,"No se permite el acceso a los jugadores que no "
                       "sean kisalas.\n");
        return ME_NO_ENTER;
    }
    return ::allow_enter(method, extra);
}
