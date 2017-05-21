/*
DESCRIPCION  : calle del mercado
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cmerc1.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
			[Maler]
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <scheduler.h>


inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la calle del mercado");
    SetIntLong("Estás en la calle del mercado, llamada así porque en "
    "ella se realizan la mayoría de compra-ventas del pueblo, es una calle "
    "larga, y bastante ancha, en la que siempre podemos encontrarnos con "
    "alguien. La calle se une con la calle Golduin al norte, y continua "
    "hacia el sur.\n  Al oeste vemos la casa de algún mercader, y al este "
    "una forja, con un letrero en la puerta.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el bullicio típico de una calle como esta.\n");
    SetIntSmell("Huele a humo.\n");
    AddDetail(({"camino","calle"}),"Es una calle bastante antigua, "
    "pero se encuentra en inmejorables condiciones.\n");
    AddDetail("casa","Parece una casa bastante alta, será de algún "
    "comerciante.\n");
    AddDetail(({"cartel", "letrero"}), "Está clavado sobre la puerta.\n");
    AddReadMsg(({"letrero", "cartel"}),"En él puedes leer FORJA DE KOLKSON.\n");

    AddExit("norte","./cgold1");
    AddExit("sur","./cmerc2");
    AddExit("este","./fragua");
    AddExit("oeste","./hab4_1");
    AddDoor("este", "la puerta de la herrería",
    "Es la puerta para entrar a la herrería de Berat.\n",
    ({"puerta", "puerta de la herrería", "puerta de la herreria", "puerta del este"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddDoor("oeste", "la puerta de una casa");


    AddItem(PNJ("simauria/berat/campes1"),REFRESH_DESTRUCT,1);
}

