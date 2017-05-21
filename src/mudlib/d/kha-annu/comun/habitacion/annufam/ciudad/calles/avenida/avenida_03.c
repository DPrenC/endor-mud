/****************************************************************************
Fichero: avenida_03.c
Autor: Kastwey
Creación: 27/07/2005
Descripción: Continuación de la avenida real de Annufam
****************************************************************************/

#include "./path.h"

inherit BASE_CIUDAD_ANNUFAM;

public void create()
{
    ::create();
    SetIntShort("la avenida Real, cruce con calle Ungrim");
    SetIntLong(W("Has llegado a una parte de la avenida donde es atravesada "
                 "por la calle Ungrim. En esta calle es donde se encuentran "
                 "todas las tiendas y bares de la ciudad, para los ratos "
                 "libres de los guerreros enanos. La avenida sigue de norte "
                 "a sur, y dicha calle al este y al oeste.\n"));

    AddSuelo();
    AddLuzAntorchas();

    AddExit("sur",HAB_AVENIDA_ANNUFAM("avenida_02"));
    AddExit("norte",HAB_AVENIDA_ANNUFAM("avenida_04"));
    AddExit("este",HAB_CIUDAD_ANNUFAM("calles/ungrim/ungrim_01"));
    AddExit("oeste",HAB_CIUDAD_ANNUFAM("calles/ungrim/ungrim_05"));

}

