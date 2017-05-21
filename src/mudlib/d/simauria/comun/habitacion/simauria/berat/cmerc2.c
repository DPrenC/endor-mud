/*
DESCRIPCION  : calle del mercado
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cmerc2.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
		[Maler]
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <door.h>
#include <sounds.h>
#include <scheduler.h>



inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la calle del mercado");
    SetIntLong("Est�s en la calle del mercado, es una calle "
    "larga, y bastante ancha, es la calle m�s limpia de la ciudad, "
    "y tambi�n la que se encuentra en mejor estado.\n  La calle continua "
    "al norte y al sur, al este vemos la casa de algun mercader, y al oeste "
    "una tienda, con un letrero en la puerta.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el bullicio t�pico de una calle como esta.\n");
    SetIntSmell("Huele a cuero.\n");
    AddDetail(({"camino","calle"}),"Es una calle bastante antigua, "
    "pero se encuentra en inmejorables condiciones.\n");
    AddDetail("casa","Es una casa muy normal, ser� de alg�n "
    "comerciante.\n");
    AddDetail(({"cartel", "letrero"}), "Un letrero de madera de una tienda.\n");
    AddReadMsg(({"cartel", "letrero"}), "En �l puedes leer: ARMERIA DE MALMABETH.\n");

    AddExit("norte","./cmerc1");
    AddExit("sur","./cmerc3");
    AddExit("este","./hab6_1");
    AddExit("oeste","./tienda2");
    AddDoor("este", "la puerta de una casa");
    AddDoor("oeste", "la puerta de la tienda",
    "Es la puerta de la armer�a.\n",
    ({"puerta", "puerta del oeste", "puerta de la armer�a", "puerta de la armeria"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddItem(PNJ("simauria/berat/guardia"),REFRESH_DESTRUCT,d2());
}

