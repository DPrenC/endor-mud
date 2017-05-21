/*****************************************************************************************
 ARCHIVO:       robledal25.c
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

    SetIntShort("un sendero en el bosque");
    SetIntLong("Mirando hacia arriba puedes ver como las copas de los altos robles "
        "crecen desmesuradamente, y por doquier la urdimbre de las lianas envuelve "
        "las pequeñas colinas. A tu alrededor el ambiente es muy confuso y "
        "misterioso.\n");
    AddDetail("suelo", "Su trazado es especialmente irregular y observas pequeños "
        "senderos probablemente formados por animalillos.\n");
    AddDetail("copas", "Son tan verdes y densas que apenas permiten el paso de "
        "finísimos rayos de luz.\n");
    AddDetail("urdimbre", "Las lianas se entrelazan formando una malla casi "
        "impracticable.\n");
    AddDetail(({"robles", "altos robles"}), "La corteza de sus troncos es blanquecina y "
        "están repletos de nudos.\n");
    AddDetail("lianas", "Su textura recorre toda la gama de verdes y azules. Forman "
        "finas columnas y enrevesadas redes por cualquier rincón.\n");
    AddDetail(({"colinas", "pequeñas colinas"}), "Rechonchos montículos poblados de matas"
        "y pequeñas florecillas están esparcidos por el suelo.\n");

    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal32.c"));
    AddExit("suroeste", HAB_BOSQUE_ISLA("robledal19.c"));
    AddExit("sur", HAB_BOSQUE_ISLA("robledal20.c"));
    AddExit("sureste", HAB_BOSQUE_ISLA("robledal21.c"));
}
