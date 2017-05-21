/*****************************************************************************************
 ARCHIVO:       robledal02.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCI�N:   Sendero a trav�s del robledal.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("un sendero a trav�s de los �rboles");
    SetIntLong("Te encuentras en un sendero que cruza un denso bosque de recios �rboles "
        "centinela resguardados tras robles y acebos tan viejos como el propio bosque. "
        "Multitud de l�quenes tapizan los gruesos troncos que puedes ver a tu alrededor "
        "como t�nicas arb�reas.\n");
    AddDetail(({"�rboles", "arboles", "recios �rboles", "centinela"}), "Est�n inclinados "
        "hacia el suelo.\n");
    AddDetail("acebos", "Se trata de unos arbustos de color verde oscuro, est�n "
        "adornados con peque�as bolitas de color rojo.\n");
    AddDetail("robles", "La corteza de sus troncos est� repleta de nudos.\n");
    AddDetail(({"troncos", "t�nicas", "tunicas"}), "Algunos est�n esparcidos al lado del "
        "sendero. La mayor�a est�n podridos y huecos debido a la humedad y a la "
        "constante falta de luz.\n");
    AddDetail(({"l�quenes", "liquenes"}), "Cubren y colorean toda la superficie de los "
        "troncos.\n");
    AddDetail("suelo", "Peque�as hojas secas disimulan lo que parece ser un sendero.\n");

    SetIntSmell("El ambiente est� h�medo y huele a madera picada.\n");
    SetIntNoise("Escuchas el crujir de los �rboles y gru�idos procedentes de alg�n lugar "
        "cercano.\n");

    AddExit("norte", HAB_BOSQUE_ISLA("robledal06.c"));
    AddExit("oeste", HAB_BOSQUE_ISLA("robledal01.c"));
}
