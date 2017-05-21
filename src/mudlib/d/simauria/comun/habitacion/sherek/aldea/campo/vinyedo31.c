/* Archivo:         viñedo31.c
Autor:           Yalin y Lug
Descripción:     viñedos en la aldea de Sloch
Fecha:           30/05/2006
*/

#include "path.h"
inherit SHERALD("campo/vinyedo");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al oeste, un muro te separa del camino, y al norte puedes ver "
        "la entrada a las bodegas. En las demás direcciones se extiende el viñedo.\n");
    AddDetail(({"muro","tapia","valla"}), "Es un muro de unos 2 metros de "
        "altura, hecho de piedra, que separa el viñedo del camino.\n");
    AddDetail(({"bodega","bodegas","entrada"}),"Sólo ves un arco bajo de piedra, por donde los "
        "aldeanos pasan con los cestos de uva en los tiempos de vendimia.\n");
    AddExit("norte", SHERALD("casas/bodega00"));
    AddExit("este", SHERALD("campo/vinyedo32"));
    AddExit("sur", SHERALD("campo/vinyedo21"));
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
