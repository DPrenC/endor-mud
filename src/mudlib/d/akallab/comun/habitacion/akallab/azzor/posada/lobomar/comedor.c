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
           "está " + (QueryEstadoChimenea() ?
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
    "En este lado de la taberna de la posada del 'Lobo de mar' más alejado de la barra "
    "se encuentran varias largas mesas de madera con bancos donde la gente se sienta a "
    "comer. Hay una gran chimenea en la esquina y sobre ella cuelga una enorme mandíbula "
    "de tiburón.\n");

    AddDetail("chimenea",SF(mirar_chimenea));

    AddDetail(({"mesas","bancos"}),
    "Hay varias mesas a tu alrededor con bancos y todas son parecidas: de madera, "
    "largas y gastadas.\n");

    AddDetail(({"mandibula","mandíbula","mandíbulas"}),
    "Está colgada sobre la chimenea. Son dos gigantescas mandíbulas abiertas llenas "
    "de grandes y afilados dientes. El tiburón del que proviene debió ser un monstruo "
    "temible que podía engullir a un hombre de un sólo bocado... Te preguntas como "
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
    SetThrowOutMsg("Al este oyes a Molly gritar:\n¡Venga, se acabó! ¡Todo el mundo fuera, que "
        "me voy a dormir!\n");
    SetNotifyExits(({}));
    SetInformCloseMsg("Oyes a Molly en la taberna, golpeando el mostrador con un cucharón "
        "gritando:\n¡Vamos, id terminando que nos vamos!\n");
    AddExit("este","taberna");
}

