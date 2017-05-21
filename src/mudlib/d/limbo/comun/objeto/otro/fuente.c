/****************************************************************************
Fichero: /d/limbo/comun/objeto/otro/fuente.c
Autor: Lug y Yalin
Fecha: 10/05/2007
Descripción: Fuente para el claro del bosque en Limbo
****************************************************************************/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("En el medio del claro se haya una fuente de agua cristalina. El "
        "agua brota de ella a través de varios caños de metal para caer "
        "después en una pila. Posiblemente el agua provenga de algún "
        "acuífero subterráneo.\nEste agua fresca es un buen remedio para "
        "cualquiera que tenga sed.\n");
    SetNoGet("Claro..., ¿algo más?\n");
}

