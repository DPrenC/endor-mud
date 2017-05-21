/*****************************************************************************************
 ARCHIVO:       robledal33.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Gruta en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("la gruta");
    SetIntLong("Te encuentras en un angosto pasadizo envuelto por una densa oscuridad. "
        "A ambos lados las rocas se cubren de cal, que rellena las fisuras entre los "
        "bloques. El techo está lleno de fisuras y el suelo es muy resbaladizo. Observas "
        "una tenue luz hacia el sudeste.\n");
    AddDetail(({"goteras", "fisuras"}), "Del techo se desprenden gotas de humedad que te "
        "salpican.\n");
    AddDetail(({"paredes", "rocas", "bloques", "losas"}), "Son grandes losas de unos "
        "siete metros de altura.\n");
    AddDetail("cal", "Blanquea las paredes.\n");
    AddDetail(({"techo", "fisuras"}), "El tiempo y las heladas han hecho que las rocas se "
        "quiebren.\n");
    AddDetail("suelo", "La sal que se hay depositada en el suelo hace que sea aceitoso y "
        "por eso es tan deslizante.\n");
    AddDetail(({"luz", "tenue luz"}), "Es un ligero y sutil resplandor que pasa casi "
        "desapercibido.\n");

    SetIndoors(1);
    SetIntBright(0);

    AddExit("sur", HAB_BOSQUE_ISLA("robledal27.c"));
    AddExit("sureste", HAB_BOSQUE_ISLA("robledal28.c"));
}
