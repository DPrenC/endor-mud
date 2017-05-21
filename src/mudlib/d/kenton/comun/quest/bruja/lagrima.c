/*
DESCRIPCION  : lagrima de la felicidad
FICHERO      : /d/kenton/comun/quest/bruja/lagrima.c
MODIFICACION : 19-9-00 [Maler] Creacion.
--------------------------------------------------------------------------------
*/
inherit THING;
#include "path.h"
#include <properties.h>
create() {
  ::create();
  AddId("lagrima");
  AddId("l�grima");
  AddId("quest_lagrima_bruja");
  SetShort("una l�grima");
  SetLong(W("Es una l�grima, derramada por Tamara, la humana de belleza legendaria, "
  "al ver que su problema con Altur se habia solucionado gracias a t�.\n"));
  SetWeight(30);
  Set(P_NOSELL,"Te da pena venderla, a lo mejor te es de utilidad.\n");
  Set(P_NODROP,"Prefieres qued�rtela como un recuerdo.\n");
  Set(P_AUTOOBJECT,1);
}
