/*
DESCRIPCION  : calle del mercado
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cmerc4.c
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
    SetIntLong("Estás en la calle del mercado, llamada así porque en "
    "ella se realizan la mayoria de compra-ventas del pueblo, es una calle "
    "larga.\n  Este tramo se une con la calle de las tabernas al sur, y continúa "
    "hacia el norte.\n Al oeste ves la entrada de una tienda, con un letrero "
    "en la puerta.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el bullicio típico de una calle como esta.\n");
    AddDetail(({"camino","calle"}),"Es una calle bastante antigua, "
    "pero se encuentra en inmejorables condiciones.\n");
    AddDetail(({"cartel", "letrero"}),
    "El letrero que cuelga de la puerta de la tienda del oeste.\n");
    AddReadMsg(({"cartel", "letrero"}), "En él puedes leer: TIENDA DE KALIB.\n");
    AddExit("norte","./cmerc3");
    AddExit("sur","./ctab4");
    AddExit("oeste","./tienda1");
    AddDoor("oeste", "la puerta de la tienda",
    "La puerta para entrar a la tienda del oeste",
    ({"puerta", "puerta del oeste", "puerta de la tienda"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}

