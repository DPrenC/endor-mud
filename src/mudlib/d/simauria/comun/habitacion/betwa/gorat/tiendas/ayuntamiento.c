
#include "./path.h"
#include <door.h>
#include <nightday.h>
inherit SCHEDULER_ROOM;
hacer_pedir(string cad1){
    object ob;
    if (!cad1) {
        write("uso pedir <que> para <que>\n");
        return 1;
    }
    if (cad1=="licencia para pescar"){
        ob=clone_object(OTRO("licenciap"));
        ob->move(TP);
        write("El conserje te da una licencia para pescar\n");
    }else
    write("pedir <que> para <que>\n");
    return 1;
}

create () {
    ::create();
    SetLocate("Gorat");
    SetIntShort("el ayuntamiento de Gorat");
    SetIntLong("Estás en el ayuntamiento del pueblo pesquero de Gorat, es un edificio muy "
    "viejo, y bastante corroído por la salitre del mar. "
    "Puedes pedir informacion al conserje.\n");
    SetIntBright(30);

    AddItem(GORPNJ("conserje"),REFRESH_DESTRUCT);
    AddExit("arriba","./censo");
    AddExit("norte","../calles/callep6");
    AddItem(GORPNJ("guard"), REFRESH_DESTRUCT,2);
    AddItem(GORPNJ("guard2"), REFRESH_DESTRUCT);
    AddDoor("norte", "la puerta de la calle", "Es la puerta que da a la calle principal.\n",
    ({"puerta", "puerta de la calle", "puerta del norte", "puerta de salida"}),
    ([P_DOOR_CLOSE_TIME : ({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE})]));
    SetLastDest("../calles/callep6");
    SetNotifyExits("norte");
    SetAssociatedRooms("./censo");
    SetSchedulerID("conserje");
    SetCloseTime(({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE}));
}

init(){
add_action("hacer_pedir","pedir");
::init();}