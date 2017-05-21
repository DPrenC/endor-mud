#include "path.h"
inherit ATB_C("std_cueva");


create(){
  object ob;
  ::create();
  SetIntLong(W("El lago se abre en toda su enormidad ante ti. Un "
	"poco mas al norte y el este hay lo que podria ser una pequenya cala "
	"natural, pero desde aqui es dificil precisar.\n"));
  SetIntShort("el lago de la cueva de Atbalnin");
  AddDetail("suelo", "Es frio, liso y humedo.\n");
  AddDetail(({"paredes", "pared"}), W("Las paredes se abren para "
	"dejar paso a un enorme lago.\n"));
  AddDetail("lago", "Es un inmenso y oscuro lago.\n");
  AddDetail("cala", "Ves lo que podria ser una cala natural.\n");
  AddExit("nordeste", ATB_C("cueva10"));
  AddExit("este", ATB_C("cueva09"));
  AddExit("sudeste", ATB_C("cueva08"));
  AddExit("sur", ATB_C("cueva05"));
  AddExit("suroeste", ATB_C("cueva04"));
}
