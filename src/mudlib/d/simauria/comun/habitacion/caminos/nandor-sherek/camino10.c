/*
Archivo        camino10.c
Autor:         Yalin y Lug
Fecha:         30/04/2006
Descripción:   Camino de Nandor a Sherek
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"En dirección sur y suroeste, hasta donde alcanza tu vista, se "
        "extiende un joven bosque de encinas y robles.\n");
    AddExit("oeste", CNSH("camino09"));
    AddExit("este", CNSH("camino11"));
    AddExit("suroeste", MARH("nandor/bosque/bosque006"));
    Bichejo();
}
