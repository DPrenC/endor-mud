/**************************************************************************
fichero: minas19.c
Autor: Riberales
Creación: 11/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un extremo de la galería");
    SetIntLong("Te encuentras en uno de los extremos de una de las muchas "
               "galerías que pueblan estas minas. Al norte observas un cruce "
               "de túneles, mientras que la galería discurre hacia el sur.\n");

    DetalleParedes();


    AddExit("norte",HAB_SEGUNDA_MINAS("minas20"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas18"));
    AddGuardia();
}
