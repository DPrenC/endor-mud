/****************************************************************************
Fichero: calle9.c
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
    SetIntShort("una calle de Nandor");
    SetIntLong("Esta calle parece algo solitaria, pero es notablemente m�s amplia que "
        "el callej�n del sur. A ambos lados tienes paredes pertenecientes a viviendas,"
        " aunque sus entradas est�n por otra parte.\n Al norte comienza la calle"
        " Narwhald, donde puedes apreciar el cartel de una tienda.\n");
    SetIntNoise("Por esta parte de la villa s�lo escuchas silencio.\n");
    SetIndoors(0);
    AddDetail(({"pared","paredes","viviendas","vivienda"}), "La pared del este pertenece "
        "a la armer�a cuya entrada se encuentra en la calle paralela, y la"
        " del oeste pertenece a una vivienda que hay algo m�s al norte en la calle "
        "Narwhald.\n");
    AddDetail(({"tienda","cartel","letrero"}), "Todav�a est�s muy lejos para apreciar de"
        " que se trata esa tienda.\n");
    AddExit("norte","calle10");
    AddExit("sur","calle8");
}
