/****************************************************************************
Fichero: playa4.c
Autor: Ratwor
Fecha: 17/11/2007
Descripción: La playa de Gorat
****************************************************************************/
#include "./path.h"
inherit BETWA "gorat/playa/playa_base";
create(){
    ::create();
    SetLocate("puerto de Gorat");
    SetIntLong("Te encuentras rodeado de rocas y mar. Esta playa está notablemente "
    "desierta, posiblemente debido a la irregularidad del terreno.\n Las olas golpean "
    "incesantes contra las piedras que forman esta orilla.\n En dirección sur se levanta "
    "magestuoso el faro de Gorat.\n En el noroeste, a lo lejos, se aprecia una "
    "pequeña construcción.\n");
    AddDetail("playa", "La playa es todo lo que te rodea: las rocas, las olas, el "
    "mar...\n En dirección sur llegas al puerto de Gorat, mientras que la playa sigue "
    "hacia el noroeste para encontrarse con una pequeña construcción.\n");
    AddDetail(({"construcción", "construccion", "pequeña construcción",
        "pequeña construccion"}), "Desde aquí todavía no llega a apreciarse de qué "
        "se trata.\n");
    AddExit("noroeste", "./playa5");
    AddExit("sudeste", "./playa3");
}
