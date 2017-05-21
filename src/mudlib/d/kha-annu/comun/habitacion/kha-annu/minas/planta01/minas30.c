/**************************************************************************
fichero: minas30.c
Autor: Riberales
Creaci�n: 02/11/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("las galer�as de Kha-annu");
    SetIntLong("Vagas por una de las varias galer�as que componen esta "
               "primera planta de las minas enanas de Kha-annu. El t�nel en "
               "el que te encuentras es bastante oscuro, aunque en direcci�n "
               "sudeste parece que hay alg�n tipo de emisi�n luminosa, no "
               "as� como por el noroeste, donde las tinieblas se apoderan del "
               "camino.\n");


    DetalleParedes();


    AddExit("noroeste",HAB_PRIMERA_MINAS("minas29"));
    AddExit("sudeste",HAB_PRIMERA_MINAS("minas31"));
    AddItem(PNJ_MINAS("minero_primera"),REFRESH_DESTRUCT);
    AddGuardia();
}
