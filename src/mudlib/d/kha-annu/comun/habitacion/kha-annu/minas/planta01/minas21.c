/**************************************************************************
fichero: minas21.c
Autor: Riberales
Creaci�n: 31/10/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("una galer�a");
    SetIntLong("Observas uno de los t�neles de las minas de Kha-annu. "
               "La orientaci�n es un fen�meno que has perdido hace un buen "
               "rato, y piensas que todos los caminos son el mismo repetido. "
               "Ves un cruce de galer�as al norte, mientras que este t�nel "
               "se extiende en direcci�n oeste. Un par de antorchas te ayudan "
               "a proseguir tu ruta.\n");

    DetalleAntorchas();
    DetalleParedes();



    AddExit("norte",HAB_PRIMERA_MINAS("minas22"));
    AddExit("oeste",HAB_PRIMERA_MINAS("minas20"));

    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
    AddGuardia();
}
