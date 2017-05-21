/* Archivo: /d/simauria/comun/pnj/abadia/base.c
* Descripci�n: funciones base para los guardias.
* Autor: Lug y Yalin.
*/
#include "path.h"

inherit PNJ("sherek/aldea/base");
inherit GUARD;

create()
{
    "*"::create();
    AddId(({"humano","guardia","guardian","guardi�n","vigilante"}));
    SetNoGet("El guardi�n gru�e y dice: �Eh, con las manos nada de bromas!\n");
    SetCitizenship("sherek");
    SetGuardDefendMsg("Un guardi�n grita: �Eh, insolente! �Te atreves a atacar a un ciudadano "
        "en mi presencia? �Por la diosa que pagar�s con tu vida!\n");
}

