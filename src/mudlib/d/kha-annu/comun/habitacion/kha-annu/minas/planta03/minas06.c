/**************************************************************************
fichero: minas06.c
Autor: Riberales
Creaci�n: 22/12/05
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("el interior de las minas de Kha-annu");
    SetIntLong("Te hallas internado en las minas enanas, al sur de Kha-annu. "
               "En esta parte de las minas encuentras la roca mucho m�s "
               "h�meda que en niveles superiores, lo que te hace pensar que "
               "no muy lejos habr� alg�n c�mulo de agua. Este t�nel sigue al "
               "este y al suroeste, donde unas antorchas permiten alumbrar "
               "esta parte de las minas.\n");

    DetalleParedes();

    AddExit("suroeste",HAB_TERCERA_MINAS("minas07"));
    AddExit("este",HAB_TERCERA_MINAS("minas05"));

    AddGuardia();
}
