/*

    Nombre      : calle04
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Calle del comercio

*/
#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>

inherit SIM_ROOM;

create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetIntShort("la calle del comercio");
    SetIntLong("Estás en la calle del comercio. Aquí se encuentran todo tipo "
    "de productos. La calle discurre de este a oeste. Al norte está la entrada a "
    "la herboristería y al sur la entrada a la tienda de la vieja Marla.\n");
    SetIndoors(0);
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail("suelo","El suelo de arena está lleno de pisadas de los transeuntes.\n");
    AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible "
    "distinguir un rastro.\n");
    AddExit("este",ENALHAB"poblado/calles/calle03");
    AddExit("oeste",ENALHAB"poblado/calles/calle05");
    AddExit("norte",ENALHAB"poblado/tiendas/mil_hierbas");
    AddExit("sur",ENALHAB"poblado/tiendas/marla");
    AddDoor("norte", "la puerta de la herboristería",
    "Es la puerta para entrar a la herboristería las mil hierbas.\n",
    ({"puerta", "puerta de la herboristería", "puerta de la herboristeria",
    "puerta del norte"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddDoor("sur", "la puerta de la tienda",
    "La puerta para entrar a la tienda de Marla.\n",
    ({"puerta", "puerta del sur", "puerta de la tienda"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));

}