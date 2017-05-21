/* ENDOR-MUD OROME */
#include <combat.h>
#include <properties.h>
#include <gremios.h>
inherit NPC;

create() {
  string color;
  ::create();

    color=random(2)?"marrón":"blanco";

  SetStandard("un conejo", "conejo",([GC_CM_MM:1]), GENDER_MALE);
  SetShort("un conejo"+(random(2)?" "+color:""));
  SetLong("Es un conejo. Es un animalillo bastante "
  	"nervioso, prácticamente no puede hacer otra cosa que moverse "
  	"continuamente. En concreto este conejo es "+color+", un color "
  	"bastante abundante entre los de su especie.\n");


  AddId("conejo");
  SetAds(({color}));
  SetWhimpy(QueryMaxHP()/10);
  InitChats(5,  ({"Un conejo "+color+" se pone a rascar el suelo.\n",
  		  "Un conejo "+color+" te mira cautamente.\n",
  		  "Un conejo "+color+" se atusa los bigotes.\n",
  		  "Un conejo "+color+" se limpia el pelaje.\n",
  		  "Un conejo "+color+" se frota las orejas.\n",
  		  "Un conejo "+color+" se pone a roer algo.\n"
  		    		}));
  SetGoChance(25);

}
