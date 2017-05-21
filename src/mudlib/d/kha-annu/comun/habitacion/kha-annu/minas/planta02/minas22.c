/**************************************************************************
fichero: minas22.c
Autor: Riberales
Creación: 11/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("una galería en las minas");
    SetIntLong("Estás inmerso en una de las galerías en el segundo piso de estas "
               "minas enanas de Kha-annu. A tu alrededor sigues observando "
               "roca y más roca, y los pies ya te duelen un poco, debido al "
               "irregular y escarpado suelo por el que transitas. El túnel "
               "sigue en dirección este y suroeste, en lo que aparenta ser "
               "una unión de galerías.\n");

    DetalleParedes();

    AddExit("este",HAB_SEGUNDA_MINAS("minas21"));
    AddExit("suroeste",HAB_SEGUNDA_MINAS("minas14"));
    AddGuardia();
}
