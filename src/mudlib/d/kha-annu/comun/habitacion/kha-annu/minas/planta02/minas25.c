/**************************************************************************
fichero: minas25.c
Autor: Riberales
Creaci�n: 11/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"


inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("la segunda planta de las minas");
    SetIntLong("Te encuentras en el segundo nivel de las minas enanas de Kha-"
               "Annu, en una de sus galer�as. Observas que aqu� hay una "
               "escalerilla que asciende al piso superior. La galer�a sigue "
               "en direcci�n noroeste y sur.\n");


    DetalleParedes();

    AddDetail(({"escalera","escalerilla"}),
                "Es una peque�a escalera met�lica que comunica este nivel con "
                "el superior.\n");

    AddDetail(({"hueco","agujero"}),
                "Es un agujero hecho en la piedra, que comunica este nivel "
                "con el de arriba.\n");

    AddExit("noroeste",HAB_SEGUNDA_MINAS("minas26"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas24"));
    AddExit("arriba",HAB_PRIMERA_MINAS("minas04"));
    AddGuardia();
}
