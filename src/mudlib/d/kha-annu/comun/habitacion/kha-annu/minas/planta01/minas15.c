/**************************************************************************
fichero: minas15.c
Autor: Riberales
Creaci�n: 31/10/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("las galer�as enanas");
    SetIntLong("Vagas por las galer�as enanas, y cada vez son m�s abruptas e "
               "invitan al extrav�o. Tanto t�nel y tanta estancia sin salida "
               "hacen de este lugar un buen sitio para perderse. Al sur "
               "observas una c�mara bastante desgastada, mientras que la "
               "galer�a sigue su rumbo este oeste.\n");

    AddDetail(({"camara","c�mara"}),
                "Es una estancia donde parece que los enanos han hecho una "
                "buena extracci�n de mineral.\n");

    DetalleParedes();

    AddExit("este",HAB_PRIMERA_MINAS("minas13"));
    AddExit("sur",HAB_PRIMERA_MINAS("minas16"));
    AddExit("oeste",HAB_PRIMERA_MINAS("minas17"));
    AddGuardia();
}
