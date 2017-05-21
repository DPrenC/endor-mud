/*
DESCRIPCION  : El Mapa hacia la tumba de erkil
FICHERO      : /guilds/hechiceros/quest/proyectilelectrico/mapa.c
MODIFICACION : 14-6-00 [Maler] Creacion.
19/01/2005 [kastwey@simauria] Pongo aquí un move, para que solo
puedas darle el mapa a forlafil.
--------------------------------------------------------------------------------
*/

inherit "std/thing";
#include <properties.h>
#include <moving.h>
#include "path.h"

create() {
  ::create();
  AddId("mapa");
  AddId("spell_proyectil_arandil");
  SetShort("un Mapa");
  SetLong(W("Es el mapa con la localizacion de la entrada a la tumba de Erkil. "
  "Parece muy importante.\n"));
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  SetWeight(30);
}


public varargs int move(mixed dest, int method, mixed extra)
{
	if (method == M_GIVE && !dest->QueryArandil()) return ME_NO_GIVE;
	return ::move(dest, method, extra);
}
