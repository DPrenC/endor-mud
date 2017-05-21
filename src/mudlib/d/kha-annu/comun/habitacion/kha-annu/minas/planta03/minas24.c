/**************************************************************************
fichero: minas24.c
Autor: Riberales
Creaci�n: 2/1/06
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/



#include <moving.h>
#include "path.h"


inherit HAB_TERCERA_MINAS("tercera_base");
int ir_sudeste();

        create()
{

    ::create();

    SetIntShort("las minas de Kha-annu");
    SetIntLong("Te hallas en el interior de las minas de Kha-annu. Esta "
               "galer�a es mucho m�s estrecha y se te hace m�s dif�cil seguir "
               "intern�ndote en direcci�n sudeste. Al suroeste observas un "
               "cruce de galer�as, donde el espacio es mucho m�s generoso.\n");

    DetalleParedes();

    AddExit("suroeste",HAB_TERCERA_MINAS("minas23"));
   AddExit("sudeste",SF(ir_sudeste));
    AddGuardia();
}




int ir_sudeste()
{
    if (TP->QuerySize() < 2)
    {
        TP->move(HAB_TERCERA_MINAS("minas25"),M_GO);
        return 1;
    }

        return notify_fail("Intentas dirigirte al sudeste, mas eres demasiado "
                           "grande.\n",NOTIFY_NOT_VALID);
}

