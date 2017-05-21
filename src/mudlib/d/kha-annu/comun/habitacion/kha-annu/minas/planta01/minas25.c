/**************************************************************************
fichero: minas25.c
Autor: Riberales
Creación: 31/10/05
Descripción: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("las minas enanas");
    SetIntLong("Te encuentras en una de las múltiples galerías de las minas "
               "enanas de Kha-annu. Aquí la humedad parece que se acentúa un "
               "poco. Esta galería continúa hacia el norte, donde vislumbras "
               "unas luces, y en dirección suroeste.\n");



    AddExit("norte",HAB_PRIMERA_MINAS("minas24"));
    AddExit("suroeste",HAB_PRIMERA_MINAS("minas26"));

    AddItem(PNJ_MINAS("minero_primera"));
    AddGuardia();
}
