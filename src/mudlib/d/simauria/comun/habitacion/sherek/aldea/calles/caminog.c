/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/calles/caminog.c
Autor: Lug y Yalin
Fecha: 16/01/2007
Descripción: Base para el camino a la granja.
****************************************************************************/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("el camino a la granja de la aldea de Sloch");
    SetIntLong("Te encuentras sobre un camino de grava que lleva a la granja "
        "de la aldea de Sloch, donde los aldeanos rinden determinados días de "
        "trabajo al año para beneficio de los monjes de la abadía de "
        "Sherek.\n");
    SetIntNoise("Oyes a lo lejos el balar de las ovejas y alguna vaca que "
        "muge.\n");
    SetIntSmell("Huele a bosta de vaca.\n");
    AddDetail(({"suelo","camino"}),"Es un camino de grava en el que ves las "
        "huellas del ganado que pasa por aquí muy a menudo.\n");
}
