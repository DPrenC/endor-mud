/**************************************************************************
fichero: minas26.c
Autor: Riberales
Creación: 27/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"


inherit HAB_SEGUNDA_MINAS("segunda_base");

create()
{
    ::create();

    SetIntShort("un enrevesado túnel");
    SetIntLong("Estás en un túnel de las minas, un tanto más enrevesado "
               "que el resto si eso es posible. Aquí hay bastantes marcas de "
               "carretilla, por lo que no sería raro ver a algún enano "
               "trabajando por las cercanías.\n");


    DetalleParedes();

    AddExit("suroeste",HAB_SEGUNDA_MINAS("minas27"));
    AddExit("sudeste",HAB_SEGUNDA_MINAS("minas25"));
    AddItem(OTRO_MINAS("carretilla_vacia"));
    AddGuardia();
}


