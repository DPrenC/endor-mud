/***
Fichero: /guilds/guardabosques/pnj/jabali.c
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
  color=random(2)?"marrón":random(2)?"moteado":"negro";

  SetStandard("un jabalí", "jabalí", 5, GENDER_MALE);
  SetShort("un jabalí"+(random(2)?" "+color:""));
  SetLong(W("Es un jabalí "+color+". Suelen ser "
  	"animales bastante peligrosos, y desde luego éste no dudará en "
  	"atacarte si lo cree conveniente.\n"));
  SetWeight(45000);
  SetHands(({({"colmillos",0,5})}));

  SetSize(P_SIZE_MEDIUM);
  SetIds(({"jabali", "jabalí", "cerdo"}));
  SetAds(({color}));
  InitChats(10, ({"Un jabalí "+color+" husmea el suelo.\n",
  		"Un jabalí "+color+" se pone a masticar algo.\n",
  		"Un jabalí "+color+" va de un sitio a otro.\n",
  		"Un jabalí "+color+" empieza a correr... y se para en seco.\n"
  		}));
  InitAChats(15, ({"El jabalí "+color+" ruge de rabia.\n",
  		"Al jabalí se le eriza el pelo.\n"}));
}


