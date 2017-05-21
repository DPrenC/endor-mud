/*

    Nombre      : calle06
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Calle del comercio.
                  Aquí se encuentra una fuente.

*/
#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <properties.h>
#include <materials.h>
#include <scheduler.h>

inherit SIM_ROOM;

create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetIntShort("la calle del comercio");
    SetIntLong("Estás en la parte oriental de la calle del comercio de Enalel. "
    "La calle se ensancha un poco para hacer lugar a una pequeña fuente situada en "
    "el centro de la calle. Aquí están dos de los edificios donde la gente de "
    "Enalel se reune a conversar. Al oeste la posada de la manzana feliz y al sur "
    "el ayuntamiento de Enalel. Al norte está la tienda del excéntrico Pofor, que "
    "compra casi cualquier cosa.\n");
    SetIndoors(0);
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail("suelo","El suelo de arena está lleno de pisadas de los transeuntes.\n");
    AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible "
    "distinguir un rastro.\n");
    AddDetail(({"posada","manzana feliz","posada la manzana feliz"}),"Es un edificio "
    "de madera de cuyo interior se desprenden aromas de suculentas comidas.\n");
    AddDetail(({"agua","chorro","chorro de agua"}),"Es un refrescante y cristalino "
    "chorro de agua que sale de la fuente.\nParece potable.\n");
    AddItem(OTRO("marhalt/enalel/fuente"));
    AddExit("norte",ENALHAB"poblado/tiendas/pofor");
    AddExit("este",ENALHAB"poblado/calles/calle05");
    AddExit("sur",ENALHAB"poblado/varios/ayuntamiento");
    AddExit("oeste",ENALHAB"poblado/posada/posada");
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
    AddDoor("norte",  "la puerta de la tienda",
    "La puerta para entrar a la tienda de Pofor.\n",
    ({"puerta", "puerta de la tienda", "puerta del norte"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddDoor("sur", "la puerta del ayuntamiento",
    "La puerta para entrar al edificio del ayujntamiento.\n",
    ({"puerta", "puerta del ayuntamiento", "puerta del sur"}),
    ([P_DOOR_CLOSE_TIME : ({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE})]));
    AddDoor("oeste", "la puerta principal de la posada",
    "Es una de las puertas de la posada de Enalel.\n",
    ({"puerta", "puerta de la posada", "puerta principal de la posada", "puerta del oeste"}));
}
