/* Archivo:         vi�edo31.c
Autor:           Yalin y Lug
Descripci�n:     vi�edos en la aldea de Sloch
Fecha:           30/05/2006
*/

#include "path.h"
inherit SHERALD("campo/vinyedo");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al oeste, un muro te separa del camino, y al norte puedes ver "
        "la entrada a las bodegas. En las dem�s direcciones se extiende el vi�edo.\n");
    AddDetail(({"muro","tapia","valla"}), "Es un muro de unos 2 metros de "
        "altura, hecho de piedra, que separa el vi�edo del camino.\n");
    AddDetail(({"bodega","bodegas","entrada"}),"S�lo ves un arco bajo de piedra, por donde los "
        "aldeanos pasan con los cestos de uva en los tiempos de vendimia.\n");
    AddExit("norte", SHERALD("casas/bodega00"));
    AddExit("este", SHERALD("campo/vinyedo32"));
    AddExit("sur", SHERALD("campo/vinyedo21"));
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
