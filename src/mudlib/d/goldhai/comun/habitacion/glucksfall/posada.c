#include "path.h"
inherit PUB;

create()
{
    ::create();
    SetIntShort("la posada 'huesos rotos'");
    SetIntLong("Será mejor que no salgas de aquí sin haber comido algo, ya que nunca "
        "sabes que puede esperarte ahí fuera ni si será esta tu última comida.\n  La "
        "posada tiene el nombre de 'huesos rotos', lo que puede darte una idea de la "
        "gente que discurre por este lugar.\n");
    SetIndoors(1);
    SetIntBright(30);
    AddDrink("cerveza","una",4,5,6,0,"Te bebes una cerveza bien fresquita.");
    AddDrink("vino","un vaso de",2,5,3,0);
    AddDrink("whisky","un vaso de",1,7,2,0);
    AddFood("pollo","un plato de",10,12,0);
    AddFood("conejo","un plato de",8,10,0);
    AddFood("jabalí","una pata de",9,13,0);
    AddFood("lechón", "un tierno", 10, 10, 0);
    AddFood("jamón", "unos taquitos de", 9,9,0);
    AddExit("sur","calle1");
    SetLocate("Glucksfall");
    SetKeeper(PNJ("glucksfall/posadera_glucksfall"));
}
