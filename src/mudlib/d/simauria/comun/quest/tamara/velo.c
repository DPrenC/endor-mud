/*
DESCRIPCION  : el velo de tamara
FICHERO      : /d/simauria/comun/quest/tamara/velo.c
MODIFICACION : 14-9-00 [Maler] Creacion.
14/01/2005: [kastwey@simauria]: lo modifico un poquito para añadirle el move.
--------------------------------------------------------------------------------
*/
#include "path.h"
#include <properties.h>
#include <moving.h>


inherit THING;

create() {
  ::create();
  AddId("velo");
  AddId("quest_velo_tamara");
  AddAdjective("negro");
  SetShort("un velo negro");
  SetLong(W("Es un velo negro, esta finamente hilado, es muy ligero y parece cómodo. "
	"Una mujer estaría cómoda con esto.\n"));
  SetWeight(100);
  SetValue(5);
  Set(P_CANT_STEAL,1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
}

public varargs int move(mixed dest, int method, mixed extra)
{
	if (method == M_GIVE && !dest->QueryTamaraQuest()) return ME_NO_GIVE;
	return ::move(dest, method, extra);
}
