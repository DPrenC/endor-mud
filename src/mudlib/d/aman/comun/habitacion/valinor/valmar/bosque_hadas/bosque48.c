/*****************************************************************************************
 ARCHIVO:       bosque48.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCIÓN:   Bosque de las Hadas.
 COMENTARIOS:   Entrada a la cueva
*****************************************************************************************/

#include "./path.h"

inherit BASE_HADAS;

create()
{
    if(::create()) return 1;

    SetIntShort("el interior de una cueva");
    SetIntLong("Te encuentras en lo que parece la entrada de una pequeña cueva. Te "
        "resulta peculiar que en lugar de penumbra y oscuridad, la gruta esté inmersa "
        "en una tenue claridad, que no sabes exactamente de dónde procede. La salida "
        "de la cueva se encuentra al este, mientras que puedes internarte en sus "
        "profundidades si te diriges hacia el norte o hacia el sur.\n");
    SetIndoors(1);
    SetIntBright(30);

    AddExit("norte", HAB_BOSQUE_HADAS("bosque53.c"));
    AddExit("sur", HAB_BOSQUE_HADAS("bosque43.c"));
    AddExit("este", HAB_BOSQUE_HADAS("bosque49.c"));
}
