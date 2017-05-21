/*
Fichero: tabaco.c
Autor: Aulë
Fecha: 20/10/2014
Descripción: tabaco para pipa
*/

#include <properties.h>


inherit THING;

public int cantidad_tabaco;

public void create ()
{
  ::create();

  SetShort("una porción de tabaco para pipa");
  SetLong(W("Es una porción de tabaco tratado y picado, listo para fumar en pipa.\n"));
  SetIds(({"tabaco","tabaco picado","tabaco_picado", "tabaco de pipa"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(40);
  SetValue(100);
  cantidad_tabaco=10;
}

int fmenos()
{
	cantidad_tabaco--;
	if (cantidad_tabaco==0)
	{
		write(W("Fumas la última porción de tabaco que te quedaba.\n"));
		TO->remove();
	}
	else if (cantidad_tabaco==1)
	{
		SetLong(W("Es una porción de tabaco tratado y picado, listo para fumar en pipa.\n"
		"Calculas que solo te queda lo suficiente para fumar una pipa.\n"));
	}
	else if (cantidad_tabaco>1)
	{
		SetLong(W("Es una porción de tabaco tratado y picado, listo para fumar en pipa.\n"
		"Calculas que tienes lo suficiente como para llenar "+cantidad_tabaco+" "
		"pipas.\n"));
	}
	return cantidad_tabaco;
}

int QueryCantidadTabaco()
{
	return cantidad_tabaco;
}
