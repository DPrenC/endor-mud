// Supongo que el creador fue Theuzifan...
// Bueno, pues que sepas:
// a) Pon cabeceras, que mola que te cagas ;)
// b) Soy Neme, y te he modificao la habitacion...
// [07-Nov-2001] A�adida la salida a la fragua de Kheron

#include "path.h"
#include "rooms.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Est�s frente a una peque�a caba�a de madera construida "
  	"en el hueco de un inmenso �rbol. Es obvio que nada m�s grande que "
  	"un gato podr�a vivir, y a�n as� deber�a tener el rabo bastante corto. "
  	"Probablemente sea alguna especie de almac�n. Junto a ella ves lo que, "
  	"por sonoridad y olor parece una fragua.\n"));

  AddItem(PNJ("atbalnin/ciudad/lainor"), REFRESH_DESTRUCT, 1);
  AddDetail(({"arbol", "�rbol"}), "Es un arbol enorme.\n");
  AddDetail(({"almacen", "almac�n", "caba�a", "cabanya"}), "Es una min�scula caba�a construida en el hueco de un �rbol.\n");
  AddDetail(({"fragua", "peque�a fragua","pequenya fragua"}),
  "Es una peque�a fragua. La puerta est� cubierta de runas enanas.\n");
  AddDetail(({"runas","runas enanas"}), W("Lo que parec�an runas enanas se "
  	"revelan como alegres esconchones, fruto quiz�s de la persistencia de "
  	"alg�n cliente descontento.\n"));
  AddExit("norte", ATB_CI("ciudad13"));
  AddExit("este", ATB_CI("ciudad14"));
  AddExit("sur", ATB_CI("ciudad01"));
  AddExit("oeste", ATB_CI("ciudad00"));
  AddExit("entrar", ATB_CI("fragua"));
}

