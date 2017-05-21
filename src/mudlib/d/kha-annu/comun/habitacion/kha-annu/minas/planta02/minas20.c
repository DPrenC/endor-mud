/**************************************************************************
fichero: minas20.c
Autor: Riberales
Creaci�n: 11/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("una confluencia de galer�as");
    SetIntLong("Has aparecido en un punto de las minas donde se unen varias "
               "galer�as. Una de ellas, en direcci�n sur, parece ser que est� "
               "algo iluminada a lo lejos. En direcci�n nordeste observas "
               "otra, bastante amplia, mientras que nace una galer�a al "
               "oeste, algo angosta y tristemente iluminada.\n");

    DetalleParedes();

    AddExit("sur",HAB_SEGUNDA_MINAS("minas19"));
    AddExit("oeste",HAB_SEGUNDA_MINAS("minas21"));
    AddExit("nordeste",HAB_SEGUNDA_MINAS("minas23"));
    AddItem(OTRO_MINAS("carretilla_vacia"));
    AddGuardia();
}
