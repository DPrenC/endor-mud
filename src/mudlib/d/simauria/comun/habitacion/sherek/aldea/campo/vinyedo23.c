/* Archivo:         viñedo23.c
Autor:           Yalin y Lug
Descripción:     viñedos en la aldea de Sloch
Fecha:           30/05/2006
*/

#include "path.h"
inherit SHERALD("campo/vinyedo");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al norte y al oeste, un muro te separa del "
        "camino. En las demás direcciones se extiende el viñedo.\n");
    AddDetail(({"muro","tapia","valla"}),"Es un muro de unos 2 metros de "
        "altura, hecho de piedra, que separa el viñedo del camino.\n");
    AddExit("este", SHERALD("campo/vinyedo21"));
    AddExit("sur", SHERALD("campo/vinyedo13"));
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
