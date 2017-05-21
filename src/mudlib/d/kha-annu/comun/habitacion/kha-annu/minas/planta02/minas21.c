/**************************************************************************
fichero: minas21.c
Autor: Riberales
Creaci�n: 11/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un angosto t�nel");
    SetIntLong("Est�s en una galer�a bastante estrecha y sin iluminaci�n "
               "alguna, quitando la que proviene del este, la cual te permite "
               "observar en la pared una zona de la roca sin tratar. Un "
               "peque�o pasaje se abre hacia el norte, el t�nel sigue en "
               "direcci�n oeste, mientras que al este hay un cruce.\n");

    DetalleParedes();

    AddExit("norte",HAB_SEGUNDA_MINAS("minas30"));
    AddExit("oeste",HAB_SEGUNDA_MINAS("minas22"));
    AddExit("este",HAB_SEGUNDA_MINAS("minas20"));
    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
    AddGuardia();
}
