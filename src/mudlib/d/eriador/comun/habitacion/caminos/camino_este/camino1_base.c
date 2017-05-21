/****
autor: Orome
archivo base del primer tramo del camino del este en el dominio de eriador.

****/

#include "./path.h"

inherit ROOM;

create(){
    ::create();
    SetLocate("el gran camino del este");
    SetIntShort("camino del este, al oeste de los pantanos de Moscagua");
    SetIntLong("El gran camino del este, bordeando los pantanos de Moscagua en su parte oeste.\n");
    SetIndoors(0);

}
