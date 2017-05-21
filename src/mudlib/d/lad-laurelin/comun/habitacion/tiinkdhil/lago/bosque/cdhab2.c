
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create() {
  ::create();
  SetIndoors(0);
  SetIntNoise("Escuchas un horrible griznar de algun pájaro.\n");
  SetIntShort("un camino estrecho");
  SetIntLong("Lejos, a lo largo del camino divisas una enorme estructura que parecen "
		"los restos de un edificio. Hay un poste con un cartel. "
		"Un poco mas cerca al norte ves un cementerio.\n");
  AddDetail(({"cementerio"}),"No logras verlo bien, pero te llama la atención una "
  		"bandada de pájaros que revolotean por encima.\n");
  AddDetail(({"poste","cartel"}),"Escrito en sangre lees:\n"
  "				-----------------------------\n"
  "				  CUIDADO AVENTURERO\n"
  "				  ZONA MUY PELIGROSA\n"
  "				  NO APTA PARA SERES .. VIVOS\n"
  "				-----------------------------\n");

  AddExit("sur",ALULAGO("bosque/cdhab1"));
  AddExit("norte",ALULAGO("bosque/cdhab3"));
}