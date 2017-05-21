/**************************************************************************
fichero: minas25.c
Autor: Riberales
Creaci�n: 31/10/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("las minas enanas");
    SetIntLong("Te encuentras en una de las m�ltiples galer�as de las minas "
               "enanas de Kha-annu. Aqu� la humedad parece que se acent�a un "
               "poco. Esta galer�a contin�a hacia el norte, donde vislumbras "
               "unas luces, y en direcci�n suroeste.\n");



    AddExit("norte",HAB_PRIMERA_MINAS("minas24"));
    AddExit("suroeste",HAB_PRIMERA_MINAS("minas26"));

    AddItem(PNJ_MINAS("minero_primera"));
    AddGuardia();
}
