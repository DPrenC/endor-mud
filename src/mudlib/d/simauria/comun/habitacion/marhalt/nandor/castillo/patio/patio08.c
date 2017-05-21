/****************************************************************************
Fichero: patio08.c
Autor: Ratwor
Fecha: 28/12/2007
Descripci�n: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    SetIntLong(QueryIntLong()+"Aqu� el patio de armas forma un callej�n entre la "
    "muralla y las caballerizas. Al nordeste un angosto pasadizo atraviesa la muralla "
    "uniendo el patio con el torre�n de C�nor.\n");
    AddDetail("caballerizas", "Un amplio cobertizo de paredes de piedra y techo de "
    "pizarra donde se guardan las monturas de los Dhes-Bl�in.\n");
    AddDetail("pozo", "Es el pozo que proporciona agua al castillo.\n");
    AddExit("oeste",  "./patio07");
    AddExit("nordeste", CASTILLO("murallas/pasadizo2"));
}


