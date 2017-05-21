/**************************************************************************
fichero: minas07.c
Autor: Riberales
Creación: 9/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un pequeño pasaje");
    SetIntLong("Te encuentras en el interior de las minas de Kha-annu, en la "
               "segunda planta, y con la orientación seriamente trastornada. "
               "Caminas por un túnel bastante angosto y oscuro, aunque al "
               "nordeste te parece observar unas antorchas. El túnel, sin "
               "embargo, continúa en dirección noroeste, y al sur observas un "
               "desvío.\n");

    DetalleParedes();
    AddItem(PNJ_MINAS("minero_segunda"),REFRESH_DESTRUCT);

    AddExit("noroeste",HAB_SEGUNDA_MINAS("minas08"));
    AddExit("nordeste",HAB_SEGUNDA_MINAS("minas06"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas12"));
    AddGuardia();
}
