/*
DESCRIPCION  : fuente con abrevadero
FICHERO      : /d/akallab/comun/objeto/otro/fuente_abrevadero.c
MODIFICACION : 16-09-07 [Angor] Creacion
*/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente con abrevadero");
    SetLong(
    "Es una peque�a fuente hecha de piedra. El agua que sale de ella por un ca�o "
    "se recoge en un abrevadero antes de irse canalizada hacia otros lugares. "
    "El abrevadero es una especie de caj�n largo y bajo tambi�n de piedra. Sus bordes "
    "son poco elevados para que los animales puedan beber de �l.\n");
    
    SetNoGet("Claro..., �algo m�s?\n");
}

