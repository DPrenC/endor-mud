/**************************************************************************
fichero: minas02.c
Autor: Riberales
Creación: 9/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un túnel en las minas");
    SetIntLong("Estás en un túnel de las minas de Kha-annu. Observas que "
               "hay una pequeña galería que discurre en dirección sur, "
               "alejándose del que hasta ahora parece el túnel principal de "
               "esta segunda planta. Unas antorchas colocadas en la roca de "
               "las paredes te facilitan la visión por este oscuro "
               "pasaje.\n");

    DetalleParedes();
    DetalleAntorchas();

    AddExit("oeste",HAB_SEGUNDA_MINAS("minas01"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas03"));
    AddExit("este",HAB_SEGUNDA_MINAS("minas04"));
    AddGuardia();
}
