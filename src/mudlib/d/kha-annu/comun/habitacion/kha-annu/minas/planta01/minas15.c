/**************************************************************************
fichero: minas15.c
Autor: Riberales
Creación: 31/10/05
Descripción: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("las galerías enanas");
    SetIntLong("Vagas por las galerías enanas, y cada vez son más abruptas e "
               "invitan al extravío. Tanto túnel y tanta estancia sin salida "
               "hacen de este lugar un buen sitio para perderse. Al sur "
               "observas una cámara bastante desgastada, mientras que la "
               "galería sigue su rumbo este oeste.\n");

    AddDetail(({"camara","cámara"}),
                "Es una estancia donde parece que los enanos han hecho una "
                "buena extracción de mineral.\n");

    DetalleParedes();

    AddExit("este",HAB_PRIMERA_MINAS("minas13"));
    AddExit("sur",HAB_PRIMERA_MINAS("minas16"));
    AddExit("oeste",HAB_PRIMERA_MINAS("minas17"));
    AddGuardia();
}
