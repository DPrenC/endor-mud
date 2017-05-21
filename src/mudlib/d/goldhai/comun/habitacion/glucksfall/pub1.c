#include "path.h"
inherit PUB;

create()
{
    ::create();
    SetIntShort("la taberna 'espada negra'");
    SetIntLong("Has entrado a la taberna Espada Negra, un sitio sucio, asqueroso y que se cae "
        "de solo mirarlo, pero parece que eso no importa demasiado a la gente que viene aquí.\n"
        "Si sales llegarás a la avenida principal de Glucksfall.\n");
    SetIndoors(1);
    SetIntBright(30);
    AddDrink("cerveza","una",4,5,6,0,"Te bebes una cerveza bien fresquita.");
    AddDrink("grog","una jarra de",3,8,4,0);
    AddDrink("whisky","un vaso de",1,7,2,0);
    AddDrink("orujo","un vaso de",3,10,1,0,
        "Notas como el orujo te va quemando la garganta lentamente.\n");
    SetKeeper(PNJ("glucksfall/esclavo_tabernero"));
    AddItem(PNJ("glucksfall/durghim"),REFRESH_DESTRUCT);
    AddItem(PNJ("glucksfall/kurzuj"),REFRESH_DESTRUCT);
    AddItem(PNJ("glucksfall/tuerto"),REFRESH_DESTRUCT);
    AddExit("este","calle4");
    SetLocate("Glucksfall");
}
