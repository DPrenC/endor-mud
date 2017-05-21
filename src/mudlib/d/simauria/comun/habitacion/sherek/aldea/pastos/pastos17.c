/* Archivo        pastos17.c
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
    AddExit("norte", SHERALD("pastos/pastos22"));
    AddExit("sur", SHERALD("pastos/pastos12"));
    AddExit("este", SHERALD("pastos/pastos18"));
    AddExit("oeste", SHERALD("pastos/pastos16"));
    pongo();
}
