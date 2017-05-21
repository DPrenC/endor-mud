/****************************************************************************
Fichero: vest4.c
Autor: Riberales
Fecha: 14/02/2006
Descripción: Vestíbulo de las Kisalas. Remodelación espacial total.
Notas: [R] Por no tener no tiene ni fecha, así es que le pongo la de hoy.
****************************************************************************/


#include "path.h"

inherit INTERIOR_BASE;

create()
{
    ::create();
    SetIntShort("el vestíbulo de las Kisalas");
    SetIntLong("Estás en una parte del enorme vestíbulo del Gremio de las "
               "Kisalas. Por las paredes hay muchísimos bajorrelieves que "
               "representan la vida y la historia de la Órden. En el suelo "
               "está grabado un sello con el símbolo de las Kisalas. En el "
               "techo puedes ver muchas espirales fosforescentes que son las "
               "que iluminan la estancia. Al sur se encuentra la entrada del "
               "gremio, mientras que al Norte puedes ver la habitación principal "
               "de la orden.\n");


    AddDetalleGrabados();
    AddDetalleRelieves();

    AddExit("este",AM_VESTIBULO("vest5"));
    AddExit("oeste",AM_VESTIBULO("vest3"));
    AddExit("suroeste",AM_VESTIBULO("vest1"));
    AddExit("sudeste",AM_VESTIBULO("vest2"));
    AddExit("sur",AM_ROOM("entrada"));
    AddExit("norte",AM_ROOM("gremio"));
}
