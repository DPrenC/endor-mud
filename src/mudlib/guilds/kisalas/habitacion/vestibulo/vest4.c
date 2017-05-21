/****************************************************************************
Fichero: vest4.c
Autor: Riberales
Fecha: 14/02/2006
Descripci�n: Vest�bulo de las Kisalas. Remodelaci�n espacial total.
Notas: [R] Por no tener no tiene ni fecha, as� es que le pongo la de hoy.
****************************************************************************/


#include "path.h"

inherit INTERIOR_BASE;

create()
{
    ::create();
    SetIntShort("el vest�bulo de las Kisalas");
    SetIntLong("Est�s en una parte del enorme vest�bulo del Gremio de las "
               "Kisalas. Por las paredes hay much�simos bajorrelieves que "
               "representan la vida y la historia de la �rden. En el suelo "
               "est� grabado un sello con el s�mbolo de las Kisalas. En el "
               "techo puedes ver muchas espirales fosforescentes que son las "
               "que iluminan la estancia. Al sur se encuentra la entrada del "
               "gremio, mientras que al Norte puedes ver la habitaci�n principal "
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
