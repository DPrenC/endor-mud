#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Te encuentras en la parte más noroccidental de la ciudad, hacia "
  	"las afueras. La muralla exterior ha sido reducida a escombros por el "
  	"inagotable esfuerzo que realiza el bosque por invadir la ciudad.\n"));
  AddDetail("muralla", W("Los restos de la muralla se esparcen por el suelo, "
  	"peleando por el protagonismo del mismo con las diversas muestras que "
  	"la naturaleza generosamente nos ofrece.\n"));
  SetIntShort("las afueras occidental de Atbalnin");
  	
  AddExit("este", ATB_CI("ciudad22"));
  AddExit("sur", ATB_CI("ciudad18"));
}
