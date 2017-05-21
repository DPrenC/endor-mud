/**************************************************************************
fichero: minas21.c
Autor: Riberales
Creación: 31/10/05
Descripción: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("una galería");
    SetIntLong("Observas uno de los túneles de las minas de Kha-annu. "
               "La orientación es un fenómeno que has perdido hace un buen "
               "rato, y piensas que todos los caminos son el mismo repetido. "
               "Ves un cruce de galerías al norte, mientras que este túnel "
               "se extiende en dirección oeste. Un par de antorchas te ayudan "
               "a proseguir tu ruta.\n");

    DetalleAntorchas();
    DetalleParedes();



    AddExit("norte",HAB_PRIMERA_MINAS("minas22"));
    AddExit("oeste",HAB_PRIMERA_MINAS("minas20"));

    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
    AddGuardia();
}
