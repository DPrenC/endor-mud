
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create(){
  ::create();
  SetIndoors(0);
  SetLocate("cementerio2");
  SetIntSmell("El olor cada vez se hace mas fuerte en cuanto te adentras en "
  		"el cementerio... no hay duda... huele a muertos... a muchos...\n");
  SetIntNoise("Tu imaginación te esta gastando una mala pasada... porque dirías "
  		"que escuchas pasos...como de algo que se arrastra entre la niebla.\n");
  SetIntShort("el cementerio");
  SetIntLong("El sendero continua aqui haciendo una esquina. Hacia el norte, "
  		"a no demasiada distancia dirias que se ven mausoleos de antiguas "
  		"familias, hacia el este regresa el sendero... la bruma no te deja "
  		"ver bien de todas maneras pero jurarias que algo se ha movido y no "
  		"lo has visto...te estaran jugando tus ojos una mala pasada?\n");
  AddDetail(({"niebla","bruma"}),"Cerca del suelo es espesa y apenas te deja ver "
  		"la hierba que recubre todo el cementerio, el resto se trata de una "
  		"niebla mucho menos densa pero que aún así te impide ver el final "
  		"del camino.\n");
  AddDetail(({"tumbas"}),"Hay tumbas en el suelo a los lados del camino, algunas "
  		"tienen aspecto extraño, como si alguien hubiera removido la tierra. "
  		"En otros sitios se adivinan lugares en los que una lapida ha sido "
  		"arrancada.\n");

  AddExit("norte",ALUTIIN("cementerio/camino2"));
  AddExit("este",ALUTIIN("cementerio/camino4"));

  AddItem(ALUOBJ("otro/tumba"));
}

