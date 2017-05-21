
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create(){
  ::create();
  SetIndoors(0);
  SetLocate("cementerio2");
  SetIntSmell("El olor nauseabundo de la carne putrefacta se extiende por todos "
  		"lados.\n");
  SetIntNoise("Oyes como se mueven cosas, ara�azos y algun tipo de extra�o grito.\n");
  SetIntShort("el cementerio");
  SetIntLong("Esta parte del camino, que atraviesa en diagonal el cementerio "
  		"es m�s estrecha que los caminos por los que has pasado. La pared "
  		"del cementerio, desconchada por el tiempo, se extiende por toda "
  		"esta zona. Hay un gran numero de lapidas apiladas contra ella.\n");
  AddDetail(({"niebla"}),"La niebla parece formar figuras solidas que tienen "
  		"aspectos amenazadores, crees distinguir movimientos por todos lados... "
  		"ser� real o una ilusi�n de tu miedo?\n");
  AddDetail(({"tumbas"}),"Hay tumbas en el suelo a los lados del camino, algunas "
  		"tienen aspecto extra�o, como si alguien hubiera removido la tierra. "
  		"En otros sitios se adivinan lugares en los que una lapida ha sido "
  		"arrancada.\n");
  AddDetail(({"lapidas","l�pidas"}),"L�pidas arrancadas de su lugar se apilan "
  		"contra la pared.\n");

  AddExit("sudeste",ALUTIIN("cementerio/camino13"));
  AddExit("oeste",ALUTIIN("cementerio/camino8"));

  AddItem(ALUOBJ("/otro/tumba"));
  AddItem(ALUOBJ("/otro/tumba"));
  AddItem(ALUPNJ("momia"),REFRESH_DESTRUCT,1);
}

