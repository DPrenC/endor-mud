/**************************************************************************
fichero: minas02.c
Autor: Riberales
Creaci�n: 21/12/05
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");



create()
{
    ::create();

    SetIntShort("una galer�a de las minas");
    SetIntLong("Est�s internado en las minas de Kha-annu, en su nivel "
               "inferior. Al sur observas el final de la galer�a por la que "
               "vas. Al norte sigue la misma, alumbrada por un par de "
               "antorchas, mientras que al nordeste hay un desv�o hacia otro "
               "de los t�neles.\n");

    DetalleParedes();

    AddItem(OTRO_MINAS("carretilla_vacia"),REFRESH_DESTRUCT,random(2));

    AddExit("sur",HAB_TERCERA_MINAS("minas01"));
    AddExit("norte",HAB_TERCERA_MINAS("minas03"));
    AddExit("nordeste",HAB_TERCERA_MINAS("minas21"));

    AddGuardia();
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT);
}

