#include "path.h"
inherit ATB_C("std_cueva");


create(){
  object ob;
  ::create();
  SetIntLong("Estas al sur de lo que casi seguro es un cala. "
	"A tus pies, ves como la orilla del lago es lamida por el lento oleaje "
	"del lago, lo que poco a poco ha convertido la piedra en arena.\n");
	  SetIntShort("la orilla del lago");
  AddDetail(({"suelo", "arena"}), "Alguna que otra roca sobresale "
	"timidamente por sobre la arena.\n");
  AddDetail(({"lago","agua"}), "Es un inmenso y oscuro lago.\n");
  AddDetail("orilla", "Solo ves esta orilla, la otra esta demasiado lejana.\n");
  SetNoise("Escuchas el rumor del oleaje.\n");
  SetSmell("Curiosamente el olor a humedo deja paso al olor de vegetacion.\n");
  AddExit("sur", ATB_C("cueva08"));
  AddExit("suroeste", ATB_C("cueva05"));
  AddExit("oeste", ATB_C("cueva06"));
  AddExit("norte", ATB_C("cueva10"));
  AddExit("este", ATB_C("agua00"));
  AddExit("sudeste", ATB_C("agua01"));
}
