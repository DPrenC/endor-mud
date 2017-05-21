/**************************************************************************
fichero: minas16.c
Autor: Riberales
Creaci�n: 11/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un t�nel en la segunda planta de las minas");
    SetIntLong("Sigues inmerso en las minas enanas de Kha-annu. El t�nel por "
               "donde caminas se extiende en direcci�n este, y al final del "
               "mismo observas luces, mientras que al noroeste te parece "
               "divisar un cruce de t�neles, tambi�n debidamente "
               "iluminado.\n");


    DetalleParedes();

    AddExit("este",HAB_SEGUNDA_MINAS("minas17"));
    AddExit("noroeste",HAB_SEGUNDA_MINAS("minas14"));
    AddItem(OTRO_MINAS("carretilla_vacia"));
    AddGuardia();
}
