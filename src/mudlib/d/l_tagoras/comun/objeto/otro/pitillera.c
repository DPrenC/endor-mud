#include <properties.h>
#include <combat.h>

#define P_PITILLOS P_AUX1
#define DEF_PITILLOS 20

inherit THING;

public int cmd_fumar(string str);

public string QueryLong()
{
	string str;

	str = "Es una pitillera con capacidad para "+DEF_PITILLOS+" cigarrillos.\n";
	if (Query(P_PITILLOS)==0)
		str += "Desgraciadamente está vacía.\n";
	else
		if (Query(P_PITILLOS)==1)
			str += "Queda un último cigarrillo. Mejor que lo reserves para una ocasión especial.\n";
		else
			if (Query(P_PITILLOS)<DEF_PITILLOS)
				str += "Aún quedan "+itoa(Query(P_PITILLOS))+" cigarrillos.\n";
			else
				str += "Está llena; no cabe ni un cigarrillo más.\n";

	return str;
}

public string QueryShort()
{
	return "una pitillera de alpaca ("+Query(P_PITILLOS)+")";
}

create()
{
	::create();

	SetShort("una pitillera de alpaca");
	Set(P_PITILLOS, DEF_PITILLOS);
	AddId("pitillera");
	SetAds(({"una", "de", "alpaca"}));
	SetWeight(250);
	SetValue(200+10*Query(P_PITILLOS));
	SetSize(P_SIZE_SMALL);
}

init()
{
	::init();

	add_action ("cmd_fumar", "fumar");
}

public int cmd_fumar(string str)
{
	if (!str) 
		return notify_fail("¿Fumar QUE?\n", NOTIFY_ILL_ARG);
	if ((LOWER(str) != "cigarrillo") && (LOWER(str) != "cigarillo") && (LOWER(str) != "pitillo"))
		return notify_fail("¿Fumar QUE?\n", NOTIFY_ILL_ARG);
	else
	{
		if (Query(P_PITILLOS) == 0)
			return notify_fail("Maldición, no te quedan cigarrillos.\n", NOTIFY_NOT_VALID);
		else
		{
			Set(P_PITILLOS, Query(P_PITILLOS)-1);
			SetValue(200+10*Query(P_PITILLOS));
			write ("Te fumas un cigarrillo y exhalas las volutas de humo formando graciosas figuras en el aire.\n");
			say (CAP(TNAME)+" se fuma un cigarrillo.\n", TP);
			write ("Empiezas a toser y notas que los pulmones rechazan el tabaco.\n");
			say (CAP(TNAME)+" tose. Parece que se le escapa la vida por la boca.\n", TP);
			//TP->Defend(10);
			TP->Defend(50+random(50), DT_POISON, DEFEND_F_NOMSG);
			return 1;
		}
	}
	return 0;
}
