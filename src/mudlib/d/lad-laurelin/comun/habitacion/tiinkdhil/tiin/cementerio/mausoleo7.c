
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create(){
  ::create();

  SetIndoors(1);
  SetIntBright(30);
  SetLocate("cementerio2");
  SetIntShort("el cementerio");
  SetIntLong("Te encuentras en una pequeña estancia en medio de la cual ves "
  		"lo que queda de una tumba rodeada por telarañas, mugre y "
  		"porqueria que se ha acumulado con el tiempo. Lo que en otro "
  		"tiempo fue un gran mausoleo de alguna familia adinerada, "
    		"ahora es morada de cualquier tipo de engendros que puedan pulular "
    		"por esta zona.\n");
  SetIntSmell("El olor a cerrado y a humedad flota en el ambiente.\n");
  SetIntNoise("Ruidos como de arañazos se escuchan a lo lejos.\n");
  AddDetail(({"tumba"}),"Una tumba de piedra guarda lo que en su dia fueron "
  		"los restos de alguien vivo.\nEl aspecto es el de un ataud hecho "
  		"de piedra que permanece intacto en el centro de la estancia.\n");
  AddDetail(({"niebla"}),"Una niebla fina se filtra dentro de esta estancia "
  		"haciendo de ella un triste y lóbrego final para la gente que "
  		"tiene en esta su ultima morada.\n");

  AddExit("oeste",ALUTIIN("cementerio/camino12"));

  AddItem(ALUPNJ("momia"),REFRESH_DESTRUCT,1);
  AddItem(ALUPNJ("momia"),REFRESH_DESTRUCT,1);
}
