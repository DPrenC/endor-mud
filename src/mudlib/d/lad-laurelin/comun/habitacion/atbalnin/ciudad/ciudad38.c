#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Hacia el norte ves la gran biblioteca y hacia el este un �rbol "
  	"de tama�o medio que crece solitariamente.\n"));
  AddDetail(({"biblioteca", "edificio"}), "Es la biblioteca de Atbalnin, "
  	"centro de sabidur�a.\n");
  AddDetail(({"arbol", "�rbol"}), "Es un arbol de tama�o medio.\n");
  SetIntShort("el sur de la biblioteca");
  	
  AddExit("norte", ATB_CI("ciudad36"));
  AddExit("este", ATB_CI("ciudad39"));
}
