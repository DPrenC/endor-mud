/* Archivo        pastos20.c
   Autor:         Yalin y Lug
   Fecha:         14/05/2006
   Descripción:   pastos de la granja de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("pastos/pastos");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al norte los pastos terminan en un tupido "
        "bosque que te impide el paso. En las demás direcciones se extienden "
        "los pastos.\n");
    AddDetail(({"bosque"}), "es un bosque extremadamente espeso que impide "
        "que se pueda acceder a él desde los pastos limitándolos al norte.\n");
    AddExit("sur", SHERALD("pastos/pastos15"));
    AddExit("oeste", SHERALD("pastos/pastos19"));
    AddExit("este", SHERALD("pastos/pastos21"));
    pongo();
}
