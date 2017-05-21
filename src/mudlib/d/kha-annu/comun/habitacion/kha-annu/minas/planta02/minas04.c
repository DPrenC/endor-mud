/**************************************************************************
fichero: minas04.c
Autor: Riberales
Creaci�n: 9/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"
#include <materials.h>

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("las minas enanas de Kha-annu");
    SetIntLong("Sigues tu inspecci�n por las minas enanas. En esta zona "
               "parece que hay un trozo de roca sin tratar, y que podr�a "
               "quedar alg�n resto de mineral en ella. El t�nel sigue hacia "
               "el sudeste y hacia el oeste, donde observas una mayor "
               "presencia de luz.\n");


    SetTipo(M_PLATA);
    DetalleVeta();

    AddExit("sudeste",HAB_SEGUNDA_MINAS("minas05"));
    AddExit("oeste",HAB_SEGUNDA_MINAS("minas02"));
    AddGuardia();
}
