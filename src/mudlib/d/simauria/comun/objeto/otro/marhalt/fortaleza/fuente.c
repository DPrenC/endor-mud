/****************************************************************************
Fichero: /d/simauria/comun/objeto/otro/marhalt/fortaleza/fuente.c
Autor: Lug y Yalin
Fecha: 02/05/2007
Descripci�n: Fuente para la fortaleza de Cored
****************************************************************************/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("S�lo es una pila de piedra, con varios ca�os saliendo de su borde.\n");
    SetNoGet("Si, s�, ya puedes llev�rtela.\n");
}

