 /*
DESCRIPCION : en la taberna de Sally la gorda el puerto de Azzor
FICHERO     : /d/akallab/comun/habitación/akallab/azzor/taberna/sally/mesas.c
MODIFICACION: 08-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit SCHEDULER_ROOM;

create()
{
    ::create();
    SetIntShort("la taberna de Sally la gorda");
    SetIntLong("Estás junto a la ventana. Esta zona de la taberna está llena de mesas bajas de "
        "madera rodeadas de taburetes. La gente suele comprar su bebida en la barra y "
        "tomársela aquí tranquilamente mientras habla con los amigos.\nJunto a ti, al este, "
        "hay una ventana a través de la cual puedes ver la bahía del puerto.\n");
    AddDetail(({"ventana"}),"En la pared del Este, a tu lado, se halla una gran ventana. A "
        "través de ella puedes observar la bahía del puerto y los barcos fondeados en ella.\n");
    AddDetail(({"bahia","bahía","barcos"}),"En la bahía que forma el puerto se pueden observar "
        "multitud de barcos fondeados. Algunos de ellos están en medio de la bahía, mientras "
        "que otros se hallan atracados junto al muelle.\n");
#include "taberna_detail.h"
    SetMainRoom("barra");
    SetLastDest(AZ_PUERTO("portico05"));
    SetNotifyExits(({}));
    SetThrowOutMsg("Sally grita desde el escenario: Nytjar, me voy, cierra ya.\nNitjar sale de "
        "detrás del mostrador, agitando los puños y gritando: ¡Fuera todos! ¡A dormir la mona "
        "a vuestros barcos! ¡Fuera, fuera!\n");
    SetInformCloseMsg("Al este oyes a Sally gritar: Nytjy, bonita, vamos a ir cerrando ya, ¿no "
        "te parece?.\n Nytjar golpea el mostrador con un vaso y grita: ¡Ya lo habéis oído, "
        "mostrencos! Id vaciando esos vasos, y ¡a la calle a tomar el aire!\n");
    AddExit("oeste","rincon");
    AddExit("sur","barra");
}
