#include "path.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Si algo te ha enseñado el cursillo acelerado para aventureros "
  	"(pendiente de patente) es a distinguir los diversos, cambiantes y "
  	"traicioneros puntos cardinales. Según tus complicados cálculos, "
  	"podrías llegar a asegurar que estás en la parte sur de Atbalnin. "
  	"bueno, según eso y el cartel que tienes ante tí...\n"));
  AddDetail("cartel", "Es un cartel. Podrías leerlo.\n");
  AddReadMsg("cartel", "En el cartel pone: Artículos interesantes. Zona Sur.\n");

  AddExit("oeste", ATB_CI("ciudad03"));
  AddExit("entrar", ATB_TI("tienda01"));
  AddExit("noroeste",ATB_CI("ciudad08"));
}

