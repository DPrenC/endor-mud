
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create() {
  ::create();
  SetIndoors(0);
  SetIntNoise("Escuchas un horrible griznar de algun pájaro.\n");
  SetIntShort("un camino estrecho.");
  SetIntLong("Estas en un camino empedrado. A tu alrededor no ves mas vegetación "
  		"que algunos arbustos. Esto esta realmente desolado. A ambos lados "
  		"del camino se extiende un bosque. Al norte continúa el sendero.\n");
  AddDetail(({"cementerio"}),"No logras verlo bien, pero te llama la atencion una "
  		"bandada de pájaros que revolotean por encima.\n");
  AddDetail(("edificio"),"Parece un gran templo.\n");
  AddDetail(({"pájaros","pájaros"}),"Estás demasiado lejos para saber qué son.\n");

  AddExit("sur",ALULAGO("bosque/cam2"));
  AddExit("norte",ALULAGO("bosque/cam4"));
  AddExit("este",ALULAGO("bosque/bosque8"));
  AddExit("oeste",ALULAGO("bosque/bosque7"));
}