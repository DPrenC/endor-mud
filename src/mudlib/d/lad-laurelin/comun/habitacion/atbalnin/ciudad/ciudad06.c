// Supongo que el creador fue Theuzifan...
// Bueno, pues que sepas:
// a) Pon cabeceras, que mola que te cagas ;)
// b) Soy Neme, y te he modificao la habitacion...
// [07-Nov-2001] Añadida la salida a la fragua de Kheron

#include "path.h"
#include "rooms.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Estás frente a una pequeña cabaña de madera construida "
  	"en el hueco de un inmenso árbol. Es obvio que nada más grande que "
  	"un gato podría vivir, y aún así debería tener el rabo bastante corto. "
  	"Probablemente sea alguna especie de almacén. Junto a ella ves lo que, "
  	"por sonoridad y olor parece una fragua.\n"));

  AddItem(PNJ("atbalnin/ciudad/lainor"), REFRESH_DESTRUCT, 1);
  AddDetail(({"arbol", "árbol"}), "Es un arbol enorme.\n");
  AddDetail(({"almacen", "almacén", "cabaña", "cabanya"}), "Es una minúscula cabaña construida en el hueco de un árbol.\n");
  AddDetail(({"fragua", "pequeña fragua","pequenya fragua"}),
  "Es una pequeña fragua. La puerta está cubierta de runas enanas.\n");
  AddDetail(({"runas","runas enanas"}), W("Lo que parecían runas enanas se "
  	"revelan como alegres esconchones, fruto quizás de la persistencia de "
  	"algún cliente descontento.\n"));
  AddExit("norte", ATB_CI("ciudad13"));
  AddExit("este", ATB_CI("ciudad14"));
  AddExit("sur", ATB_CI("ciudad01"));
  AddExit("oeste", ATB_CI("ciudad00"));
  AddExit("entrar", ATB_CI("fragua"));
}

