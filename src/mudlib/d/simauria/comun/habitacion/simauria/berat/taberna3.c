//[Maler]
#include "./path.h"
inherit PUB;

create() {
    ::create();
    SetIntShort("la taberna 'Serpiente marina'");
    SetIntLong("Te encuentras en uno de los peores antros de toda Simauria, "
    "en este local son muy frecuentes las peleas entre marineros.\n "
    "Viendo como está el suelo con resecas manchas de sangre, y las mesas y sillas "
    "rotas en su mayoría, te puedes hacer una leve idea de lo que supone "
    "quedarse mucho tiempo en este lugar.\n  Al fondo, entre dos columnas, "
    "consigues divisar la destartalada barra del local.\n");

    AddDetail("mesas",
    "Te resulta difícil creer que esos montones de tablas y clavos hayan "
    "servido de mesas en algun tiempo.\n");
    AddDetail(({"mostrador", "barra"}),
    "Es una destartalada barra de madera, reforzada con unas tablas nuevas.\n");
    AddDetail("sillas",
    "Aunque a la mayoría de ellas le falta alguna pata, todavía cumplen su función.\n");
    AddDetail(({"paredes", "pared"}),
    "Carecen de cualquier motivo decorativo, salvo las abundantes "
    "manchas de licor y sangre.\n");
    AddDetail(({"manchas","sangre"}),
    "Son tan abundantes, que parecen parte de la decoración del local.\n");

    SetIntNoise("Oyes el sonido del mar a lo lejos.\n");
    SetIntSmell("El local desprende un hedor pestilente.\n");
    SetLocate("berat");
    SetIntBright(30);

    AddDrink("vino","una jarra de",3,6,4,0);
    AddDrink("cerveza","una jarra de",2,5,4,0);
    AddDrink("ron","una jarra de",2,8,4,0);
    AddDrink("aguardiente","un vaso de",3,10,4,0);
    AddExit("sur","./ctab3");
    AddDoor("sur", "la puerta de la calle",
    "Es la puerta que da a la calle de las tabernas, se nota que ha sido arreglada "
    "multitud de veces.\n",
    ({"puerta", "puerta de la calle", "puerta de salida", "puerta del sur"}));
    SetKeeper(PNJ("simauria/berat/gregor"));
    AddItem(PNJ("simauria/berat/marinero"), REFRESH_DESTRUCT,1);
    AddItem(PNJ("simauria/berat/mankson"),REFRESH_DESTRUCT, 1);
}


