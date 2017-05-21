/* Archivo        pastos14.c
   Autor:         Yalin y Lug
   Fecha:         14/05/2006
   Descripción:   pastos de la granja de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("pastos/pastos");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al sur puedes ver el camino tras una "
        "empalizada, al oeste la pared de una cabaña. En las demás "
        "direcciones se extienden los pastos.\n");
    AddDetail(({"empalizada","valla","suroeste"}),"se trata de una valla de "
        "maderas que separa los pastos del camino que lleva de la granja a "
        "la aldea.\n");
    AddDetail(({"pared","cabaña","oeste"}),"Es la pared de una pobre cabaña "
        "de la aldea.\n");
    AddExit("norte", SHERALD("pastos/pastos19"));
    AddExit("este", SHERALD("pastos/pastos15"));
    pongo();
}
