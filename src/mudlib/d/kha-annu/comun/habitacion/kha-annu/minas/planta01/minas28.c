/**************************************************************************
fichero: minas28.c
Autor: Riberales
Creaci�n: 02/11/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("un oscuro t�nel");
    SetIntLong("Te has internado en lo que parece la galer�a menos iluminada "
               "de toda esta planta. Una tenue luz asoma en direcci�n norte, "
               "mas el t�nel sigue tenebroso e inexorable al suroeste. Para "
               "colmo de males, las paredes est�n muy pr�ximas, lo que hace "
               "m�s dif�cil el paso.\n");

    DetalleParedes();
    SetIntBright(0);


    AddExit("norte",HAB_PRIMERA_MINAS("minas27"));
    AddExit("suroeste",HAB_PRIMERA_MINAS("minas29"));
    AddItem(PNJ_MINAS("minero_primera"),REFRESH_DESTRUCT,2);
        AddGuardia();
}
