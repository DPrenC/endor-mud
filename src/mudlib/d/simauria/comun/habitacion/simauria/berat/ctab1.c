/*
DESCRIPCION  : calle de las tabernas
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/ctab1.c

--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit SIM_ROOM;
create() { 
    ::create();
    SetLocate("Berat");
    SetIntShort("la calle de las tabernas");
    SetIntLong("Estás en la calle de la sirena o calle de las tabernas, la calle "
    "preferida por comerciantes y marineros para descansar y divertirse tras un "
    "largo viaje.\n La calle continúa al oeste con distintas tabernas y al este se "
    "une con la calle principal.\n En el sur se aprecia la abundante maleza de "
    "un solar abandonado.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el bullicio proveniente de las tabernas.\n");
    AddDetail(({"camino","calle"}),"Es la calle más transitada de la "
    "ciudad, está bastante sucia y mal iluminada.\n");
    AddDetail(({"solar", "solar abandonado", "maleza"}), "Es un solar abandonado de hace "
    "tiempo que está lleno de maleza en el sur.\n");
    AddExit("oeste","./ctab2");
    AddExit("este","./cprin7");
    AddExit("sur", "./cpuerto");
    HideExit("sur",1);
}

