/**************************************************************************
fichero: minas23.c
Autor: Riberales
Creaci�n: 11/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"
#include <materials.h>

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("las minas de Kha-annu");
    SetIntLong("Observas las paredes de esta zona de las minas, y un haz de "
               "luz se refleja en alg�n punto de la misma, lo que te hace "
               "deducir que puede que haya alg�n resquicio de mineral por "
               "aqu�. La galer�a sigue en direcci�n norte y suroeste, donde "
               "hay uno de los tantos cruces de galer�as.\n");


    AddItem(OTRO_MINAS("carretilla_vacia"),REFRESH_DESTRUCT,random(2));
    AddItem(PNJ_MINAS("minero_segunda"),REFRESH_REMOVE,random(3));
    SetTipo(M_PLATA);
    DetalleVeta();

    AddExit("norte",HAB_SEGUNDA_MINAS("minas24"));
    AddExit("suroeste",HAB_SEGUNDA_MINAS("minas20"));
    AddGuardia();
}

