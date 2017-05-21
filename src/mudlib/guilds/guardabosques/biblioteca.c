#include "./path.h"
inherit "/room/bibl_room";

prestado()
{
  write("Este libro no est� disponible en estos momentos.\n"
  	"Rogamos disculpen las molestias.\n");
  return 1;
}


create () {
  ::create();
  SetIntShort("la biblioteca del gremio de Guardabosques");
  SetIntLong(W("Est�s en la biblioteca del gremio de los Guardabosques. En "
  	"estos libros encontrar�s valiosa informaci�n sobre el gremio y sus "
  	"habilidades, e incluso algo de historia para aquellos que deseen "
  	"enriquecer su esp�ritu.\n"));

  SetTema("Informaci�n del Gremio");
  AddBook("Generalidades","Visi�n global del Guardabosque", BASE+"docs/historia", 1);
  AddBook("Habilidades","Las habilidades de los Guardabosques", BASE+"docs/habilidades", 1);
  AddExit("oeste", BASE+"gremio");
}

