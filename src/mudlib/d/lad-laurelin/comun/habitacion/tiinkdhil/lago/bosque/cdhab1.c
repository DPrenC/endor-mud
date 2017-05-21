
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create() {
  ::create();
  SetIndoors(0);
  SetIntShort("una gruta");
  SetIntNoise("No escuchas nada, ni siquiera el canto de los pájaros.\n");
  SetIntLong("Estas en una pequeña gruta que se abre paso entre las montanyas rocosas a un "
		"inhabitado camino lleno de zarzas y piedras dificil de transitar. Al parecer "
		"no fue creada por la naturaleza, sino por mano humana.\n");
  AddDetail(({"suelo"}),"Esta lleno de pedruscos y piedrecitas.\n");

  AddExit("norte",ALULAGO("bosque/cdhab2"));
  //AddExit("noroeste","");  retorno al camino al valle
  //AddExit("este","cdhab5");

}




