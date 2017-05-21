/****************************************************************************
Fichero: escalera1_3.c
Autor: Ratwor
Fecha: 30/03/2008
Descripci�n: la escalera de los torreones.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("una escalera de caracol, sobre el torre�n de la Inmolaci�n");
    SetIntLong("Est�s en el centro de la plataforma que corona el torre�n de la "
    "Inmolaci�n. A un lado una estrecha escalera de caracol desciende hacia el interior "
    "de la torre y a tu alrrededor se extiende la plataforma almenada.\n");
    AddDetail("suelo", "El suelo est� formado por pesadas losas de piedra  que "
    "aparecen ennegrecidas y carcomidas como si el fuego las hubiera da�ado.\n");
    SetIndoors(0);
    AddExit("sudeste", "./torre1_09");
    AddExit("suroeste", "./torre1_12");
    AddExit("noroeste", "./torre1_11");
    AddExit("nordeste", "./torre1_10");
    AddExit("abajo", "./escalera1_2");
}
