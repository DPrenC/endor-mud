/**************************************************************************
fichero: minas30.c
Autor: Riberales
Creaci�n: 27/11/05
Descripci�n: Room en segunda planta de las minas, acceso a la tercera y �ltima.
**************************************************************************/


#include "path.h"


inherit HAB_SEGUNDA_MINAS("segunda_base");

create()
{
    ::create();

    SetIntShort("el segundo nivel de las minas");
    SetIntLong("Te encuentras en la segunda planta de las minas de Kha-annu, "
               "frente a la escalerilla que comunica este nivel con el "
               "inferior. Observas un peque�o pasaje en direcci�n sur, y un "
               "t�nel que va al noroeste y nordeste.\n");

    DetalleParedes();
    AddDetail(({"hueco","agujero"}),
                "Es un agujero hecho en la piedra, que comunica la segunda "
                "planta con la m�s profunda.\n");

    AddDetail(({"escalerilla","escalera"}),
                "Es una peque�a escalera met�lica que comunica este nivel con "
                "el inferior.\n");

    AddExit("nordeste",HAB_SEGUNDA_MINAS("minas31"));
    AddExit("noroeste",HAB_SEGUNDA_MINAS("minas29"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas21"));
    AddExit("abajo",HAB_TERCERA_MINAS("minas01"));
    AddGuardia();
}

