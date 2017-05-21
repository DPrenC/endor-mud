/*
DESCRIPCION  : El Mapa hacia la tumba de erkil
FICHERO      : /guilds/hechiceros/quest/proyectilelectrico/mapa.c
MODIFICACION : 14-6-00 [Maler] Creacion.
19/01/2005: [kastwey]: pongo un move para que solo puedas darle el sello a forlafil
--------------------------------------------------------------------------------
*/

inherit "std/thing";
#include <properties.h>
#include <moving.h>
#include "path.h"

create() {
  ::create();
  AddId("sello");
  AddId("sello_proyectil_arandil");
  SetShort("un sello");
  SetLong(W("Es el sello de Arandil, no parece tener ningún valor. "
  "Parece muy importante.\n"));
  SetWeight(30);
}


public varargs int move(mixed dest, int method, mixed extra)
{
	if (method == M_GIVE && !dest->QueryForlafil()) return ME_NO_GIVE;
	return ::move(dest, method, extra);
}
