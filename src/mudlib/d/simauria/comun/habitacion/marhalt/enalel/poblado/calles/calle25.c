/*

    Nombre      : calle25
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripci�n : Camino de la meditaci�n

*/
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetIntShort("el camino de la meditaci�n");
    SetIntLong("Est�s en el sendero conocido como el camino de la meditaci�n. Aqu�, "
    "los fieles seguidores del dios Nhaigel, meditan y purgan sus pecados antes de "
    "entrar al templo. El camino termina al norte, donde se une con la calle del "
    "manzanar.\n Al sudeste contin�a el camino de la meditaci�n.\n");
    SetIndoors(0);
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail("suelo","El suelo de arena est� lleno de pisadas de los transeuntes.\n");
    AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible "
    "distinguir un rastro.\n");
    AddExit("norte",ENALHAB"poblado/calles/calle22");
    AddExit("sudeste",ENALHAB"poblado/calles/calle24");
    AddItem(ENALPNJ"otros/pueblerino",REFRESH_DESTRUCT,d2());
}
