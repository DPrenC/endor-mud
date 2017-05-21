#include "path.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Si algo caracteriza esta ciudad es por su cantidad de puertas "
  	"que dan a ninguna parte por estar selladas. Estas frente a la Segunda "
  	"Entrada Sur, que curiosamente, sí está abierta. Parece dar al bosque, "
  	"claro que a pocos más sitios puede dar estando la ciudad ubicada justo "
  	"en el centro de un bosque. Hacia el norte se extiende la plaza central.\n"));

  AddDetail("cartel", W("Es un gran cartel que tienes ante tí. Y por si "
  	"esto no fuera suficiente, además lo puedes leer.\n"));
  	
  AddDetail("plaza", "Es una plaza, tiene pájaros, etc.\n");
  AddReadMsg("cartel", "En el cartel pone: \"Segunda Entrada Sur\". ¿Qué esperabas?");
  AddExit("oeste", ATB_CI("ciudad10"));
  AddExit("sur", ATB_CI("ciudad05"));
  AddExit("norte", ATB_CI("ciudad34"));
}

