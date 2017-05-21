/**************************************************************************
fichero: minas28.c
Autor: Riberales
Creaci�n: 27/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"


inherit HAB_SEGUNDA_MINAS("segunda_base");

create()
{
    ::create();

    SetIntShort("un t�nel de las minas");
    SetIntLong("Te encuentras en un t�nel en la segunda planta de las minas "
               "enanas. Esta zona es bastante tenebrosa, y a veces se hace "
               "imposible la visi�n si no llevas alguna antorcha encima. "
               "Observas que la galer�a contin�a hacia el sudeste y el "
               "suroeste.\n");

    DetalleParedes();

    AddExit("suroeste",HAB_SEGUNDA_MINAS("minas05"));
    AddExit("sudeste",HAB_SEGUNDA_MINAS("minas27"));
    AddItem(PNJ_MINAS("minero_segunda"),REFRESH_DESTRUCT);
    AddGuardia();
}

