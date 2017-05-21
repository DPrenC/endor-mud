/****
autor: Orome
archivo base del segundo tramo del camino del este en el dominio de eriador, en la parte sur de los pantanos.

****/

#include "./path.h"

inherit ROOM;

create(){
    ::create();
    SetLocate("el gran camino del este");
    SetIntShort("camino del este, al sur de los pantanos de Moscagua");
    SetIntLong("El gran camino del este, bordeando los pantanos de Moscagua en su parte sur.\n");
    SetIndoors(0);

}
