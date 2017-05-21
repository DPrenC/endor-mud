/****************************************************************************
Fichero: patio02.c
Autor: Ratwor
Fecha: 28/12/2007
Descripci�n: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    SetIntLong("El patio de armas forma en esta parte una especie de callej�n con las "
    "murallas cerr�ndolo por el norte y el oeste, y la pared de la herrer�a al sur.\n"
    "Hacia el noroeste un angosto pasadizo atraviesa la muralla hasta la parte baja "
    "del torre�n de la Inmolaci�n.\n");
    AddDetail("pasadizo", "La entrada del pasadizo es un arco bajo sin puerta ni "
    "talla alguna.\n");
    AddDetail(({"taller", "cobertizo", "herrer�a"}), "Apoyado en la muralla occidental "
    "hay un achaparrado cobertizo de techo de pizarra con un agujero a modo de "
    "chimenea que alberga la herrer�a donde se fabrica y repara la impedimenta de la "
    "guarnici�n.\n");
    AddExit("este", "./patio03");
    AddExit("noroeste", CASTILLO("murallas/pasadizo1"));
}


