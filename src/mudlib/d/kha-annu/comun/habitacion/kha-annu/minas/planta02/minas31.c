/**************************************************************************
fichero: minas31.c
Autor: Riberales
Creación: 27/11/05
Descripción: Room en segunda planta de las minas, acceso a la tercera y última.
**************************************************************************/


#include "path.h"
#include <materials.h>

inherit HAB_SEGUNDA_MINAS("segunda_base");

create()
{
    ::create();

    SetIntShort("una estancia en las minas de Kha-annu");
    SetIntLong("Has aparecido en una estancia dentro de las minas enanas de "
               "Kha-annu. Parece que esta área la han repasado muy a fondo, "
               "por la morfología de la roca, casi en paredes perfectas. Aun "
               "así, alcanzas a ver algunos sectores sin tratar.\n");


    SetTipo(M_PLATA);
    DetalleVeta();

    AddExit("noroeste",HAB_SEGUNDA_MINAS("minas27"));
    AddExit("suroeste",HAB_SEGUNDA_MINAS("minas30"));
    AddItem(PNJ_MINAS("minero_segunda"),REFRESH_DESTRUCT);
    AddGuardia();
}

