/****************************************************************************
Fichero: pasadizo2.c
Autor: Ratwor
Fecha: 29/12/2007
Descripci�n: Uno de los pasadizos del castillo para acceder a alguna de las torres.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("un pasadizo");
    SetIntLong("Est�s en un pasadizo estrecho que atraviesa la muralla uniendo la parte "
    "baja del torre�n de C�nor al nordeste con el patio de armas al suroeste.\n Una "
    "antorcha solitaria ilumina tenuemente el pasaje.\n");
    AddDetail("antorcha", "Una peque�a antorcha sostenida por un soporte oxidado.\n");
    SetIntBright(20);
    SetLocate("el castillo de Nandor");
    AddExit("suroeste", CASTILLO("patio/patio08"));
    AddExit("nordeste", "./torre2_04");
}

