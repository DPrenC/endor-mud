/* Archivo: /d/simauria/comun/pnj/abadia
* Descripción: Ardilla para el camino de Nandor a la abadía de Sherek
* Autor: Lug y Yalin.
*/

#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("una ardilla","ardilla",([ GC_TORPE: 10]),GENERO_FEMENINO);
    SetShort("una ardilla");
    SetLong("Una ardilla es un roedor algo mayor que un conejo, con los "
    "incisivos más desarrollados y fuertes, para romper los frutos secos más "
    "duros. Tiene una cola enorme y peluda, más grande que el propio cuerpo.\n"
    "Parece muy inquieta.\n");
    AddId("ardilla");
    SetSize(1);
    SetMaxHP(87);;
    SetHP(QueryMaxHP());
    SetInt(1);
    SetStr(9);
    SetDex(10);
    SetHands(({({"mordisco",1,1})}));
    SetWeight(4000);
    SetGoChance(90);
    AddWalkZones("/d/simauria/comun/habitacion/caminos/nandor-sherek");
    SetAlign(100);
    SetNoGet("La ardilla pega un brinco y se aleja de ti.\n");
    InitChats(5,({"La ardilla mira nerviosa a todos lados.\n",
                "La ardilla encuentra una nuez, la casca y se la come.\n",
                "La ardilla va de aquí para allá.\n",
                "La ardilla rebusca entre las hierbas.\n"}));
}
