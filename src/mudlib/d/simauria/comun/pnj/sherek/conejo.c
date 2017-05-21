/* Archivo /d/simauria/comun/pnj/abadia/conejo.c
* descripción: conejo para el camino Nandor-Sherek.
* autor Lug y Yalin
*/
#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("un conejo","conejo",([ GC_TORPE: 5]),GENERO_MASCULINO);
    SetShort("un conejo blanco");
    SetLong("Es una bola de pelo blanco, con un hociquito sonrosado y unas enormes "
          "orejas en forma de cuchara.\n Te mira con sus ojos curiosos.\n");
    AddId("conejo");
    AddAdjective(({"blanco"}));
    SetSize(1);
    SetMaxHP(57);
    SetHP(QueryMaxHP());
    SetStr(4);
    SetDex(7);
    SetInt(1);
    SetHands( ({ ({"mordisco",TD_PENETRACION,2}) }) );
    SetWeight(2000);
    SetGoChance(90);
    AddWalkZones("/d/simauria/comun/habitacion/caminos/nandor-sherek");
    SetAlign(100);
    SetNoGet("No eres lo bastante rápido, y el conejo se aparta de un brinco.\n");
    InitChats(5,({"El conejo rebusca entre las hierbas.\n",
                 "El conejo mueve despacio las orejas, escuchando con atención.\n",
                 "El conejo roe una corteza de árbol.\n",
                 "El conejo mira desconfiado a todas partes.\n"}));
}

