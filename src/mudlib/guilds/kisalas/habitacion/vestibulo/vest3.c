/****************************************************************************
Fichero: vest3.c
Autor: Riberales
Fecha: 14/02/2006
Descripci�n: Vest�bulo de las Kisalas. Remodelaci�n espacial total.
Notas: [R] No tiene fecha, as� es que le pongo la de hoy.
****************************************************************************/


#include "path.h"

inherit INTERIOR_BASE;

create()
{
    ::create();
    SetIntShort("el vest�bulo del gremio de las Kisalas");
    SetIntLong("Contin�as en el enorme vest�bulo de la �rden de las Kisalas. "
               "Por las paredes puedes ver numerosos grabados y bajorelieves "
               "que representan escenas de la vida de la �rden, al igual que "
               "reglas y condiciones. En el suelo est� grabado un sello que "
               "representa el s�mbolo de las Kisalas. La luz de la estancia "
               "proviene de unas enormes espirales fosforescentes situadas en "
               "el techo. Al Sur y al Este el vest�bulo contin�a, al Sudeste "
               "est� la puerta de salida, mientras que un pasillo se abre "
               "paso en direcci�n oeste.\n");

    AddDetalleGrabados();
    AddDetalleRelieves();

    AddExit("sur",AM_VESTIBULO("vest1"));
    AddExit("este",AM_VESTIBULO("vest4"));
    AddExit("sudeste",AM_ROOM("entrada"));
    AddExit("oeste",AM_PASILLO("pasillo3"));
}
