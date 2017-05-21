/* Nido de Wyvelt (pajarraco)
   Theuzifan, 01-10-99, Creaci�n
*/

#include "path.h"

inherit THING;

create()
{
  ::create();
  SetShort("un nido de Wyvelt");
  SetLong(W("Es una enorme nido de Wyvelt. Est� hecho a base de ramas m�s "
  	"bien grandes, y aunque no ha sido usado en mucho tiempo, est� en "
  	"buen estado.\n"));
  SetIds(({"nido"}));

  SetWeight(6000);
  SetNoGet("No puedes cogerlo, es demasiado pesado.\n");
}