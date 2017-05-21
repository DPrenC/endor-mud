#include "path.h"
inherit KHA_ROOM;
#include "darts.h"

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntBright(30);
    SetIntLong("El corredor se estrecha mucho más, y casi caminas de lado. Una especie de "
        "líquido parduzco fluye bajo tus pies y huele realmente mal.\n");
    AddDetail( ({"líquido","liquido","agua"}),"Es agua mezclada con las inmundicias de una "
        "gran ciudad.\n");
    AddExit("derecha",CLOACAS+"cloaca22");
    AddExit("izquierda",CLOACAS+"cloaca20");
}
