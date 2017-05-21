/****************************************************************************
Fichero: /d/kha-annu/comun/objeto/otro/fuente.c
Autor: Lug y Yalin
Fecha: 11/05/2007
Descripción: Fuente para el jardín del castillo de Kha-annu
****************************************************************************/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("Como todo lo que hacen los enanos, a pesar de su tamaño, la "
        "fuente es descomunal.\nEs una pila semiesférica, en forma de copa, "
        "sostenida por cuatro pilares tallados.\nTodo el conjunto está "
        "realizado en mármol con finas tallas.\n");
    AddId(({"fuente","copa","pila"}));
    SetNoGet("Claro, y te la querrás poner de sombrero también, ¿no?\n");
}

