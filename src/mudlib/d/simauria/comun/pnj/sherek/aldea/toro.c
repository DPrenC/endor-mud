/* Archivo: /d/simauria/comun/pnj/abadia/toro.c
* Descripción: Un toro para la granja.
* Autor: Lug y Yalin
*/
#include "path.h"
#include <properties.h>
#include <guild.h>
#include <sounds.h>

inherit NPC;

create()
{
    ::create();
    SetStandard("un toro","toro",([ GC_LUCHADOR:20+d10() ]), GENERO_MASCULINO);
    SetIds(({"toro"}));
    SetShort("un toro");
    SetLong("Es un sobervio toro, con toda seguridad el semental de la "
        "granja.\nEs un magnífico ejemplar de más de 500 kilos.\nParece temer "
        "algo de ti, pues no te quita los ojos de encima.\n");
    AddId("toro");
    SetNoGet("¿Con esos cuernos? No sería aconsejable.\n");
    SetHands(({({"los cuernos",3,8})}));
    SetHP(QueryMaxHP());
    InitChats(5,({"El toro te mira desconfiado.\n",
        "El toro se rasca con la pared.\n",
        (:play_sound(environment(), SND_PNJS("toro")); return "El toro muge furioso.\n";:),
        "El toro escarva con las patas.\n"}));
    InitAChats(10,({(:play_sound(environment(), SND_PNJS("toro")); return "El toro te embiste furioso.\n";:)}));
}

