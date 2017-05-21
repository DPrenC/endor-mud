/**************************************************************************
fichero: minas08.c
Autor: Riberales
Creaci�n: 23/12/05
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("un estrecho t�nel");
    SetIntLong("Te encuentras en un angosto t�nel de las minas al sur de "
               "Kha-annu. Las paredes se encuentran muy pr�ximas, dejando un "
               "estrecho camino por donde pasar, y proporcion�ndote una ya "
               "conocida sensaci�n claustrof�bica. La galer�a sigue al oeste "
               "y al nordeste.\n");

    DetalleParedes();

    AddExit("oeste",HAB_TERCERA_MINAS("minas07"));
    AddExit("nordeste",HAB_TERCERA_MINAS("minas05"));
    AddGuardia();
}

