/* Archivo: /d/simauria/comun/pnj/abadia/guardian2.c
* Descripción: Guardián especial de la abadía para la vigilancia de la casa del
    administrador.
* Autor: Lug y Yalin.
*/
#include "path.h"
#include <properties.h>
#include <guild.h>
#include <skills.h>
inherit PNJ("sherek/gbase");

create()
{
    ::create();
    SetStandard("un guardián mayor","humano",([ GC_LUCHADOR:50+d10() ]),GENERO_MASCULINO);
    SetShort("un guardián mayor");
    SetLong("Es un miembro del cuerpo especial del servicio privado de guardias "
        "de la abadía de Sherek.\nSu entrenamiento es más duro y exigente que el "
        "de los demás guardianes, por lo que se les dedica a la guardia y "
        "cuidado de los lugares más exclusivos de la abadía, como la casa "
        "de administración.\n");
    AddId(({"guardia mayor","guardián mayor","guardian mayor","vigilante mayor"}));
    SetCon(QueryCon()+5);
    SetHP(QueryMaxHP());
    Set(P_CANT_LURE,1);
    AddItem(ARMA("sherek/aldea/espada2"),REFRESH_REMOVE,2,SF(wieldme));
    AddItem(PROT("sherek/aldea/coraza"),REFRESH_REMOVE,1,SF(wearme));
}
