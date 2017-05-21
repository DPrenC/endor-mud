/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/calles/caminop.c
Autor: Lug y Yalin
Fecha: 19/08/2006
Descripción: Callejón que une la aldea con la pradera.
****************************************************************************/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("un callejón");
    SetIntLong("Esto es un callejón estrecho, que comunica la aldea con la "
        "pradera que se extiende al sur, junto al río. No es más que el "
        "hueco que queda entre el templo, al oeste, y una mísera cabaña que "
        "hay al este.\n");
    SetIntSmell("Percibes el olor a hierba de la pradera cercana.\n");
    SetIntNoise("Oyes cantos de pájaros y risas de niños a lo lejos.\n");
    AddExit("norte", SHERALD("calles/caminogranja00"));
    AddExit("sur", SHERALD("pradera/pradera01"));
}
