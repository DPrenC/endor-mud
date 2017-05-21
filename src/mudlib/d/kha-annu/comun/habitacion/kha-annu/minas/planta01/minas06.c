/**************************************************************************
fichero: minas06.c
Autor: Riberales
Creaci�n: 28/10/05
Descripci�n: Room en primera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("una galer�a");
    SetIntLong("Observas la misma galer�a enana. Aqu�, el pasillo "
               "se estrecha un poco, por lo que notas la fr�a superficie de "
               "las paredes de roca. Adem�s, hay una antorcha, y al ser "
               "angosto el paso, la luz sale reflejada con m�s fuerza hacia "
               "el resto de la galer�a. �sta sigue de norte a sur, mientras "
               "al sudeste observas un peque�o pasadizo.\n");


    DetalleParedes();
    DetalleAntorchas();

    AddExit("norte",HAB_PRIMERA_MINAS("minas07"));
    AddExit("sur",HAB_PRIMERA_MINAS("minas05"));
    AddExit("sudeste",HAB_PRIMERA_MINAS("minas04"));
    AddGuardia();
}
