/***
Fichero: /guilds/guardabosques/pnj/jabali.c
30/08/2004. Kastwey@simauria. Quitados los chats que hagan referencia a un
decorado espec�fico.
Los animales pueden convocarse en cualquier lado, por lo que pueden producirse incongruencias.
***/
#include <living.h>
#include <properties.h>
#include "path.h"

inherit "/std/npc";

create() {
  string color;

  ::create();
  color=random(2)?"marr�n":random(2)?"moteado":"negro";

  SetStandard("un jabal�", "jabal�", 5, GENDER_MALE);
  SetShort("un jabal�"+(random(2)?" "+color:""));
  SetLong(W("Es un jabal� "+color+". Suelen ser "
  	"animales bastante peligrosos, y desde luego �ste no dudar� en "
  	"atacarte si lo cree conveniente.\n"));
  SetWeight(45000);
  SetHands(({({"colmillos",0,5})}));

  SetSize(P_SIZE_MEDIUM);
  SetIds(({"jabali", "jabal�", "cerdo"}));
  SetAds(({color}));
  InitChats(10, ({"Un jabal� "+color+" husmea el suelo.\n",
  		"Un jabal� "+color+" se pone a masticar algo.\n",
  		"Un jabal� "+color+" va de un sitio a otro.\n",
  		"Un jabal� "+color+" empieza a correr... y se para en seco.\n"
  		}));
  InitAChats(15, ({"El jabal� "+color+" ruge de rabia.\n",
  		"Al jabal� se le eriza el pelo.\n"}));
}


