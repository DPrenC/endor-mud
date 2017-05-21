/**************************************************************************
fichero: minas31.c
Autor: Riberales
Creaci�n: 02/11/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"
#include <materials.h>

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("una galer�a de las minas");
    SetIntLong("Permaneces en el interior de las minas de Kha-annu, rodeado "
               "de piedra y m�s piedra. Unas antorchas permiten ver a tu "
               "alrededor. En una de las paredes te parece observar una "
               "peque�a veta de mineral, que seguramente a�n no haya sido "
               "muy explotada. El t�nel prosigue en direcci�n noroeste, "
               "mientras que al nordeste adviertes un cruce de galer�as.\n");

    SetTipo(M_HIERRO);
    DetalleVeta();
    AddItem(OTRO_MINAS("carretilla_vacia"),REFRESH_DESTRUCT);

    AddExit("nordeste",HAB_PRIMERA_MINAS("minas18"));
    AddExit("noroeste",HAB_PRIMERA_MINAS("minas30"));
    AddGuardia();
}
