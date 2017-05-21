/* Archivo: /d/simauria/comun/pnj/abadia/loysha.c
* Descripci�n: la tendera de la tienda de Sloch.
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
    SetLong("Loysha es una humana m�s bien bajita y delgada.\nAunque su cara "
        "deja ver la tristeza y el aburrimiento que le causa estar encerrada "
        "en tan m�sera aldea, no lo demuestra con sus clientes, con los que se "
        "muestra exquisitamente amable y simp�tica.\n");
    AddId(({"loysha","Loysha","tendera","la tendera","humana","mujer"}));
    SetHP(QueryMaxHP());
}
