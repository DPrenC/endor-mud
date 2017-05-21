/****************************************************************************
Fichero: calle8.c
Autor: Ratwor
Fecha: 01/11/2006
Descripción:  Un callejón de Nandor.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("un callejón");
    SetIntLong("Te encuentras en un pequeño callejón, entre la casa de tributos y un "
        " pequeño templo, que desemboca   en la plaza de la aldea de Nandor.\n"
        " Desde aquí puedes apreciar la majestuosidad de la encina que reina en la plaza"
        " que se encuentra al suroeste.\n Al norte parece que se ensancha la calle.\n");
    SetIntNoise("Escuchas a lo lejos el típico sonido de una plaza.\n");
    SetIndoors(0);
    AddDetail("casa de tributos", "Es un edificio de piedra donde los aldeanos "
    "acuden a pagar los tributos impuestos por el noble.\n");
    AddDetail(({"templo", "pequeño templo", "pequeno templo"}),
        "Desde aquí sólo se puede apreciar el lateral del templo, quizá el"
        " muro necesite alguna restauración.\n");
    AddDetail(({"encina","arbol","árbol"}), "Ves una formidable encina que reina en la"
        " plaza del suroeste.\n");
    AddExit("suroeste","./calle42n");
        AddExit("norte","./calle9");
    AddItem(PNJ("marhalt/pueblerinos_nandor"),REFRESH_DESTRUCT,1);
}
