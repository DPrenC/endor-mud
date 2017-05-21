/**************************************************************************
fichero: minas08.c
Autor: Riberales
Creación: 23/12/05
Descripción: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("un estrecho túnel");
    SetIntLong("Te encuentras en un angosto túnel de las minas al sur de "
               "Kha-annu. Las paredes se encuentran muy próximas, dejando un "
               "estrecho camino por donde pasar, y proporcionándote una ya "
               "conocida sensación claustrofóbica. La galería sigue al oeste "
               "y al nordeste.\n");

    DetalleParedes();

    AddExit("oeste",HAB_TERCERA_MINAS("minas07"));
    AddExit("nordeste",HAB_TERCERA_MINAS("minas05"));
    AddGuardia();
}

