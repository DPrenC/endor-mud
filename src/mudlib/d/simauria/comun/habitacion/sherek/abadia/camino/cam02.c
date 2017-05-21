/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam02.c
Autor: Yalin
Fecha: 21/06/2009 23:02
Descripción: Camino de montaña hacia la abadía
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"El camino continúa en dirección norte hacia la abadía situada casi "
        "en la cima, dejando al sur el camino de Nandor.\n");
    AddExit("norte", SHERAB("camino/cam03"));
    AddExit("sur", SHERAB("camino/cam01"));
}
