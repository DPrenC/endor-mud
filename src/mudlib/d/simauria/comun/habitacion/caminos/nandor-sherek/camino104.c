/* Archivo        camino104.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripci�n:   Camino a la abad�a (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el norte arranca el camino que lleva a la abad�a, residencia "
        "de los monjes de Sherek, mientras que hacia el este puede verse el r�o Kandal, que baja de "
        "la monta�a, trazando una curva en direcci�n suroeste, para rodear por el sur la vecina "
        "aldea de Sloch, y perderse al oeste hacia las tierras de Marhalt.\n");
    AddExit("norte", SHERAB("camino/cam01"));
    AddExit("oeste", CNSH("camino103"));
    Bichejo();
}
