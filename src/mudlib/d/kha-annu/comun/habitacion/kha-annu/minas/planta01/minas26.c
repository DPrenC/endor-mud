/**************************************************************************
fichero: minas26.c
Autor: Riberales
Creaci�n: 02/11/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("un pasadizo de las minas");
    SetIntLong("Te encuentras en el interior de las minas enanas. Parece que"
               " a esta altura de la galer�a hay una peque�a escalerilla que "
               "comunica con el piso inferior. A parte de ello, no encuentras "
               "elemento alguno para diferenciar este tramo con alg�n otro. La"
               " galer�a sigue hacia el nordeste y hacia el este.\n");

    DetalleParedes();

    AddDetail(({"hueco","agujero"}),
                "Es un agujero hecho en la piedra, que comunica este nivel "
                "con el inferior.\n");

    AddDetail(({"escalerilla","escalera"}),
                "Es una peque�a escalera met�lica que comunica este nivel "
                "con el inferior.\n");

    AddExit("abajo",HAB_SEGUNDA_MINAS("minas01"));
    AddExit("nordeste",HAB_PRIMERA_MINAS("minas25"));
    AddExit("oeste",HAB_PRIMERA_MINAS("minas27"));
    AddGuardia();
}
