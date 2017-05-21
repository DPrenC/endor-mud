/**************************************************************************
fichero: minas03.c
Autor: Riberales
Creación: 9/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un pequeño pasaje");
    SetIntLong("Observas que estás en un estrecho túnel en la segunda planta "
               "de estas minas enanas. Al norte notas mucha más claridad, en "
               "lo que parece la salida a un pasaje más amplio. Esta galería, "
               "por el contrario, continúa inexorable en dirección sur.\n");

    DetalleParedes();

    AddExit("norte",HAB_SEGUNDA_MINAS("minas02"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas08"));
    AddItem(OTRO_MINAS("carretilla_vacia"),REFRESH_DESTRUCT,random(2));
    AddItem(PNJ_MINAS("minero_segunda"),REFRESH_DESTRUCT);
    AddGuardia();
}
