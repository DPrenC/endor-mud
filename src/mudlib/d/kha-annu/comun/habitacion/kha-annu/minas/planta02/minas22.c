/**************************************************************************
fichero: minas22.c
Autor: Riberales
Creaci�n: 11/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("una galer�a en las minas");
    SetIntLong("Est�s inmerso en una de las galer�as en el segundo piso de estas "
               "minas enanas de Kha-annu. A tu alrededor sigues observando "
               "roca y m�s roca, y los pies ya te duelen un poco, debido al "
               "irregular y escarpado suelo por el que transitas. El t�nel "
               "sigue en direcci�n este y suroeste, en lo que aparenta ser "
               "una uni�n de galer�as.\n");

    DetalleParedes();

    AddExit("este",HAB_SEGUNDA_MINAS("minas21"));
    AddExit("suroeste",HAB_SEGUNDA_MINAS("minas14"));
    AddGuardia();
}
