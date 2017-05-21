/****************************************************************************
Fichero: vest3.c
Autor: Riberales
Fecha: 14/02/2006
Descripción: Vestíbulo de las Kisalas. Remodelación espacial total.
Notas: [R] No tiene fecha, así es que le pongo la de hoy.
****************************************************************************/


#include "path.h"

inherit INTERIOR_BASE;

create()
{
    ::create();
    SetIntShort("el vestíbulo del gremio de las Kisalas");
    SetIntLong("Continúas en el enorme vestíbulo de la Órden de las Kisalas. "
               "Por las paredes puedes ver numerosos grabados y bajorelieves "
               "que representan escenas de la vida de la Órden, al igual que "
               "reglas y condiciones. En el suelo está grabado un sello que "
               "representa el símbolo de las Kisalas. La luz de la estancia "
               "proviene de unas enormes espirales fosforescentes situadas en "
               "el techo. Al Sur y al Este el vestíbulo continúa, al Sudeste "
               "está la puerta de salida, mientras que un pasillo se abre "
               "paso en dirección oeste.\n");

    AddDetalleGrabados();
    AddDetalleRelieves();

    AddExit("sur",AM_VESTIBULO("vest1"));
    AddExit("este",AM_VESTIBULO("vest4"));
    AddExit("sudeste",AM_ROOM("entrada"));
    AddExit("oeste",AM_PASILLO("pasillo3"));
}
