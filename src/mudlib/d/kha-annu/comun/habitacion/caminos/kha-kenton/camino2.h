#include "./path.h"
#define CAMINO "/d/kha-annu/comun/habitacion/caminos/kha-kenton/"
inherit ROOM;
static void SetDesc();

SetDesc()
{
    switch (random(4)) {
        case 0:
            return(SetIntLong("Te encuentras en el camino entre Kha-annu y el bosque de Kenton "
                "que transcurre en direcci�n sur-sudeste serpenteando la Monta�a.\n"));
        break;
        case 1:
            return(SetIntLong("El camino sigue el curso del r�o en direcci�n sur-sudeste hasta "
                "el bosque de Kenton.\n"));
        break;
        case 2:
            return(SetIntLong("Las grandes monta�as de Kha-annu resguardan el camino entre "
                "Kha-annu y el bosque de Kenton, y junto al r�o hacen la traves�a agradable y "
                "segura de asaltantes.\n"));
        break;
        case 3:
            return(SetIntLong("Por este camino, la ciudad de Kha-annu queda hacia el norte. "
                "Fue empedrado hace alg�n tiempo por los enanos y hacen lenta la traves�a de "
                "las carretas.\n"));
        break;
    }
}
