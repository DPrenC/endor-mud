// DESCRIPCION  : tronco de arbol
// MODIFICACION : 28-05-2008 [Angor] Creacion

#include "path.h"
//#include AK_MACRO
#include <properties.h>
inherit THING;

create () {
  ::create();
  replace_program();
  SetShort("un gran tronco de árbol");
  SetLong(
  "Es un gran tronco de árbol tumbado en el suelo. Por la forma del corte se "
  "ve que ha sido talado. Probablemente esta aquí a la espera de ser cortado "
  "en piezas mas pequeñas como tablones o planchas.\n");
  SetIds(({"tronco","arbol","árbol"}));
  SetWeight(100000);
  SetValue(100);
}
