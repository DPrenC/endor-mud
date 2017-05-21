/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam02.c
Autor: Yalin
Fecha: 21/06/2009 23:02
Descripci�n: Camino de monta�a hacia la abad�a
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"El camino contin�a en direcci�n norte hacia la abad�a situada casi "
        "en la cima, dejando al sur el camino de Nandor.\n");
    AddExit("norte", SHERAB("camino/cam03"));
    AddExit("sur", SHERAB("camino/cam01"));
}
