/*
Archivo: /d/simauria/comun/habitacion/sherek/caminos/nandor-sherek/camino01.c
Autor:         Yalin y Lug
Fecha:         30/04/2006
Descripci�n: camino de Nandor a Sherek.
*/

#include "path.h"
inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("el camino de Nandor a Sherek");
    SetIntShort("el camino de Nandor a la abad�a de Sherek");
    SetIntLong("Est�s andando por el camino que conecta la aldea de Nandor "
        "con la abad�a de Sherek. No es muy ancho, pero s� lo suficiente "
        "como para que una carreta pueda circular con facilidad por �l. "
        "Hacia el oeste, a lo lejos, el camino parece unirse con un cruce, mientras "
        "que contin�a inmutable en direcci�n este. Pueden verse, asimismo, "
        "unos muros al norte, mientras que al sur y sudeste se extiende el bosque.\n");
    SetIntNoise("Escuchas el canto de algunos p�jaros y los zumbidos de los "
        "insectos.\n");
    SetIntSmell("Huele a naturaleza viva.\n");
    SetIndoors(0);
    AddDetail(({"muro", "muros", "muralla", "murallas"}), "Parece ser la muralla de un "
        "cementerio.\n");
    AddDetail(({"suelo", "camino"}), "Al mirarlo puedes ver por doquier "
        "diferentes huellas.\n");
    AddDetail(({"huella", "huellas"}), "Son marcas de cascos de cabalgaduras "
        "y de ruedas de alg�n tipo de carruaje que te indican que este "
        "ccamino es transitado.\n");
    AddDetail(({"arboles", "�rboles"}), "Son grandes �rboles pertenecientes "
    "al bosque que hay al sur.\n");
    AddDetail(({"bosque"}), "se trata de un gran bosque de j�venes robles "
        "y encinas, que se extiende al sudeste de la Aldea de Nandor.\n");
    AddDetail("cruce", "Es un cruce que se aprecia al oeste.\n");    
    AddExit("oeste", CNSH("camino00"));
    AddExit("este", CNSH("camino02"));
    AddExit("sur", MARH("nandor/bosque/bosque001"));
}
