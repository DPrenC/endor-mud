/*
DESCRIPCION  : Banco de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/tienda/banco.c
MODIFICACION : 14-10-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <door.h>
#include <scheduler.h>
#include <materials.h>
#include <properties.h>

inherit BANK;

create()
{
    ::create();
    SetLocate("ciudad de Zarkam");
    SetBankName("zarkam");
    SetKeeper(PNJ_Z_CIUDAD("banquero"),REFRESH_DESTRUCT);
    SetAssociatedRooms("./taquillas");
    SetLastDest(Z_CIUDAD("plaza_00"));
    SetNotifyExits("sur");
    AddExit("sur",Z_CIUDAD("plaza_00"));
    AddExit("oeste",Z_TIENDA("taquillas"));
    AddDoor("sur", "la puerta de la calle", "Se trata de una gran puerta de madera maciza.\n",
        ({"puerta", "puerta maciza", "puerta de madera"}), GENDER_FEMALE,
        ([P_MATERIAL : M_MADERA, P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}
