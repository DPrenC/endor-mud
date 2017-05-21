/*
DESCRIPCION  : bota
FICHERO      : /d/kenton/comun/quest/bruja/bota.c
MODIFICACION : 20-9-00 [Maler] Creacion.
--------------------------------------------------------------------------------
*/

inherit THING;
#include "path.h"
#include <properties.h>

create() {
  ::create();
  AddId("bota");
  AddId("quest_bota_bruja");
  SetShort("una bota");
  SetLong(W("Es una bota pequeña, más o menos del tamaño de un kender, parece estar "
  "muy desgastada por el uso, dirías que ha visto tiempos mejores. Tiene el nombre 'Turon' en "
  "uno de los lados.\n"));
  Set(P_NOGIVE);
  Set(P_NOSELL);
  Set(P_NODROP);
  SetWeight(50);
}
