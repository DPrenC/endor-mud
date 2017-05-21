/*
DESCRIPCION  : calle principal
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cprin4.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
[Maler]
07/05/2007, [Y] (Yalin): añado fuente.
*/
#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <nightday.h>
inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la calle principal");
    SetIntLong("Estás en la calle principal de Berat. La calle continúa "
    "al norte y al este. Al sur esta la entrada al ayuntamiento que es el "
    "edificio mas alto de la ciudad, y al oeste ves la entrada de la vieja "
    "posada con un cartel colgando de su fachada.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el bullicio típico de los pueblos comerciantes.\n");
    AddDetail(({"camino","calle"}),"Es la calle mas grande de la ciudad"
    " y las piedras que lo forman están muy desgastadas.\n");
    AddDetail(({"posada","vieja posada"}),"Parece un edificio muy antiguo pero"
        " acogedor.\n");
    AddDetail("piedras","Parecen cantos rodados, muy desgastados.\n");
    AddDetail("ayuntamiento","Es un edificio muy antiguo pero parece "
    "bastante sólido.\n");
    AddDetail(({"letrero", "cartel"}), "Es el cartel de la posada, está notablemente "
    "viejo, pero todavía se puede leer.\n");
    AddReadMsg(({"letrero", "cartel"}), "En él puedes leer FONDA DE GRENEL.\n");
    AddDetail(({"pileta","pila"}),"Es un recipiente rectangular, donde se recoge "
    "el chorro de agua que cae del caño.\n");
    AddDetail(({"caño","canyo","grifo"}),"Es un tubo metálico que sale de la "
    "pared, del que brota un chorro de agua.\n");
    AddDetail(({"chorro","agua","chorro de agua"}),"Agua, mucha agua, fresca y "
    "tentadora.\n");
    AddItem(OTRO("berat/fuente"));
    AddExit("norte","./cprin3");
    AddExit("sur","./ayuntami");
    AddExit("este","./cprin5");
    AddExit("oeste","./fonda");
    AddDoor("sur", "la puerta del ayuntamiento",
    "Es una puerta de madera de medio tamaño que da entrada al ayuntamiento de Berat.\n",
    ({"puerta", "puerta del sur", "puerta del ayuntamiento"}),
    ([P_DOOR_CLOSE_TIME : ({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE})]));
    AddDoor("oeste", "la puerta de la posada",
    "Una doble puerta de madera para entrar a la posada, casi es tan vieja como el "
    "mismo edificio.\n", ({"puerta", "puerta de la posada", "puerta del oeste"}));
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}

