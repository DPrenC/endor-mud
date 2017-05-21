
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
  		"lo que queda de una tumba rodeada por telarañas, mugre y porqueria "
  		"que se ha acumulado con el tiempo.\n");
  SetIntSmell("El olor a cerrado y a humedad flota en el ambiente.\n");
  SetIntNoise("Ruidos como de arañazos se escuchan a lo lejos.\n");
  AddDetail(({"niebla"}),W("Una niebla fina se filtra dentro de esta estancia "
  		"haciendo de ella un triste y lóbrego final para la gente que "
  		"tiene de esta su ultima morada.\n"));
  AddDetail(({"porqueria","mugre","polvo"}),W("Telas de araña, mugre y porqueria "
  		"se acumulan por doquier donde quiera que miras.\n"));

  AddExit("oeste",ALUTIIN("cementerio/camino7"));

  AddItem(ALUPNJ("zombie1"),REFRESH_DESTRUCT,1);
  AddItem(ALUPNJ("momia"),REFRESH_DESTRUCT,1);
}
