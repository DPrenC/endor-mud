/* Archivo        pastos02.c
   Autor:         Yalin y Lug
   Fecha:         14/05/2006
   Descripción:   pastos de la granja de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("pastos/pastos");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al este y al norte puedes ver el río; hacia "
        "el oeste y el sur continúan los pastos.\n");
    SetIntNoise("Oyes la corriente del río, el canto de algún pájaro y los "
        "animales mientras pacen.\n");
    AddDetail(({"rio", "río", "este"}), "Ves el río Kandal que todavía no "
        "adquiere las proporciones que tendrá en las llanuras más cerca del "
        "mar. En esta zona describe cerradas curvas entre las rocas y la "
        "corriente es bastante fuerte.\n");
    AddExit("sur", SHERALD("pastos/pastos01"));
    AddExit("oeste", SHERALD("pastos/pastos03"));
    pongo();
}
