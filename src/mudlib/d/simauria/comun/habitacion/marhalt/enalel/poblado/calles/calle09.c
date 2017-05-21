/*

    Nombre      : calle09
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripci�n : Calle de la empalizada

*/
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetIntShort("la calle de la empalizada");
    SetIntLong("Est�s en la calle de la empalizada. Parece que no hay "
    "ning�n edificio cuyas puertas d� hacia esta calle. La calle contin�a "
    "al oeste y al este.\n");
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail(({"suelo"}),"El suelo de arena est� lleno de pisadas de los transeuntes.\n");
    AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible distinguir un rastro.\n");
    AddDetail(({"empalizada"}),"Es una empalizada de madera que rodea todo el poblado.\n");
    AddExit("este",ENALHAB"poblado/calles/calle08");
    AddExit("oeste",ENALHAB"poblado/calles/calle10");
    AddItem(ENALPNJ"otros/pueblerino",REFRESH_DESTRUCT,d2());
}
