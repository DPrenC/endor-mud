#include "path.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("En las ciudades hay tiendas, y en las tiendas artículos. "
  	"Nadie sabe por qué las cosas son así, por qué llueve hacia abajo, "
  	"por qué las manzanas tienen la mala idea de caer sobre las mentes "
  	"pensantes. Pero es así. Frente tí hay una cabaña donde se practica "
  	"el noble arte de la compra venta. Noble mientras seas tú el tendero. "
  	"La tienda parece ser de carácter general, o al menos no hay nada que "
  	"demuestre lo contrario.\n"));
  AddDetail("cartel", "Es un cartel de madera. Tiene letras escritas.\n");
  AddReadMsg("cartel", "Puedes leer: Tienda de Comestibles.\n");

  SetPreIntShort("frente a");
  SetIntShort("una tienda");
  AddExit("entrar", ATB_TI("tienda02"));
  AddExit("norte", ATB_CI("ciudad18"));
  AddExit("noroeste", ATB_CI("ciudad14"));
AddExit("suroeste",ATB_CI("ciudad08"));
  AddExit("oeste", ATB_CI("ciudad07"));
}
