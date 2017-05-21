/*
DESCRIPCION : mesas en la taberna de la posada del Lobo de mar
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/posada/lobomar/comedor.c
MODIFICACION:
16-09-07 [Angor] Creacion
*/

#include "path.h"
inherit SCHEDULER_ROOM;
#include <chronos.h>

private int pEstadoChimenea;
public int QueryEstadoChimenea() { return pEstadoChimenea; }

public string mirar_chimenea()
{
    return "Es una gran chimenea situada en la esquina noroeste. Ahora mismo "
           "est� " + (QueryEstadoChimenea() ?
                      "encendida, proporcionando un agradable calor al "
                      "lugar.\n" : "apagada.\n");
}

create()
{
    ::create();
    int estacion = CHRONOS->QueryEstacion();
    pEstadoChimenea = estacion == 1 || estacion == 4;
    SetLocate("ciudad de Azzor");
    SetIntShort("el comedor de la taberna");
    SetIntLong(
    "En este lado de la taberna de la posada del 'Lobo de mar' m�s alejado de la barra "
    "se encuentran varias largas mesas de madera con bancos donde la gente se sienta a "
    "comer. Hay una gran chimenea en la esquina y sobre ella cuelga una enorme mand�bula "
    "de tibur�n.\n");

    AddDetail("chimenea",SF(mirar_chimenea));

    AddDetail(({"mesas","bancos"}),
    "Hay varias mesas a tu alrededor con bancos y todas son parecidas: de madera, "
    "largas y gastadas.\n");

    AddDetail(({"mandibula","mand�bula","mand�bulas"}),
    "Est� colgada sobre la chimenea. Son dos gigantescas mand�bulas abiertas llenas "
    "de grandes y afilados dientes. El tibur�n del que proviene debi� ser un monstruo "
    "temible que pod�a engullir a un hombre de un s�lo bocado... Te preguntas como "
    "pudieron atraparlo.\n");
    SetIndoors(1);
    SetIntBright(45);
    SetIntNoise((pEstadoChimenea ? "Escuchas el crepitar del fuego que "
                 "hay en la chimenea.\n" : 0));
    SetIntSmell("Huele a asado.\n");
    SetLocate("ciudad de Azzor");
    SetMainRoom("taberna");
    SetLastDest("entrada");
    SetNoSchedulerObject(1);
    SetThrowOutMsg("Al este oyes a Molly gritar:\n�Venga, se acab�! �Todo el mundo fuera, que "
        "me voy a dormir!\n");
    SetNotifyExits(({}));
    SetInformCloseMsg("Oyes a Molly en la taberna, golpeando el mostrador con un cuchar�n "
        "gritando:\n�Vamos, id terminando que nos vamos!\n");
    AddExit("este","taberna");
}

