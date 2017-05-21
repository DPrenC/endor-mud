/**************************************************************************
fichero: minas19.c
Autor: Riberales
Creaci�n: 11/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un extremo de la galer�a");
    SetIntLong("Te encuentras en uno de los extremos de una de las muchas "
               "galer�as que pueblan estas minas. Al norte observas un cruce "
               "de t�neles, mientras que la galer�a discurre hacia el sur.\n");

    DetalleParedes();


    AddExit("norte",HAB_SEGUNDA_MINAS("minas20"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas18"));
    AddGuardia();
}
