/* Banco de Gorat
 * [c] cheto
 *
 * 16-11-98 [c] Creacion
 */

#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <scheduler.h>
inherit BANK;

create() {
    ::create();
    SetLocate("Gorat");
    SetBankName("gorat");
    SetIntShort("el banco de Gorat");
    SetIntLong(
    "Te encuentras en el banco de Gorat. Aquí puedes "
    "abrirte una cuenta o cancelarla, así como ver el estado de la misma, o ingresar y "
    "sacar dinero.\n");


    SetIndoors(1);
    SetIntBright(45);

    SetKeeper(PNJ("banquero"),REFRESH_DESTRUCT);
    AddItem(GORPNJ("guard"), REFRESH_DESTRUCT, 2);
    AddExit("norte","./taquillas");
    SetNotifyExits("sur");
    SetAssociatedRooms("./taquillas");
    SetLastDest("../calles/callep6");
    AddExit("sur","../calles/callep6");
    AddDoor("sur", "la puerta de la calle",
    "La puerta que da a la calle principal de Gorat.\n",
    ({"puerta", "puerta de salida", "puerta de la calle", "puerta del sur"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}
