/**************************************************************************
fichero: minas02.c
Autor: Riberales
Creación: 21/12/05
Descripción: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");



create()
{
    ::create();

    SetIntShort("una galería de las minas");
    SetIntLong("Estás internado en las minas de Kha-annu, en su nivel "
               "inferior. Al sur observas el final de la galería por la que "
               "vas. Al norte sigue la misma, alumbrada por un par de "
               "antorchas, mientras que al nordeste hay un desvío hacia otro "
               "de los túneles.\n");

    DetalleParedes();

    AddItem(OTRO_MINAS("carretilla_vacia"),REFRESH_DESTRUCT,random(2));

    AddExit("sur",HAB_TERCERA_MINAS("minas01"));
    AddExit("norte",HAB_TERCERA_MINAS("minas03"));
    AddExit("nordeste",HAB_TERCERA_MINAS("minas21"));

    AddGuardia();
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT);
}

