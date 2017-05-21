/****************************************************************************
Fichero: patio02.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    SetIntLong("El patio de armas forma en esta parte una especie de callejón con las "
    "murallas cerrándolo por el norte y el oeste, y la pared de la herrería al sur.\n"
    "Hacia el noroeste un angosto pasadizo atraviesa la muralla hasta la parte baja "
    "del torreón de la Inmolación.\n");
    AddDetail("pasadizo", "La entrada del pasadizo es un arco bajo sin puerta ni "
    "talla alguna.\n");
    AddDetail(({"taller", "cobertizo", "herrería"}), "Apoyado en la muralla occidental "
    "hay un achaparrado cobertizo de techo de pizarra con un agujero a modo de "
    "chimenea que alberga la herrería donde se fabrica y repara la impedimenta de la "
    "guarnición.\n");
    AddExit("este", "./patio03");
    AddExit("noroeste", CASTILLO("murallas/pasadizo1"));
}


