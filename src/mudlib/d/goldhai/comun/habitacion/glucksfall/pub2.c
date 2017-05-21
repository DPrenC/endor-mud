#include "path.h"
inherit PUB;

create(){
    ::create();
    SetIntShort("la taberna 'mi hacha me acompaña'");
    SetIntLong("¿Cómo puede llamarse una taberna 'mi hacha me acompaña'? La verdad es "
        "que resulta bastante chocante verte aquí, sabes que no es tu sitio pero tu "
        "curiosidad ha podido más que tu cordura.\n");
    SetIndoors(1);
    SetIntBright(30);
    AddExit("oeste","calle7");
    AddDrink("cerveza", "una jarra de", 5, 5, 5, 0);
    AddDrink("cerveza negra", "una jarra de", 6, 6, 6, 0);
    AddDrink("grog","una jarra de",3,8,4,0);
    AddDrink("vino rancio","un vaso de",2,4,2,0,"Uarrgghh.. está asqueroso.\n");
    AddDrink("yith-pen","un vaso de",8,2,5,0,
        "Sabe a leche con almendras pero es muy refrescante y sabroso.\n");
    AddDrink("agua", "una buena jarra de", 2, 0, 12, 0);
    AddDrink("licor de frutas", "un chupito de", 8, 8, 8, 0);
    AddItem(PNJ("glucksfall/raghzim"),REFRESH_DESTRUCT);
    AddItem(PNJ("glucksfall/ogro_shafil"),REFRESH_DESTRUCT);
    SetKeeper(PNJ("glucksfall/tabernera_glucksfall"));
    SetLocate("Glucksfall");
}
