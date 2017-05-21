/* Lobo del camino a la abadía.
* Archivo /d/simauria/comun/pnj/abadia/lobo.c
* 3 de Mayo de 2006
* Creación: Yalin y Lug. */
#include "path.h"
#include <properties.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("un lobo","lobo",20,GENERO_MASCULINO);
    SetName("un lobo");
    SetShort("un gran lobo gris");
    SetLong("Es un magnífico ejemplar de lobo gris que merodea por los caminos "
        "en busca de presas o despojos dejados por las caravanas.\nA juzgar por "
        "su actitud, tiene toda la pinta de comerse lo primero que encuentre... "
        "o al primero.\n");
    AddId("lobo");
    AddAdjective("gris");
    AddAdjective("gran");
    AddAdjective("grande");
    SetGoChance(90);
    AddWalkZones("/d/simauria/comun/habitacion/caminos/nandor-sherek");
    SetStr(24);
    SetDex(25);
    SetCon(20);
    SetInt(7);
    SetHP(QueryMaxHP());
    SetMaxHP(140);
    SetAlign(-100);
    SetWeight(40000);
    SetNoGet("El lobo gruñe y te muestra los colmillos... Mejor le dejas tranquilo.\n");
    SetHands(({({"la pata delantera derecha",2,3}),
		  ({"la otra pata delantera",2,3}),
		  ({"los colmillos",1,6})}));
    InitChats(5,({"El lobo encuentra un hueso y se pone a roerlo.\n",
            "El lobo sacude las orejas.\n",
            "El lobo te mira y se relame...\n",
            "El lobo aúlla: ¡aaaaaahúuuuuuuuuuuuhhhhhgrrrrrrrrr!\n"}));
}
