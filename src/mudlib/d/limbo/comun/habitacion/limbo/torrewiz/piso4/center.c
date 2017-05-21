/**
 * /torrewiz/piso4/center.c
 */

#include "path.h"
inherit ROOM;

create() {
    ::create();

    SetIntShort("la cuarta planta de la Torre de Magia");
    SetIntLong(
"Estás en el cuarto piso de la torre. En esta planta se encuentran "
"las habitaciones de los Councilers y Dioses. Hay puertas en todas las "
"direcciones, cada una con un letrero con el nombre del propietario de "
"la habitacion. "
"Unas escaleras bajan hacia el tercer piso.\n");

    SetIntBright(70);
    SetIndoors(1);

    AddExit("abajo",TORRE("piso3/center"));

    AddExit("khelben",   TORRE("rooms/khelben/workroom"));
    AddExit("mirill",    TORRE("rooms/mirill/workroom"));
    AddExit("nyh",       TORRE("rooms/nyh/workroom"));
    AddExit("theuzifan", TORRE("rooms/theuzifan/workroom"));
    AddExit("kastwey", TORRE("rooms/kastwey/workroom"));
    // AddExit(<nombre>, TORRE("rooms/<nombre>/workroom"));
}

