/****************************************************************************
Fichero: /d/limbo/comun/objeto/otro/fuente.c
Autor: Lug y Yalin
Fecha: 10/05/2007
Descripci�n: Fuente para el claro del bosque en Limbo
****************************************************************************/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("En el medio del claro se haya una fuente de agua cristalina. El "
        "agua brota de ella a trav�s de varios ca�os de metal para caer "
        "despu�s en una pila. Posiblemente el agua provenga de alg�n "
        "acu�fero subterr�neo.\nEste agua fresca es un buen remedio para "
        "cualquiera que tenga sed.\n");
    SetNoGet("Claro..., �algo m�s?\n");
}

