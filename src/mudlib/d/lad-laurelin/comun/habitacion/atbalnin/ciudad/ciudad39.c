#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Estás frente a un solitario árbol, el único que crece en esta "
  	"zona. Es grande, no el más grande que has visto, pero tiene un "
  	"qué-se-yo que le da cierto morbo...\n"));

  AddDetail(({"arbol", "árbol"}), W("Es un árbol no muy grande pero bastante "
  	"ancho.\n"));

  AddExit("oeste", ATB_CI("ciudad38"));
  AddExit("norte", ATB_CI("ciudad37"));
  AddItem(QUEST_GARDIL("gardil"), REFRESH_DESTRUCT, 1);
}
