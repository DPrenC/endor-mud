/****************************************************************************
Fichero: /d/simauria/comun/habitacion/caminos/nandor_sherek/cam01.c
Autor: Yalin
Fecha: 21/06/2009 23:02
Descripción: Camino de montaña hacia la abadía
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"El camino continúa en dirección norte, hacia la cima, dejando "
        "al sur el largo camino que une este valle con la aldea de Nandor, muy lejos al "
        "oeste.\n");
    AddExit("norte", SHERAB("camino/cam02"));
    AddExit("sur", CNSH("camino104"));
}
