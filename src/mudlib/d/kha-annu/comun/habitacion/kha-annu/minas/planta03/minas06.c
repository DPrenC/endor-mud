/**************************************************************************
fichero: minas06.c
Autor: Riberales
Creación: 22/12/05
Descripción: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("el interior de las minas de Kha-annu");
    SetIntLong("Te hallas internado en las minas enanas, al sur de Kha-annu. "
               "En esta parte de las minas encuentras la roca mucho más "
               "húmeda que en niveles superiores, lo que te hace pensar que "
               "no muy lejos habrá algún cúmulo de agua. Este túnel sigue al "
               "este y al suroeste, donde unas antorchas permiten alumbrar "
               "esta parte de las minas.\n");

    DetalleParedes();

    AddExit("suroeste",HAB_TERCERA_MINAS("minas07"));
    AddExit("este",HAB_TERCERA_MINAS("minas05"));

    AddGuardia();
}
