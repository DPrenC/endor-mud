#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Los edificios suelen tener esquinas, algunos m�s que otros, "
  	"pero ese es un rasgo que comparten la mayor�a. Estas justamente en "
  	"la esquina sudeste de la biblioteca, e imaginas que probablemente "
  	"habr�n otras tres diseminadas a lo largo de la ciudad.\n"));
  SetIntShort("el sudeste de la biblioteca");
  AddDetail("biblioteca", W("Es un gran edificio de madera, cuya entrada "
  	"parece estar m�s al oeste, y que llega hasta casi el mismo borde del "
  	"lago. Est� rodead por �rboles y arbustos\n"));
  AddDetail(({"arboles", "�rboles", "arbustos"}), "Rodean la biblioteca y son "
  	"bastante frondosos.\n");
	  	
  AddExit("oeste", ATB_CI("ciudad36"));
  AddExit("sur", ATB_CI("ciudad39"));
  AddItem(PNJ("atbalnin/ciudad/mendigo"), REFRESH_DESTRUCT, 1);
}

