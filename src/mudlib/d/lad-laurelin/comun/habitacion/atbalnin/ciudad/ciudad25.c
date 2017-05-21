#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Justo al sur ves la plaza centra de Atbalnin, lo que parece "
  	"indicar que estás bastante cerca del centro de la ciudad. Hacia el "
  	"este se alza el edificio que sirve de biblioteca. Es bastante grande, "
  	"al menos para lo que llevas visto de la ciudad.\n"));
  AddDetail("biblioteca", "Se alza hacia el este, majestuosa. Al menos lo intenta.\n");
  SetPreIntShort("a");
  SetIntShort("elnorte de la plaza");
  	
  AddExit("oeste", ATB_CI("ciudad21"));
  AddExit("este", ATB_CI("ciudad28"));
  AddExit("norte", ATB_CI("ciudad24"));
  AddExit("sur", ATB_CI("ciudad34"));
}
