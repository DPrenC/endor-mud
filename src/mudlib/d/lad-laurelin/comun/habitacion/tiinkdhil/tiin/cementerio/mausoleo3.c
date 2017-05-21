
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Te encuentras en una pequeña estancia en medio de la cual ves una tumba\n"
    "con inscripciones de calaveras con aspectos temibles y amenazantes, un\n"
    "escalofrio recorre tu espalda con este tipo de decoracion.\n"
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
    "Una fina capa de niebla cubre el suelo de manera amenazante, dando a este\n"
    "lugar un aspecto tetrico y olvidado de la mano de dios.\n"
    );
  AddDetail(({"calaveras"}),
    "Unas figuras de calaveras adornan esta sala. Tienen un aspecto muy real.\n"
    );
  AddDetail(({"tumba"}),
    "Una especie de sarcofago de piedra, adornado con calaveras se alza en el centro\n"
    "de esta sala.\n"
    );
  AddExit("este",ALUTIIN("cementerio/camino6"));
  AddItem(ALUPNJ("momia"),REFRESH_DESTRUCT,1);
  SetLocate("cementerio2");
}
