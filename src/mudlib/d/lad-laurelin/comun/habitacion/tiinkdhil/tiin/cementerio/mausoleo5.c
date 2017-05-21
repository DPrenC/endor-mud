
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Este mausoleo tiene un gran sarcofago en el centro de la sala. Adornado con craneos "
    "y de aspecto temible es lo unico que se ve en la sala a estilo de decoracion.\n"
    "Extrañamente, parece mas limpio que el resto de sitios en los que has estado hasta llegar aqui.\n"
    );
  SetIndoors(1);
  SetIntBright(30);
  SetIntSmell(
    "El olor a cerrado y a humedad flota en el ambiente.\n"
    );
  SetIntNoise(
    "Ruidos como de arañazos se escuchan a lo lejos.\n"
    );
  AddDetail(({"niebla"}),
    "Una fina capa de niebla cubre el suelo.\n"
    );
  AddDetail(({"craneos"}),
    "Unos craneos de aspecto muy real cubren el sarcofago por los lados, dandole\n"
    "un aspecto siniestro.Quien querria tener su sueño final en un lugar como este,\n"
    "te preguntas.\n"
    );
  AddDetail(({"sarcofago"}),
    "Una tumba se alza en el centro de la sala, impresionante con su macrabra decoracion.\n"
    );
  AddExit("oeste",ALUTIIN("cementerio/camino6"));
  AddItem(ALUPNJ("espectro"),REFRESH_DESTRUCT,1);
  AddItem(ALUPNJ("espectro"),REFRESH_DESTRUCT,1);
  SetLocate("cementerio2");
}
