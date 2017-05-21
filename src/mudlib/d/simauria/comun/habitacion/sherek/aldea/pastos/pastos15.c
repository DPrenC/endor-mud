/* Archivo        pastos15.c
   Autor:         Yalin y Lug
   Fecha:         14/05/2006
   Descripción:   pastos de la granja de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("pastos/pastos");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Ves una extensión de hierba en todas "
        "direcciones.\n");
    AddExit("norte", SHERALD("pastos/pastos20"));
    AddExit("sur", SHERALD("pastos/pastos10"));
    AddExit("este", SHERALD("pastos/pastos16"));
    AddExit("oeste", SHERALD("pastos/pastos14"));
    pongo();
}
