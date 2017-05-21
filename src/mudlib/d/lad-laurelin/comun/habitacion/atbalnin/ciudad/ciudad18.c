#include "path.h"

inherit ATB_CI("std_ciudad");

create()
{
  ::create();

  SetIntLong(W("Hacia el este la calle principal sigue hasta la parte central "
  	"de la ciudad. Hacia el oeste, está, uh, la parte oeste de la ciudad. "
  	"Estás justamente en ese punto que define un lugar concreto de cada "
  	"localidad, donde empieza una zona y acaba otra.\n"));

  AddDetail("oeste", W("Ves árboles grandes, una cabaña, y algo parecido a una "
  	"fragua, aunque desde aquí sería imposible concretarlo.\n"));
  AddDetail("este", W("La calle principal sigue hasta el centro de la ciudad, "
  	"probablemente donde habrá ubicado algún edificio importante o algo "
  	"similar.\n"));
  AddExit("sur", ATB_CI("ciudad15"));
  AddExit("oeste", ATB_CI("ciudad14"));
  AddExit("este", ATB_CI("ciudad19"));
  AddExit("norte", ATB_CI("ciudad20"));
}

