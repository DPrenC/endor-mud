#include "path.h"

inherit ATB_CI("std_ciudad");

create()
{
  ::create();

  SetIntLong(W("Hacia el este la calle principal sigue hasta la parte central "
  	"de la ciudad. Hacia el oeste, est�, uh, la parte oeste de la ciudad. "
  	"Est�s justamente en ese punto que define un lugar concreto de cada "
  	"localidad, donde empieza una zona y acaba otra.\n"));

  AddDetail("oeste", W("Ves �rboles grandes, una caba�a, y algo parecido a una "
  	"fragua, aunque desde aqu� ser�a imposible concretarlo.\n"));
  AddDetail("este", W("La calle principal sigue hasta el centro de la ciudad, "
  	"probablemente donde habr� ubicado alg�n edificio importante o algo "
  	"similar.\n"));
  AddExit("sur", ATB_CI("ciudad15"));
  AddExit("oeste", ATB_CI("ciudad14"));
  AddExit("este", ATB_CI("ciudad19"));
  AddExit("norte", ATB_CI("ciudad20"));
}

