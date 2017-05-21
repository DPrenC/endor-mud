/**************************************************************************
fichero: minas30.c
Autor: Riberales
Creación: 02/11/05
Descripción: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("las galerías de Kha-annu");
    SetIntLong("Vagas por una de las varias galerías que componen esta "
               "primera planta de las minas enanas de Kha-annu. El túnel en "
               "el que te encuentras es bastante oscuro, aunque en dirección "
               "sudeste parece que hay algún tipo de emisión luminosa, no "
               "así como por el noroeste, donde las tinieblas se apoderan del "
               "camino.\n");


    DetalleParedes();


    AddExit("noroeste",HAB_PRIMERA_MINAS("minas29"));
    AddExit("sudeste",HAB_PRIMERA_MINAS("minas31"));
    AddItem(PNJ_MINAS("minero_primera"),REFRESH_DESTRUCT);
    AddGuardia();
}
