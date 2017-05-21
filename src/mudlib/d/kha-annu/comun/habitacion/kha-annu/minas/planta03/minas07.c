/**************************************************************************
fichero: minas07.c
Autor: Riberales
Creaci�n: 23/12/05
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("un cruce de t�neles");
    SetIntLong("Has aparecido en una de las muchas intersecciones de galer�as "
               "y t�neles de estas minas enanas. Unas antorchas te facilitan "
               "la elecci�n que puedes tomar, pues los caminos al nordeste y "
               "al sur son bastante anchos, mientras que el que se desv�a al "
               "este es algo m�s estrecho.\n");

    DetalleParedes();
    DetalleAntorchas();


    AddExit("este",HAB_TERCERA_MINAS("minas08"));
    AddExit("nordeste",HAB_TERCERA_MINAS("minas06"));
    AddExit("sur",HAB_TERCERA_MINAS("minas09"));
    AddGuardia();
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT);
}
