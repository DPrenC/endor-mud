/**************************************************************************
fichero: minas10.c
Autor: Riberales
Creaci�n: 23/12/05
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("las minas enanas");
    SetIntLong("Te encuentras en el interior de las minas enanas de Kha-annu, "
               "en su nivel m�s inferior y a la vez, m�s h�medo. Cada vez te "
               "cuesta m�s respirar, sobre todo, conforme vas intern�ndote "
               "en la zona sur de esta planta. El t�nel sigue al norte y al "
               "sudeste, donde observas un par de antorchas alumbrando.\n");


    DetalleParedes();
    AddItem(ARMA_MINAS("pico"));


    AddExit("norte",HAB_TERCERA_MINAS("minas09"));
    AddExit("sudeste",HAB_TERCERA_MINAS("minas11"));
    AddGuardia();
    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
}

