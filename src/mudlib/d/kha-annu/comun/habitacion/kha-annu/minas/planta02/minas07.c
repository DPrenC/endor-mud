/**************************************************************************
fichero: minas07.c
Autor: Riberales
Creaci�n: 9/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un peque�o pasaje");
    SetIntLong("Te encuentras en el interior de las minas de Kha-annu, en la "
               "segunda planta, y con la orientaci�n seriamente trastornada. "
               "Caminas por un t�nel bastante angosto y oscuro, aunque al "
               "nordeste te parece observar unas antorchas. El t�nel, sin "
               "embargo, contin�a en direcci�n noroeste, y al sur observas un "
               "desv�o.\n");

    DetalleParedes();
    AddItem(PNJ_MINAS("minero_segunda"),REFRESH_DESTRUCT);

    AddExit("noroeste",HAB_SEGUNDA_MINAS("minas08"));
    AddExit("nordeste",HAB_SEGUNDA_MINAS("minas06"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas12"));
    AddGuardia();
}
