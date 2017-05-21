/* Archivo        pastos05.c
   Autor:         Yalin y Lug
   Fecha:         14/05/2006
   Descripción:   pastos de la granja de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("pastos/pastos");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al oeste puedes ver el camino tras una "
        "empalizada. En las demás direcciones se extienden los pastos.\n");
    AddDetail(({"empalizada","valla"}),"se trata de una valla de maderas que "
        "separa los pastos del camino que lleva de la granja a la aldea.\n");
    AddExit("norte", SHERALD("pastos/pastos08"));
    AddExit("sur", SHERALD("pastos/pastos04"));
    AddExit("este", SHERALD("pastos/pastos06"));
    AddExit("oeste", SHERALD("calles/caminogranja05"));
    pongo();
}
