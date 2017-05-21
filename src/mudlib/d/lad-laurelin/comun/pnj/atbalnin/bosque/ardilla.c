#include <living.h>
#include <properties.h>
#include "path.h"

inherit NPC;

create() {
  string color;
  ::create();

  AddWalkZones("/d/lad-laurelin/comun/habitacion/atbalnin/bosque");
  color=random(2)?"marr�n":"rayada";

  SetStandard("una ardilla", "ardilla", 1, GENDER_FEMALE);

  SetShort("una ardilla"+(random(2)?" "+color:""));
  SetLong("Es una ardilla com�n. Te mira con una "
  	"expresi�n entre cauta y nerviosa. Desde luego no es ninguna amenaza "
  	"como enemigo, y lo m�s seguro es que si te acercas m�s huir� "
  	"r�pidamente. Su pelaje "+color+" le hace confundirse "
    	"ligeramente con el entorno en el que vive.\n");

  SetWeight(1000);
  SetHands(({({"zarpa derecha",0,1}),
  	   ({"zarpa izquierda",0,1})}));
  SetSize(P_SIZE_SMALL);

  AddId("ardilla");
  SetAds(({color}));
  SetWhimpy(QueryMaxHP());
  InitChats(15,  ({"Una ardilla "+color+" empieza a roer un fruto seco.\n",
  		  "Una ardilla "+color+" te mira.\n",
  		  "Una ardilla "+color+" se atusa los bigotes.\n",
  		  "Una ardilla "+color+" empieza a corretear por el suelo.\n",
  		  "Una ardilla "+color+" se sube por el tronco de un �rbol.\n"
  		}));
  SetGoChance(25);
}
