/***
Fichero: /guilds/guardabosques/pnj/ciervo.c
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

  color=random(2)?"marrón":"moteado";

  SetStandard("un ciervo", "ciervo", 10+random(5), GENDER_MALE);
  SetShort("un ciervo");
  SetLong("Es un ciervo bastante grande y bien desarrollado, con una imponente cornamenta.\n");

  SetWeight(15000);
  SetHands(({({"cornamenta",0,15})}));
  SetSize(P_SIZE_MEDIUM);
  AddId("ciervo");
  SetAds(({color}));
  InitChats(1, ({"Un ciervo se pone a comer hierba.\n",
  		 "Un ciervo te mira con indiferencia.\n",
  		 "Un ciervo trota un poco dando vueltas.\n",
  		 "Un ciervo husmea el ambiente.\n"}));
}
