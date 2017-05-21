#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Est�s frente a un solitario �rbol, el �nico que crece en esta "
  	"zona. Es grande, no el m�s grande que has visto, pero tiene un "
  	"qu�-se-yo que le da cierto morbo...\n"));

  AddDetail(({"arbol", "�rbol"}), W("Es un �rbol no muy grande pero bastante "
  	"ancho.\n"));

  AddExit("oeste", ATB_CI("ciudad38"));
  AddExit("norte", ATB_CI("ciudad37"));
  AddItem(QUEST_GARDIL("gardil"), REFRESH_DESTRUCT, 1);
}
