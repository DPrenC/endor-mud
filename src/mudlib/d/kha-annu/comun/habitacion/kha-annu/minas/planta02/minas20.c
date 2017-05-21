/**************************************************************************
fichero: minas20.c
Autor: Riberales
Creación: 11/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("una confluencia de galerías");
    SetIntLong("Has aparecido en un punto de las minas donde se unen varias "
               "galerías. Una de ellas, en dirección sur, parece ser que está "
               "algo iluminada a lo lejos. En dirección nordeste observas "
               "otra, bastante amplia, mientras que nace una galería al "
               "oeste, algo angosta y tristemente iluminada.\n");

    DetalleParedes();

    AddExit("sur",HAB_SEGUNDA_MINAS("minas19"));
    AddExit("oeste",HAB_SEGUNDA_MINAS("minas21"));
    AddExit("nordeste",HAB_SEGUNDA_MINAS("minas23"));
    AddItem(OTRO_MINAS("carretilla_vacia"));
    AddGuardia();
}
