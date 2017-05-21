/* Archivo: /d/simauria/comun/pnj/abadia/guardian2.c
* Descripci�n: Guardi�n especial de la abad�a para la vigilancia de la casa del
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
    SetStandard("un guardi�n mayor","humano",([ GC_LUCHADOR:50+d10() ]),GENERO_MASCULINO);
    SetShort("un guardi�n mayor");
    SetLong("Es un miembro del cuerpo especial del servicio privado de guardias "
        "de la abad�a de Sherek.\nSu entrenamiento es m�s duro y exigente que el "
        "de los dem�s guardianes, por lo que se les dedica a la guardia y "
        "cuidado de los lugares m�s exclusivos de la abad�a, como la casa "
        "de administraci�n.\n");
    AddId(({"guardia mayor","guardi�n mayor","guardian mayor","vigilante mayor"}));
    SetCon(QueryCon()+5);
    SetHP(QueryMaxHP());
    Set(P_CANT_LURE,1);
    AddItem(ARMA("sherek/aldea/espada2"),REFRESH_REMOVE,2,SF(wieldme));
    AddItem(PROT("sherek/aldea/coraza"),REFRESH_REMOVE,1,SF(wearme));
}
