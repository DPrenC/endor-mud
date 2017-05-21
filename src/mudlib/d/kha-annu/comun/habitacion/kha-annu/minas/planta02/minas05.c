/**************************************************************************
fichero: minas05.c
Autor: Riberales
Creaci�n: 9/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("la segunda planta de las minas de Kha-annu");
    SetIntLong("Te encuentras en las siempre confusas minas enanas, y cada "
               "vez te es m�s dif�cil recordar la organizaci�n de las mismas. "
               "Dos t�neles se dirigen al sudeste y nordeste respectivamente. "
               "En direcci�n sur te parece observar un cruce de galer�as, "
               "mientras que al noroeste sigue el t�nel por el que "
               "caminas.\n");

    DetalleParedes();

    AddExit("nordeste",HAB_SEGUNDA_MINAS("minas28"));AddExit("noroeste",HAB_SEGUNDA_MINAS("minas04"));
    AddExit("sudeste",HAB_SEGUNDA_MINAS("minas29"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas06"));
    AddGuardia();
}
