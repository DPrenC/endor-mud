/****************************************************************************
Fichero: avenida_04.c
Autor: Kastwey
Creación: 27/07/2005
Descripción: Avenida real de Annufam
****************************************************************************/
#include "./path.h"

inherit BASE_CIUDAD_ANNUFAM;

public void create()
{
    ::create();
    SetIntShort("la avenida real de Annufam");
    SetIntLong(W("Sigues paseando por la Avenida Real de la ciudad de "
                 "Annufam. Todo continúa siendo igual de sobrio y austero. "
                 "Al sur puedes ver el cruce con la calle Ungrim, y al "
                 "norte, la plaza. Un par de antorchas están dispuestas para "
                 "cuando sean necesarias.\n"));

    AddAntorchas();
    AddSuelo();

    AddExit("sur",HAB_AVENIDA_ANNUFAM("avenida_03"));
    AddExit("norte",HAB_AVENIDA_ANNUFAM("avenida_05"));
}