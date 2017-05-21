/**************************************************************************
fichero: minas27.c
Autor: Riberales
Creaci�n: 27/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"


inherit HAB_SEGUNDA_MINAS("segunda_base");

create()
{
    ::create();

    SetIntShort("una bifurcaci�n de t�neles y galer�as");
    SetIntLong("Has llegado a otro cruce de galer�as y t�neles que reinan en "
               "estas minas enanas. En la pared norte observas unas antorchas "
               "que te permiten observar los distintos caminos que van en "
               "direcci�n noroeste, nordeste, sudeste y suroeste.\n");

    DetalleParedes();
    DetalleAntorchas();

    AddExit("nordeste",HAB_SEGUNDA_MINAS("minas26"));
    AddExit("noroeste",HAB_SEGUNDA_MINAS("minas28"));
    AddExit("suroeste",HAB_SEGUNDA_MINAS("minas29"));
    AddExit("sudeste",HAB_SEGUNDA_MINAS("minas31"));
    AddGuardia();
}
