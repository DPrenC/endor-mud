/*
DESCRIPCION : fonda 'el Pirata Cojo'
FICHERO     : /d/limbo/comun/habitacion/limbo/limbo/fonda.c
MODIFICACION: 15-09-98 [Angor@Simauria] Creacion
              11-10-99 [Woo] Pasada a /std/pub
              4-11-99 [Icaro] Vuelvo a robar para Berat
[Maler]seguro q de nuevo robas mal.... aaaay, me toy haciendo viejo
retiro lo dicho, bien robao ;)
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit PUB;

create() {
    ::create();
    SetIntShort("la taberna 'El Pirata Cojo'");
    SetIntLong("Estás en la taberna 'El Pirata Cojo'. Es un local oscuro donde "
    "parece que los marineros más violentos vienen a beber. No está "
    "demasiado limpia y casi siempre hay alguna pelea entre los clientes. \n"
    "A la entrada, en la pared, puedes ver un menú con las especialidades "
    "de la taberna.\n");
    AddDetail("clientes","Los clientes de la taberna son marineros "
    "venidos de lejos, normalmente tienen mala cara o van borrachos.\n");
    AddDetail("local","Es un local sucio y oscuro, donde se suelen "
    "cerrar oscuros negocios y tratos.\n El servicio no es bueno, pero "
    "nadie hace preguntas.\n");
    AddDetail(({"menu","menú","tablon","tablón"}),"Deberías leer el menú.\n");
    SetIntNoise("Oyes a la gente hablando fuerte, gritando, riendo y cantando.\n");
    SetIntSmell("Huele bastante mal, aunque a los clientes no parece importarles mucho.\n");
    SetLocate("Berat");
    SetIntBright(20);
    AddFood("pulpitos","una ración de",2,3,0);
    AddFood("sardinas fritas","una ración de",2,2,0);
    AddDrink("vino","una jarra de",3,6,4,0);
    AddDrink("cerveza","una jarra de",2,5,4,0);
    AddDrink("ron","una jarra de",2,8,4,0);
    AddDrink("aguardiente","un vaso de",3,10,4,0);
    AddDrink("mataenanos","un vaso de",3,12,4,0);
    AddExit("norte","./ctab4");
    AddExit("sur","./muelle03");
    AddDoor("sur", "la puerta del muelle",
    "La puerta que da salida al muelle del puerto.\n",
    ({"puerta", "puerta del sur", "puerta del muelle"}));
    AddDoor("norte", "la puerta principal",
    "La puerta que da a la calle de las tabernas.\n",
    ({"puerta", "puerta del norte", "puerta principal"}));
    AddItem(PNJ("simauria/berat/mercader"),REFRESH_DESTRUCT,1);
    SetKeeper(PNJ("simauria/berat/malsin"));
    AddItem(PNJ("simauria/berat/borracho"),REFRESH_DESTRUCT,1);
}