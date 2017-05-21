
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create(){  ::create();
  SetIntShort("la habitación de RadHul");
  SetIntLong(
    "Estas en un sitio distinto a los demas mausoleos, aqui hay opulencia en todo lo que te rodea. "
    "Ricos cortinajes cubren las paredes, dandole un aire noble y pomposo. Candelabros bellamente "
    "tallados dan una iluminacion parcial que permite un ambiente suave.Un aire enrarecido asalta "
    "tus sentidos, haciendo imposible pensar con claridad... Imagenes de bellezas androginas vienen a "
    "tu cabeza y te hacen tener extraños pensamientos de lujuria y placeres prohibidos.\n"
    );
  SetIndoors(1);
  SetIntBright(35);
  SetIntSmell(
    "Un fuerte olor a incienso y a sangre fresca inunda el ambiente de manera brutal.\n");
  SetIntNoise("Una musica suave que no sabrias decir de donde viene te incita a pensamientos extraños.\n");

  AddDetail(({"niebla"}),
    "Remolinos de niebla se mueven inexplicablemente de un lado a otro, impidiendo que "
    "veas mas alla de un par de metros, te sientes terriblemente solo y triste en este mar blanco.\n");
  AddDetail(({"cortinas"}),
    "Unas ricas cortinas adornan las paredes de este mausoleo.\n");
  AddDetail(({"candelabros","candelabro"}),
    "Unos hermosos candelabros labrados estan fijos a las paredes en forma de pequeñas antorchas."
    "La cera cae en cascadas por las velas que iluminan la estancia.\n");
  AddDetail(({"humo"}),
    "De la pared sale un poco de humo que identificas como incienso.\n");

 AddDetail(({"pared"}),    "Pequeños agujeros permiten la salida de humo.\n"    );
 AddExit("norte",ALUTIIN("cementerio/camino6"));
 AddItem(ALUPNJ("Radhul"),REFRESH_DESTRUCT,1);
 AddItem(ALUPNJ("vampiresa"),REFRESH_DESTRUCT,1);
 AddItem(ALUPNJ("vampiresa"),REFRESH_DESTRUCT,1);
 AddItem(ALUPNJ("vampiresa"),REFRESH_DESTRUCT,1);
 SetLocate("cementerio2");
}