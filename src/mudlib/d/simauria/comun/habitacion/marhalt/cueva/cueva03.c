/********************************************
*    Nombre: cueva03.c			    *
*    Localizacion: Cueva de los Trolls      *
*    Realizada por : Cajun, el ejecutor     *
*    Creado : 20-10-99                      *
*    Modificado:                            *
*********************************************/


#include "./path.h"
#include <properties.h>

inherit MARHCUEVA("cueva_base");

create () {
    ::create();
    SetIntShort("una bifurcación de la cueva");
    SetIntLong("Llegas a un lugar en donde la cueva se divide en dos caminos. El camino "
    "que sigue hacia el noroeste se agranda, pero el pequeño pasaje que empieza "
    "en el oeste se hace algo más pequeño.\n");
    SetIntSmell("Desde el pasaje del oeste emerge un pestilente olor a podrido.\n");
    AddDetail(({"humedad","agua"}),
        "la humedad que cae por las paredes ayuda a que proliferen todo tipo de hongos.\n");
    AddExit("noroeste", "./cueva07");
    AddExit("oeste", "./cueva04");
    AddExit("sur", "./cueva02");
    AddItem(PNJ("marhalt/cueva/troll"), REFRESH_DESTRUCT, d3());
}
