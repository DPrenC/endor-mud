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
    "Una niebla fina se filtra dentro de esta estancia haciendo de ella un triste y lobrego final para la gente que tiene de esta su ultima morada.\n"
    );
  AddDetail(({"porqueria","mugre","polvo"}),
    "Telas de araña, mugre y porqueria se acumulan por doquier donde quiera que miras.\n"
    );
  AddExit("oeste","camino7.c");
  SetLocate("cementerio2");
}
