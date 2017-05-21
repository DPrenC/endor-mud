
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create() {
  ::create();
  SetIndoors(0);
  SetIntNoise("No escuchas nada, ni siquiera el canto de los pájaros.\n");
  SetIntShort("una gruta");
  SetIntLong("Estas en una pequeña gruta que se abre paso entre las montanyas "
  		"rocosas a un inhabitado camino lleno de zarzas y piedras difícil "
  		"de transitar. Al parecer no fue creada por la naturaleza, sino "
  		"por mano humana pues parece un acceso rápido al valle que ves.\n");
  AddDetail(({"suelo"}),"Esta lleno de pedruscos y piedrecitas.\n");

  AddExit("gruta",ALUKHAN("gruta1")); // retorno al camino al valle
  AddExit("norte",ALULAGO("bosque/cam2"));
}