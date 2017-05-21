#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Esta es la plaza central de Atbalnin. Al sur la biblioteca "
  	"te impiden el paso, ya que llega hasta pr�cticamente el agua y al "
  	"este puedes ver una isleta en el centro del lago.\n"));
  SetIntShort("la plaza de Atbalnin");
  AddDetail("lago", W("Es un lago de agua clara y poco profunda. En el centro "
  	"hay una peque�a isleta.\n"));
  AddDetail("biblioteca", W("Es un gran edificio de madera, cuya entrada "
  	"est� hacia el oeste, y que llega hasta casi el mismo borde del "
  	"lago. Est� rodead por �rboles y arbustos\n"));
  AddDetail(({"arboles", "�rboles", "arbustos"}), "Rodean la biblioteca y son "
  	"bastante frondosos.\n");
  AddDetail("isleta", W("Es una peque�a isleta de roca que sobresale "
  	"alrededor de un metro por encima del agua. En la parte m�s alta "
  	"est�s seguro de que hay algo, pero desde aqu� no ves bien lo que "
  	"es. Quiz�s m�s al norte lo veas un poco mejor.\n"));
	  	
  AddExit("norte", ATB_CI("ciudad31"));
  AddExit("oeste", ATB_CI("ciudad29"));
  AddExit("nordeste", ATB_CI("ciudad33"));
}

