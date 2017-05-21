/**************************************************************************
fichero: minas22.c
Autor: Riberales
Creaci�n: 31/10/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("un t�nel de las minas");
    SetIntLong("Est�s en una de las galer�as de esta mina. Esta parte est� "
               "bastante bien iluminada, pues unas antorchas situadas al sur "
               "te protegen de la casi siempre temida oscuridad. Al norte te "
               "parece advertir un cruce de galer�as, mientras que en la que "
               "est�s situado prosigue en direcci�n sur.\n");

    DetalleParedes();


    AddExit("sur",HAB_PRIMERA_MINAS("minas21"));
    AddExit("norte",HAB_PRIMERA_MINAS("minas10"));

    AddItem(PNJ_MINAS("minero_primera"));
    AddGuardia();
}

