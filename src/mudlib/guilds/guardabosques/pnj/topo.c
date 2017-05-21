/***
Fichero: /guilds/guardabosques/pnj/topo.c
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
  int level;

  ::create();
  level = 5+random(5);

  SetStandard("un topo", "topo", level, GENDER_MALE);
  SetShort("un topo");
  SetLong(W("Es un topo corriente. Aunque es un "
    	  "animal poco peligroso, tiene unas potentes garras delanteras"
    	  "que usa para excavar sus túneles en el suelo.\n"));
  SetWeight(6000);
  SetHands(({({"zarpa derecha",0,level}),
       	  ({"zarpa izquierda",0,level})}));
  SetSize(P_SIZE_SMALL);
  AddId("topo");
  SetAds(({"común", "comun"}));
  InitChats(1, ({"Un topo empieza a escavar en el suelo.\n",
  		"Un topo intenta mirarte.\n",
  		"Un topo husmea el aire.\n"}));
}
