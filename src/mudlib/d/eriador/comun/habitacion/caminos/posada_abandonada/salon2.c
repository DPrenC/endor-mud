/*****************************************************************************
 AUTOR:		orome
 DETALLES:	posada abandonada
 *****************************************************************************/

#include "./path.h"

inherit ROOM;

create() {
    ::create();

    SetIntBright(20);
    SetLocate("una posada abandonada");
    SetIntShort("el salón principal");
    SetIntLong("En esta parte del salón se encuentran las más esquisitas "
    "muestras de arte élfico de todo el territorio humano: Tapices, cuadros, "
    "lámparas y esculturas crean un clima de arte y naturaleza.\n Aquí, el salón "
    "está despejado para poder celebrar bailes o juegos. Una puerta situada al "
    "este comunica con el comedor de la casa. Hacia el norte se extiende el "
    "enorme salón.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"tapiz","tapices","cuadro","cuadros","lampara","lámpara","lamparas",
    "lámparas","escultura","esculturas","estatua","estatuas"}),"Todos los objetos "
    "de decoración se basan en temas de la naturaleza.\n");
    AddExit("norte","./salon1");
    AddExit("este","./comedor");
    AddDoor("este", "la puerta del comedor",
    "La puerta que comunica el gran salón con el comedor.\n",
    ({"puerta", "puerta del comedor", "puerta del este"}));
}