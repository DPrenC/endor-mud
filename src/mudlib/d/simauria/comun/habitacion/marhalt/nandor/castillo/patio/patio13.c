/****************************************************************************
Fichero: patio13.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    SetIntLong(QueryIntLong()+"Al este se encuentran las caballerizas, y hacia el oeste "
    "puedes ver un pozo.\n");
    AddDetail("caballerizas", "Un amplio cobertizo de paredes de piedra y techo de "
    "pizarra donde se guardan las monturas de los Dhes-Bláin.\n");
    AddDetail("pozo", "Es el pozo que proporciona agua al castillo.\n");
    AddExit("este", "./caballerizas");
    AddExit("oeste",  "./patio12");
    AddExit("norte", "./patio07");
    AddExit("noroeste", "./patio06");
    AddExit("sur", "./patio15");
    AddExit("suroeste", "./patio14");
    AddDoor("este", "la puerta de las caballerizas",
    "Es una ancha puerta de madera para entrar a las caballerizas.\n",
    ({"puerta", "puerta ancha", "ancha puerta", "puerta de las caballerizas",
        "puerta del este", "puerta de madera"}));
}


