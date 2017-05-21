/*****************************************************************************************
 ARCHIVO:       robledal32.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCI�N:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("un sendero en el robledal");
    SetIntLong("No aciertas a ver nada a simple vista a causa de la intensa niebla que "
        "puebla el bosque. Atisbas sabios robles que te observan desde sus eternos "
        "puestos de vigilancia. Sientes un escalofr�o como si algo te observara. �Es "
        "tu imaginaci�n, o ves como algunos �rboles parecen adoptar apariencia "
        "humana?\n");
    AddDetail("niebla", "Todo est� envuelto en una neblina casi permanente que seguro "
        "despierta fascinaci�n y respeto.\n");
    AddDetail(({"robles", "viejos robles"}), "Nunca hab�as visto antes unos robles tan "
        "altos y esbeltos como los de este bosque, la corteza de los troncos es "
        "blanquecina y est�n repletos de nudos.\n");
    AddDetail(({"�rboles", "arboles"}), "Est�n cubiertos de l�quenes, musgos, "
        "bromelias y orqu�deas con flores de brillantes colores, as� como por decenas "
        "de helechos.\n");
    AddDetail("helechos", "Son hermosos y gigantescos, de colores vivaces y alegres.\n");
    AddDetail("suelo", "No ves el suelo en el que pisas a causa de la niebla.\n");

    AddExit("norte", HAB_BOSQUE_ISLA("robledal36.c"));
    AddExit("sur", HAB_BOSQUE_ISLA("robledal24.c"));
    AddExit("sureste", HAB_BOSQUE_ISLA("robledal25.c"));
}
