/**************************************************************************
fichero: minas06.c
Autor: Riberales
Creación: 9/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un cruce de galerías");
    SetIntLong("Has aparecido en un cruce de galerías, en el segundo nivel de "
               "las minas enanas. Parece que el túnel principal va hacia el "
               "norte y el este, mientras que al suroeste se encuentra una "
               "galería algo más estrecha.\n");

    DetalleParedes();

    AddExit("norte",HAB_SEGUNDA_MINAS("minas05"));
    AddExit("este",HAB_SEGUNDA_MINAS("minas29"));
    AddExit("suroeste",HAB_SEGUNDA_MINAS("minas07"));
    AddItem(OTRO_MINAS("carretilla_vacia"));
    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
    AddGuardia();
}
