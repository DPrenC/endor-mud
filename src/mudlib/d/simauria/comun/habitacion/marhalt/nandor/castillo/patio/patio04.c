/****************************************************************************
Fichero: patio04.c
Autor: Ratwor
Fecha: 28/12/2007
Descripci�n: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    SetIntShort("el patio de armas, zona de entrenamiento");
    SetIntLong(QueryIntLong()+"En esta parte del patio, una empinada escalera de "
    "piedra asciende al adarbe de la muralla.\n");
    AddDetail(({"escaleras", "escalera"}), "Una estrecha escalera de piedra algo "
    "deteriorada que comunica el adarbe de la muralla con el patio de armas, justo "
    "frente a una escalera gemela existente en la porci�n de muralla del otro lado de "
    "la puerta.\n"
    "�sta disposici�n obedece al prop�sito de facilitar el r�pido acceso entre lo alto "
    "del muro y el interior de las puertas, de forma que si alg�n enemigo penetra por "
    "ellas se encuentre atacado por ambos flancos por los defensores que bajen por las "
    "escaleras.\n");
    AddExit("este", "./patio05");
    AddExit("oeste",  "./patio03");
    AddExit("sur", "./patio10");
    AddExit("sudeste", "./patio11");
    AddExit("suroeste", "./patio09");
    AddExit("nordeste", "./patio01");
    AddExit("arriba", CASTILLO("murallas/muralla06"));
}


