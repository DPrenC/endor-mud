/*****************************************************************************************
 ARCHIVO:       robledal23.c
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

    SetIntShort("una peque�a senda");
    SetIntLong("Al norte .\n");
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

    SetIntNoise("No muy lejos de aqu� se escucha el ruido de un chapoteo.\n");

    AddExit("suroeste", HAB_BOSQUE_ISLA("robledal18.c"));
    AddExit("norte", HAB_BOSQUE_ISLA("robledal29.c"));
    AddExit("noreste", HAB_BOSQUE_ISLA("robledal30.c"));
}
