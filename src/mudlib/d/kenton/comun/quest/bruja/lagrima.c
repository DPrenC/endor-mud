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
  AddId("lágrima");
  AddId("quest_lagrima_bruja");
  SetShort("una lágrima");
  SetLong(W("Es una lágrima, derramada por Tamara, la humana de belleza legendaria, "
  "al ver que su problema con Altur se habia solucionado gracias a tí.\n"));
  SetWeight(30);
  Set(P_NOSELL,"Te da pena venderla, a lo mejor te es de utilidad.\n");
  Set(P_NODROP,"Prefieres quedártela como un recuerdo.\n");
  Set(P_AUTOOBJECT,1);
}
