#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Te encuentras en una pequeña estancia en medio de la cual ves lo que queda\n"
    "de una tumba rodeada por telarañas y porqueria que se ha acumulado con\n"
    "el tiempo.La tapa de este ataud de piedra esta rota en el suelo.\n"
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
  AddDetail(({"tumba"}),
    "Una tumba con la tapa superior partida... esta vacia.\n"
    );
  AddDetail(({"ataud"}),
    "Un ataud de piedra abierto y vacio esta en el centro de la estancia.\n"
    );
  AddDetail(({"tapa","piedra"}),
    "La tapa de piedra del ataud esta hecha pedazos en el suelo.\n"
    );
  AddDetail(({"porqueria","telarañas"}),
    "Restos de hojas, telas de araña y polvo se acumulan por todos lados.\n"
    );
  AddExit("este","camino3.c");
  SetLocate("cementerio2");
}
