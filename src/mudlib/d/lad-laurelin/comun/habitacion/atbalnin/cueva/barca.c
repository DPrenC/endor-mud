#include "path.h"
#include <moving.h>
#include <colours.h>

inherit ROOM;
private static int t;

void movimiento()
{
  switch (t) {
    case 0: write("El bote comienza a moverse. Se esta alejando de la "
			"orilla.\n");
	    break;
    case 1: write("Poco a poco el bote se va moviendo hacia el este.\n");
	    break;
    case 2: write("Aunque parezca mentira, ves como la barca "
		"esta siendo lentamente rodeada por la niebla.\n");
	    break;
    case 3: write("La barca sigue moviendose hacia el este y esta "
		"siendo totalmente rodeada por la niebla.\n");
	    break;
    case 4: write("La niebla te impide ver la propia barca.\n");
  	    AddDetail(({"remo", "remos"}), "Si los hubiera la niebla te "
		"impediria verlos.\n");
  	    AddDetail("timon", "La niebla te impide ver el timon. De hecho, "
		"no hay tal timon.\n");
	    break;
    case 5: write("Poco a poco la niebla comienza a difuminarse. "
		"La sensacion que antes tenias de que ibas hacia el este se "
		"ha esfumado para dar paso a una desorientacion total...\n");
	    break;
    case 6: write("Recobras el sentido de la orientacion. Hacia el "
		"norte ves un islote.\n");
	    break;
    case 7: write("Llegas a la orilla. Con cuidado de no caerte "
		"(la barca todavia se cimbrea) pones los pies en tierra.\n");
	    say(capitalize(TP->QueryRealName())+" se baja de la barca.\n");
	    return TP->move(ATB_I("isleta00"), M_SILENT);
  }
  t++;
  call_out("movimiento", 15);
}


create(){
  ::create();

  SetIntLong("Estás en una pequeña barca de madera.\n");
  SetIntShort("una barca de madera");
  AddDetail(({"remo", "remos"}), "No hay remos; la barca sigue la corriente.\n");
  AddDetail("timon", "Te preguntas cómo puede moverse una barca sin "
	"timón.\n");
  AddDetail("timón", "Te preguntas cómo puede moverse una barca sin "
	"timón.\n");
}


init()
{
  ::init();
  t=0;
  call_out("movimiento", 5);
}


