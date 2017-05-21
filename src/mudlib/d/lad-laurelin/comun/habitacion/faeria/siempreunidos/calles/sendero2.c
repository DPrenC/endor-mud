/***
Fichero: sendero2.c
Autor: kastwey@simauria
Descripción: Sendero para entrar al pueblo de Siempreunidos.
Creación: 17/12/2004
***/

#include "path.h"

inherit STD_FAERIA("hab_siempreunidos");

create()
{
    ::create();
    SetIntShort("un sendero en el bosque");
    SetIntLong(W("Te encuentras en un sendero que discurre de norte a sur.\n"
    "En esta parte, observas como el sendero se ensancha, desembocando al norte en lo que parece la calle de un pequeño poblado.\n"));
    SetIntSmell("Huele a naturaleza.\n");
    SetIntNoise("Escuchas el sonido de la naturaleza.\n");
    SetOutdoors(1);
    AddExit("sur",HAB_PUESTO("/calles/sendero1"));
    AddExit("norte",HAB_PUESTO("calles/calle_01"));
}

  