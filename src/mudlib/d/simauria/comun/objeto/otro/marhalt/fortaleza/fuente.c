/****************************************************************************
Fichero: /d/simauria/comun/objeto/otro/marhalt/fortaleza/fuente.c
Autor: Lug y Yalin
Fecha: 02/05/2007
Descripción: Fuente para la fortaleza de Cored
****************************************************************************/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("Sólo es una pila de piedra, con varios caños saliendo de su borde.\n");
    SetNoGet("Si, sí, ya puedes llevártela.\n");
}

