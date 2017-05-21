#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("La biblioteca se alza imponente ante tí, o al menos eso "
  	"parece desde tu punto de vista. Sea como fuere estás frente a la "
  	"pared norte. Desde aquí puedes escuchar los sonidos típicos de una "
  	"biblioteca, es decir, el más profundo silencio.\n"));
  SetIntShort("la zona central de la ciudad de Atbalnin");
  	
  AddExit("norte", ATB_CI("ciudad30"));
  AddExit("oeste", ATB_CI("ciudad26"));
AddExit("este",ATB_CI("ciudad32"));
}
