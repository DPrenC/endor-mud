/*
Se supone que esta es mia(jajajajaja)18-11-1999
[Maler] sigh
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <door.h>
#include <nightday.h>
inherit PUB;

create() {
    ::create();
    SetIntShort("la taberna 'Rosa de los vientos'");
    SetIntLong("Te encuentras en la Taberna Rosa de los vientos, la taberna "
    "preferida por los oficiales de los barcos.\n Es una taberna amplia "
    "y limpia, adornada con timones, anclas y remos, puedes ver unas "
    "cuatro mesas con sus correspondientes sillas y una barra  tras la que suele "
    "estar el tabernero Balthur.\n");

    AddDetail("mesas",
    "En cada mesa hay talladas cartas náuticas.\n");
    AddDetail("barra",
"Es una barra normal, no tiene nada especial.\n");
    AddDetail("sillas",
    "Son sillas normales, hay cuatro por mesa.\n");
    AddDetail(({"adornos","paredes","timones","anclas","remos"}),
    "Son adornos típicos de los marineros, están bien sujetos.\n");

    SetIntNoise("Oyes el sonido del mar a lo lejos.\n");
    SetIntSmell("Hmmmm el olor que llega de la cocina te hace la boca agua.\n");
    SetLocate("berat");
    SetIntBright(30);

    AddFood("pulpitos","una racion de",2,3,0);
    AddFood("sardinas fritas","una ración de",2,2,0);

    AddDrink("vino","una jarra de",3,6,4,0);
    AddDrink("cerveza","una jarra de",2,5,4,0);
    AddDrink("ron","una jarra de",2,8,4,0);
    AddDrink("aguardiente","un vaso de",3,10,4,0);
    AddDrink("mataenanos","un vaso de",3,12,4,0);
    AddExit("norte","./ctab2");
    AddExit("sur","./muelle05");
    AddDoor("sur", "la puerta del muelle",
    "Esa puerta sale al muelle del puerto.\n",
    ({"puerta", "puerta del muelle", "puerta del sur"}),
    ([P_DOOR_CLOSE_TIME : ND_NIGHT]));
    AddDoor("norte", "la puerta principal",
    "la puerta principal que da a la calle de las tabernas.\n",
    ({"puerta", "puerta del norte", "puerta principal"}),
    ([P_DOOR_CLOSE_TIME : ND_NIGHT]));
    SetLastDest("./ctab2");
    SetNotifyExits(({"sur", "norte"}));
    SetCloseTime(ND_NIGHT);
    SetKeeper(PNJ("simauria/berat/balthur"));
    AddItem(PNJ("simauria/berat/griff"),REFRESH_DESTRUCT,1);
    AddItem(PNJ("simauria/berat/apostador"),REFRESH_DESTRUCT,1);
}
