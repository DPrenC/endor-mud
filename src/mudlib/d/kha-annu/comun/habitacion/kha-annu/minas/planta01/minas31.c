/**************************************************************************
fichero: minas31.c
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

    SetIntShort("una galería de las minas");
    SetIntLong("Permaneces en el interior de las minas de Kha-annu, rodeado "
               "de piedra y más piedra. Unas antorchas permiten ver a tu "
               "alrededor. En una de las paredes te parece observar una "
               "pequeña veta de mineral, que seguramente aún no haya sido "
               "muy explotada. El túnel prosigue en dirección noroeste, "
               "mientras que al nordeste adviertes un cruce de galerías.\n");

    SetTipo(M_HIERRO);
    DetalleVeta();
    AddItem(OTRO_MINAS("carretilla_vacia"),REFRESH_DESTRUCT);

    AddExit("nordeste",HAB_PRIMERA_MINAS("minas18"));
    AddExit("noroeste",HAB_PRIMERA_MINAS("minas30"));
    AddGuardia();
}
