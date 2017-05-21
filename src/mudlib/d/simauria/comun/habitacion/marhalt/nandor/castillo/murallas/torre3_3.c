/****************************************************************************
Fichero: torre3_3.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: La peque�a torre sudeste del castillo.
****************************************************************************/

#include "./path.h"
#include <door.h>
#include <sounds.h>
inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("una peque�a torre");
    SetIntLong("La escalera de caracol que asciende de la planta inferior termina en "
    "esta peque�a estancia, ocupada solo por un par de catres de madera. Dos ventanas "
    "arqueadas dan al norte y al sur, cerradas por barrotes de hierro y postigos de "
    "madera que permiten aislar la habitaci�n del exterior. Una escalerilla de mano "
    "asciende hasta una trampilla en el techo.\n");
    AddDetail("escalerilla", "Una escalera de madera carcomida y de aspecto poco fiable.\n");
    AddDetail("ventanas", "Asom�ndote a la del sur contemplas desde gran altura los "
    "prados bajos a orillas del Kandal y las �speras tierras de m�s all�. Asom�ndote a "
    "la del norte observas la porci�n de muralla oriental y el fuerte torre�n de C�nor.\n");
    AddDetail("escalera", "Una ruinosa escalera de caracol que une las distintas partes "
    "de la torre. Constru�da en piedra de mala calidad, sus escalones est�n hundidos en "
    "algunos puntos y medio derrumbados en otros, con algunas de las piedras que la "
    "constituyen medio sueltas.\n");
    AddDetail("soportes", "Viejos soportes de hierro oxidados y en ocasiones medio "
    "desprendidos del muro que los sustenta.\n");
    AddDetail("catres", "Simples tarimas de madera lo suficientemente grandes para "
    "que un hombre se tienda encima.\n");
    AddDetail("techo", "Un mont�n de maderas con muy mal aspecto que da poca "
    "tranquilidad.\n");
    SetIntBright(21);
    SetLocate("el castillo de Nandor");
    AddExit("arriba", "./torre3_4");
    AddExit("abajo", "./torre3_2");
    AddDoor("arriba", "una trampilla",
    "Una vieja trampilla de tablas unidas con bandas de hierro.\n",
    ({"trampilla", "arriba"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_pequena"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_puerta_pequena")]));
}

