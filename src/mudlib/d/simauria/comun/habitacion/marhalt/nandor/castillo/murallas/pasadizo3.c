/****************************************************************************
Fichero: pasadizo3.c
Autor: Ratwor
Fecha: 29/12/2007
Descripción: Uno de los pasadizos del castillo para acceder a alguna de las torres.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("un pasadizo");
    SetIntLong("Estás en un pasadizo estrecho que atraviesa la muralla uniendo la parte "
    "baja de la torre de la Dama al sureste con el patio de armas al noroeste. Una "
    "antorcha solitaria ilumina tenuemente el pasaje.\n");
    AddDetail("antorcha", "Una pequeña antorcha sostenida por un soporte oxidado.\n");
    SetIntBright(20);
    SetLocate("el castillo de Nandor");
    AddExit("noroeste", CASTILLO("patio/patio22"));
    AddExit("sudeste", "./torre3_1");
}

