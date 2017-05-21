/*

    Nombre      : calle24
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
    SetIntShort("el centro del camino de la meditaci�n");
    SetIntLong("Est�s en el centro del camino de la meditaci�n. Frente a ti, hacia "
    "el norte, se alza el enorme templo del dios Nhaigel, dios de la naturaleza. El "
    "camino de la meditaci�n transcurre de nordeste a noroeste.\n");
    SetIndoors(0);
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail("suelo","El suelo de arena est� lleno de pisadas de los transeuntes.\n");
    AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible "
    "distinguir un rastro.\n");
    AddExit("nordeste",ENALHAB"poblado/calles/calle23");
    AddExit("noroeste",ENALHAB"poblado/calles/calle25");
    AddExit("norte",ENALHAB"poblado/varios/templo_nhaigel");
    AddDoor("norte", "la puerta del templo",
    "Es una peque�a puerta para entrar al templo del Dios Nhaigel.\n",
    ({"puerta", "puerta del norte", "puerta del templo"}));
}
