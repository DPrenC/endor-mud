/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:enteste.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creación                         * */
/* **************************************************************** */

#include <moving.h>
#include <nightday.h>
#include "path.h"

inherit SIM_ROOM;

object *ob;
int i,estatua,amuleto;

create() {
::create();
SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Estás al este de de la entrada a las antiguas ruinas de la "
"torre de Gundistyr. Todas las salidas están bloqueadas exceptuando la que "
"te lleva hacia el oeste. Al norte tienes los restos de lo que en su dia "
"fue un alto muro, ahora no es más que un simple montón de piedras...\n"));
AddDetail(({"ruinas","ruina","torre"}),W("Hacia el norte ves los restos de la "
"torre.\n"));
AddDetail(({"piedras","monton de piedra", "montónes de piedra","montón "
"piedra","monton piedra"}),W("Simplemente son un montón de piedras "
"que te impiden seguir hacia el norte y el este.\n"));
SetIntNoise("Únicamente escuchas una suave brisa.\n");
SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"agradable hierba.\n"));
AddItem(GOBJETO("otro/gundistyr/estagar"));
AddExit("oeste","enttorre");
AddRoomCmd("alzar","cmd_alzar");
}

int fgargola(int estado,object amuleto,object estatua)
{
	if (!estado)
	{
		write("Alzas el amuleto, pero no ocurre nada.\n");
		return 1;
	}
	else
	{
		write(W("Alzas el amuleto sobre tu cabeza. Observas como la luz de la "
		"luna se refleja sobre él y se proyecta sobre la tenebrosa estatua de "
		"la gárgola que se levanta frente a ti. Lentamente la piel de la gárgola "
		"comienza a tomar tonos oscuros y empieza a moverse lentamente. ¡Está viva! "
		"De repente notas como el amuleto que sostienes con tus manos se fragmenta "
		"en miles de pedazos.\n"));
		say(W(capitalize(TP->QueryRealName())+" alza un amuleto sobre su cabeza y la "
		"luz de la luna se proyecta sobre él y se proyecta sobre la tenebrosa estatua de "
		"la gárgola que se levanta frente a ti. Lentamente la piel de la gárgola "
		"comienza a tomar tonos oscuros y empieza a moverse lentamente. ¡Está viva! "
		"El amuleto desaparece entre sus dedos.\n"));
		amuleto->remove();
		estatua->remove();
		clone_object(PNJGD("gargola"))->move(TO,M_SILENT);
		return 1;
	}
}

int cmd_alzar (string str)
{
	object amuleto,estatua,falso;
	if (str=="amuleto")
	{
		amuleto=present("q_amuleto_gargola",TP);
		estatua=present("q_estatua_gargola",TO);
		falso=present("amuleto",TP);
		if (!amuleto)
		{
			if (falso)
			{
				notify_fail("Alzas el amuleto, pero no ocurre nada.\n");
				return 0;
			}
			else
			{
				notify_fail("¿Qué amuleto?\n");
				return 0;
			}
		}
		else if (!estatua)
		{
			notify_fail("Alzas el amuleto, pero no ocurre nada.\n");
			return 0;
		}
		else
		{
			switch(NIGHTDAY->QueryState())
			{
				case ND_NIGHT:		fgargola(1,amuleto,estatua);	break;
				case ND_FALL:		fgargola(1,amuleto,estatua);	break;
				case ND_PRENIGHT:	fgargola(1,amuleto,estatua);	break;
				case ND_PREDAWN:	fgargola(1,amuleto,estatua);	break;
				case ND_DAWN:	fgargola(1,amuleto,estatua);	break;
				default:		fgargola(0,amuleto,estatua);	break;
			}
			return 1;
		}
	}
}
