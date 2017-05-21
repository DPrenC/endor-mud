/**************************************************************************
fichero: minas07.c
Autor: Riberales
Creaci�n: 29/10/05
Descripci�n: Room en primera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("un t�nel de las minas");
    SetIntLong("Te encuentras en el interior de las minas enanas de Kha-annu. "
               "Al sur observas la galer�a con una "
               "antorcha en una de las paredes, mientras que el t�nel "
               "sigue hacia el noroeste, m�s tenebroso.\n");


    DetalleParedes();

    AddExit("noroeste",HAB_PRIMERA_MINAS("minas08"));
    AddExit("sur",HAB_PRIMERA_MINAS("minas06"));
    AddGuardia();
}
