/*
Archivo        camino11.c
Autor:         Yalin y Lug
Fecha:         30/04/2006
Descripción:   Camino de Nandor a
Sherek
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el nordeste, una ramificación del "
        "camino conduce a las viejas ruinas de Gundistyr.\n");
    AddExit("noreste", GSUP("camino01"));
    AddExit("oeste", CNSH("camino10"));
    AddExit("sureste", CNSH("camino12"));
    Bichejo();
}
