/* Archivo        cabaña00.c
   Autor:         Yalin y Lug
   Fecha:         04/05/2006
   Descripción:   cabaña de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("casas/cabanya");

create ()
{
    ::create();
    AddExit("sur", SHERALD("calles/callejuela01"));
}
