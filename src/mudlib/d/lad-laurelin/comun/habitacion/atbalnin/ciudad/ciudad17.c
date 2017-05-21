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
    write("�Wow! �Tu mano no encuentra el travesa�o y caes!\n");
    TP->Defend(random(-(perc/2)));
  }

  write("Consigues bajar hasta el suelo.\n");
  TP->move(ATB_CI("ciudad14"));

  return 1;
}

create()
{
  ::create();
  SetIntLong(W("�Qu� se puede colocar en lo alto de uno de los �rboles m�s "
  	"grandes de la zona? Un puesto de vig�a, obviamente. �Y cu�l es la "
  	"funci�n de ese puesto de vig�a actualmente? Probablemente como "
  	"soporte a la inmensa mara�a de telas de ara�a que lo recubren. "
  	"Esta no es una zona demasiado popular. �Por qu� habr�a de serla? "
  	"Los accesos son un asco...\n"));
  AddDetail("abajo", "Est� muy pero que muy abajo...\n");
  AddDetail("escala", W("Es una escala de cuerda con los travesa�os de "
  	"madera. Llega hasta abajo.\n"));
  AddExit("bajar", SF(cmd_bajar));
}

