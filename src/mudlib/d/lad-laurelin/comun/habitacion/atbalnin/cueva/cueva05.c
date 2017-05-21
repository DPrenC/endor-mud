#include "path.h"
inherit ATB_C("std_cueva");


create(){
  object ob;
  ::create();
  SetIntLong(W("Ante ti, hacia el este, las estrechas paredes de la "
	"cueva se abren para dar paso a una enorme habitacion. Aqui parece "
	"estar la respuesta al incesante goteo y a la humedad que reina. "
	"Estas ante el propio corazon del bosque, tallado en la roca por "
	"cientos de anyos de erosion del agua, del agua del inmenso lago que "
	"se descubre ante ti.\n"));
  SetIntShort("el lago de la cueva de Atbalnin");
  AddDetail("suelo", "Es frio, liso y humedo.\n");
  AddDetail(({"paredes", "pared"}), W("Las paredes se abren para "
	"dejar paso a un enorme lago.\n"));
  AddDetail("lago", "Es un inmenso y oscuro lago.\n");
  AddExit("nordeste", ATB_C("cueva09"));
  AddExit("este", ATB_C("cueva08"));
  AddExit("sudeste", ATB_C("cueva11"));
  AddExit("sur", ATB_C("cueva07"));
  AddExit("oeste", ATB_C("cueva04"));
  AddExit("norte", ATB_C("cueva06"));
}
