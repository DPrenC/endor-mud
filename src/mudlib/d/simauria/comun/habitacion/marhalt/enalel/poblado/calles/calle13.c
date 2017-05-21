/*

    Nombre      : calle13
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Calle de las cosechas

*/
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetIntShort("la calle de las cosechas");
    SetIntLong("Estás en la calle de las cosechas. La empalizada que rodea el "
    "poblado se puede ver desde aquí. La calle continúa al norte hacia la calle "
    "del comercio y al suroeste hacia el cruce entre la calle de las cosechas y "
    "la calle del manzanar.\n");
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail(({"suelo"}),"El suelo de arena está lleno de pisadas de los transeuntes.\n");
    AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible distinguir un rastro.\n");
    AddDetail(({"empalizada"}),"Es una empalizada de madera que rodea todo el poblado.\n");
    AddExit("norte",ENALHAB"poblado/calles/calle02");
    AddExit("suroeste",ENALHAB"poblado/calles/calle14");
    AddItem(ENALPNJ"otros/pueblerino",REFRESH_DESTRUCT,d2());
}
