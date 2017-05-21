/**************************************************************************
fichero: minas17.c
Autor: Riberales
Creación: 31/10/05
Descripción: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("las minas de Kha-annu");
    SetIntLong("Estás en una angosta galería del que crees que es el primer "
               "piso de las minas. Todo sigue siendo igual, roca y más roca a "
               "tu alrededor. Las paredes sólo te dejan dos alternativas para "
               "moverte: Al este y al noroeste.\n");

    DetalleParedes();

    AddItem(OTRO_MINAS("carretilla_vacia"),REFRESH_DESTRUCT);
    AddExit("este",HAB_PRIMERA_MINAS("minas15"));
    AddExit("noroeste",HAB_PRIMERA_MINAS("minas18"));
    AddGuardia();
}
