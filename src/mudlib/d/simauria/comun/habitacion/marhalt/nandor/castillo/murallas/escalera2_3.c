/****************************************************************************
Fichero: escalera2_3.c
Autor: Ratwor
Fecha: 30/03/2008
Descripci�n: la escalera de los torreones.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("una escalera de caracol, sobre el torre�n de C�nor");
    SetIntLong("Est�s en el centro de la plataforma que corona el torre�n de C�nor. A "
    "un lado una estrecha escalera de caracol desciende hacia el interior de la torre y "
    "a tu alrrededor se extiende la plataforma almenada.\n");
    AddDetail("suelo", "El suelo est� formado por pesadas losas de piedra perfectamente "
    "encajadas entre s�.\n");
    SetIndoors(0);
    AddExit("suroeste", "./torre2_12");
    AddExit("noroeste", "./torre2_11");
    AddExit("nordeste", "./torre2_10");
    AddExit("sudeste", "./torre2_09");
    AddExit("abajo", "./escalera2_2");
    }
