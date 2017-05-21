/**************************************************************************
fichero: minas28.c
Autor: Riberales
Creación: 02/11/05
Descripción: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("un oscuro túnel");
    SetIntLong("Te has internado en lo que parece la galería menos iluminada "
               "de toda esta planta. Una tenue luz asoma en dirección norte, "
               "mas el túnel sigue tenebroso e inexorable al suroeste. Para "
               "colmo de males, las paredes están muy próximas, lo que hace "
               "más difícil el paso.\n");

    DetalleParedes();
    SetIntBright(0);


    AddExit("norte",HAB_PRIMERA_MINAS("minas27"));
    AddExit("suroeste",HAB_PRIMERA_MINAS("minas29"));
    AddItem(PNJ_MINAS("minero_primera"),REFRESH_DESTRUCT,2);
        AddGuardia();
}
