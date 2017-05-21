/*
08/05/2007, [Y] (Yalin): suprimo función cmd_beber() y cambio la fuente al
    nuevo standard.
*/
#include "path.h"
#include <sounds.h>
inherit ATB_CI("std_ciudad");


create()
{
  ::create();
  SetIntLong(W("Levantas la vista intentando ver hasta dónde llega la copa del "
  	"arbol que tienes frente a tí. Es curioso lo que se puede llegar a "
  	"pensar cuando estás en una postura tan poco ortodoxa como la que "
  	"presentas ahora. Bajas la vista y ves una pequeña fuente incrustada, "
  	"o mejor dicho, que sale armoniosamente del hueco central del árbol.\n"));
  AddDetail("arbol", W("Es sin duda uno de los árboles más ancianos del "
  	"lugar. En tu mente se formula una inquietante pregunta: ¿qué hacía "
  	"tamaño árbol en una ciudadela humana?\n"));
  AddDetail("agua", W("El agua de la fuente es cristalina y parece "
  	"refrescante. Te invita a beber.\n"));
  AddItem("/d/lad-laurelin/comun/objeto/otro/fuente");
  AddExit("norte", ATB_CI("ciudad14"));
  AddExit("este", ATB_CI("ciudad15"));
  AddExit("sur", ATB_CI("ciudad08"));
  AddExit("oeste", ATB_CI("ciudad01"));
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}

