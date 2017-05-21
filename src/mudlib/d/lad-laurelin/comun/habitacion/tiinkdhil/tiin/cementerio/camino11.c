
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create(){
  ::create();
  SetIndoors(0);
  SetLocate("cementerio2");
  SetIntSmell(W("El olor cada vez se hace mas fuerte en cuanto te adentras en el "
  		"cementerio... no hay duda... huele a muertos... a muchos... y en "
  		"alto estado de descomposicion.\n"));
  SetIntNoise(W("Tu imaginación te esta gastando una mala pasada... porque dirias "
  		"que escuchas pasos...como de algo que se arrastra entre la niebla.\n"));
  SetIntShort("el cementerio");
  SetIntLong(W("Estas cerca de una de las paredes laterales del cementerio, aquí "
  		"el camino sigue al norte haciendo que te internes un poco mas en "
  		"este lugar de muerte y al oeste, en un sendero brumoso que no "
  		"parece nada seguro...\n"));
  AddDetail(({"niebla","bruma"}),W("Cerca del suelo es espesa y apenas te deja ver "
  		"la hierba que recubre todo el cementerio, el resto se trata de una "
  		"niebla mucho menos densa pero que aún así te impide ver el final "
  		"del camino.\n"));
  		
  AddExit("oeste",ALUTIIN("cementerio/camino9"));
  AddExit("norte",ALUTIIN("cementerio/camino14"));
}
