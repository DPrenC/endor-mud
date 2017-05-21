/**************************************************************************
fichero: minas07.c
Autor: Riberales
Creación: 23/12/05
Descripción: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("un cruce de túneles");
    SetIntLong("Has aparecido en una de las muchas intersecciones de galerías "
               "y túneles de estas minas enanas. Unas antorchas te facilitan "
               "la elección que puedes tomar, pues los caminos al nordeste y "
               "al sur son bastante anchos, mientras que el que se desvía al "
               "este es algo más estrecho.\n");

    DetalleParedes();
    DetalleAntorchas();


    AddExit("este",HAB_TERCERA_MINAS("minas08"));
    AddExit("nordeste",HAB_TERCERA_MINAS("minas06"));
    AddExit("sur",HAB_TERCERA_MINAS("minas09"));
    AddGuardia();
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT);
}
