/* Archivo: /d/simauria/comun/pnj/abadia/loysha.c
* Descripción: la tendera de la tienda de Sloch.
* Autor: Lug y Yalin.
*/
#include "path.h"
#include <properties.h>
#include <guild.h>
inherit PNJ("sherek/aldea/base");

create()
{
    ::create();
    SetStandard("Loysha","humano",([ GC_TORPE:20 ]),GENERO_FEMENINO);
    SetName("Loysha");
    SetShort("Loysha, la tendera");
    SetLong("Loysha es una humana más bien bajita y delgada.\nAunque su cara "
        "deja ver la tristeza y el aburrimiento que le causa estar encerrada "
        "en tan mísera aldea, no lo demuestra con sus clientes, con los que se "
        "muestra exquisitamente amable y simpática.\n");
    AddId(({"loysha","Loysha","tendera","la tendera","humana","mujer"}));
    SetHP(QueryMaxHP());
}
