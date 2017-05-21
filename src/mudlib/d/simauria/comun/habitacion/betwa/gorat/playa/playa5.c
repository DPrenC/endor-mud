/****************************************************************************
Fichero: playa5.c
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
    "magestuoso el faro de Gorat.\n Al norte tienes la entrada a una peque�a construcci�n"
    " que parece ser una ermita.\n");
    AddDetail("playa", "La playa es todo lo que te rodea: las rocas, las olas, el "
    "mar...\n");
    AddDetail(({"construcci�n", "construccion", "peque�a construcci�n",
        "peque�a construccion", "ermita"}),
        "Es una peque�a ermita, posiblemente dedicada a alg�n Dios local.\n");
    AddExit("norte", "../hermita/entrada");
    AddExit("sudeste", "./playa4");
    AddDoor("norte", "la puerta de la ermita",
    "Es una puerta de madera corro�da por el salitre del mar.\n",
    ({"puerta", "puerta de madera", "puerta del norte", "puerta de la ermita"}));
}
