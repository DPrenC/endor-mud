/* Izet@Simauria */

#include "path.h"
inherit KHA_ROOM;
#include "stink.h"

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntLong("El corredor es mas estrecho aqu�. No ves nada interesante y solo percibes un "
        "desagradable olor. Puedes ver un l�quido parduzco por el suelo.\n");
    AddDetail(({"suelo"}),"Ves restos de comida por el suelo.\n");
    AddDetail(({"restos","restos de comida"}),"Resultan desagradables y te entran ganas de "
        "vomitar.\n");
    AddDetail(({"liquido","liquido parduzco","l�quido","l�quido parduzco"}),"Es un nauseabundo "
        "l�quido de color marr�n.\n");
    SetIntSmell("��Puag!! ��Aqu� huele a muertos!!\n");
    SetIntBright(30);
    SetIndoors(1);
    AddExit("norte",CLOACAS+"cloaca10");
/*
    AddExit("este",CLOACAS+"cloaca35");
*/
    AddExit("sur",CLOACAS+"cloaca8");
}

