/**************************************************************************
fichero: minas19.c
Autor: Riberales
Creación: 31/10/05
Descripción: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("la continuación de un  túnel");
    SetIntLong("Sigues uno de los túneles principales de estas minas. En este "
               "punto, las paredes se ensanchan ligeramente, quitándote de la "
               "cabeza esa sensación de claustrofobia. Además, una buena dosis"
               " de luz llega del sur y también te calma. En esa dirección "
               "observas un arco que va a dar a un cruce, mientras que la "
               "galería sigue su curso hacia el nordeste.\n");

    DetalleParedes();
    AddDetail("arco","Es el resultado de la escavación por el túnel. Permite "
              "la comunicación del túnel con el cruce que hay al sur.\n");


    AddExit("nordeste",HAB_PRIMERA_MINAS("minas20"));
    AddExit("sur",HAB_PRIMERA_MINAS("minas18"));
    AddGuardia();
}

