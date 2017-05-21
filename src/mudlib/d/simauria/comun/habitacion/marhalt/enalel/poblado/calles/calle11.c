/*

    Nombre      : calle11
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Calle de la empalizada

*/
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetIntShort("la calle de la empalizada");
    SetIntLong("Estás en la calle de la empalizada. La empalizada que rodea "
    "todo el poblado se encuentra al norte y la parte trasera de las tiendas "
    "que dan a la calle del comercio están hacia el sur. La calle continua al "
    "suroeste y al este.\n");
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail(({"suelo"}),"El suelo de arena está lleno de pisadas de los transeuntes.\n");
    AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible distinguir un rastro.\n");
    AddDetail(({"empalizada"}),"Es una empalizada de madera que rodea todo el poblado.\n");
    AddExit("suroeste",ENALHAB"poblado/calles/calle12");
    AddExit("este",ENALHAB"poblado/calles/calle10");
    AddItem(ENALPNJ"otros/pueblerino",REFRESH_DESTRUCT,d2());
}
