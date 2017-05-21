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
  SetIntShort("la biblioteca del gremio de Guardabosques");
  SetIntLong(W("Estás en la biblioteca del gremio de los Guardabosques. En "
  	"estos libros encontrarás valiosa información sobre el gremio y sus "
  	"habilidades, e incluso algo de historia para aquellos que deseen "
  	"enriquecer su espíritu.\n"));

  SetTema("Información del Gremio");
  AddBook("Generalidades","Visión global del Guardabosque", BASE+"docs/historia", 1);
  AddBook("Habilidades","Las habilidades de los Guardabosques", BASE+"docs/habilidades", 1);
  AddExit("oeste", BASE+"gremio");
}

