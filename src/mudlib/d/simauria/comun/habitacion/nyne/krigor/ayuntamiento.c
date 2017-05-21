/*
DESCRIPCION  : Ayuntamiento del pueblo de Krigor
FICHERO      : /d/simauria/comun/habitacion/nyne/krigor/ayuntamiento.c
MODIFICACION : 26-11-01 [Chaos@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <nightday.h>
#include <door.h>

inherit SCHEDULER_ROOM;
inherit "/room/censo";


create() {
    ::create();
    SetCity("Krigor");
    SetIntShort("el ayuntamiento del poblado de Krigor");
    SetIntLong(
    "Est�s en el ayuntamiento del poblado de Krigor. Frente a ti se halla un "
    "mostrador y un libro de censo sobre �l. Al norte de esta habitaci�n se halla "
    "la sala de reuniones.\n");

        AddDetail("mostrador",
    "El mostrador es una especie de mesa alta y estrecha de madera. Tras ella "
    "rodeado de papeles y archivos se encuentra el secretario del ayuntamiento.\n");

    AddDetail(({"sala de reuni�n", "sala de reunion", "sala"}),
    "Al norte de aqui se halla una amplia sala de reuni�n.\n");

    AddDetail(({"censo","libro"}),
    "En este libro esta una copia del censo actual en Simauria. Pasa censarte en "
    "este lugar o cambiar el lugar en el que estas censado utiliza 'censar' y"
    "si quieres saber donde est�s censado, usa 'consultar'.\n");

    SetIntSmell("Un fuerte olor a hierba fresca.\n");
    SetLocate("Krigor");
    SetIndoors(1);
    SetIntBright(30);
    AddExit("sur",KRIGOR("plaza"));
    AddExit("norte",KRIGOR("salon_ayto"));
    AddDoor("sur", "la puerta de salida",
    "Es la puerta que da a la plaza de Krigor.\n",
    ({"puerta", "puerta de la calle", "puerta del sur"}),
    ([P_DOOR_CLOSE_TIME : ({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE})]));
    SetLastDest("./plaza");
    SetNotifyExits("sur");
    SetAssociatedRooms("./salon_ayto");
    SetSchedulerID("secretario");
    SetCloseTime(({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE}));
    AddItem(PNJKRIG("secretario"));
}
