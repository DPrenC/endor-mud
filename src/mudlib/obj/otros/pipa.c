/*
 ARCHIVO:	pipa.c
 AUTOR:		Aulë
 FECHA:		13/09/2014
 Descripción:	
 una pipa para fumar.
 */

#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("una pipa");
  SetLong(W("Es una pipa sencilla tallada en madera de unos treinta centímetros de "
  "longitud.\n"));
  SetIds(({"pipa"}));
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(120);
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
			write(W("Coges un buen pellizco de tabaco de tu bolsa "
			"y rellenas tu pipa cuidadosamente .\n"
			"Acto seguido la enciendes y empiezas a fumar con gran placer.\n"
			"Inspiras con deleite, disfrutando del tabaco y expeliendo algunos anillos de humo "
			"que ascienden lentamente.\n"));
			say(W(CAP(TNAME)+" echa mano de la bolsa del tabaco y rellena su pipa lenta y cuidadosamente.\n"
			"A continuación la enciende y se lleva la boquilla a los labios aspirando con deleite.\n"
			"El humo de la pipa forma algunos anillos de humo que ascienden lentamente.\n"),TP);
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
			notify_fail(W("Echas mano a la bolsa del tabaco pero ya no te queda.\n"));
			return 0;
		}
	}
	else
	{
		notify_fail(W("¿Pero tú estás bien?\n"));
		return 0;
	}
}
