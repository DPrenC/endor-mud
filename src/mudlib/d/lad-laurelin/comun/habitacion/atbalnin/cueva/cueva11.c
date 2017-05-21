#include "path.h"
inherit ATB_C("std_cueva");


create(){
  object ob;
  ::create();
  SetIntLong(W("El agua, mecida de oeste a este, llega hasta tus "
	"pies suave y lentamente. La arena, en esta parte de la orilla, es "
	"muy fina, casi como la de una playa normal.\n"));
  SetIntShort("la orilla del lago");
  AddDetail(({"suelo", "arena"}), W("La erosion del agua ha hecho que "
	"la roca se convierta en arena.\n"));
  AddDetail(({"paredes", "pared"}), W("No puedes ver las paredes desde "
	"aqui.\n"));
  AddDetail(({"lago","agua"}), "Es un inmenso y oscuro lago.\n");
  AddDetail("orilla", "Solo ves esta orilla, la otra esta demasiado lejana.\n");
  SetNoise("Escuchas el rumor del oleaje.\n");
  SetSmell("Curiosamente el olor a humedo deja paso al olor de vegetacion.\n");
  AddExit("sur", ATB_C("cueva12"));
  AddExit("oeste", ATB_C("cueva07"));
  AddExit("noroeste", ATB_C("cueva05"));
  AddExit("norte", ATB_C("cueva08"));
  AddExit("este", ATB_C("agua02"));
  AddExit("nordeste", ATB_C("agua01"));
  AddExit("sudeste", ATB_C("agua03"));
}
