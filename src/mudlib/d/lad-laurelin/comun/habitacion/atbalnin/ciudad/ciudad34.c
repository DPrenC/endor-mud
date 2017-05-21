#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Esta es la plaza central de Atbalnin. No es que haya nada "
  	"especial en ella que no hayas visto ya antes; en el centro se alza "
  	"una estatua de algo prácticamente irreconocible (es increíble lo que "
  	"puede hacer el paso del tiempo en una estatua). Hacia el nordeste ves "
  	"la bliblioteca central, y hacia el sur parecen haber varias salidas "
  	"hacia el bosque.\n"));
  	
  AddDetail("estatua", W("Tu imaginación vaga sin control por lugares "
  	"realmente insospechados, pero en ninguno de esos sitios ves algo "
  	"parecido a lo que tienes ante tí. El paso del tiempo no perdona, y "
  	"por aquí ha pasado en grandes cantidades.\n"));
  AddExit("noroeste", ATB_CI("ciudad21"));
  AddExit("este", ATB_CI("ciudad35"));
  AddExit("nordeste", ATB_CI("ciudad28"));
  AddExit("suroeste", ATB_CI("ciudad10"));
  AddExit("norte", ATB_CI("ciudad25"));
  AddExit("sur", ATB_CI("ciudad11"));
}

