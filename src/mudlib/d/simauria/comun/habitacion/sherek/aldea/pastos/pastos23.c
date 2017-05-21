/* Archivo        pastos18.c
   Autor:         Yalin y Lug
   Fecha:         14/05/2006
   Descripción:   pastos de la granja de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("pastos/pastos");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al este puedes ver el río; al norte los "
        "pastos terminan en un tupido bosque que te impide el paso. En las "
        "demás direcciones se extienden los pastos.\n");
    SetIntNoise("Oyes la corriente del río, el canto de algún pájaro y los "
        "animales mientras pacen.\n");
    AddDetail(({"bosque"}),"es un bosque extremadamente espeso que impide "
        "que se pueda acceder a él desde los pastos limitándolos al norte.\n");
    AddDetail(({"rio","río","este"}),"Ves el río Kandal que todavía no "
        "adquiere las proporciones que tendrá en las llanuras más cerca del "
        "mar. En esta zona describe cerradas curvas entre las rocas y la "
        "corriente es bastante fuerte.\n");
    AddExit("sur", SHERALD("pastos/pastos18"));
    AddExit("oeste", SHERALD("pastos/pastos22"));
    pongo();
}
