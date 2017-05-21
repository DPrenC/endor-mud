/**************************************************************************
fichero: minas14.c
Autor: Riberales
Creaci�n: 29/10/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"
#include <materials.h>

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("una cueva en las minas");
    SetIntLong("Has aparecido en una estancia cerrada en las minas de "
               "Kha-annu. Las paredes te demuestran que aqu� se hall� una "
               "gran cantidad de mineral, pues est�n totalmente picadas. Al "
               "sur hay un peque�o arco que te lleva a una de las galer�as "
               "principales del primer nivel.\n");

    SetTipo(M_HIERRO);
    DetalleVeta();



    AddExit("sur",HAB_PRIMERA_MINAS("minas13"));

    AddItem(PNJ_MINAS("minero_primera"),REFRESH_DESTRUCT);
    AddGuardia();
}
