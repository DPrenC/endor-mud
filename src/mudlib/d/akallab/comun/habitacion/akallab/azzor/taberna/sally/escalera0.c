 /*
DESCRIPCION : en la taberna de Sally la gorda el puerto de Azzor
FICHERO     : /d/akallab/comun/habitaci�n/akallab/
              azzor/taberna/sally/escalera0.c
MODIFICACION: 09-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit SCHEDULER_ROOM;

create()
{
    ::create();
    SetIntShort("la escalera de la taberna de Sally la gorda");
    SetIntLong("Como el resto de la taberna, esta zona est� llena de mesas donde la gente "
        "puede sentarse y beber tranquilamente. Desde aqu� puedes ver el peque�o escenario que "
        "hay en el rinc�n de la taberna que queda al Norte. La barra de la taberna, que "
        "recorre la pared norte del local, llega casi hasta �l.\nEn este lugar, adosada a la "
        "pared, hay una escalera de gruesos pelda�os de madera que permite subir hasta el piso "
        "superior.\n");
    AddDetail(({"ventana"}),"La ventana queda al Nordeste al otro lado de la taberna.\n");
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
    AddExit("norte","rincon");
    AddExit("este","barra");
    AddExit("arriba","escalera1");
}
