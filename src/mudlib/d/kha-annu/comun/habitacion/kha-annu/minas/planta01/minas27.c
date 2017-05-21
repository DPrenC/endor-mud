/**************************************************************************
fichero: minas27.c
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

    SetIntShort("una galer�a en las minas");
    SetIntLong("Esta zona de las minas enanas de Kha-annu parece que es "
               "bastante reciente y observas algunas vetas sin casi tratar. "
               "Adem�s, un par de antorchas contribuyen a una mejor "
               "extracci�n del posible mineral. El t�nel sigue al este y al "
               "sur.\n");

    SetTipo(M_HIERRO);
    DetalleVeta();
    DetalleAntorchas();

    AddExit("este",HAB_PRIMERA_MINAS("minas26"));
    AddExit("sur",HAB_PRIMERA_MINAS("minas28"));
    AddGuardia();
}
