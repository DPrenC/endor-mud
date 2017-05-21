/***************************************************************************************
 ARCHIVO:	cebo.c
 AUTOR:		[z] Zomax
 FECHA:		07-01-2002
 COMENTARIOS:	Cebo para pescar.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

public int cebo;

create () {
 ::create();

  SetShort("cebo para pescar");
  SetLong(W("Es el cebo típico que usan los pescadores de Koek. Parece una mezcla de "
  	"insectos y gusanos de la zona. La verdad es que esperas que no se mueva mucho "
  	"en tu bolsillo.\n"));
  AddSubDetail(({"insecto","insectos","gusano","gusanos"}),W("Esperas por todos los dioses "
  	"que no se muevan mucho en tu bolsillo.\n"));
  SetIds(({"cebo","cebo para pescar"}));
  Set(P_GENDER,GENERO_NEUTRO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(50);
  SetValue(100);
  cebo=10;
}

int fmenos()
{
	cebo--;
	if (cebo==0)
	{
		write("Acabas tu último cebo.\n");
		TO->remove();
	}
	else if (cebo==1)
	{
		SetLong(W("Es el cebo típico que usan los pescadores de Koek. Parece "
			"una mezcla de insectos y gusanos de la zona. La verdad es que "
			"esperas que no se mueva mucho en tu bolsillo. Te queda muy poco, "
			"quizás lo suficiente para cebar la caña una última vez.\n"));
	}
	else if (cebo>1)
	{
		SetLong(W("Es el cebo típico que usan los pescadores de Koek. Parece "
			"una mezcla de insectos y gusanos de la zona. La verdad es que "
			"esperas que no se mueva mucho en tu bolsillo. Queda suficiente "
			"para cebar la caña "+cebo+" veces.\n"));
	}
	return cebo;
}

int QueryCantidadCebo()
{
	return cebo;
}
