/**************************************************************************
fichero: minas14.c
Autor: Riberales
Creación: 29/10/05
Descripción: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"
#include <materials.h>

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("una cueva en las minas");
    SetIntLong("Has aparecido en una estancia cerrada en las minas de "
               "Kha-annu. Las paredes te demuestran que aquí se halló una "
               "gran cantidad de mineral, pues están totalmente picadas. Al "
               "sur hay un pequeño arco que te lleva a una de las galerías "
               "principales del primer nivel.\n");

    SetTipo(M_HIERRO);
    DetalleVeta();



    AddExit("sur",HAB_PRIMERA_MINAS("minas13"));

    AddItem(PNJ_MINAS("minero_primera"),REFRESH_DESTRUCT);
    AddGuardia();
}
