/****************************************************************************
Fichero: vest5.c
Autor: Riberales
Fecha: 14/02/2006
Descripción: Vestíbulo de las Kisalas. Remodelación espacial total.
Notas: [R] No tiene ni fecha, le pongo la de hoy.
****************************************************************************/

#include "path.h"

inherit INTERIOR_BASE;

create()
{
    ::create();

    SetIntShort("el vestíbulo del gremio de las Kisalas");
    SetIntLong("Te encuentras en el extenso vestíbulo del Gremio de las "
               "Kisalas. Por las paredes puedes ver numerosos bajorelieves que"
               " representan escenas de la vida cotidiana de las Kisalas. En "
               "el suelo puedes observar un sello grabado, que es el símbolo "
               "de la Órden. La luz proviene del techo gracias a las espirales"
               " fosforescentes elfas. Al Sur y al Oeste sigue el vestíbulo, "
               "al Suroeste está la salida del Gremio, y al Este hay un "
               "pequeño pasillo.\n");


    AddDetalleGrabados();
    AddDetalleRelieves();

    AddExit("oeste",AM_VESTIBULO("vest4"));
    AddExit("sur",AM_VESTIBULO("vest2"));
    AddExit("suroeste",AM_ROOM("entrada"));
    AddExit("este",AM_PASILLO("pasillo1"));
}
