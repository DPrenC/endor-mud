/**************************************************************************
fichero: minas11.c
Autor: Riberales
Creaci�n: 11/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("las galer�as de Kha-annu");
    SetIntLong("Permaneces en el interior de estas minas enanas de Kha-annu. "
               "Esta zona parece la m�s h�meda de la segunda planta, pues se "
               "te hace m�s complicado respirar. Incluso hay unas antorchas en"
               " las paredes, pero est�n apagadas. El t�nel sigue en direcci�n"
               " noroeste y nordeste, donde observas algo m�s de claridad.\n");

    DetalleParedes();

    AddDetail(({"antorcha","antorchas"}),
                "Son unos recipientes met�licos, mas ahora est�n apagados.\n");

    AddExit("noroeste",HAB_SEGUNDA_MINAS("minas10"));
    AddExit("nordeste",HAB_SEGUNDA_MINAS("minas12"));
    AddItem(PNJ_MINAS("minero_segunda"),REFRESH_DESTRUCT);
    AddGuardia();
}

