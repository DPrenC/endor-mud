/****************************************************************************
Fichero: patio19.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    SetIntLong(QueryIntLong()+"Al este se encuentra el cobertizo de las pajareras, "
    "mientras que mas al oeste se alza la torre del homenaje con su ancho portón.\n");
    AddDetail(({"cobertizo", "pajareras", "pajareras"}), "El cobertizo de las pajareras "
    "es un recinto con paredes de adobe y techo de pizarra cuya parte frontal es una "
    "delgada valla de alambre que proporciona luz a las aves de su interior.\n");
    AddExit("oeste",  "./patio18");
    AddExit("este", "./pajareras");
    AddExit("norte", "./patio17");
    AddExit("noroeste", "./patio16");
    AddExit("sur", "./patio21");
    AddExit("suroeste", "./patio20");
    AddDoor("este", "la puerta de las pajareras",
"Es una puerta de madera para entrar a la estancia donde se guardan las aves del castillo.\n",
({"puerta", "puerta de madera", "puerta de las pajareras", "puerta del este"}));
}


