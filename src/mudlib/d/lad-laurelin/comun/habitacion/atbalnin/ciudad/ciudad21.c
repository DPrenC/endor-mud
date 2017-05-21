#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Este es el centro geofráfico de Atbalnin. Probablemente en "
  	"dicho centro sea lógico ubicar una especie de plaza que lo indique "
  	"claramente, y por eso estás en una de ellas. Estas concretamente en la "
  	"parte noroeste de la misma. Normalmente se suelen "
  	"construir edificios importantes a su alrededor, y por eso mismo "
  	"construyeron la biblioteca central en esta zona.\n"));
  	
  AddDetail(({"biblioteca", "edificio"}), W("Es uno de los pocos edificios que "
  	"no es de madera. Combinar un envoltorio maderero con un interior de "
  	"papel puede dar lugar a ciertos efectos indeseados, como incendios "
  	"incontrolables.\n"));
  AddDetail("plaza", "Es una plaza corriente, cuando llueve se moja como las "
  	"demás.\n");
  SetPreIntShort("a");
  SetIntShort("el noroeste de la plaza de atbalnin");
  	
  AddExit("este", ATB_CI("ciudad25"));
  AddExit("norte", ATB_CI("ciudad23"));
  AddExit("oeste", ATB_CI("ciudad19"));
  AddExit("sudeste", ATB_CI("ciudad34"));
}
