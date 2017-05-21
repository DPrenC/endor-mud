#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Esta es una zona relativamente bulliciosa de la ciudad. Al "
  	"menos los indicios que encuentras por el suelo así lo demuestran. "
  	"Claro que también demuestran la carencia de un sistema medianamente "
  	"organizado de escuadrones de limpieza.\n"));

  SetIntShort("la zona central de Atbalnin");
  AddExit("oeste", ATB_CI("ciudad18"));
  AddExit("este", ATB_CI("ciudad21"));
  AddExit("norte", ATB_CI("ciudad22"));
}
