#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Hacia el sur ves el edificio que sirve de biblioteca "
  	"central, y hacia el oeste ves una salida que parece llevar hacia "
  	"el bosque.\n"));
  SetIntShort("la zona central de Atbalnin");
  AddDetail("biblioteca", W("Es un edificio grande, algo desvencijado pero "
  	"que mantiene orgulloso sus características principales.\n"));
  AddDetail("salida", "Algo hacia el oeste y el norte, parece dar al bosqu.\n");
  AddExit("sur", ATB_CI("ciudad29"));
  AddExit("oeste", ATB_CI("ciudad27"));
  AddExit("este", ATB_CI("ciudad31"));
  AddExit("nordeste", ATB_CI("ciudad40"));
}
