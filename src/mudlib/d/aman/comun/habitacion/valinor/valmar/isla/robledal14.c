/*****************************************************************************************
 ARCHIVO:       robledal14.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCI�N:   Robledal en la Isla de los druidas.
 COMENTARIOS:   Hacia el ESTE, ventana de la posada05_hab3.c
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("los alrededores de la posada");
    SetIntLong("El paso del tiempo ha ido dejando huella en este lugar. Te encuentras "
        "en un claro con forma ovalada. La aspereza y robusted de los �rboles que "
        "circundan el claro es especialmente definida y todo el suelo est� cubierto "
        "por cientos y cientos de peque�as bellotas imitando los tonos de una "
        "alfombra jaspeada.\n");
    AddDetail("claro", "Echas un vistazo a tu alrededor y no divisas nada extra�o.\n");
    AddDetail(({"�rboles", "arboles"}), "Est�n cubiertos de l�quenes, musgos, "
        "bromelias y orqu�deas con flores de brillantes colores, as� como por decenas "
        "de helechos.\n");
    AddDetail("helechos", "Son hermosos y gigantescos, de colores vivaces y "
        "alegres.\n");
    AddDetail(({"bellotas", "peque�as bellotas"}), "Son los frutos maduros que han ido "
        "cayendo de las ramas de los robles.\n");
    AddDetail(({"suelo", "alfombra", "alfombra jaspeada"}), "El paso del tiempo ha ido "
        "acumulando las bellotas por todo el claro.\n");

    SetIntNoise("No muy lejos de aqu� se escucha el ruido de un chapoteo.\n");

    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal18.c"));
    AddExit("oeste", HAB_BOSQUE_ISLA("robledal13.c"));
    AddExit("suroeste", HAB_BOSQUE_ISLA("robledal09.c"));
    AddExit("sur", HAB_BOSQUE_ISLA("robledal10.c"));
}
