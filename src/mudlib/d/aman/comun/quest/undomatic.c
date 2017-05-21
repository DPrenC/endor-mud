/* Pluma de Wyvelt (pajarraco)
   Theuzifan, 30-09-99, Creación
*/

#include "path.h"
#include <properties.h>


inherit THING;

cmd_hacer(string str)
{
  if (!str) return 0;
  tell_object(TI, "No puedes hacer eso aqui.\n");
  return 1;
}
create()
{
  ::create();
  SetShort("undomatic(r)");
  SetLong(W("Esto es el undomatic(r) y sirve para que no puedas poner 'hacer#20 buscar'.\n"));
  SetIds(({"undomatic"}));
  SetWeight(0);
  SetInvis(10);
  Set(P_MAGIC, 1);
}
init()
{
  ::init();
  add_action("cmd_hacer", "hacer");
}