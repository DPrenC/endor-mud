/*****************************************************************************************
 ARCHIVO:       robledal23.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("una pequeña senda");
    SetIntLong("Al norte .\n");
    AddDetail("niebla", "Todo está envuelto en una neblina casi permanente que seguro "
        "despierta fascinación y respeto.\n");
    AddDetail("troncos", "Están huecos y la mayoría están podridos debido a la humedad "
        "y a la contante falta de luz.\n");
    AddDetail(({"robles", "gruesos robles"}), "Nunca habías visto antes unos robles "
        "tan altos y esbeltos como los de este bosque, la corteza de los troncos es "
        "blanquecina y están repletos de nudos.\n");
    AddDetail(({"formas", "formas fantasmagóricas"}), "Asoman rasgos humanos, "
        "encarnando el espectro de algún alma errante.\n");
    AddDetail("suelo", "No ves el suelo en el que pisas a causa de la niebla.\n");

    SetIntNoise("No muy lejos de aquí se escucha el ruido de un chapoteo.\n");

    AddExit("suroeste", HAB_BOSQUE_ISLA("robledal18.c"));
    AddExit("norte", HAB_BOSQUE_ISLA("robledal29.c"));
    AddExit("noreste", HAB_BOSQUE_ISLA("robledal30.c"));
}
