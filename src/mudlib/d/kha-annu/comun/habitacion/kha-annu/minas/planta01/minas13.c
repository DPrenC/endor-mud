/**************************************************************************
fichero: minas13.c
Autor: Riberales
Creaci�n: 29/10/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("un pasaje de las minas");
    SetIntLong("Te encuentras en uno de los pasadizos de estas minas enanas. "
               "En la pared sur observas una antorcha, la cual da luminosidad "
               "a esta parte de la galer�a, as� como a las zonas cercanas. Al "
               "norte parece que hay una especie de cub�culo que ha sido "
               "especialmente explotado. El t�nel se extiende de este a "
               "oeste.\n");

    DetalleParedes();
    DetalleAntorchas();

    AddExit("este",HAB_PRIMERA_MINAS("minas12"));
    AddExit("norte",HAB_PRIMERA_MINAS("minas14"));
    AddExit("oeste",HAB_PRIMERA_MINAS("minas15"));
    AddGuardia();
}
