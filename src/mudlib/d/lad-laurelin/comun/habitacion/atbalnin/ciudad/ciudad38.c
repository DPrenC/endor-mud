#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Hacia el norte ves la gran biblioteca y hacia el este un árbol "
  	"de tamaño medio que crece solitariamente.\n"));
  AddDetail(({"biblioteca", "edificio"}), "Es la biblioteca de Atbalnin, "
  	"centro de sabiduría.\n");
  AddDetail(({"arbol", "árbol"}), "Es un arbol de tamaño medio.\n");
  SetIntShort("el sur de la biblioteca");
  	
  AddExit("norte", ATB_CI("ciudad36"));
  AddExit("este", ATB_CI("ciudad39"));
}
