/***
Fichero: calle_04.c
Autor: kastwey@simauria
Descripción: Fin del sendero de Siempreunidos.
Creación: 07/12/2004
***/

#include "path.h"

inherit STD_FAERIA("hab_siempreunidos");


create()
{
    ::create();
    SetIntShort("la calle principal de Siempreunidos");
    SetIntLong(W("Te encuentras en la parte norte del pueblo de Siempreunidos, al final del sendero que lo atraviesa de norte a sur.\n"
    "Hacia el sur continúa el sendero, y hacia el norte tienes la casa de Shadezzar, el capitán de la guardia del poblado.\n"));
    SetOficina(HAB_PUESTO("calles/calle_03"));
    SetOutdoors(1);
    AddExit("sur", HAB_PUESTO("calles/calle_03"));
    AddExit("norte", HAB_PUESTO("casas/casa_shadezzar"));
    AddItem(PNJ_PUESTO("encubierto"), REFRESH_HOME, 1);
}