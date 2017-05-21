/***************************************************************************************
 ARCHIVO:	incienso.c
 AUTOR:		[z] Zomax
 FECHA:		19-12-2001
 COMENTARIOS:	Un poco de incienso para quemar
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

public int cantidad_incienso;

create () {
 ::create();

  SetShort("un montoncito de incienso");
  SetLong(W("Es un montoncito de incienso. Suele usarse para quemarlo en diferentes "
  	"ofrendas como ritual de purificación. Tiene un olor muy fuerte, pero mientras "
  	"arde el olor se multiplica.\n"));
   SetIds(({"incienso","montoncito de incienso"}));
   Set(P_GENDER,GENERO_MASCULINO);
  SetWeight(50);
  SetValue(500);
  cantidad_incienso=10;
}

int fmenos()
{
	cantidad_incienso--;
	if (cantidad_incienso==0)
	{
		write("Acabas tu último montón de incienso.\n");
		TO->remove();
	}
	else if (cantidad_incienso==1)
	{
		SetLong(W("Es un montoncito de incienso. Tiene un aroma tan fuerte "
		"que te marea. Sólo te queda un poco, quizás lo suficiente para una última "
		"ofrenda.\n"));
	}
	else if (cantidad_incienso>1)
	{
		SetLong(W("Es un montoncito de incienso. Tiene un aroma tan fuerte "
		"que te marea. Te queda suficiente como para realizar "+cantidad_incienso+" "
		"ofrendas.\n"));
	}
	return cantidad_incienso;
}

int QueryCantidadIncienso()
{
	return cantidad_incienso;
}
