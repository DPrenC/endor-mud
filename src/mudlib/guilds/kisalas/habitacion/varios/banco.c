/* Banco del Gremio de Kisalas
Creado: [Greywolf] 16-01-05

*/

#include "path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit BANK;

create()
{
    ::create();
    SetBankName("kisalas");
    SetIntShort("la oficina de la Hermandad de banqueros de las Kisalas");
    SetIntLong("Esta es la Oficina de la Hermandad de Banqueros. Aqu� puedes "
               "abrir o cancelar cuentas,  sacar y meter dinero, etc...\n");

    SetIndoors(1);
    SetIntBright(45);
    SetKeeper(AM_PNJ("nika"));
    SetAssociatedRooms(({AM_VARIOS("taquillas")}));
    SetLastDest(AM_PASILLO("pasillo3"));
    SetNotifyExits(({"sur"}));
    SetInformCloseMsg("Nika mira hacia la oficina de consignas y grita: �Geneibr, ve "
        "terminando ah�, que nos vamos!\nLuego te mira un segundo y dice: Ser� mejor que "
        "termines lo que has venido a hacer aqu�, se va haciendo tarde.\n");
    SetThrowOutMsg("Nika se levanta y sale de detr�s del mostrador diciendo: Est� bien, por "
        "hoy hemos terminado. Los balances est�n cerrados y no se har�n m�s operaciones.\nActo "
        "seguido, te conmina a salir con obstensibles gestos.\n");
    SetNotifyCloseMsg("Nika sale acompa�ada por Geneibr, cierra la puerta del banco y ambas se "
        "alejan charlando por el pasillo.\n");
    SetNotifyOpenMsg("Llegan Nika y Geneibr charlando por el pasillo.\nNika abre la puerta del "
        "banco, y ambas funcionarias se dirigen a sus puestos.\n");
    AddExit("norte",AM_VARIOS("taquillas"));
    AddExit("sur", AM_PASILLO("pasillo3"));
    AddDoor("sur", "la puerta del pasillo",
        "Es la puerta que da al pasillo. Est� hecha de gruesos paneles de madera enmarcados "
            "por listones de hierro.\n",
        ({"puerta","puerta del pasillo","puerta sur"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
        P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
        P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
}


