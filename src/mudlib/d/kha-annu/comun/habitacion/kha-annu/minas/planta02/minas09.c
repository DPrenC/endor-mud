/**************************************************************************
fichero: minas09.c
Autor: Riberales
Creación: 9/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"
#include <moving.h>  //para el notify_leave();


inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("una galería en las minas");
    SetIntLong("Te hallas en un pequeño túnel en las minas de Kha-annu. El "
               "pasaje continúa al nordeste y al sur, donde el nivel del "
               "techo desciende considerablemente y puede que si no vas con "
               "cautela te lleves un recuerdo de las minas.\n");

    DetalleParedes();

    AddExit("nordeste",HAB_SEGUNDA_MINAS("minas08"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas10"));
    AddItem(OTRO_MINAS("carretilla_vacia"));
    AddGuardia();
}


