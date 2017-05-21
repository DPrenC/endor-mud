/***************************************************************************************
 ARCHIVO:	tabaco.c
 AUTOR:		[z] Zomax
 FECHA:		19-12-2001
 COMENTARIOS:	Un poco de tabaco picado
 ***************************************************************************************/

#include "path.h"
#include <properties.h>


inherit THING;

public int cantidad_tabaco;

public void create ()
{
  ::create();

  SetShort("un poco de tabaco picado");
  SetLong(W("Es un montoncito de tabaco picado. Tiene un aroma tan fuerte que te marea.\n"));
  SetIds(({"tabaco","tabaco picado","tabaco_picado"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(50);
  SetValue(500);
  cantidad_tabaco=10;
}

int fmenos()
{
	cantidad_tabaco--;
	if (cantidad_tabaco==0)
	{
		write(W("Acabas tu último montón de tabaco.\n"));
		TO->remove();
	}
	else if (cantidad_tabaco==1)
	{
		SetLong(W("Es un montoncito de tabaco picado. Tiene un aroma tan fuerte "
		"que te marea. Sólo te queda un poco, quizás lo suficiente para una ultima "
		"pipa.\n"));
	}
	else if (cantidad_tabaco>1)
	{
		SetLong(W("Es un montoncito de tabaco picado. Tiene un aroma tan fuerte "
		"que te marea. Te queda suficiente como para llenar "+cantidad_tabaco+" "
		"pipas.\n"));
	}
	return cantidad_tabaco;
}

int QueryCantidadTabaco()
{
	return cantidad_tabaco;
}
