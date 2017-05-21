#include "path.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Esto parece ser la entrada suroeste de Atbalnin. Aqui se "
  	"cuenta que Alees, la elfa guerrera, luch� valientemente y consigui� "
  	"expulsar a la Segunda Invasi�n orca, no sin cierta p�rdida. Y por "
  	"eso hay una estatua rememorando el combate.\n"));
  	
  AddDetail("estatua", W("Es una estatua de piedra finamente tallada, "
  	"seguramente por enanos, en la �poca de la Alianza (en alguna de "
  	"ellas). Representa el combate entre Alees y sus soldados y los "
  	"orcos. Hay una inscripci�n.\n"));
  AddReadMsg(({"inscripci�n", "inscripcion"}),
  	W("En la inscripci�n puedes leer:\n"
  	"A Alees y sus soldados. Los que consiguieron derrotar a los enemigos "
  	"ser�n ahora y para siempre recordados.\n"));

  AddExit("norte", ATB_CI("ciudad01"));
  AddExit("este", ATB_CI("ciudad08"));
  AddExit("sur", ATB_B("bosque28"));
  AddExit("oeste", ATB_B("bosque30"));
}

