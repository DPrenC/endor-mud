/**************************************************************************
fichero: minas06.c
Autor: Riberales
Creaci�n: 9/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un cruce de galer�as");
    SetIntLong("Has aparecido en un cruce de galer�as, en el segundo nivel de "
               "las minas enanas. Parece que el t�nel principal va hacia el "
               "norte y el este, mientras que al suroeste se encuentra una "
               "galer�a algo m�s estrecha.\n");

    DetalleParedes();

    AddExit("norte",HAB_SEGUNDA_MINAS("minas05"));
    AddExit("este",HAB_SEGUNDA_MINAS("minas29"));
    AddExit("suroeste",HAB_SEGUNDA_MINAS("minas07"));
    AddItem(OTRO_MINAS("carretilla_vacia"));
    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
    AddGuardia();
}
