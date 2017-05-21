
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create(){
  ::create();
  SetIndoors(0);
  SetIntNoise("Escuchas un horrible griznar de algun pajaro.\n");
  SetIntShort("un cruce de caminos");
  SetIntLong("Estas en un cruce de caminos. Al nordeste hay un cementerio "
  		"y al noroeste las ruinas de un templo.\n");
  AddDetail(({"cementerio"}),"No parece el tipico cementerio elfo.\n");
  AddDetail(("templo"),"Es una gran estructura semiderruida, pero que todavia "
  		"se mantiene en pie.\n");

  AddExit("sur",ALULAGO("bosque/cdhab3"));
  AddExit("noroeste",ALULAGO("templo/tdent"));
  AddExit("nordeste",ALUTIIN("cementerio/entradacem"));
}




