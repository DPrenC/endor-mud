#include "path.h"
#include <door.h>
#include <properties.h>
inherit ATB_I("std_islote");

create(){
  object ob;
  ::create();
  SetIntLong("Estas en la  "
  	"una puerta de tamanyo medio por la que podrias salir. "
  	"La cueva se abre hacia el este, donde se hace cada vez mas dificil "
	"ver lo que hay por ahi...\n");
  SetIntShort("la cueva de Atbalnin");
  AddExit("este", ATB_C("cueva01"));
  /*
   AddDoor("id00","arriba",ATB_B("bosque37"), "puerta de madera",
	"Es una puerta de madera.\n");
  */
  SetIntBright(35);
}