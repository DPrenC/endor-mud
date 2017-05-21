/**************************************************************************
fichero: minas28.c
Autor: Riberales
Creación: 27/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"


inherit HAB_SEGUNDA_MINAS("segunda_base");

create()
{
    ::create();

    SetIntShort("un túnel de las minas");
    SetIntLong("Te encuentras en un túnel en la segunda planta de las minas "
               "enanas. Esta zona es bastante tenebrosa, y a veces se hace "
               "imposible la visión si no llevas alguna antorcha encima. "
               "Observas que la galería continúa hacia el sudeste y el "
               "suroeste.\n");

    DetalleParedes();

    AddExit("suroeste",HAB_SEGUNDA_MINAS("minas05"));
    AddExit("sudeste",HAB_SEGUNDA_MINAS("minas27"));
    AddItem(PNJ_MINAS("minero_segunda"),REFRESH_DESTRUCT);
    AddGuardia();
}

