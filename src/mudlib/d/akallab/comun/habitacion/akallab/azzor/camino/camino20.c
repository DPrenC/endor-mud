/*
DESCRIPCION  : parche temporal para conectar varias zonas de territorio
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/camino/camino20.c
MODIFICACION : 12-11-98 [Angor@Simauria] Creacion
	       24-06-03 [Daneel] La modifico para que sea algo más que
	       		         un parche.
*/
#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
 SetIntShort("el camino frente a la entrada de Azzor");
  SetIntLong(
   "Estás en un camino, a la entrada de Azzor. Hacia el oeste sigue "
   	"el camino que llega a un cruce, mientras que hacia el este la "
   	"ciudad crece.\n");
  AddDetail(({"Azzor","ciudad","pueblo"}),
     "Hacia el este puedes ver el pueblo de Azzor, formado por sus sucias "
     "casas en torno al puerto.\n");
  AddDetail(({"cruce","camino"}),
     "Hacia el oeste el camino se bifurca en varias direcciones.\n");
  AddDetail(({"puerto","puerto de Azzor"}),
     "Alla en el puerto se encuentran varios barcos, muy usados por "
     "aventurerospara alcanzar otras costas donde hacer fortuna.\n");
  SetIntNoise("Sopla una suave brisa desde el este.\n");
  SetIntSmell("Hueles el fragante aroma del campo que se mezcla con la fresca brisa marina.\n");
  SetIndoors(0);
  SetLocate("valle de Azzor");
  AddExit("este",AZ_CIUDAD("calle01"));
  AddExit("oeste",AZ_CAMINO("camino06"));
}
