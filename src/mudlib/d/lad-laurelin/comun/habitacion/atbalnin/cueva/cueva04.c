#include "path.h"
inherit ATB_C("std_cueva");


create(){
  object ob;
  ::create();
  SetIntLong(W("La humedad en esta parte de la zona parece que no "
	"afecta a la roca... O quizas es que la roca no se deja afectar por "
	"el agua? Parece una roca normal, pero esta casi demasiado fria "
	"y desde luego desde el tiempo que lleva aqui deberia estar bastante "
	"mas desgastada.\n"));
  SetIntShort("la cueva de Atbalnin");
  AddDetail("suelo", "Es frio, liso y humedo.\n");
  AddDetail(({"paredes", "pared"}), W("Las paredes son de roca viva. "
	"De vez en cuando ves las marcas de alguna herramienta, seguramente "
	"de un pico manejado con maestria.\n"));
  AddExit("nordeste", ATB_C("cueva06"));
  AddExit("este", ATB_C("cueva05"));
  AddExit("sudeste", ATB_C("cueva07"));
  AddExit("oeste", ATB_C("cueva03"));
}