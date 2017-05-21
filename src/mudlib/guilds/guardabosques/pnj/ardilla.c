/***
Fichero: /guilds/guardabosques/pnj/ardilla.c
30/08/2004. Kastwey@simauria. Quitados los chats que hagan referencia a un
decorado específico.
Los animales pueden convocarse en cualquier lado, por lo que pueden producirse incongruencias.
***/
#include <living.h>
#include <properties.h>
#include "path.h"

inherit "/std/npc";

create() {
  string color;
  ::create();

  color=random(2)?"marrón":"rayada";

  SetStandard("una ardilla", "ardilla", 1, GENDER_FEMALE);

  SetShort("una ardilla"+(random(2)?" "+color:""));
  SetLong(W("Es una ardilla común. Te mira con una "
  	"expresión entre cauta y nerviosa. Desde luego no es ninguna amenaza "
  	"como enemigo, y lo más seguro es que si te acercas más huirá "
  	"rápidamente. Su pelaje "+color+" le hace confundirse "
    	"ligeramente con el entorno en el que vive.\n"));

  SetWeight(1000);
  SetHands(({({"zarpa derecha",0,1}),
  	   ({"zarpa izquierda",0,1})}));
  SetSize(P_SIZE_SMALL);

  AddId("ardilla");
  SetAds(({color}));
  InitChats(15,  ({"Una ardilla "+color+" empieza a roer un fruto seco.\n",
  		  "Una ardilla "+color+" te mira.\n",
  		  "Una ardilla "+color+" se atusa los bigotes.\n",
  		  "Una ardilla "+color+" empieza a corretear por el suelo.\n"}));
}
