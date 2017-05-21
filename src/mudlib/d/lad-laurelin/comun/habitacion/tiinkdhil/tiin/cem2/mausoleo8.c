#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Te encuentras en una peque�a estancia en medio de la cual ves lo que queda\n"
    "de una tumba rodeada por telara�as, mugre y porqueria que se ha acumulado con\n"
    "el tiempo.\n"
    );
  SetIndoors(1);
  SetIntBright(30);
  SetIntSmell(
    "El olor a cerrado y a humedad flota en el ambiente.\n"
    );
  SetIntNoise(
    "Ruidos como de ara�azos se escuchan a lo lejos.\n"
    );
  AddDetail(({"niebla"}),
    "Una niebla fina se filtra dentro de esta estancia haciendo de ella un triste y lobrego final para la gente que tiene de esta su ultima morada.\n"
    );
  AddDetail(({"porqueria","telara�as","polvo"}),
    "Restos de hojas, telas de ara�a y polvo se acumulan por todos lados.\n"
    );
  AddDetail(({"ataud","tumba"}),
    "Una tumba de piedra ocupa el centro de la estancia. En la tapa, la figura de una mujer esculpida en marmol, descansa en un sue�o profundo.\n"
    );
  AddDetail(({"mujer"}),
    "Una bella mujer durmiendo, esculpida en marmol blanco.\n"
    );
  AddExit("oeste","camino13.c");
  SetLocate("cementerio2");
}
