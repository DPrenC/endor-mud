/* Archivo          cerdo.c
* descripción:      cerdo que habita en la pocilga de la granja de la aldea de Sloch.
* autor:            Lug y Yalin.
* Fecha:            19/05/2006
*/
#include "path.h"
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("un cerdo","cerdo",15,GENERO_MASCULINO);
    SetName("un cerdo");
    AddId("cerdo");
    SetShort("un cerdo negro");
    SetLong("Un cerdo negro y bastante peludo. Tiene unas grandes orejotas y unos amenazantes "
            "colmillos. Se parece bastante a un jabalí, pero es claramente un animal doméstico "
            "por lo gordo y reluciente que está.\n");
    SetStr(14);
    SetDex(18);
    SetInt(5);
    SetCon(15);
    SetHP(QueryMaxHP());
    SetMaxHP(117);
    SetWeight(150000);
    SetHands(({({"la pata delantera derecha",2,2}),
		   ({"la otra pata delantera",2,2}),
		   ({"los colmillos",3,4})}));
     InitChats(5,({"El cerdo sacude las orejas.\n",
                "El cerdo se rasca la espalda contra los maderos de la pared.\n",
                "El cerdo gruñe mientras se reboza contra el suelo.\n"}));
}
