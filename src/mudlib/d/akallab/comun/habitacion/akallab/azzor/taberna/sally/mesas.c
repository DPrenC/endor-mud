 /*
DESCRIPCION : en la taberna de Sally la gorda el puerto de Azzor
FICHERO     : /d/akallab/comun/habitaci�n/akallab/azzor/taberna/sally/mesas.c
MODIFICACION: 08-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit SCHEDULER_ROOM;

create()
{
    ::create();
    SetIntShort("la taberna de Sally la gorda");
    SetIntLong("Est�s junto a la ventana. Esta zona de la taberna est� llena de mesas bajas de "
        "madera rodeadas de taburetes. La gente suele comprar su bebida en la barra y "
        "tom�rsela aqu� tranquilamente mientras habla con los amigos.\nJunto a ti, al este, "
        "hay una ventana a trav�s de la cual puedes ver la bah�a del puerto.\n");
    AddDetail(({"ventana"}),"En la pared del Este, a tu lado, se halla una gran ventana. A "
        "trav�s de ella puedes observar la bah�a del puerto y los barcos fondeados en ella.\n");
    AddDetail(({"bahia","bah�a","barcos"}),"En la bah�a que forma el puerto se pueden observar "
        "multitud de barcos fondeados. Algunos de ellos est�n en medio de la bah�a, mientras "
        "que otros se hallan atracados junto al muelle.\n");
#include "taberna_detail.h"
    SetMainRoom("barra");
    SetLastDest(AZ_PUERTO("portico05"));
    SetNotifyExits(({}));
    SetThrowOutMsg("Sally grita desde el escenario: Nytjar, me voy, cierra ya.\nNitjar sale de "
        "detr�s del mostrador, agitando los pu�os y gritando: �Fuera todos! �A dormir la mona "
        "a vuestros barcos! �Fuera, fuera!\n");
    SetInformCloseMsg("Al este oyes a Sally gritar: Nytjy, bonita, vamos a ir cerrando ya, �no "
        "te parece?.\n Nytjar golpea el mostrador con un vaso y grita: �Ya lo hab�is o�do, "
        "mostrencos! Id vaciando esos vasos, y �a la calle a tomar el aire!\n");
    AddExit("oeste","rincon");
    AddExit("sur","barra");
}
