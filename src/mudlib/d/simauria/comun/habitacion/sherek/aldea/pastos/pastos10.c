/* Archivo        pastos10.c
   Autor:         Yalin y Lug
   Fecha:         14/05/2006
   Descripción:   pastos de la granja de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("pastos/pastos");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al suroeste puedes ver el camino tras una "
        "empalizada. En las demás direcciones se extienden los pastos.\n");
    AddDetail(({"empalizada","valla","suroeste"}),"se trata de una valla de "
        "maderas que separa los pastos del camino que lleva de la granja a "
        "la aldea.\n");
    AddExit("norte", SHERALD("pastos/pastos15"));
    AddExit("este", SHERALD("pastos/pastos11"));
    pongo();
}
