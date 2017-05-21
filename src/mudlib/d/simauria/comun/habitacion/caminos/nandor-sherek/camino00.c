/**********
Archivo        /d/simauria/comun/habitacion/caminos/nandor-sherek/camino00.c
Autor:         Yalin y Lug
Fecha:         30/04/2006
Descripción:   Camino De nandor a Sherek.
*/

#include "path.h"
inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("el camino a Sherek");
    SetIntShort("el camino de Nandor a la abadía de Sherek ");
    SetIntLong("Caminas por una senda que transcurre entre los árboles "
        "comunicando el bosque de nandor con la abadía de Sherek. A través de "
        "los árboles puedes ver unas murallas al norte, y, más "
        "lejos, al nordeste, una edificación.\nEl bosque se extiende hasta donde puedes "
        "distinguir, al sur y sudeste. hacia el oeste se aprecia un ancho cruce.\n");
    SetIntNoise("Puedes oír el viento y los pájaros entre las ramas del bosque que se extiende hacia el oeste.");
    SetIntSmell("Huele a la abundante vegetación que te rodea.");
    SetIndoors(0);
    AddDetail(({"muro", "muros", "muralla", "murallas"}), "Se trata de los "
        "muros que rodean un viejo cementerio, posiblemente perteneciente a "
        "la aldea de Nandor.\n");
    AddDetail(({"edificacion", "edificación"}), "parece una iglesia, pero "
        "estás demasiado lejos para asegurarlo.\n");
    AddDetail(({"suelo", "camino"}), "Está cubierto por malezas y raíces, "
        "pero ves que hay señales de ser bastante transitado.\n");
    AddDetail(({"huella", "huellas", "señal", "señales"}), "Son señales de "
        "tránsito de caballos y carretas que suelen pasar por aquí.\n");
    AddDetail(({"arboles", "árboles"}), "Son grandes y frondosos árboles "
        "pertenecientes al bosque que comienza aquí.\n");
    AddDetail(({"bosque"}), "se trata de un gran bosque de jóvenes robles "
        "y encinas, que se extiende al sur de la Aldea de Nandor.\n");
    AddDetail("cruce", "Al oeste el camino termina en un ancho cruce, donde también "
    "parece que la vegetación del bosque no es tan importante.\n");
    AddExit("oeste", MARH("nandor/cruce"));
    AddExit("este", CNSH("camino01"));
}
