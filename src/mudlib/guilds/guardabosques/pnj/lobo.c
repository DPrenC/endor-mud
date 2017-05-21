/***
Fichero: /guilds/guardabosques/pnj/lobo.c
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
  level = 10 + random(10);
  color=random(2)?"marrón":"gris";

  SetStandard("un lobo", "lobo", level, GENDER_MALE);
  SetShort("un lobo"+(random(2)?" "+color:""));
  SetLong(W("Es un lobo "+color+"."+
  	"Te mira con mucha hambre y parece "
  	"dispuesto a atacarte a la menor ocasión.\n"));
  SetWeight(45000);
  SetHands(({({"zarpa derecha",0,level/2}),
  	   ({"zarpa izquierda",0,level/2}),
  	   ({"colmillos",0,level})}));
  AddId("lobo");
  SetAds(({color}));
  InitChats(2, ({"Un lobo "+color+" gruñe entre dientes.\n",
  		"Un lobo "+color+" te mira amenazador.\n",
  		"Un lobo "+color+" husmea el aire.\n",
  		"Un lobo "+color+" empieza a limpiarse.\n",
  		"Un lobo "+color+" se rasca las pulgas.\n"}));
  InitAChats(10, ({"Un lobo "+color+" ladra.\n",
  		"Un lobo "+color+" aulla de rabia.\n"}));
}
