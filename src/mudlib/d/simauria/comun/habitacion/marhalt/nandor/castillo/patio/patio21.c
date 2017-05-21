/****************************************************************************
Fichero: patio21.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    SetIntLong(QueryIntLong()+
    "Al sur se alza la muralla a la que se accede por una estrecha escalera situada al "
    "oeste, mientras que hacia el este el patio forma un callejón entre la pared "
    "lateral de un cobertizo y la muralla, en la que hay practicada una entrada baja.\n");
    AddDetail("escalera", "Una empinada escalera de piedra con algunos escalones a "
    "medio derrumbar que une el patio de armas con la muralla sur.\n");
    AddDetail(({"cobertizo", "pajareras", "pajareras"}), "El cobertizo de las pajareras "
    "es un recinto con paredes de adobe y techo de pizarra cuya parte frontal es una "
    "delgada valla de alambre que proporciona luz a las aves de su interior.\n");
    AddExit("este", "./patio22");
    AddExit("oeste", "./patio20");
    AddExit("norte", "./patio19");
    AddExit("noroeste", "./patio18");
}


