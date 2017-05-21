/****************************************************************************
Fichero: patio17.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    SetIntLong(QueryIntLong()+"Al este se encuentran las perreras.\n");
    AddDetail("perreras", "Es un espacio descubierto entre dos cobertizos situados al "
    "norte y al sur, cerrado por una verja y una tosca puerta de madera, donde se "
    "encierran los perros guardianes y de caza.\n");
    AddDetail("verja", "Una verja de barrotes de hierro algo descascarillados por el "
    "óxido, levantada sobre un bajo muro de piedra con una destartalada puerta en la "
    "parte central.\n");
    AddExit("oeste",  "./patio16");
    AddExit("este", "./perreras");
    AddExit("norte", "./patio15");
    AddExit("noroeste", "./patio14");
    AddExit("sur", "./patio19");
    AddExit("suroeste", "./patio18");
    AddDoor("este", "la puerta de las perreras",
"Es una puerta de madera para entrar a las perreras del castillo.\n",
({"puerta", "puerta de madera", "puerta de las perreras", "puerta del este"}));
}


