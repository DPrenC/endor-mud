/*****************************************************************************************
 ARCHIVO:       robledal16.c
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

    SetIntShort("el robledal de la isla de los Druidas");
    SetIntLong("Como salida de las profundidades de la tierra, una densa niebla "
        "comienza a arremolinarse a tus pies. Ser� tu imaginaci�n, tal vez, pero te "
        "da la impresi�n que los troncos de los gruesos robles de tu alrededor "
        "comienzan a tomar formas fantasmag�ricas, como si de repente quisieran "
        "cobrar vida propia.\n");
    AddDetail("niebla", "Todo est� envuelto en una neblina casi permanente que seguro "
        "despierta fascinaci�n y respeto.\n");
    AddDetail("troncos", "Est�n huecos y la mayor�a est�n podridos debido a la humedad "
        "y a la contante falta de luz.\n");
    AddDetail(({"robles", "gruesos robles"}), "Nunca hab�as visto antes unos robles "
        "tan altos y esbeltos como los de este bosque, la corteza de los troncos es "
        "blanquecina y est�n repletos de nudos.\n");
    AddDetail(({"formas", "formas fantasmag�ricas"}), "Asoman rasgos humanos, "
        "encarnando el espectro de alg�n alma errante.\n");
    AddDetail("suelo", "No ves el suelo en el que pisas a causa de la niebla.\n");

    AddExit("norte", HAB_BOSQUE_ISLA("robledal21.c"));
    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal20.c"));
    AddExit("este", HAB_BOSQUE_ISLA("robledal17.c"));
}
