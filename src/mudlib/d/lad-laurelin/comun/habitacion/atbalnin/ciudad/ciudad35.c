#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Desde esta posici�n se domina la casi totalidad de la plaza "
  	"central de Atbalnin, que se extiende hacia el oeste. Las palomas y "
  	"dem�s bichos alados parecen concentrarse en el centro de la misma, "
  	"emitiendo alegremente su gracioso gorjeo. Hacia el nordeste ves "
  	"un gran edificio.\n"));
  AddDetail("biblioteca", "Es un gran edificio donde probablemente habr�n muchos libros.\n");
  AddDetail("plaza", W("Es una plaza bastante corriente. Palomas, palomas y m�s "
  	"palomas. Ah, si, y una est�tua en el centro.\n"));
  SetIntShort("la parte oeste de la plaza central");
  	
  AddExit("norte", ATB_CI("ciudad28"));
  AddExit("este", ATB_CI("ciudad36"));
  AddExit("oeste", ATB_CI("ciudad34"));
}
