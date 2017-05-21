#include "./path.h"
#define CAMINO "/d/kha-annu/comun/habitacion/caminos/kha-kenton/"
inherit ROOM;
static void SetDesc();

SetDesc()
{
    switch (random(4)) {
        case 0:
            return(SetIntLong("Te encuentras en el camino entre Kha-annu y el bosque de Kenton "
                "que transcurre en dirección sur-sudeste serpenteando la Montaña.\n"));
        break;
        case 1:
            return(SetIntLong("El camino sigue el curso del río en dirección sur-sudeste hasta "
                "el bosque de Kenton.\n"));
        break;
        case 2:
            return(SetIntLong("Las grandes montañas de Kha-annu resguardan el camino entre "
                "Kha-annu y el bosque de Kenton, y junto al río hacen la travesía agradable y "
                "segura de asaltantes.\n"));
        break;
        case 3:
            return(SetIntLong("Por este camino, la ciudad de Kha-annu queda hacia el norte. "
                "Fue empedrado hace algún tiempo por los enanos y hacen lenta la travesía de "
                "las carretas.\n"));
        break;
    }
}
