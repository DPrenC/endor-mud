/*****************************************************************************************
 ARCHIVO:       robledal14.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:   Hacia el ESTE, ventana de la posada05_hab3.c
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("los alrededores de la posada");
    SetIntLong("El paso del tiempo ha ido dejando huella en este lugar. Te encuentras "
        "en un claro con forma ovalada. La aspereza y robusted de los árboles que "
        "circundan el claro es especialmente definida y todo el suelo está cubierto "
        "por cientos y cientos de pequeñas bellotas imitando los tonos de una "
        "alfombra jaspeada.\n");
    AddDetail("claro", "Echas un vistazo a tu alrededor y no divisas nada extraño.\n");
    AddDetail(({"árboles", "arboles"}), "Están cubiertos de líquenes, musgos, "
        "bromelias y orquídeas con flores de brillantes colores, así como por decenas "
        "de helechos.\n");
    AddDetail("helechos", "Son hermosos y gigantescos, de colores vivaces y "
        "alegres.\n");
    AddDetail(({"bellotas", "pequeñas bellotas"}), "Son los frutos maduros que han ido "
        "cayendo de las ramas de los robles.\n");
    AddDetail(({"suelo", "alfombra", "alfombra jaspeada"}), "El paso del tiempo ha ido "
        "acumulando las bellotas por todo el claro.\n");

    SetIntNoise("No muy lejos de aquí se escucha el ruido de un chapoteo.\n");

    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal18.c"));
    AddExit("oeste", HAB_BOSQUE_ISLA("robledal13.c"));
    AddExit("suroeste", HAB_BOSQUE_ISLA("robledal09.c"));
    AddExit("sur", HAB_BOSQUE_ISLA("robledal10.c"));
}
