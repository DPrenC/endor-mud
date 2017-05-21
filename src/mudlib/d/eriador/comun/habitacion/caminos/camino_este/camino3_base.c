/****
autor: Orome
archivo base del tercer tramo del camino del este en el dominio de eriador, en la parte este de los pantanos de moscagua.
****/

#include "./path.h"

inherit ROOM;

create(){
    ::create();
    SetLocate("el gran camino del este");
    SetIntShort("camino del este, al este de los pantanos de Moscagua");
    SetIntLong("El gran camino del este, bordeando los pantanos de Moscagua en su parte este.\n");
    SetIndoors(0);

}
