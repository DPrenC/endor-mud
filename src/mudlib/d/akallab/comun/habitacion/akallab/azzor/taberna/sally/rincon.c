/*
DESCRIPCION : rinc�n de la taberna de Sally la gorda el puerto de Azzor
FICHERO     : /d/akallab/comun/habitaci�n/akallab/azzor/
              taberna/sally/rinc�n.c
MODIFICACION: 09-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit SCHEDULER_ROOM;

create()
{
    ::create();
    SetIntShort("un rinc�n de la taberna de Sally la gorda");
    SetIntLong("En este rinc�n de la taberna se ha colocado una especie de peque�o escenario, "
        "que no es otra cosa que una peque�a y r�stica plataforma de madera elevada por encima "
        "del nivel del suelo. Es aqu� donde act�an los juglares y titiriteros que suelen pasar "
        "por aqu�. A veces, hasta la propia Sally se anima a cantar algunas canciones obscenas "
        "e irreverentes, muy del agrado de los marineros.\n");
    AddDetail(({"escenario","plataforma"}),"Adosada a la esquina del local se halla colocada "
        "una peque�a plataforma r�stica de madera. Es en ese lugar sobre el que suelen actuar "
        "los artistas ambulantes que pasan por aqu� y alg�n que otro cliente borracho de la "
        "taberna.\n");
#include "taberna_detail.h"
    SetMainRoom("barra");
    SetLastDest(AZ_PUERTO("portico05"));
    SetNotifyExits(({}));
    SetThrowOutMsg("Sally grita: Nytjar, me voy, cierra ya.\nLuego salta del escenario y con "
        "un gesto elocuente dice: Vamos, a la calle, que estoy muy cansada.\n");
    SetInformCloseMsg("Sally grita: Nytjy, bonita, vamos a ir cerrando, �no te "
        "parece?\nCrees vislumbrar una sonrisa maliciosa en sus labios.\n");
    AddExit("este","mesas");
    AddExit("sur","escalera0");
    AddItem(PNJ_AZZOR("sally"),REFRESH_DESTRUCT);
    AddItem(PNJ_AZZOR("orco_borracho"),REFRESH_DESTRUCT,4+d4());
}
