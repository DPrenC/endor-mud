/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/calles/caminop.c
Autor: Lug y Yalin
Fecha: 19/08/2006
Descripci�n: Callej�n que une la aldea con la pradera.
****************************************************************************/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("un callej�n");
    SetIntLong("Esto es un callej�n estrecho, que comunica la aldea con la "
        "pradera que se extiende al sur, junto al r�o. No es m�s que el "
        "hueco que queda entre el templo, al oeste, y una m�sera caba�a que "
        "hay al este.\n");
    SetIntSmell("Percibes el olor a hierba de la pradera cercana.\n");
    SetIntNoise("Oyes cantos de p�jaros y risas de ni�os a lo lejos.\n");
    AddExit("norte", SHERALD("calles/caminogranja00"));
    AddExit("sur", SHERALD("pradera/pradera01"));
}
