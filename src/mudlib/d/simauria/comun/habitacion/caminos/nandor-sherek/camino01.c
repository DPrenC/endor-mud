/*
Archivo: /d/simauria/comun/habitacion/sherek/caminos/nandor-sherek/camino01.c
Autor:         Yalin y Lug
Fecha:         30/04/2006
Descripción: camino de Nandor a Sherek.
*/

#include "path.h"
inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("el camino de Nandor a Sherek");
    SetIntShort("el camino de Nandor a la abadía de Sherek");
    SetIntLong("Estás andando por el camino que conecta la aldea de Nandor "
        "con la abadía de Sherek. No es muy ancho, pero sí lo suficiente "
        "como para que una carreta pueda circular con facilidad por él. "
        "Hacia el oeste, a lo lejos, el camino parece unirse con un cruce, mientras "
        "que continúa inmutable en dirección este. Pueden verse, asimismo, "
        "unos muros al norte, mientras que al sur y sudeste se extiende el bosque.\n");
    SetIntNoise("Escuchas el canto de algunos pájaros y los zumbidos de los "
        "insectos.\n");
    SetIntSmell("Huele a naturaleza viva.\n");
    SetIndoors(0);
    AddDetail(({"muro", "muros", "muralla", "murallas"}), "Parece ser la muralla de un "
        "cementerio.\n");
    AddDetail(({"suelo", "camino"}), "Al mirarlo puedes ver por doquier "
        "diferentes huellas.\n");
    AddDetail(({"huella", "huellas"}), "Son marcas de cascos de cabalgaduras "
        "y de ruedas de algún tipo de carruaje que te indican que este "
        "ccamino es transitado.\n");
    AddDetail(({"arboles", "árboles"}), "Son grandes árboles pertenecientes "
    "al bosque que hay al sur.\n");
    AddDetail(({"bosque"}), "se trata de un gran bosque de jóvenes robles "
        "y encinas, que se extiende al sudeste de la Aldea de Nandor.\n");
    AddDetail("cruce", "Es un cruce que se aprecia al oeste.\n");    
    AddExit("oeste", CNSH("camino00"));
    AddExit("este", CNSH("camino02"));
    AddExit("sur", MARH("nandor/bosque/bosque001"));
}
