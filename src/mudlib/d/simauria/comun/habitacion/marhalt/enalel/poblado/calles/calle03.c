/*

    Nombre      : calle03
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripci�n : Calle del comercio

*/
#include "./path.h"
#include <properties.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit SIM_ROOM;

create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetIntShort("la calle del comercio");
    SetIntLong("Est�s en la llamada calle del comercio del poblado de Enalel. "
    "En ella podr�s encontrar multitud de tiendas y productos aut�ctonos de la "
    "zona. La calle discurre de este a oeste. Al norte se encuentra la herrer�a "
    "de Krolle y al sur est� la entrada de la gran casa de la familia Fhainfos.\n");
    SetIndoors(0);
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail("suelo","El suelo de arena est� lleno de pisadas de los transeuntes.\n");
    AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible "
    "distinguir un rastro.\n");
    AddExit("este",ENALHAB"poblado/calles/calle02");
    AddExit("oeste",ENALHAB"poblado/calles/calle04");
    AddExit("norte",ENALHAB"poblado/tiendas/herreria");
    AddExit("sur",ENALHAB"poblado/casas/fhainfos/hall");
    AddDoor("norte", "la puerta de la herrer�a",
    "La puerta para entrar a la herrer�a del poblado.\n",
    ({"puerta", "puerta de la herrer�a", "puerta de la herreria", "puerta del norte"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddDoor("sur", "la puerta de la casa",
    "Es la puerta principal de la casa de la familia Fhainfos.\n",
    ({"puerta", "puerta de la casa", "puerta del sur"}));
}
