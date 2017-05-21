/****************************************************************************
Fichero: pasaje_02.c
Autor: Kastwey
Creaci�n: 21/08/2005
Descripci�n: Extremo del pasaje hacia calle Ungrim
****************************************************************************/

#include "./path.h"

inherit BASE_CIUDAD_ANNUFAM;

public void create()
{
    ::create();
    SetIntShort("un pasaje");
    SetIntLong(W("Te encuentras en un peque�o pasaje que une las dos calles "
                 "de la ciudad, paralelo a la Avenida Real. Como �nica "
                 "observaci�n, a parte de la oscuridad reinante, es la "
                 "estrechez del callej�n que te produce una leve "
                 "sensaci�n de claustrofobia. Al sur se encuentra la salida "
                 "hacia la calle Ungrim, mientras que al norte sigue el "
                 "pasaje.\n"));

    SetIndoors(1);
    SetIntBright(10);

    AddExit("norte",HAB_CALLES_ANNUFAM("pasaje_01"));
    AddExit("sur",HAB_UNGRIM_ANNUFAM("ungrim_04"));

}


