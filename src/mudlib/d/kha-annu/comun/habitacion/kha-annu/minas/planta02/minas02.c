/**************************************************************************
fichero: minas02.c
Autor: Riberales
Creaci�n: 9/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un t�nel en las minas");
    SetIntLong("Est�s en un t�nel de las minas de Kha-annu. Observas que "
               "hay una peque�a galer�a que discurre en direcci�n sur, "
               "alej�ndose del que hasta ahora parece el t�nel principal de "
               "esta segunda planta. Unas antorchas colocadas en la roca de "
               "las paredes te facilitan la visi�n por este oscuro "
               "pasaje.\n");

    DetalleParedes();
    DetalleAntorchas();

    AddExit("oeste",HAB_SEGUNDA_MINAS("minas01"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas03"));
    AddExit("este",HAB_SEGUNDA_MINAS("minas04"));
    AddGuardia();
}
