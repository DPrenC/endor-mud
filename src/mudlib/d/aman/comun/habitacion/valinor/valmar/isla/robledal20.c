/*****************************************************************************************
 ARCHIVO:       robledal20.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("un claro lleno de ramas");
    SetIntLong("Estás en medio del solitario y silencioso bosque. Ocultas por una "
        "inexpugnable niebla misteriosa, atisbas incontables ramas de todos los "
        "tamaños que intentan abrirse paso entre la bruma, y que sólo te dejan paso "
        "por el camino.\n");
    AddDetail("niebla", "Sigue siendo tan espesa como en el resto de la isla.\n");
    AddDetail("ramas", "Se entrelazan formando arcos y pasarelas.\n");
    AddDetail(({"arcos", "pasarelas"}), "Te cierran el paso en cualquier dirección "
        "excepto por la que marca el sendero.\n");
    AddDetail(({"camino", "sendero"}), "Solamente quedan indicios de que lo hubo, y fue "
        "transitado alguna vez.\n");
    AddDetail("suelo", "Las ramitas que se esparcen por el suelo crujen bajo tus "
        "pies.\n");

    AddExit("norte", HAB_BOSQUE_ISLA("robledal25.c"));
    AddExit("sureste", HAB_BOSQUE_ISLA("robledal16.c"));
}
