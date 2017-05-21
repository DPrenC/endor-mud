
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create(){
  ::create();
  SetIndoors(0);
  SetIntNoise("Escuchas un horrible griznar de algun pájaro.\n");
  SetIntShort("un cruce de caminos");
  SetIntLong("Estas en un cruce de caminos. Al oeste ves un cementerio "
  		"y al nordeste las ruinas de un templo.\n");
 AddDetail(({"cementerio"}),"No parece el típico cementerio elfo.\n");
 AddDetail(("templo"),"Es una gran finca parcialmente derruida, pero que "
 		"todavia se mantiene en pie.\n");

 AddExit("sur",ALULAGO("bosque/cam4"));
 AddExit("oeste",ALUTIIN("cementerio/entradacem"));
 AddExit("nordeste",ALULAGO("templo/tdent"));
}