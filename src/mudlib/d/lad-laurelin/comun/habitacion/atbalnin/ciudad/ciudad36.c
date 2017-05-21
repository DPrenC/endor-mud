#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Estás en la parte sur de la biblioteca, un gran y sólido "
  	"edificio. Hacia el oeste ves la plaza central y hacia el este, "
  	"pues poco más, la calle sigue.\n"));
  SetPreIntShort("a");
  SetIntShort("el sur de la biblioteca");
  AddDetail(({"biblioteca", "edificio"}), "Es la biblioteca de Atbalnin, "
  	"centro de sabiduría. O algo.\n");
  AddDetail("plaza", "Es una plaza.\n");
  	
  AddExit("oeste", ATB_CI("ciudad35"));
  AddExit("este", ATB_CI("ciudad37"));
  AddExit("sur", ATB_CI("ciudad38"));
}
