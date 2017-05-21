/**************************************************************************
fichero: pico.c
Autor: Riberales
Creación: 30/10/05
Descripción: El pico de los mineros en Kha-annu, imprescindible pa picar.
**************************************************************************/




#include "path.h"
#include <properties.h>
#include <combat.h>

inherit WEAPON;

create()
{
    ::create();

    SetStandard(WT_MAZA,3,P_SIZE_GENERIC,M_ACERO);

    SetShort("un pico");
    SetLong("Es un pico con un mango de madera y una barra de acero, que entre"
            " otras cosas, sirve para picar las paredes de minas y "
            "ablandar tierras.\n");


    SetNumberHands(2);
    SetIds(({"pico","arma","pico de acero","pico_minas"}));

}


