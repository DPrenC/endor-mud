/****************************************************************************
Fichero: playa5.c
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
    "magestuoso el faro de Gorat.\n Al norte tienes la entrada a una pequeña construcción"
    " que parece ser una ermita.\n");
    AddDetail("playa", "La playa es todo lo que te rodea: las rocas, las olas, el "
    "mar...\n");
    AddDetail(({"construcción", "construccion", "pequeña construcción",
        "pequeña construccion", "ermita"}),
        "Es una pequeña ermita, posiblemente dedicada a algún Dios local.\n");
    AddExit("norte", "../hermita/entrada");
    AddExit("sudeste", "./playa4");
    AddDoor("norte", "la puerta de la ermita",
    "Es una puerta de madera corroída por el salitre del mar.\n",
    ({"puerta", "puerta de madera", "puerta del norte", "puerta de la ermita"}));
}
