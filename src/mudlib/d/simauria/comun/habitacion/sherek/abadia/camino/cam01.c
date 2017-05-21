/****************************************************************************
Fichero: /d/simauria/comun/habitacion/caminos/nandor_sherek/cam01.c
Autor: Yalin
Fecha: 21/06/2009 23:02
Descripci�n: Camino de monta�a hacia la abad�a
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"El camino contin�a en direcci�n norte, hacia la cima, dejando "
        "al sur el largo camino que une este valle con la aldea de Nandor, muy lejos al "
        "oeste.\n");
    AddExit("norte", SHERAB("camino/cam02"));
    AddExit("sur", CNSH("camino104"));
}
