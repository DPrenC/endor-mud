/*****************************************************************************************
 ARCHIVO:       robledal16.c
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

    SetIntShort("el robledal de la isla de los Druidas");
    SetIntLong("Como salida de las profundidades de la tierra, una densa niebla "
        "comienza a arremolinarse a tus pies. Será tu imaginación, tal vez, pero te "
        "da la impresión que los troncos de los gruesos robles de tu alrededor "
        "comienzan a tomar formas fantasmagóricas, como si de repente quisieran "
        "cobrar vida propia.\n");
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

    AddExit("norte", HAB_BOSQUE_ISLA("robledal21.c"));
    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal20.c"));
    AddExit("este", HAB_BOSQUE_ISLA("robledal17.c"));
}
