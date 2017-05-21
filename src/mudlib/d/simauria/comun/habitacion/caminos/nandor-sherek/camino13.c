/*
Archivo        camino13.c
Autor:         Yalin y Lug
Fecha:         30/04/2006
Descripción:   Camino de Nandor a Sherek
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    AddExit("noroeste", CNSH("camino12"));
    AddExit("sureste", CNSH("camino14"));
    Bichejo();
}
