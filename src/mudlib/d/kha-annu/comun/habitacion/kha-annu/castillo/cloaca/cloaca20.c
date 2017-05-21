#include "./path.h"
inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntBright(30);
    SetIntLong("El corredor se estrecha un poco m�s aqu�. No ves nada interesante a tu "
        "alrededor aparte de la podredumbre que caracteriza a este lugar.\n");
    AddDetail( ({"suciedad","podredumbre"}), "Todo a tu alrededor es sucio y apestoso.\n");
    AddExit("este",CLOACAS+"cloaca21");
    AddExit("sur",CLOACAS+"cloaca19");
    AddItem(MONS+"slug",REFRESH_REMOVE,2);
}
