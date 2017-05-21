/**************************************************************************
fichero: minas27.c
Autor: Riberales
Creación: 02/11/05
Descripción: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"
#include <materials.h>

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("una galería en las minas");
    SetIntLong("Esta zona de las minas enanas de Kha-annu parece que es "
               "bastante reciente y observas algunas vetas sin casi tratar. "
               "Además, un par de antorchas contribuyen a una mejor "
               "extracción del posible mineral. El túnel sigue al este y al "
               "sur.\n");

    SetTipo(M_HIERRO);
    DetalleVeta();
    DetalleAntorchas();

    AddExit("este",HAB_PRIMERA_MINAS("minas26"));
    AddExit("sur",HAB_PRIMERA_MINAS("minas28"));
    AddGuardia();
}
