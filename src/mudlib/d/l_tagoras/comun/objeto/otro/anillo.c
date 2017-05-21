/* vi: set tabstop=4 */
/** @file armadura_test.c
	@brief el anillo de Sharanna
	@author SimBuilder
	@version 1.00
	@date 2009-02-08
Con este anillo, el wizard (s√≥lo wizards) puede controlar las acciones de Rak-nal-turi
Mayormente copiado del brazaletede las kisalas.
TOOD: No s√© poqu√© no se puede equipar el anillo y tampoco potque una verificaci√≥n del entrono en el init no va.

	Puedes ver que este anillo dorado lleva inscrita una leyenda grabada por la mism√≠sima diosa Sharanna.
*/

inherit ARMOUR;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

static object wizard;

object QueryObjectOwner() { return wizard; }

object SetObjectOwner(object wiz)
{
	if (!wiz || !query_once_interactive(wiz)) return 0;
	return wizard=wiz;
}

create()
{
	::create();
	SetStandard(AT_ANILLO, 0, P_SIZE_GENERIC, M_ORO);
	SetShort("el anillo de Sharanna");
	SetLong("Puedes ver que este anillo dorado lleva inscrita una leyenda grabada por la mismÌsima diosa Sharanna.\n");
	AddAdjective(({"de sharanna"}));
	AddSubDetail(({"leyenda"}),"El portador de este anillo controlar· el destino de Rak-nal-turi.\n");
	if (TP)
	{
		SetObjectOwner(TP);
		if (!query_wiz_level(TP)) call_out("remove", 1);
	}
}

void autodest()
{
	destruct(TO);
	return;
}

public void init()
{
	object ob;

	::init();
	if (!TP) return;
//	if (!(ob = environment()) || !query_once_interactive(ob))
//	{
//		call_out("autodest",2);
//	}
	ob=QueryObjectOwner();
	if (ob && ob==TP)
	{
		add_action("cmd_telepatia","tel");
		add_action("cmd_telepatia","telepatia");
	}
}

int cmd_telepatia(string str)
{
	string comando;
	object rak;

	if (!str ||str == "") return 0;
	if ((sscanf(LOWER(str),"rak-nal-turi %s", comando) == 1) || (sscanf(LOWER(str),"rak %s", comando) == 1))
	{
		if (0 == sizeof(clones("/d/l_tagoras/comun/pnj/rak-nal-turi.c")))
			write("Rak-nal-turi no est· cargado.\n");
		else
		{
			rak = clones("/d/l_tagoras/comun/pnj/rak-nal-turi.c")[0];
			if (!rak) return 0;
			else
			{
				rak->RakExec(TP, comando);
				return 1;
			}
		}
	}
	return 0;
}
