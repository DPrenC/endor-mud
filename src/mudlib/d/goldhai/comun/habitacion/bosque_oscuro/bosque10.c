/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-01-98                |
 |               Ultima Modificacion.. 18-11-98                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
    ::create();
    SetIntShort("un cruce");
    SetIntLong("Te has parado en un cruce perdido en este bosque. Te resulta prácticamente "
        "imposible ver que hay mas allá por cualquiera de las salidas que puedes tomar, por lo "
        "tanto, lo recomendable es que tomes cualquiera de ellas y no permanezcas mucho tiempo "
        "en este lugar, quién sabe los peligros que te pueden acechar.\n");
    AddExit("norte",BOSCURO("bosque13"));
    AddExit("este",BOSCURO("bosque11"));
    AddExit("sur",BOSCURO("bosque9"));
    AddPnj();
    SetLocate("bosque oscuro de Goldhai");
}
