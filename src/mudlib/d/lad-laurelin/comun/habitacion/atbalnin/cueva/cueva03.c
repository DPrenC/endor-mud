#include "path.h"
inherit ATB_C("std_cueva");


create(){
  object ob;
  ::create();
  SetIntLong(W("En las paredes ves unas marcas demasiado violentas "
	"para ser de la misma herramienta que les dieron forma. Parece que "
	"por aqui se ha librado alguna especie de batalla.\n"));
  AddDetail("suelo", "Es frio, liso y humedo.\n");
  AddDetail(({"marca", "marcas"}), W("Son unas marcas producidas por "
	"un arma roma y contundente, quizas de un mazo.\n"));
  AddDetail(({"paredes", "pared"}), W("Las paredes son de roca viva. "
	"De vez en cuando ves las marcas de alguna herramienta, seguramente "
	"de un pico manejado con maestria.\n"));
  SetIntShort("la cueva de Atbalnin");
  AddExit("este", ATB_C("cueva04"));
  AddExit("noroeste", ATB_C("cueva02"));
}