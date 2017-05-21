// DESCRIPCION  : tronco de arbol
// MODIFICACION : 28-05-2008 [Angor] Creacion

#include "path.h"
//#include AK_MACRO
#include <properties.h>
inherit THING;

create () {
  ::create();
  replace_program();
  SetShort("un gran tronco de �rbol");
  SetLong(
  "Es un gran tronco de �rbol tumbado en el suelo. Por la forma del corte se "
  "ve que ha sido talado. Probablemente esta aqu� a la espera de ser cortado "
  "en piezas mas peque�as como tablones o planchas.\n");
  SetIds(({"tronco","arbol","�rbol"}));
  SetWeight(100000);
  SetValue(100);
}
