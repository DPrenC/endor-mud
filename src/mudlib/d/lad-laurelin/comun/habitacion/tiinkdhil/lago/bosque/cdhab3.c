
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create() {
  ::create();
  SetIndoors(0);
  SetIntNoise("Escuchas un horrible griznar de algun pájaro.\n");
  SetIntShort("un camino estrecho");
  SetIntLong("Estas en un camino empedrado. A tu alrededor no ves mas vegetación "
  		"que algunos arbustos. Esto esta realmente desolado. Un poco mas hacia "
  		"delante ves un edificio y un cementerio.\n");
  AddDetail(({"cementerio"}),"No logras verlo bien, pero te llama la atencion una "
		"bandada de pájaros que revolotean por encima.\n");
  AddDetail(("edificio"),"Parece un gran templo.\n");

  AddExit("sur",ALULAGO("bosque/cdhab2"));
  AddExit("norte",ALULAGO("bosque/cdhab4"));
}