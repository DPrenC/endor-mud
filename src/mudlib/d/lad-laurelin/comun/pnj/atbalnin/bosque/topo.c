#include <living.h>
#include <properties.h>
#include "path.h"

inherit NPC;

create() {
  string color;

  ::create();

  AddWalkZones("/d/lad-laurelin/comun/habitacion/atbalnin/bosque");
  SetStandard("un topo", "topo", 3, GENDER_MALE);
  SetShort("un topo");
  SetLong("Es un topo corriente. Aunque es un "
    	  "animal poco peligroso, tiene unas potentes garras delanteras"
    	  "que usa para excavar sus túneles en el suelo.\n");
  SetWeight(6000);
  SetHands(({({"zarpa derecha",0,5}),
       	  ({"zarpa izquierda",0,5})}));
  SetSize(P_SIZE_SMALL);
  AddId("topo");
  SetAds(({"común", "comun"}));
  SetWhimpy(QueryMaxHP()/2);
  InitChats(1, ({"Un topo empieza a escavar en el suelo.\n",
  		"Un topo intenta mirarte.\n",
  		"Un topo husmea el aire.\n",
  		"Un topo se esconde en un agujero.\n"}));
  SetGoChance(25);
}
