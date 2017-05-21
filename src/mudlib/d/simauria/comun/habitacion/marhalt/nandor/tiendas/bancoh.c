/* Banco de Nandor
 * [m] Mirill
 *
 * 25/01/98 [m] Creacion
 */

#include "./path.h"
#include <properties.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>
inherit BANK;

create() {
    ::create();
    SetLocate("Aldea de Nandor");
    SetBankName("nandor");
    SetIntShort("el banco de Nandor");
    SetIntLong(
    "Te encuentras en el banco de Nandor. Aquí puedes "
    "abrir o cancelar cuentas, sacar y meter dinero, etc...\n");

    SetKeeper(PNJ("marhalt/cennort"));
    SetAssociatedRooms("./taquillas");
    SetNotifyExits("norte");
    SetLastDest("../calle0");
    AddExit("oeste",MARH("nandor/tiendas/taquillas"));
    AddExit("norte", "../calle0");
    AddDoor("norte", "la puerta de la calle",
    "Es la puerta que da a la calle principal.\n",
    ({"puerta de la calle", "puerta del norte", "puerta"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));

}