#include "./path.h"
inherit "/room/bibl_room";

prestado()
{
  write("Este libro no está disponible en estos momentos.\n"
  	"Rogamos disculpen las molestias.\n");
  return 1;
}


create () {
  ::create();
  SetLocate("Gremio de hechiceros");
  SetIntShort("la biblioteca del gremio de Hechiceros");
  SetIntLong(W("Estás en la biblioteca del gremio de los Hechiceros. En "
  	"estos libros encontrarás valiosa información sobre el gremio y sus "
  	"habilidades, e incluso algo de historia para aquellos que deseen "
  	"enriquecer su espíritu.\n"));


  AddExit("nordeste","./esca1");
}

