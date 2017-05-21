/**************************************************************************
fichero: minas12.c
Autor: Riberales
Creación: 28/10/05
Descripción: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("la continuación de una galería");
    SetIntLong("Te encuentras a lo largo de una de las galerías del primer "
               "nivel de las minas. Llega un tenue resplandor del oeste, "
               "debido a una de las antorchas que alumbran el lugar. Por el "
               "contrario, al nordeste se prolonga el túnel, en una zona casi "
               "opaca.\n");


    DetalleParedes();

    AddItem(OTRO_MINAS("carretilla_vacia"),REFRESH_DESTRUCT);
    AddExit("nordeste",HAB_PRIMERA_MINAS("minas11"));
    AddExit("oeste",HAB_PRIMERA_MINAS("minas13"));
    AddGuardia();
}
