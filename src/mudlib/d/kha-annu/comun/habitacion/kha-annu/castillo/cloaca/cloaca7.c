/* Izet@Simauria */
#include "path.h"
inherit KHA_ROOM;
#include "stink.h"

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntLong("El corredor es m�s estrecho aqu�. No ves nada interesante y solo percibes un "
        "desagradable olor. El sitio apesta, y solo puedes aguantar la respiraci�n.\nPuedes "
        "ver un l�quido parduzco por el suelo.\n");
    AddDetail(({"suelo"}),"Ves restos de comida por el suelo.\n");
    AddDetail(({"restos","restos de comida"}),"Resultan desagradables y te entran ganas de "
        "vomitar.\n");
    AddDetail(({"liquido","liquido parduzco","l�quido","l�quido parduzco"}),"Es un nauseabundo "
        "l�quido de color marr�n.\n");
    SetIntSmell("��Puag!! ��Aqu� huele a muertos!!\n");
    SetIntBright(30);
    SetIndoors(1);
    AddExit("este",CLOACAS+"cloaca8");
    AddExit("oeste",CLOACAS+"cloaca6");
    AddItem(MONS+"slug",REFRESH_DESTRUCT,1);
}
