/**************************************************************************
fichero: minas23.c
Autor: Riberales
Creaci�n: 31/10/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"
#include <materials.h>

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("las minas de Kha-annu");
    SetIntLong("Est�s internado en las confusas minas de Kha-annu. El orden "
               "que los enanos han seguido para ir abriendo t�neles y "
               "galer�as no es precisamente organizado, aunque unas minas "
               "tampoco tienen el porqu� de serlo. Te percatas en una de las "
               "paredes de que hay un fragmento de roca sin apenas tratar, y "
               "la luz que proviene del oeste te otorga la iluminaci�n "
               "necesaria para picar en ella.\n");


    SetTipo(M_HIERRO);
    DetalleVeta();



    AddExit("oeste",HAB_PRIMERA_MINAS("minas24"));
    AddExit("sudeste",HAB_PRIMERA_MINAS("minas10"));

    AddItem(PNJ_MINAS("minero_primera"));
    AddGuardia();
}

