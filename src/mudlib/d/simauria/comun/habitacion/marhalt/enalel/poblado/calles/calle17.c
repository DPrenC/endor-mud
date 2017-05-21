/*

    Nombre      : calle17
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Calle de las cosechas

*/
#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <materials.h>
#include <scheduler.h>
inherit SIM_ROOM;

create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetIntShort("la calle de las cosechas");
    SetIntLong("Estás en la calle de las cosechas. Pocas estatuas y postes "
    "se ven en esta parte de la calle.\n Al norte de aquí se encuentra el banco "
    "del poblado, la calle de las cosechas transcurre de este a oeste.\n");
    SetIndoors(0);
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail("suelo","El suelo de arena está lleno de pisadas de los transeuntes.\n");
    AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible "
    "distinguir un rastro.\n");
    AddDetail(({"postes","poste","estatuillas","estatuilla"}),"Son los símbolos "
    "que recuerdan algunas cosechas de gran calidad o hazañas de algunos héroes locales.\n");
    AddExit("este",ENALHAB"poblado/calles/calle16");
    AddExit("oeste",ENALHAB"poblado/calles/calle18");
    AddExit("norte",ENALHAB"poblado/varios/banco");
    AddDoor("norte", "la puerta del banco",
    "La puerta para entrar al banco del poblado.\n",
    ({"puerta", "puerta del banco", "puerta del norte"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}
