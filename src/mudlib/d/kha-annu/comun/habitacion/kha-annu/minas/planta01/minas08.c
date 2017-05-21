/**************************************************************************
fichero: minas08.c
Autor: Riberales
Creación: 28/10/05
Descripción: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"
#include <materials.h>

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("un tramo de galería");
    SetIntLong("Estás internado en las galerías de las minas del sur de "
               "Kha-annu. Esta zona parece que también podría contener aún "
               "algo de mineral. Al sudeste observas un arco que te lleva a "
               "un cruce, y al suroeste sigue la galería.\n");


    SetTipo(M_HIERRO);
    DetalleVeta();

    AddDetail("arco","Es un hueco hecho en la roca que  comunica esta galería "
              "con el cruce que hay al sudeste.\n");

    AddItem(OTRO_MINAS("carretilla_vacia"));


    AddExit("suroeste",HAB_PRIMERA_MINAS("minas09"));
    AddExit("sudeste",HAB_PRIMERA_MINAS("minas07"));

    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);

    AddGuardia();
}
