/**************************************************************************
fichero: minas16.c
Autor: Riberales
Creación: 11/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un túnel en la segunda planta de las minas");
    SetIntLong("Sigues inmerso en las minas enanas de Kha-annu. El túnel por "
               "donde caminas se extiende en dirección este, y al final del "
               "mismo observas luces, mientras que al noroeste te parece "
               "divisar un cruce de túneles, también debidamente "
               "iluminado.\n");


    DetalleParedes();

    AddExit("este",HAB_SEGUNDA_MINAS("minas17"));
    AddExit("noroeste",HAB_SEGUNDA_MINAS("minas14"));
    AddItem(OTRO_MINAS("carretilla_vacia"));
    AddGuardia();
}
