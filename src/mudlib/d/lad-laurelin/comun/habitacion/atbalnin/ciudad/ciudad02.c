#include "path.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Esto parece ser la entrada suroeste de Atbalnin. Aqui se "
  	"cuenta que Alees, la elfa guerrera, luchó valientemente y consiguió "
  	"expulsar a la Segunda Invasión orca, no sin cierta pérdida. Y por "
  	"eso hay una estatua rememorando el combate.\n"));
  	
  AddDetail("estatua", W("Es una estatua de piedra finamente tallada, "
  	"seguramente por enanos, en la época de la Alianza (en alguna de "
  	"ellas). Representa el combate entre Alees y sus soldados y los "
  	"orcos. Hay una inscripción.\n"));
  AddReadMsg(({"inscripción", "inscripcion"}),
  	W("En la inscripción puedes leer:\n"
  	"A Alees y sus soldados. Los que consiguieron derrotar a los enemigos "
  	"serán ahora y para siempre recordados.\n"));

  AddExit("norte", ATB_CI("ciudad01"));
  AddExit("este", ATB_CI("ciudad08"));
  AddExit("sur", ATB_B("bosque28"));
  AddExit("oeste", ATB_B("bosque30"));
}

