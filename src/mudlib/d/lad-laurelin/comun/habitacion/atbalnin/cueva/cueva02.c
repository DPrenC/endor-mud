#include "path.h"
inherit ATB_C("std_cueva");


create(){
  object ob;
  ::create();
  SetIntLong(W("El suelo de esta zona de la cueva es de una piedra "
	"fria, demasiado fria. No es que moleste, pero parece un tanto "
	"antinatural.\n"));
  AddDetail("suelo", "Es demasiado frio, demasiado liso y demasiado humedo.\n");
  AddDetail(({"paredes", "pared"}), W("Las paredes son de roca viva. "
	"De vez en cuando ves las marcas de alguna herramienta, seguramente "
	"de un pico manejado con maestria.\n"));
  SetIntShort("la cueva de Atbalnin");
  AddExit("sudeste", ATB_C("cueva03"));
  AddExit("noroeste", ATB_C("cueva01"));
}