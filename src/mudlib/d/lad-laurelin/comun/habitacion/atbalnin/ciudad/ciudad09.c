#include "path.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Si algo te ha ense�ado el cursillo acelerado para aventureros "
  	"(pendiente de patente) es a distinguir los diversos, cambiantes y "
  	"traicioneros puntos cardinales. Seg�n tus complicados c�lculos, "
  	"podr�as llegar a asegurar que est�s en la parte sur de Atbalnin. "
  	"bueno, seg�n eso y el cartel que tienes ante t�...\n"));
  AddDetail("cartel", "Es un cartel. Podr�as leerlo.\n");
  AddReadMsg("cartel", "En el cartel pone: Art�culos interesantes. Zona Sur.\n");

  AddExit("oeste", ATB_CI("ciudad03"));
  AddExit("entrar", ATB_TI("tienda01"));
  AddExit("noroeste",ATB_CI("ciudad08"));
}

