#include "path.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Alguien ha construido una especie de rampa en espiral que rodea "
  	"y abraza a un gran árbol de la zona. La rampa parece llevar hasta una "
  	"cabaña que parece sujetarse grácilmente en la copa del árbol. Al menos "
  	"esperas que así sea.\n"));
  AddDetail("rampa", W("Es una rampa que sigue la consabida forma en espiral. "
  	"Todas las ciudades deberían tener una.\n"));
  AddExit("norte", ATB_CI("ciudad07"));
  AddExit("nordeste", ATB_CI("ciudad15"));
  AddExit("sudeste", ATB_CI("ciudad09"));
  AddExit("sur", ATB_CI("ciudad03"));
  AddExit("oeste", ATB_CI("ciudad02"));
}

