/**************************************************************************
fichero: minas10.c
Autor: Riberales
Creaci�n: 28/10/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("una bifurcaci�n en las minas");
    SetIntLong("Has aparecido en una de las muchas bifurcaciones o cruces que "
               "hay en estas minas enanas. Un arco al este te lleva a una "
               "galer�a bastante iluminada, pues al comienzo de la misma te "
               "parece observar una antorcha. Otro arco se dispone en "
               "direcci�n sur, y el tercero al noroeste, por donde tambi�n da "
               "la impresi�n que haya suficiente luz para ir sin peligro de "
               "caerse.\n");

    AddDetail(({"arco","arcos"}),
                "Son unos arcos hechos en la piedra y que comunican los "
                "diferentes t�neles con este cruce.\n");

    DetalleParedes();

    AddExit("este",HAB_PRIMERA_MINAS("minas09"));
    AddExit("noroeste",HAB_PRIMERA_MINAS("minas23"));
    AddExit("sur",HAB_PRIMERA_MINAS("minas22"));
    AddGuardia();
}
