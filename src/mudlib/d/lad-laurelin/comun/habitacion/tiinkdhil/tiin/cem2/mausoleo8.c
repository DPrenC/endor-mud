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
  AddDetail(({"porqueria","telarañas","polvo"}),
    "Restos de hojas, telas de araña y polvo se acumulan por todos lados.\n"
    );
  AddDetail(({"ataud","tumba"}),
    "Una tumba de piedra ocupa el centro de la estancia. En la tapa, la figura de una mujer esculpida en marmol, descansa en un sueño profundo.\n"
    );
  AddDetail(({"mujer"}),
    "Una bella mujer durmiendo, esculpida en marmol blanco.\n"
    );
  AddExit("oeste","camino13.c");
  SetLocate("cementerio2");
}
