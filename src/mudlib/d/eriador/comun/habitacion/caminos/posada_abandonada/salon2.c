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
    SetIntShort("el sal�n principal");
    SetIntLong("En esta parte del sal�n se encuentran las m�s esquisitas "
    "muestras de arte �lfico de todo el territorio humano: Tapices, cuadros, "
    "l�mparas y esculturas crean un clima de arte y naturaleza.\n Aqu�, el sal�n "
    "est� despejado para poder celebrar bailes o juegos. Una puerta situada al "
    "este comunica con el comedor de la casa. Hacia el norte se extiende el "
    "enorme sal�n.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"tapiz","tapices","cuadro","cuadros","lampara","l�mpara","lamparas",
    "l�mparas","escultura","esculturas","estatua","estatuas"}),"Todos los objetos "
    "de decoraci�n se basan en temas de la naturaleza.\n");
    AddExit("norte","./salon1");
    AddExit("este","./comedor");
    AddDoor("este", "la puerta del comedor",
    "La puerta que comunica el gran sal�n con el comedor.\n",
    ({"puerta", "puerta del comedor", "puerta del este"}));
}