#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Aki va la habitacion que Tsume habia hecho para alura, o la que alura quiera.\n"
    );
  SetIndoors(1);
  SetIntBright(30);
  SetIntSmell(
    "Un olor a podrido se extiende por el ambiente poco a poco.\n"
    );
  SetIntNoise(
    "Ruidos como de arañazos se escuchan a lo lejos.\n"
    );
  AddDetail(({"niebla"}),
    "Una niebla fina se filtra dentro de esta estancia haciendo de ella un triste y lobrego final para la gente que tiene de esta su ultima morada.\n"
    );
  AddExit("este","camino2.c");
  SetLocate("cementerio2");
}
