/****************************************************************************
Fichero: playa4.c
Autor: Ratwor
Fecha: 17/11/2007
Descripci�n: La playa de Gorat
****************************************************************************/
#include "./path.h"
inherit BETWA "gorat/playa/playa_base";
create(){
    ::create();
    SetLocate("puerto de Gorat");
    SetIntLong("Te encuentras rodeado de rocas y mar. Esta playa est� notablemente "
    "desierta, posiblemente debido a la irregularidad del terreno.\n Las olas golpean "
    "incesantes contra las piedras que forman esta orilla.\n En direcci�n sur se levanta "
    "magestuoso el faro de Gorat.\n En el noroeste, a lo lejos, se aprecia una "
    "peque�a construcci�n.\n");
    AddDetail("playa", "La playa es todo lo que te rodea: las rocas, las olas, el "
    "mar...\n En direcci�n sur llegas al puerto de Gorat, mientras que la playa sigue "
    "hacia el noroeste para encontrarse con una peque�a construcci�n.\n");
    AddDetail(({"construcci�n", "construccion", "peque�a construcci�n",
        "peque�a construccion"}), "Desde aqu� todav�a no llega a apreciarse de qu� "
        "se trata.\n");
    AddExit("noroeste", "./playa5");
    AddExit("sudeste", "./playa3");
}
