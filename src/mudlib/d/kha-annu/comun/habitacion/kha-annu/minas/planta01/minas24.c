/**************************************************************************
fichero: minas24.c
Autor: Riberales
Creación: 31/10/05
Descripción: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("un túnel");
    SetIntLong("Te hallas por las minas enanas. Desde hace tiempo, la "
               "única compañera de fatigas es tu sombra, y sólo cuando hay "
               "antorchas que produzcan su presencia. Éste es un ejemplo, "
               "pues un par de ellas dan luminosidad a esta curva del túnel, "
               "que se extiende en dirección este y sur.\n");

    AddDetail("sombra","Observas tu silueta estampada contra la roca de las "
              "paredes\n");

    DetalleAntorchas();
    DetalleParedes();

    AddExit("sur",HAB_PRIMERA_MINAS("minas25"));
    AddExit("este",HAB_PRIMERA_MINAS("minas23"));
    AddGuardia();
}

