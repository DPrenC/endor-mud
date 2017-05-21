/**************************************************************************
fichero: minas22.c
Autor: Riberales
Creación: 31/10/05
Descripción: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("un túnel de las minas");
    SetIntLong("Estás en una de las galerías de esta mina. Esta parte está "
               "bastante bien iluminada, pues unas antorchas situadas al sur "
               "te protegen de la casi siempre temida oscuridad. Al norte te "
               "parece advertir un cruce de galerías, mientras que en la que "
               "estás situado prosigue en dirección sur.\n");

    DetalleParedes();


    AddExit("sur",HAB_PRIMERA_MINAS("minas21"));
    AddExit("norte",HAB_PRIMERA_MINAS("minas10"));

    AddItem(PNJ_MINAS("minero_primera"));
    AddGuardia();
}

