/**********
Archivo        /d/simauria/comun/habitacion/caminos/nandor-sherek/camino00.c
Autor:         Yalin y Lug
Fecha:         30/04/2006
Descripci�n:   Camino De nandor a Sherek.
*/

#include "path.h"
inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("el camino a Sherek");
    SetIntShort("el camino de Nandor a la abad�a de Sherek ");
    SetIntLong("Caminas por una senda que transcurre entre los �rboles "
        "comunicando el bosque de nandor con la abad�a de Sherek. A trav�s de "
        "los �rboles puedes ver unas murallas al norte, y, m�s "
        "lejos, al nordeste, una edificaci�n.\nEl bosque se extiende hasta donde puedes "
        "distinguir, al sur y sudeste. hacia el oeste se aprecia un ancho cruce.\n");
    SetIntNoise("Puedes o�r el viento y los p�jaros entre las ramas del bosque que se extiende hacia el oeste.");
    SetIntSmell("Huele a la abundante vegetaci�n que te rodea.");
    SetIndoors(0);
    AddDetail(({"muro", "muros", "muralla", "murallas"}), "Se trata de los "
        "muros que rodean un viejo cementerio, posiblemente perteneciente a "
        "la aldea de Nandor.\n");
    AddDetail(({"edificacion", "edificaci�n"}), "parece una iglesia, pero "
        "est�s demasiado lejos para asegurarlo.\n");
    AddDetail(({"suelo", "camino"}), "Est� cubierto por malezas y ra�ces, "
        "pero ves que hay se�ales de ser bastante transitado.\n");
    AddDetail(({"huella", "huellas", "se�al", "se�ales"}), "Son se�ales de "
        "tr�nsito de caballos y carretas que suelen pasar por aqu�.\n");
    AddDetail(({"arboles", "�rboles"}), "Son grandes y frondosos �rboles "
        "pertenecientes al bosque que comienza aqu�.\n");
    AddDetail(({"bosque"}), "se trata de un gran bosque de j�venes robles "
        "y encinas, que se extiende al sur de la Aldea de Nandor.\n");
    AddDetail("cruce", "Al oeste el camino termina en un ancho cruce, donde tambi�n "
    "parece que la vegetaci�n del bosque no es tan importante.\n");
    AddExit("oeste", MARH("nandor/cruce"));
    AddExit("este", CNSH("camino01"));
}
