/****************************************************************************
Fichero: playa2.c
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
    "incesantes contra las piedras que forman esta orilla.\n En este mismo lugar se encuentra "
    "magestuoso el faro de Gorat.\n");
    AddDetail("playa", "La playa es todo lo que te rodea: las rocas, las olas, el "
    "mar...\n Hacia el sur llegas al puerto de Gorat, mientras que la playa sigue "
    "hacia el noroeste.\n");

    AddExit("norte", "./playa3");
    AddExit("sudeste", "./playa1");
    AddExit("entrar", "../casas/faro1");
}
