/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam03.c
Autor: Yalin
Fecha: 21/06/2009 23:02
Descripci�n: Camino de monta�a hacia la abad�a
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"El camino contin�a en l�nea recta hacia el norte para dirigirse a "
        "la cima de la monta�a donde se encuentra la abad�a, mientras que desciende en direcci�n "
        "sur hacia el camino que lleva a las lejanas tierras de Marhalt.\n");
    AddExit("norte", SHERAB("camino/cam04"));
    AddExit("sur", SHERAB("camino/cam02"));
}
