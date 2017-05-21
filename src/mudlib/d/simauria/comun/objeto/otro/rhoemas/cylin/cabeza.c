/***************************************************************************************
 ARCHIVO:	cabeza.c
 AUTOR:		[z] Zomax
 FECHA:		27-11-2001
 COMENTARIOS:	Cabeza de la gorgona
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

int sangre;

public int QuerySangre()
{
	return sangre;
}

public int SetSangre(int san)
{
	sangre=san;
	return 1;
}

int frevivir(string str)
{
	if (sangre>=5)
	{
		if (sangre==5)
		{
			SetLong(W(TO->QueryLong()+"Ya no tiene nada "
			"de sangre, se ha secado toda.\n"));
		}
		sangre++;
		notify_fail(W("No puedes revivir nada, la cabeza de Euríale ya no tiene "
		"más sangre, se ha secado toda.\n"));
		return 0;
	}
	else if (environment(TP) && environment(TP)->QueryPlaza()) return 0;
	else
	{
		object pnj;
		pnj=present(str,environment(TP));
		if (pnj)
		{
			if(pnj->QueryEstatua())
			{
				pnj->SetEstatua(0);
				pnj->init();
				write(W("Acercas la cabeza de la gorgona a la estatua "
				"y dejas caer algo de sangre en ella. De repente la "
				"estatua cobra vida.\n"));
				say(W(CATP+" "
				"acerca la cabeza de la gorgona a la estatua y deja "
				"caer algo de sangre en ella. De repente la estatua "
				"cobra vida.\n"),TP);
				sangre++;
				return 1;
			}
			else if(pnj->QueryShort()=="unos escombros")
			{
				notify_fail(W("Es demasiado tarde... alguien ha destrozado la "
				"estatua.\n"));
				return 0;
			}
			else
			{
				notify_fail(W("No se puede revivir a "+pnj->QueryShort()+", no es "
				"una estatua.\n"));
				return 0;
			}
		}
		else if(!str)
		{
			notify_fail("¿Revivir qué?\n");
			return 0;
		}
		else
		{
			notify_fail(W("No encuentras nada llamado "+capitalize(str)+".\n"));
			return 0;
		}
	}
}

create () {
  ::create();

  SetShort("la cabeza de Euríale");
  SetLong(W(
  "Observas la cabeza de Euríale, intentando desviar la mirada de sus ojos, no sea "
  "cosa que aún pueda hacerte algo. Ves que está cubierta de sangre, y que quizás "
  "aprovechando esto puedas revivir a alguna de sus víctimas, ya que cuenta la leyenda "
  "que la sangre de una gorgona tiene esas propiedades.\n"));
  AddSubDetail(({"sangre"}),"Dicen que su sangre tiene ciertas propiedades.\n");
  SetIds(({"cabeza","cabeza de gorgona"}));
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(5000);
  SetValue(0);
  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  Set(P_CANT_STEAL,1);
  sangre=0;
}

void init() {
  ::init();
  add_action("frevivir","revivir");
}
