#include "path.h"
inherit THING;

create()
{
  ::create();


  SetLong("Es un enorme árbol, quizá uno de los Grandes Árboles. La madera "
  	"es demasiado lisa para poder escalarla. Quizás si le lanzases una "
  	"cuerda sería más facil de escalar.\n");
  SetShort("un enorme árbol");
  SetIds(({"arbol", "árbol", "arbol legendario", "árbol legendario"}));
  AddSubDetail("nido", "Desde aquí parece un nido.\n");
  AddSubDetail(({"ramas", "rama"}), "Podrías subirte a lo alto "
  	"del árbol si tuvieses una cuerda para lanzarla.\n");
  SetNoTake("No puedes cogerlo. Ni con toda la fuerza del mundo.\n");

}
