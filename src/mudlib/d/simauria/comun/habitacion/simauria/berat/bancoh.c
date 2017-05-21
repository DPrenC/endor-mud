/* Banco de berat
 * [m] Mirill
 * [j] jorus
 * 25/01/98 [m] Creacion
 * 29/10/99 [j] modifica para berat
 */
#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit BANK;


create() {
    ::create();
    SetBankName("berat");
    SetLocate("berat");
    SetIntShort("el banco de berat");
    SetIntLong(
    "Este es el banco de Berat. Aquí puedes "
    "ver el estado de tu cuenta, o sacar y meter dinero.\n");

    SetIntBright(45);

    SetKeeper(PNJ("banquero"));

    AddExit("norte","./taquillas");
    AddExit("sur","./cprin5");
    AddDoor("sur", "la puerta de salida",
    "Es la puerta para salir a la calle principal de Berat.\n",
    ({"puerta", "puerta de salida", "puerta del sur"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    SetLastDest("./cprin5");
    SetNotifyExits("sur");
    SetAssociatedRooms("./taquillas");

}


