/**************************************************************************
fichero: minas11.c
Autor: Riberales
Creaci�n: 28/10/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("una oscura galer�a");
    SetIntLong("Apenas observas que te hallas en una galer�a de las minas de "
               "Kha-annu. Aqu� la luz de las antorchas escasamente llega, y "
               "le da al lugar un toque t�trico. Consigues divisar algo m�s "
               "de claridad al nordeste, mientras que el pasaje contin�a "
               "inexorable en direcci�n suroeste.\n");

    DetalleParedes();


    AddExit("nordeste",HAB_PRIMERA_MINAS("minas03"));
    AddExit("suroeste",HAB_PRIMERA_MINAS("minas12"));

    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
    AddGuardia();
}
