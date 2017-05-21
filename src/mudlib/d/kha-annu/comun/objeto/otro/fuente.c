/****************************************************************************
Fichero: /d/kha-annu/comun/objeto/otro/fuente.c
Autor: Lug y Yalin
Fecha: 11/05/2007
Descripci�n: Fuente para el jard�n del castillo de Kha-annu
****************************************************************************/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("Como todo lo que hacen los enanos, a pesar de su tama�o, la "
        "fuente es descomunal.\nEs una pila semiesf�rica, en forma de copa, "
        "sostenida por cuatro pilares tallados.\nTodo el conjunto est� "
        "realizado en m�rmol con finas tallas.\n");
    AddId(({"fuente","copa","pila"}));
    SetNoGet("Claro, y te la querr�s poner de sombrero tambi�n, �no?\n");
}

