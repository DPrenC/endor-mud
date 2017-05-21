/***************************************************************************************
 ARCHIVO:	pipa.c
 AUTOR:		[z] Zomax
 FECHA:		19-12-2001
 COMENTARIOS:	Una pipa (de las de fumar, claro)
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("una pipa");
  SetLong("Es una bonita pipa de madera muy bien tallada para fumar.\n");
  SetIds(({"pipa"}));
  SetDieMsg("#jug# ha muerto de un ataque de tos de tanto fumar.");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(50);
  SetValue(100);
  SetMaterial(M_MADERA);
}

init(){
  ::init();
  add_action("ffumar","fumar");
}

int ffumar(string str)
{
	if (!str || str=="tabaco")
	{
		object tabaco;
		tabaco=present(("tabaco"),TP);
		if(tabaco)
		{
			write(W("Coges algo de tabaco de tu bolsillo y lo "
			"pones dentro de la pipa. Lo prendes y empiezas a fumar.\n"
			"Haces unos cuantos círculos con el humo para disfrute del "
			"personal.\n"));
			say(W(CATP+" coge algo de tabaco, lo pone en su pipa, lo "
			"prende y empieza a fumar. Hace unos cuantos círculos "
			"concéntricos con el humo y termina de fumar más relajado.\n"),TP);
			tabaco->fmenos();
			TP->AddTP(-25);
			if (TP->QueryHP()>5)
			{
				TP->AddHP(-5);
			}
			else
			{
				TP->Die();
			}
			return 1;
		}
		else
		{
			notify_fail("No te queda tabaco que fumar.\n");
			return 0;
		}
	}
	else
	{
		notify_fail("¿Pero tú estás bien?\n");
		return 0;
	}
}
