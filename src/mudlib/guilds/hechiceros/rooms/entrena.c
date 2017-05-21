#include "path.h"
inherit ROOM;

create(){
  ::create();
  SetLocate("gremio de hechiceros");
  SetIndoors(1);
  SetIntBright(50);	
  SetIntLong(W("estas en una habitacion en la que puedes practicar tus habilidades"
" puedes sentir como un hechizo protege a la habitacion de posibles desastres provocados"
" por las invocaciones que se pueden practicar aqui.\n"));

  AddExit("sur", "./pasillo");
}
