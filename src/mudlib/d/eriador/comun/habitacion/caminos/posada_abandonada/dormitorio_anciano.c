/*****************************************************************************
 AUTOR:		orome
 DETALLES:	posada abandonada
 *****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>

inherit ROOM;

create(){
    ::create();

    SetIntBright(20);
    SetLocate("una posada abandonada");
    SetIntShort("un dormitorio");
    SetIntLong("Estás en un pequeño pero cómodo dormitorio utilizado por el "
    "anciano de la familia. La decoración es simple y escasa. La puerta de salida "
    "está situada al oeste.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddExit("oeste","./despacho_anciano");
    AddDoor("oeste", "una puerta",
    "Una puerta de madera oscura para salir del dormitorio.\n",
    ({"puerta", "puerta de salida", "puerta del oeste"}),
    "llave pequeña",
    ([P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED]));
}
