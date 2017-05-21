/**************************************************************************
fichero: minas05.c
Autor: Riberales
Creación: 9/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("la segunda planta de las minas de Kha-annu");
    SetIntLong("Te encuentras en las siempre confusas minas enanas, y cada "
               "vez te es más difícil recordar la organización de las mismas. "
               "Dos túneles se dirigen al sudeste y nordeste respectivamente. "
               "En dirección sur te parece observar un cruce de galerías, "
               "mientras que al noroeste sigue el túnel por el que "
               "caminas.\n");

    DetalleParedes();

    AddExit("nordeste",HAB_SEGUNDA_MINAS("minas28"));AddExit("noroeste",HAB_SEGUNDA_MINAS("minas04"));
    AddExit("sudeste",HAB_SEGUNDA_MINAS("minas29"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas06"));
    AddGuardia();
}
