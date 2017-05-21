/**************************************************************************
fichero: minas27.c
Autor: Riberales
Creación: 27/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"


inherit HAB_SEGUNDA_MINAS("segunda_base");

create()
{
    ::create();

    SetIntShort("una bifurcación de túneles y galerías");
    SetIntLong("Has llegado a otro cruce de galerías y túneles que reinan en "
               "estas minas enanas. En la pared norte observas unas antorchas "
               "que te permiten observar los distintos caminos que van en "
               "dirección noroeste, nordeste, sudeste y suroeste.\n");

    DetalleParedes();
    DetalleAntorchas();

    AddExit("nordeste",HAB_SEGUNDA_MINAS("minas26"));
    AddExit("noroeste",HAB_SEGUNDA_MINAS("minas28"));
    AddExit("suroeste",HAB_SEGUNDA_MINAS("minas29"));
    AddExit("sudeste",HAB_SEGUNDA_MINAS("minas31"));
    AddGuardia();
}
