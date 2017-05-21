/**************************************************************************
fichero: minas06.c
Autor: Riberales
Creación: 28/10/05
Descripción: Room en primera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("una galería");
    SetIntLong("Observas la misma galería enana. Aquí, el pasillo "
               "se estrecha un poco, por lo que notas la fría superficie de "
               "las paredes de roca. Además, hay una antorcha, y al ser "
               "angosto el paso, la luz sale reflejada con más fuerza hacia "
               "el resto de la galería. Ésta sigue de norte a sur, mientras "
               "al sudeste observas un pequeño pasadizo.\n");


    DetalleParedes();
    DetalleAntorchas();

    AddExit("norte",HAB_PRIMERA_MINAS("minas07"));
    AddExit("sur",HAB_PRIMERA_MINAS("minas05"));
    AddExit("sudeste",HAB_PRIMERA_MINAS("minas04"));
    AddGuardia();
}
