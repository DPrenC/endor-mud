#include "path.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("La plaza central se extiende hacia el norte, y algo m�s all�, "
  	"hacia el nordeste, ves un alto edificio. Desde aqu� no podr�as decir "
  	"de qu� se trata.\n"));
  AddExit("este", ATB_CI("ciudad11"));
  AddExit("sur", ATB_CI("ciudad04"));
  AddExit("nordeste", ATB_CI("ciudad34"));
}

