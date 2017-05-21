/* Archivo: /d/simauria/comun/pnj/abadia/base.c
* Descripción: funciones base para los guardias.
* Autor: Lug y Yalin.
*/
#include "path.h"

inherit PNJ("sherek/aldea/base");
inherit GUARD;

create()
{
    "*"::create();
    AddId(({"humano","guardia","guardian","guardián","vigilante"}));
    SetNoGet("El guardián gruñe y dice: ¡Eh, con las manos nada de bromas!\n");
    SetCitizenship("sherek");
    SetGuardDefendMsg("Un guardián grita: ¡Eh, insolente! ¿Te atreves a atacar a un ciudadano "
        "en mi presencia? ¡Por la diosa que pagarás con tu vida!\n");
}

