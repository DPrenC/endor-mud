#include "path.h"
inherit ATB_C("std_cueva");


create(){
  object ob;
  ::create();
  SetIntLong(W("La pared de la cueva te imposibilita seguir hacia el "
	"sur. Hacia el norte la pared se 'abre', formando una especie de "
	"embudo.\n"));
  SetIntShort("la orilla del lago");
  AddDetail(({"suelo", "arena"}), W("La erosion del agua ha hecho que "
	"la roca se convierta en arena.\n"));
  AddDetail(({"paredes", "pared"}), W("No puedes ver las paredes desde "
	"aqui.\n"));
  AddDetail(({"lago","agua"}), "Es un inmenso y oscuro lago.\n");
  AddDetail("orilla", "Solo ves esta orilla, la otra esta demasiado lejana.\n");
  SetNoise("Escuchas el rumor del oleaje.\n");
  SetSmell("Curiosamente el olor a humedo deja paso al olor de vegetacion.\n");
  AddExit("sur", ATB_C("cueva11"));
  AddExit("suroeste", ATB_C("cueva07"));
  AddExit("oeste", ATB_C("cueva05"));
  AddExit("noroeste", ATB_C("cueva06"));
  AddExit("norte", ATB_C("cueva10"));
  AddExit("este", ATB_C("agua03"));
  AddExit("nordeste", ATB_C("agua02"));
}
