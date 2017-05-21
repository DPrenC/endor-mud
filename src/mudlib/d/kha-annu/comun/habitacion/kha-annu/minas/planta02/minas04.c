/**************************************************************************
fichero: minas04.c
Autor: Riberales
Creación: 9/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"
#include <materials.h>

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("las minas enanas de Kha-annu");
    SetIntLong("Sigues tu inspección por las minas enanas. En esta zona "
               "parece que hay un trozo de roca sin tratar, y que podría "
               "quedar algún resto de mineral en ella. El túnel sigue hacia "
               "el sudeste y hacia el oeste, donde observas una mayor "
               "presencia de luz.\n");


    SetTipo(M_PLATA);
    DetalleVeta();

    AddExit("sudeste",HAB_SEGUNDA_MINAS("minas05"));
    AddExit("oeste",HAB_SEGUNDA_MINAS("minas02"));
    AddGuardia();
}
