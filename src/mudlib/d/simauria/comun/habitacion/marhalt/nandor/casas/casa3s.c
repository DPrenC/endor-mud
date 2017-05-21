/*  Casa 3 Sur creada por Cheto para la aldea de Nandor                   */


#include "./path.h"

inherit SIM_ROOM;
create() {
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("la casa de Uthur");
    SetIntLong("Es una casa grande y acogedora donde viven Uthur y su joven esposa,"
        " y la cual siempre mantiene bien limpia.\n");
    SetIntBright(30);
    AddExit("norte",MARH("nandor/calle3"));
    AddDoor("norte");
    AddItem(PNJ("marhalt/tirpa"),REFRESH_DESTRUCT,1);
}
