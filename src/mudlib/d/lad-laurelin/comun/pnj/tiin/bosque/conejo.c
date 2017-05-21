#include <living.h>
#include <properties.h>
#include "path.h"

inherit NPC;

create() {
  string color;
  ::create();

  AddWalkZones("/d/lad-laurelin/comun/habitacion/tiinkdhil/bosque");
  color=random(2)?"marrón":"blanco";

  SetStandard("un conejo", "conejo", 1, GENDER_MALE);
  SetShort("un conejo"+(random(2)?" "+color:""));
  SetLong("Es un conejo. Es un animalillo bastante "
  	"nervioso, prácticamente no puede hacer otra cosa que moverse "
  	"continuamente. En concreto este conejo es "+color+", un color "
  	"bastante abundante entre los de su especie.\n");

  SetWeight(4000);
  SetHands(({({"zarpa derecha",0,1}),
  	   ({"zarpa izquierda",0,1})}));
  SetSize(P_SIZE_SMALL);

  AddId("conejo");
  SetAds(({color}));
  SetWhimpy(QueryMaxHP());
  InitChats(20,  ({"Un conejo "+color+" se pone a rascar el suelo.\n",
  		  "Un conejo "+color+" te mira cautamente.\n",
  		  "Un conejo "+color+" se atusa los bigotes.\n",
  		  "Un conejo "+color+" se limpia el pelaje.\n",
  		  "Un conejo "+color+" se frota las orejas.\n",
  		  "Un conejo "+color+" se pone a roer algo.\n",
  		  "Un conejo "+color+" se rasca las orejas.\n"
  		}));
  SetGoChance(25);

}
