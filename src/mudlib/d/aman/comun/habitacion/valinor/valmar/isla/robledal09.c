/*****************************************************************************************
 ARCHIVO:       robledal09.c
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

    SetIntShort("un bosque de robles");
    SetIntLong("Est�s en un denso bosque de recios �rboles centinela resguardados tras "
        "agujas color verde grisaceo, robles y acebos tan viejos como el propio bosque. "
        "Multitud de l�quenes tapizan los gruesos troncos que puedes ver a tu alrededor "
        "como t�nicas arb�reas.\n");
    AddDetail(({"�rboles", "arboles", "recios �rboles", "centinela"}), "Est�n inclinados "
        "hacia el suelo.\n");
    AddDetail("acebos", "Son arbustos sagrados para los druidas, y son utilizados en "
        "el solsticio de invierno para atraer suerte y prosperidad.\n");
    AddDetail("robles", "La corteza de sus troncos est� repleta de nudos.\n");
    AddDetail(({"troncos", "t�nicas", "tunicas"}), "Algunos est�n esparcidos al lado del "
        "sendero. La mayor�a est�n podridos y huecos debido a la humedad y a la "
        "constante falta de luz.\n");
    AddDetail(({"l�quenes", "liquenes"}), "Cubren y colorean toda la superficie de los "
        "troncos.\n");
    AddDetail("suelo", "Est� cubieto de peque�as hojas secas.\n");

    SetIntSmell("El ambiente est� h�medo y huele a madera picada.\n");
    SetIntNoise("Escuchas el crujir de los �rboles y gru�idos procedentes de alg�n lugar "
        "cercano.\n");

    AddExit("norte", HAB_BOSQUE_ISLA("robledal13.c"));
    AddExit("este", HAB_BOSQUE_ISLA("robledal10.c"));
    AddExit("noreste", HAB_BOSQUE_ISLA("robledal14.c"));
}
