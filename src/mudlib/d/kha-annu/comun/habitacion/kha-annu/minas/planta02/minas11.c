/**************************************************************************
fichero: minas11.c
Autor: Riberales
Creación: 11/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("las galerías de Kha-annu");
    SetIntLong("Permaneces en el interior de estas minas enanas de Kha-annu. "
               "Esta zona parece la más húmeda de la segunda planta, pues se "
               "te hace más complicado respirar. Incluso hay unas antorchas en"
               " las paredes, pero están apagadas. El túnel sigue en dirección"
               " noroeste y nordeste, donde observas algo más de claridad.\n");

    DetalleParedes();

    AddDetail(({"antorcha","antorchas"}),
                "Son unos recipientes metálicos, mas ahora están apagados.\n");

    AddExit("noroeste",HAB_SEGUNDA_MINAS("minas10"));
    AddExit("nordeste",HAB_SEGUNDA_MINAS("minas12"));
    AddItem(PNJ_MINAS("minero_segunda"),REFRESH_DESTRUCT);
    AddGuardia();
}

