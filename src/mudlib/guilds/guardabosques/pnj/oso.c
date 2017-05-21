/***
Fichero: /guilds/guardabosques/pnj/oso.c
30/08/2004. Kastwey@simauria. Quitados los chats que hagan referencia a un
decorado específico.
Los animales pueden convocarse en cualquier lado, por lo que pueden producirse incongruencias.
***/
#include <living.h>
#include <properties.h>
#include "path.h"

inherit "/std/npc";

create()
{
  string color;
  int level;

  ::create();
  color=random(2)?"pardo":"negro";
  level = 20+random(10);

  SetStandard("un oso", "oso", level, GENDER_MALE);
  SetShort("un oso"+(random(2)?" "+color:""));
  SetLong("Es un oso "+color+"; no parece hostil pero sería buena idea no "
  	"molestarlo.\n");
  SetWeight(360000);
  SetHands(({({"zarpa derecha",0,level/2}),
  	({"zarpa izquierda",0,level/2}),
  	({"mandibulas",0,level})}));
  AddId("oso");
  SetAds(({color}));
  InitChats(1, ({"Un oso "+color+" te gruñe.\n",
  		"Un oso "+color+" te mira.\n",
  		"Un oso "+color+" husmea el ambiente.\n",
  		"Un oso "+color+" se limpia el pelaje.\n"}));

  InitAChats(10, ({"Un oso "+color+" te gruñe.\n",
  		"Un oso "+color+" suelta un alarido impresionante.\n",
  		"Un oso "+color+" se eleva sobre sus patas traseras.\n"}));
}

