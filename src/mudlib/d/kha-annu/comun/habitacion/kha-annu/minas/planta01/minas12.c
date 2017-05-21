/**************************************************************************
fichero: minas12.c
Autor: Riberales
Creaci�n: 28/10/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("la continuaci�n de una galer�a");
    SetIntLong("Te encuentras a lo largo de una de las galer�as del primer "
               "nivel de las minas. Llega un tenue resplandor del oeste, "
               "debido a una de las antorchas que alumbran el lugar. Por el "
               "contrario, al nordeste se prolonga el t�nel, en una zona casi "
               "opaca.\n");


    DetalleParedes();

    AddItem(OTRO_MINAS("carretilla_vacia"),REFRESH_DESTRUCT);
    AddExit("nordeste",HAB_PRIMERA_MINAS("minas11"));
    AddExit("oeste",HAB_PRIMERA_MINAS("minas13"));
    AddGuardia();
}
