/**************************************************************************
fichero: minas18.c
Autor: Riberales
Creaci�n: 11/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("una galer�a de las minas");
    SetIntLong("Te hallas en una de las galer�as de las minas del reino enano. "
               "Un par de antorchas te ayudan a orientarte en la estancia de "
               "las mismas. Aqu� el t�nel hace esquina, siguiendo en "
               "direcci�n norte y oeste.\n");

    DetalleParedes();

    AddExit("norte",HAB_SEGUNDA_MINAS("minas19"));
    AddExit("oeste",HAB_SEGUNDA_MINAS("minas17"));
    AddItem(PNJ_MINAS("minero_segunda"),REFRESH_DESTRUCT);
    AddGuardia();
}
