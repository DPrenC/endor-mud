/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/calles/calle.c
Autor: Lug y Yalin
Fecha: 14/01/2007
Descripción: Base para la calle principal de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("la calle principal de la aldea de Sloch");
    SetIntLong("Te hallas en la calle principal de la aldea de Sloch. No se "
        "puede decir que éste sea un lugar muy animado.\n");
    SetIntNoise("Puedes oír el piar de algunos pajarillos y voces de "
        "personas a lo lejos.\n");
    SetIntSmell("Huele a bosta de vaca.\n");
    AddDetail(({"suelo","calle"}),"Es una calle de tierra apisonada, lo que "
        "no basta para que en invierno se convierta en un lodazal.\n");
}
