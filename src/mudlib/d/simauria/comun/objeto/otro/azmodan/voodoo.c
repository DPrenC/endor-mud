/***********************************************************/
//	"voodoo"
//	mu�eco vud�
//	27-11-01 : Creaci�n -> Kodex
//	16-12-01 : Modificaci�n -> Kodex
//		*Arregladas las cosas que pidi� mirill:
//		 no afecta a otros jugadores y reducci�n
//		 del da�o de 25-40 a 15-30.
//
inherit THING;
#include <properties.h>
#include "./path.h"

object target,aguja,colgante;

int tengo_aguja()
{
	aguja = present("aguja",TP);
	if (aguja)
		return 1;
	else
		return 0;
}


int tengo_colgante()
{
	colgante = present("colgante",TP);
	if (!colgante) return 0;
	if (colgante->QueryEquipped() == TP)
		return 1;
}

int danyar(string str)
{
if (str	== "aguja en mu�eco")
	{
	if (environment(TO) != TP) return notify_fail("No tienes mu�eco al que clavarle una aguja.\n");
		if (living(target))
			{
				if (tengo_aguja())
					{
						target->AddHP(-15 - random(16));
						write("Clavas una aguja con fuerza en tu mu�eco vud�!!!\n");
						say(capitalize(TP->QueryRealName()) + " saca un mu�eco vud� y lo atraviesa con una aguja!!!\n");
						tell_object(target, "Sientes un fuerte dolor en el pecho y no te explicas por qu�!!!\n");
						tell_room(environment(target),capitalize(target->QueryRealName())+" se retuerce de dolor!!!\n",({target}));
						aguja->remove();
						return 1;
					}
				else
					return notify_fail("No tienes agujas de vud� para clavar.\n");
			}
		else
			return notify_fail("Objetivo no v�lido.\n");
	}
else
	return notify_fail("Quiz� deber�as intentar clavar 'aguja en mu�eco'.\n");
}

int maldicion(string str)
{
	object targ;
	if (!str) return notify_fail("maldecir quien???\n");
	if (environment(TO) != TP) return notify_fail("No tienes mu�eco vud� necesario para la maldici�n.\n");
	if (tengo_colgante())
		{
		targ = present(str,environment(TP));
		if (targ == find_object(lower_case(str))) return notify_fail("Objetivo no v�lido.\n");
		if (living(targ))
			{
				if (TP->QuerySP() >= 40)
                				{
                				write("Agitas tu colgante de huesos para maldecir a " + capitalize(targ->QueryRealName()) + ".\n");
                				say(capitalize(TP->QueryRealName()) + " agita su colgante de huesos y pronuncia unas palabras.\n");
                				target = targ;
						SetLong(W("Es un peque�o mu�eco de paja utilizado en ritos de magia negra.\nTiene un parecido sorprendente a "+ capitalize(targ->QueryRealName())+".\n"));
						TP->AddSP(-40);
						return 1;
						}
					else
					return notify_fail("No tienes suficientes puntos de magia.\n");
			}
		else
			return notify_fail("Objetivo no v�lido.\n");
		}
	else
		return notify_fail("No tienes ning�n colgante de huesos puesto.\n");
}

create()
{
::create();
SetShort("un mu�eco vud�");
SetLong("Es un peque�o mu�eco de paja utilizado en ritos de magia negra.\n");
SetIds(({"mu�eco","mu�eco vud�","mu�eco vudu"}));
Set(P_GENDER,GENERO_MASCULINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetWeight(250);
Set(P_NOSELL);
}

init()
{
::init();
add_action("maldicion","maldecir");
add_action("danyar","clavar");
}