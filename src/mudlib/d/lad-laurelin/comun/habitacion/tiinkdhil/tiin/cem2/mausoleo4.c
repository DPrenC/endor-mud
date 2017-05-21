#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Te encuentras en una pequeña estancia en medio de la cual ves lo que queda\n"
    "de una tumba rodeada por telarañas, mugre y porqueria que se ha acumulado con\n"
    "el tiempo.\n"
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
    "Una fina capa de niebla se filtra por la entrada del mausoleo haciendo que esta estancia parezca un pequeño lago.\n"
    );
  AddDetail(({"tumba"}),
    "Una tumba de piedra se alza en el centro de la sala. Esta realtivamente en buen estado.\n"
    );
  AddDetail(({"porqueria","telarañas","mugre"}),
    "Una capa de porqueria se acumula en todas partes. Nadie a limpiado aqui en mucho tiempo.\n"
    );
  AddExit("este","camino7.c");
  SetLocate("cementerio2");
}
