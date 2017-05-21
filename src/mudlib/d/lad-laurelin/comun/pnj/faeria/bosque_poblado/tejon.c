/***
Fichero: tejon.c
Autor: kastwey@simauria
Descripci�n: Un tej�n para el bosque de siempreunidos.
Creaci�n: 18/12/2004
***/

#include "path.h"
#include <gremios.h>

inherit NPC;

create()
{
    ::create();
   SetStandard("un tej�n","tejon",([GC_TORPE:4]),1);
    SetLong("Es un tej�n. Te mira con ojillos inteligentes y asustados. No te extra�ar�a que si sigues mir�ndolo echase a correr.\n");
    SetWhimpy(QueryHP());
}
