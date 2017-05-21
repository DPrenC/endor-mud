/*****************************************************************************************
 ARCHIVO:       posada01_vestib.c
 AUTOR:         Ztico
 FECHA:         07-04-2005
 DESCRIPCIÓN:   Posada del Unicornio Azul. Vestíbulo.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <keeper.h>

inherit BASE_ISLA;
inherit KEEPER;

public int QueryIsInn() { return 1; }

create()
{
    if(::create()) return 1;

    SetIntShort("la posada 'El Unicornio Azul'");
    SetIntLong("Vestíbulo de la posada. Te hallas en la estancia que da entrada a las "
        "diferentes dependencias de la posada. Es el lugar de reposo para los druidas "
        "que realizan sus cultos y ritos en el robledal que rodea la isla. Las paredes "
        "te anuncian la belleza y magnificencia que podrás encontrar más adentro. Un "
        "espléndido cortinaje te separa del interior de la posada.\n");
    AddDetail(({"paredes", "pared"}), "Son de granito jaspeado en fulgurantes tonos "
        "dorados y verdes.\n");
    AddDetail("cortinaje", "Es de terciopelo color gris perla.\n");
    AddDetail("suelo", "A tus pies ves grandes losas de granito pulidas por el tiempo "
        "y el uso");
    AddDetail(({"losas", "grandes losas"}), "Son pesadas, cuadradas, sin estilo, frías, "
        "simplonas, duras y poco estéticas. Quizás te recuerden a alguien que "
        "conozcas...\n");
    SetIndoors(1);
    SetIntBright(40);

    AddExit("norte", HAB_BOSQUE_ISLA("posada03_atrio.c"));
    AddExit("sur", HAB_BOSQUE_ISLA("robledal01.c"));

    SetKeeper(PNJ_VALMAR("dildalh.c"));
}
