#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

int cmd_escalar()
{
  int perc;

  write(W("Ves como tus manos se suceden la una a la otra mientras asciendes "
  "por los escaños de la escala.\n"));
  perc=TP->UseSkill(HAB_TREPAR, 20);

  if (perc<=0)
    return notify_fail("¡Pero el travesaño donde tenías la mano se te escapa de los dedos!\n");

  write("Con cierta fortuna llegas a la parte alta...\n");
  TP->move(ATB_CI("ciudad17"));

  return 1;
}

create()
{
  ::create();
  SetIntLong(W("Hacia el este la calle o carretera principal de Atbalnin sigue "
  	"y sigue inexorablemente. Hacia el oeste ves una fragua, algo parecido "
  	"a una minúscula cabaña. Aqui, poco más hay. Un arbol grande, y una "
  	"escala que podría llamarse \"creaviudas\".\n"));

  AddDetail("arbol", W("Es un arbol. De la familia de los árboles. "
  	"Del género árbol. Ah, si, tiene hojas. Es grande, muy grande."));
  AddDetail(({"creaviudas", "escala"}), W("Es una escala de cuerdas con los "
  	"travesaños de madera. Podrías intentar escalarla. Con un poco de "
  	"suerte, es posible que hasta te rompas el... que llegues a la parte "
  	"de arriba. La aventura es tu vida, recuerda.\n"));
  	
  AddExit("sur", ATB_CI("ciudad07"));
  AddExit("este", ATB_CI("ciudad18"));
  AddExit("sudeste", ATB_CI("ciudad15"));
  AddExit("subir", SF(cmd_escalar));
  AddExit("oeste", ATB_CI("ciudad06"));
  AddExit("noroeste", ATB_CI("ciudad13"));
}

