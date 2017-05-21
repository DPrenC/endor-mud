/**************************************************************************
fichero: minas09.c
Autor: Riberales
Creaci�n: 28/10/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("las minas de Kha-annu");
    SetIntLong("Te encuentras en las grandes minas enanas. Observas "
               "una antorcha en la pared, para dar luz a esta parte de la "
               "galer�a y a las zonas cercanas. El camino sigue al nordeste, "
               "y en direcci�n oeste observas un arco que da a parar a uno de "
               "los cruces de galer�as.\n");

    AddDetail("arco","Es un hueco hecho en la roca que  comunica esta galer�a "
              "con el cruce que hay al oeste.\n");

    DetalleParedes();
    DetalleAntorchas();

    AddExit("oeste",HAB_PRIMERA_MINAS("minas10"));
    AddExit("nordeste",HAB_PRIMERA_MINAS("minas08"));
    AddGuardia();
}
