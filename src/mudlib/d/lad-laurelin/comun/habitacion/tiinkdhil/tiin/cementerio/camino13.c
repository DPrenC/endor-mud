
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create(){
  ::create();
  SetIndoors(0);
  SetLocate("cementerio2");
  SetIntSmell("El olor nauseabundo de la carne putrefacta se extiende por todos lados.\n");
  SetIntNoise("Oyes como se mueven cosas, arañazos y algun tipo de extraño grito.\n");
  SetIntShort("el cementerio");
  SetIntLong("Te encuentras delante de un mausoleo de pequeño tamaño. Un "
  		"camino de setos muy descuidados te conduce hasta el. La niebla "
  		"no te permite verlo con demasiada claridad, pero parece estar "
  		"bien conservado. El camino que te ha traido aqui aparece entre "
  		"la niebla como una ciudad fantasmal. Con gusto saldrias de aqui "
  		"rapidamente.\n");
  AddDetail(({"niebla"}),W("La niebla en esta zona se hace mas densa, arremolinandose "
  		"por tus piernas y haciendo que un escalofrio te suba por la espalda.\n"));
  AddDetail(({"tumbas"}),W("Hay tumbas en el suelo a los lados del camino, algunas "
  		"tienen aspecto extraño, como si alguien hubiera removido la tierra. "
  		"En otros sitios se adivinan lugares en los que una lapida ha sido "
  		"arrancada.\n"));
  AddDetail(({"setos","seto","arbusto","arbustos"}),W("Unos arbustos muy descuidados "
  		"crecen a lo largo del camino que lleva al mausoleo.\n"));

  AddExit("sur",ALUTIIN("cementerio/camino12"));
  AddExit("este",ALUTIIN("cementerio/mausoleo8"));
  AddExit("noroeste",ALUTIIN("cementerio/camino10"));

  AddItem(ALUPNJ("esquel"),REFRESH_DESTRUCT,1);
}
