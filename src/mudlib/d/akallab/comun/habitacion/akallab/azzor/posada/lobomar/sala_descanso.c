/*
DESCRIPCION : sala en la posada del Lobo de mar
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/posada/lobomar/sala_descanso.c
MODIFICACION:
06-12-05 [Riberales] Creacion
16-09-07 [Angor] Movido a posada/lobomar/ . Cambiadas las descripciones.
*/

#include "path.h"
inherit ROOM;
#include <chronos.h>

public int QueryDescanso() { return 1; }

private int pEstadoChimenea;
public int QueryEstadoChimenea() { return pEstadoChimenea; }

public string mirar_chimenea()
{
    return "Es una chimenea situada en la esquina suroeste. Ahora mismo "
           "está " + (QueryEstadoChimenea() ?
                      "encendida, proporcionando un agradable calor al "
                      "lugar.\n" : "apagada.\n");
}

public create()
{
    ::create();
    int estacion = CHRONOS->QueryEstacion();
    pEstadoChimenea = estacion == 1 || estacion == 4;
    SetLocate("ciudad de Azzor");
    SetIntShort("un salón de descanso");
    SetIntLong(
    "En esta estancia de la posada hay varios gastados sillones y una mesa "
    "baja en torno a una chimenea para calentarse en los dias fríos aquí "
    "en la costa, donde la humedad cala hasta los huesos. Un par de candelabros "
    "sobre la repisa de la chimenea dan luz a la sala.\n");

    AddDetail("chimenea",SF(mirar_chimenea));

    AddDetail(({"sillon","sillones","sillón"}),
                "Son unos sillones bastante toscos, pero que cumplen su cometido.\n");

    AddDetail(({"mesa"}),
                "Es una mesa baja junto a los sillones.\n");

    AddDetail(({"candelabro","candelabros"}),
                "Son unos candelabros de bronce muy oxidados, pero que "
                "mantienen iluminada la sala durante todo el día.\n");

    SetIndoors(1);
    SetIntBright(45);
    SetIntNoise((pEstadoChimenea ? "Escuchas el crepitar del fuego que "
                 "hay en la chimenea.\n" : 0));
    SetIntSmell("No hueles nada fuera de lo común.\n");

    AddExit("este",AZ_POSADA("lobomar/entrada"));
    AddItem(PNJ_AZZOR("posadero"),REFRESH_DESTRUCT);
    AddItem(PNJ_AZZOR("viejo01"),REFRESH_DESTRUCT);
    AddItem(PNJ_AZZOR("viejo02"),REFRESH_DESTRUCT);
}

