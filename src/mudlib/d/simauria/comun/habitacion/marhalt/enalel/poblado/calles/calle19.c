/*

    Nombre      : calle19
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Calle del manzanar

*/
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetIntShort("la calle del manzanar");
    SetIntLong("Estás en la calle del manzanar. Al nordeste se encuentra la "
    "calle de las cosechas y hacia el suroeste continúa la calle del manzanar.\n");
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail(({"suelo"}),"El suelo de arena está lleno de pisadas de los transeuntes.\n");
    AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible distinguir un rastro.\n");
    AddExit("nordeste",ENALHAB"poblado/calles/calle15");
    AddExit("suroeste",ENALHAB"poblado/calles/calle20");
    AddItem(ENALPNJ"otros/pueblerino",REFRESH_DESTRUCT,d2());
}
