
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create(){
  ::create();
  SetIndoors(1);
  SetIntBright(30);
  SetLocate("cementerio2");
  SetIntSmell("El olor a cerrado y a humedad flota en el ambiente.\n");
  SetIntNoise("Ruidos como de ara�azos se escuchan a lo lejos.\n");
  SetIntShort("el cementerio");
  SetIntLong("Te encuentras en una peque�a estancia en medio de la cual "
  		"ves lo que queda de una tumba rodeada por telara�as, mugre y "
  		"porquer�a que se ha acumulado con el tiempo.\n");
  AddDetail(({"niebla"}),"Una niebla fina se filtra dentro de esta estancia "
  		"haciendo de ella un triste y l�brego final para la gente que "
  		"tiene de esta su ultima morada.\n");
  AddDetail(({"porqueria","telara�as","polvo"}),"Restos de hojas, telas de "
  		"ara�a y polvo se acumulan por todos lados.\n");
  AddDetail(({"ataud","ata�d","tumba"}),"Una tumba de piedra ocupa el centro "
  		"de la estancia. En la tapa, la figura de una mujer esculpida en "
  		"m�rmol, descansa en un sue�o profundo.\n");
  AddDetail(({"mujer"}),"Una bella mujer durmiendo, esculpida en m�rmol blanco.\n");

  AddExit("oeste",ALUTIIN("cementerio/camino13"));

  AddItem(ALUPNJ("vampiresa"),REFRESH_DESTRUCT,1);
}
