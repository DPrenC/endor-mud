/***
Fichero: tejon.c
Autor: kastwey@simauria
Descripción: Un tejón para el bosque de siempreunidos.
Creación: 18/12/2004
***/

#include "path.h"
#include <gremios.h>

inherit NPC;

create()
{
    ::create();
   SetStandard("un tejón","tejon",([GC_TORPE:4]),1);
    SetLong("Es un tejón. Te mira con ojillos inteligentes y asustados. No te extrañaría que si sigues mirándolo echase a correr.\n");
    SetWhimpy(QueryHP());
}
