/* Nido de Wyvelt (pajarraco)
   Theuzifan, 01-10-99, Creación
*/

#include "path.h"

inherit THING;

create()
{
  ::create();
  SetShort("un nido de Wyvelt");
  SetLong(W("Es una enorme nido de Wyvelt. Está hecho a base de ramas más "
  	"bien grandes, y aunque no ha sido usado en mucho tiempo, está en "
  	"buen estado.\n"));
  SetIds(({"nido"}));

  SetWeight(6000);
  SetNoGet("No puedes cogerlo, es demasiado pesado.\n");
}