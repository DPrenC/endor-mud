/**************************************************************************
fichero: minas03.c
Autor: Riberales
Creaci�n: 9/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un peque�o pasaje");
    SetIntLong("Observas que est�s en un estrecho t�nel en la segunda planta "
               "de estas minas enanas. Al norte notas mucha m�s claridad, en "
               "lo que parece la salida a un pasaje m�s amplio. Esta galer�a, "
               "por el contrario, contin�a inexorable en direcci�n sur.\n");

    DetalleParedes();

    AddExit("norte",HAB_SEGUNDA_MINAS("minas02"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas08"));
    AddItem(OTRO_MINAS("carretilla_vacia"),REFRESH_DESTRUCT,random(2));
    AddItem(PNJ_MINAS("minero_segunda"),REFRESH_DESTRUCT);
    AddGuardia();
}
