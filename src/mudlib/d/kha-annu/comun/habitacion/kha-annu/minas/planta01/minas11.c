/**************************************************************************
fichero: minas11.c
Autor: Riberales
Creación: 28/10/05
Descripción: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("una oscura galería");
    SetIntLong("Apenas observas que te hallas en una galería de las minas de "
               "Kha-annu. Aquí la luz de las antorchas escasamente llega, y "
               "le da al lugar un toque tétrico. Consigues divisar algo más "
               "de claridad al nordeste, mientras que el pasaje continúa "
               "inexorable en dirección suroeste.\n");

    DetalleParedes();


    AddExit("nordeste",HAB_PRIMERA_MINAS("minas03"));
    AddExit("suroeste",HAB_PRIMERA_MINAS("minas12"));

    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
    AddGuardia();
}
