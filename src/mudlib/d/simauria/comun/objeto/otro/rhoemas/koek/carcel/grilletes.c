/***************************************************************************************
 ARCHIVO:	grilletes.c
 AUTOR:		[z] Zomax
 FECHA:		22-12-2001
 COMENTARIOS:	Unos grilletes para que los players no se escapen al ser apresados
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
  ::create();

  SetShort("unos grilletes");
  SetLong(W("Son unos grilletes de hierro muy resistentes que usan los patrulleros "
  	"y guardias de Koek para tener controlados a los delincuentes cuando los "
  	"llevan a la cárcel.\n"));
  SetIds(({"grilletes"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(0);
  SetValue(0);
}

int fescapar(string str)
{
	write(W("Intentas quitarte los grilletes y escapar, pero tienes los movimientos tan "
		"limitados que no consigues abrirlos.\n"));
	say(W(CATP+" intenta quitarse los grilletes y escapar, pero no lo consigue.\n"),TP);
	return 1;
}

int fsalidas(object envi_preso)
{
	int i;
  	string *salidas;
  	salidas=m_indices(envi_preso->QueryExits());
  	for (i=0;i<sizeof(salidas);i++)
  	{
  		add_action("fescapar",salidas[i]);
  	}
  	return 1;
}
