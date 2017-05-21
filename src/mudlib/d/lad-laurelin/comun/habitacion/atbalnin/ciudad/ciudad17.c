#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

int cmd_bajar()
{
  int perc;

  write("Empiezas a bajar por la escala...\n");
  perc=TP->UseSkill(HAB_TREPAR, 20);

  if (perc<=0)
  {
    write("¡Wow! ¡Tu mano no encuentra el travesaño y caes!\n");
    TP->Defend(random(-(perc/2)));
  }

  write("Consigues bajar hasta el suelo.\n");
  TP->move(ATB_CI("ciudad14"));

  return 1;
}

create()
{
  ::create();
  SetIntLong(W("¿Qué se puede colocar en lo alto de uno de los árboles más "
  	"grandes de la zona? Un puesto de vigía, obviamente. ¿Y cuál es la "
  	"función de ese puesto de vigía actualmente? Probablemente como "
  	"soporte a la inmensa maraña de telas de araña que lo recubren. "
  	"Esta no es una zona demasiado popular. ¿Por qué habría de serla? "
  	"Los accesos son un asco...\n"));
  AddDetail("abajo", "Está muy pero que muy abajo...\n");
  AddDetail("escala", W("Es una escala de cuerda con los travesaños de "
  	"madera. Llega hasta abajo.\n"));
  AddExit("bajar", SF(cmd_bajar));
}

