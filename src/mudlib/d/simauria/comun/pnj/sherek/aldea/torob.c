/* Archivo: /d/simauria/comun/pnj/abadia/torob.c
* Descripci�n: Toros bravos para los pastos.
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
    SetStandard("un toro","toro",([ GC_LUCHADOR:30+d6() ]), GENERO_MASCULINO);
    SetName("un toro");
    SetShort("un toro bravo");
    SetLong("Es un sobervio toro, un magn�fico ejemplar de m�s de 500 kilos.\n"
        "Est� criado para las fiestas de los pueblos, as� que debe ser agresivo.\n"
        "Ser�a bueno que te fueras r�pidamente.\n");
    AddId("toro","toro bravo");
    SetNoGet("�Con esos cuernos? No ser�a aconsejable.\n");
    SetAggressive(1);
    SetHands(({({"los cuernos",3,10})}));
    SetHP(QueryMaxHP());
    SetGoChance(90);
    AddWalkZones(SHERALD("pastos"));
    InitChats(5,({"El toro te mira desconfiado.\n",
        "El toro se prepara para embestir.\n",
        (:play_sound(environment(), SND_PNJS("toro")); return "El toro muge furioso.\n";:),
        "El toro escarva con las patas.\n"}));
    InitAChats(10,({"El toro te embiste furioso.\n"}));
}

