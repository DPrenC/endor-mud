/* Archivo        pastos01.c
   Autor:         Yalin y Lug
   Fecha:         14/05/2006
   Descripción:   pastos de la granja de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("pastos/pastos");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al sur ves una empalizada que separa este "
        "lugar de los campos de cultivo y al este puedes ver el río; hacia "
        "el norte y hacia el oeste continúan los pastos.\n");
    SetIntNoise("Oyes la corriente del río, el canto de algún pájaro y los "
        "animales mientras pacen.\n");
    AddDetail(({"rio","río","este"}),"Ves el río Kandal que todavía no "
        "adquiere las proporciones que tendrá en las llanuras más cerca del "
        "mar. En esta zona describe cerradas curvas entre las rocas y la "
        "corriente es bastante fuerte.\n");
    AddDetail(({"empalizada","valla","sur"}), "es una empalizada bastante "
        "alta que impide el paso de los animales hacia el sembrado.\n");
    AddExit("norte", SHERALD("pastos/pastos02"));
    AddExit("oeste", SHERALD("pastos/pastos00"));
    pongo();
}
