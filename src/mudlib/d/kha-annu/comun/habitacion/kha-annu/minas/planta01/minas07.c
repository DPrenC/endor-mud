/**************************************************************************
fichero: minas07.c
Autor: Riberales
Creación: 29/10/05
Descripción: Room en primera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("un túnel de las minas");
    SetIntLong("Te encuentras en el interior de las minas enanas de Kha-annu. "
               "Al sur observas la galería con una "
               "antorcha en una de las paredes, mientras que el túnel "
               "sigue hacia el noroeste, más tenebroso.\n");


    DetalleParedes();

    AddExit("noroeste",HAB_PRIMERA_MINAS("minas08"));
    AddExit("sur",HAB_PRIMERA_MINAS("minas06"));
    AddGuardia();
}
