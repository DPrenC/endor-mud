/****************************************************************************
Fichero: calle8.c
Autor: Ratwor
Fecha: 01/11/2006
Descripci�n:  Un callej�n de Nandor.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("un callej�n");
    SetIntLong("Te encuentras en un peque�o callej�n, entre la casa de tributos y un "
        " peque�o templo, que desemboca   en la plaza de la aldea de Nandor.\n"
        " Desde aqu� puedes apreciar la majestuosidad de la encina que reina en la plaza"
        " que se encuentra al suroeste.\n Al norte parece que se ensancha la calle.\n");
    SetIntNoise("Escuchas a lo lejos el t�pico sonido de una plaza.\n");
    SetIndoors(0);
    AddDetail("casa de tributos", "Es un edificio de piedra donde los aldeanos "
    "acuden a pagar los tributos impuestos por el noble.\n");
    AddDetail(({"templo", "peque�o templo", "pequeno templo"}),
        "Desde aqu� s�lo se puede apreciar el lateral del templo, quiz� el"
        " muro necesite alguna restauraci�n.\n");
    AddDetail(({"encina","arbol","�rbol"}), "Ves una formidable encina que reina en la"
        " plaza del suroeste.\n");
    AddExit("suroeste","./calle42n");
        AddExit("norte","./calle9");
    AddItem(PNJ("marhalt/pueblerinos_nandor"),REFRESH_DESTRUCT,1);
}
