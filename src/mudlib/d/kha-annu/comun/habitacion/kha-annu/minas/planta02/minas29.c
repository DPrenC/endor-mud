/**************************************************************************
fichero: minas29.c
Autor: Riberales
Creación: 27/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"


inherit HAB_SEGUNDA_MINAS("segunda_base");

create()
{
    ::create();

    SetIntShort("una galería de las minas enanas");
    SetIntLong("Te hallas en una de las galerías en las minas enanas "
               "de Kha-annu. Al nordeste divisas un cruce de túneles con unas "
               "antorchas para ayudar en la elección. La galería sigue de "
               "noroeste a sudeste, mientras que al oeste observas otro túnel "
               "que comunica con otra parte de la mina.\n");

    DetalleParedes();


    AddExit("noroeste",HAB_SEGUNDA_MINAS("minas05"));
    AddExit("nordeste",HAB_SEGUNDA_MINAS("minas27"));
    AddExit("sudeste",HAB_SEGUNDA_MINAS("minas30"));
    AddExit("oeste",HAB_SEGUNDA_MINAS("minas06"));
    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
    AddItem(OTRO_MINAS("carretilla_vacia"));
    AddGuardia();
}

