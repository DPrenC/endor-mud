/********************************************
*    Nombre: cueva00.c			    *
*    Localizacion: Cueva de los Trolls      *
*    Realizada por : Mirill                 *
*    Creado : 16-03-00                      *
*    Modificado: 16-03-00                   *
*********************************************/


#include "./path.h"
#include <properties.h>

inherit SIM_ROOM;

create () {
    ::create();
    SetLocate("cueva de los trolls");
    SetIntShort("la entrada a una cueva");
    SetIntLong("Adentrándose en la montaña se aprecia claramente que la apertura que "
    "hay en la roca  es la entrada a una gruta, en la que no tiene apariencia que "
    "vivan criaturas nada agradables, a juzgar por las marcas de garras de las "
    "paredes y los restos de animales muertos que yacen por el suelo.\n");
    SetIndoors(0);
    SetIntSmell("Hueles levemente a humedad y a basura.\n");
    AddDetail(({"humedad"}), "El olor a humedad viene del interior de la cueva.\n");
    AddDetail(({"garras","garra"}), "Ves grandes marcas en las paredes de la "
        "caverna, originadas probablemente por violentas peleas.\n");
    AddDetail(({"cadaveres", "restos"}), "En el suelo ves trozos de vestimentas "
        "y huesos de diferentes animales e incluso personas. Están en mal estado "
        "y no tienen nada de valor.\n");
    AddExit("sur", CAMINOS "/gremio/cam_cortado10");
    AddExit("norte", "./cueva01");
}
