/* Archivo /d/simauria/comun/pnj/abadia/ciervo.c
* descripción: Ciervo que deambula por el camino a la abadía de sherek.
* autor: Lug y Yalin.
*/
#include "path.h"
#include <properties.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("un ciervo","ciervo",15,GENERO_MASCULINO);
    SetName("un ciervo");
    AddId("ciervo");
    SetShort("un ciervo marrón");
    SetLong("Un ciervo de soberbia cornamenta, que se entretiene rumiando las "
    "escasas hierbas del camino.\n");
    SetSize(3);
    SetGoChance(90);
    AddWalkZones("/d/simauria/comun/habitacion/caminos/nandor-sherek");
    SetStr(14);
    SetDex(18);
    SetInt(5);
    SetCon(15);
    SetHP(QueryMaxHP());     SetMaxHP(117);
    SetAlign(50);
    SetWeight(150000);
    SetHands(({({"la pata delantera derecha",2,2}),
		  ({"la otra pata delantera",2,2}),
		  ({"la cornamenta",3,4})}));
     InitChats(5,({"El ciervo rumia calmosamente unas raíces.\n",
                "El ciervo remueve unas piedras con la cornamenta.\n",
                "El ciervo se rasca contra un árbol.\n"}));
}
