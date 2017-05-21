/*
DESCRIPCION  : calle del mercado
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cmerc3.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
		[Maler]
--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit SIM_ROOM;
create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la calle del mercado");
    SetIntLong("Estás en la calle del mercado, llamada así porque en "
    "ella se realizan la mayoria de compra-ventas del pueblo. Aquí "
    "siempre podemos encontrarnos con alguien. La calle continua al norte "
    "y al sur, al oeste se ve la casa de algun mercader, y al este "
    "un oscuro callejón.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el bullicio típico de una calle como esta.\n");
    AddDetail(({"camino","calle"}),"Es una calle bastante antigua, "
    "pero se encuentra en inmejorables condiciones.\n");
    AddDetail("casa","Parece la casa de algún comerciante.\n");
    AddDetail(({"callejón", "callejon"}),
    "Es algo oscuro y puede que peligroso.\n");

    AddExit("norte","./cmerc2");
    AddExit("sur","./cmerc4");
    AddExit("oeste","./hab5_1");
    AddExit("este","./callejon");
    AddItem(PNJ("simauria/berat/ciuda1"),REFRESH_DESTRUCT,d3());
    AddDoor("oeste", "la puerta de una casa");
}

