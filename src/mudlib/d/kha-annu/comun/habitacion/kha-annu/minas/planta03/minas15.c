/**************************************************************************
fichero: minas15.c
Autor: Riberales
Creación: 26/12/05
Descripción: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("las galerías de las minas enanas");
    SetIntLong("Te encuentras en el último nivel de estas minas de Kha-annu. "
               "Te da la impresión de que esta es la zona más húmeda de toda "
               "la mina, y el murmullo del agua te sigue acompañando, aunque "
               "con más intensidad. El túnel sigue al noroeste y al "
               "nordeste.\n");

    DetalleParedes();


    AddExit("nordeste",HAB_TERCERA_MINAS("minas16"));
    AddExit("noroeste",HAB_TERCERA_MINAS("minas13"));
    AddGuardia();
    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
}

