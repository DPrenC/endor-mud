#include "path.h"
inherit THING;

create()
{
  ::create();


  SetLong("Es un enorme �rbol, quiz� uno de los Grandes �rboles. La madera "
  	"es demasiado lisa para poder escalarla. Quiz�s si le lanzases una "
  	"cuerda ser�a m�s facil de escalar.\n");
  SetShort("un enorme �rbol");
  SetIds(({"arbol", "�rbol", "arbol legendario", "�rbol legendario"}));
  AddSubDetail("nido", "Desde aqu� parece un nido.\n");
  AddSubDetail(({"ramas", "rama"}), "Podr�as subirte a lo alto "
  	"del �rbol si tuvieses una cuerda para lanzarla.\n");
  SetNoTake("No puedes cogerlo. Ni con toda la fuerza del mundo.\n");

}
