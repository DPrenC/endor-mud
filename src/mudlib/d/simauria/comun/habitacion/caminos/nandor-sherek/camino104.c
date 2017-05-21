/* Archivo        camino104.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino a la abadía (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el norte arranca el camino que lleva a la abadía, residencia "
        "de los monjes de Sherek, mientras que hacia el este puede verse el río Kandal, que baja de "
        "la montaña, trazando una curva en dirección suroeste, para rodear por el sur la vecina "
        "aldea de Sloch, y perderse al oeste hacia las tierras de Marhalt.\n");
    AddExit("norte", SHERAB("camino/cam01"));
    AddExit("oeste", CNSH("camino103"));
    Bichejo();
}
