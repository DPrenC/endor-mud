/**************************************************************************
fichero: altriv.c
Autor: Tagoras.
Creaci�n: 06/03/2009
Descripci�n: Altriv
**************************************************************************/

#include "./path.h"
#include <guild.h>
#include <properties.h>
#include <combat.h>

inherit PNJ_CENTRO_ANNUFAM("base_militar");
inherit "/lib/money";

#define GRI_BULLSSTRENGTH	"_bullsstrength"
#define GRI_GUILDS			({GC_CLERIGO, GC_GUARDABOSQUE, GC_GUERRERO, GC_CONJURADOR, GC_HECHICERO})
#define GRI_COST			25000
#define GRI_COST_STR		"cinco monedas de mithril"

public string chat_grimorio()
{
	object * players;
	object choosen;
	object grimorio;

	players = filter(filter(all_inventory(environment()), (:query_once_interactive($1):)), (:-1<member(GRI_GUILDS, $1->QueryGuild()):));
	// Cogemos un player al azar
	if (sizeof(players))
	{
		choosen = players[random(sizeof(players))];
		if (grimorio = present("grimorio", choosen))
		{
			if (!grimorio->HasSpell(GRI_BULLSSTRENGTH))
				return CAP(choosen->QueryRealName())+", te puedo ense�ar como tener la fuerza de un toro por "+GRI_COST_STR".\nSeguro que te es muy �til.\nSi lo deseas, escribe: aprender fuerza de toro\n";
			else
				return "Bien, bien, veo que ya sabes como tener la fuerza de un toro, "+CAP(choosen->QueryRealName())+".\n";
		}
		else
			return "Si tuvieras un grimorio, "+CAP(choosen->QueryRealName())+", te podr�a ense�ar alg�n truquillo, jeje.\n";
	}
	else
		return "Humpf!!!\n";
}

public void create()
{
    ::create();

    seteuid(getuid());

    SetStandard("Altriv", "enano", ([GC_GUERRERO:110]), GENDER_MALE);
    AddId(({"altriv", "director"}));
    SetShort("Altriv, el director del centro");
    SetLong("Ves a Altriv, el director del centro de adiestramiento de guerreros enanos, y un escalofr�o te recorre el cuerpo. Est�s seguro de que es uno de los seres m�s fuertes que has visto nunca. Puedes advertir sus m�sculos a trav�s de su ropa y tambi�n las cicatrices que tantos a�os de lucha contra los orcos han dejado en su piel. En sus ojos se refleja todo el caos y destrucci�n de la guerra, pero tambi�n el brillo de la astucia y la inteligencia. Sin lugar a dudas, Altriv no es un enano como los dem�s.\n");
    InitChats(3,({
		"Altriv repasa unos planes de invasi�n y murmura algo incomprensible.\n",
		"Altriv alza la vista y clava sus ojos en t� petrific�ndote de terror.\n",
		#'chat_grimorio}));
	AddItem(ARMA_CENTRO_ANNUFAM("hacha_altriv"),REFRESH_REMOVE,SF(wieldme));
	AddItem(PROT_CENTRO_ANNUFAM("amuleto_altriv"),REFRESH_REMOVE,SF(wearme));
	AddItem(PROT_CENTRO_ANNUFAM("uniforme_altriv"),REFRESH_REMOVE,SF(wearme));
	SetGoChance(50);
	AddWalkZones(({HAB_TERCERA_ANNUFAM("c213"), HAB_TERCERA_ANNUFAM("c214"), HAB_TERCERA_ANNUFAM("c215")}));
}

public void init()
{
	::init();
	add_action("cmd_aprender", "aprender");
}

public varargs void Die(mixed silent)
{
	object hacha;

	if (QueryKiller())
	{
		hacha = present("hacha");
		hacha->SetOwner(QueryKiller()->QueryRealName());
		hacha->move(environment(TO));
		say ("Altriv, moribundo, deja caer su pesada hacha.\n");
	}
	::Die(silent);
}

public int cmd_aprender(string str)
{
	object grimorio;

	if (!str || !strlen(trim(str)))
		return notify_fail("Altriv te dice: �Aprender qu�?\n", NOTIFY_ILL_ARG);
	if (LOWER(trim(str)) != "fuerza de toro")
		return notify_fail("Altriv te dice: Lo siento, pero no conozco ese conjuro.\n", NOTIFY_ILL_ARG);
	if (!(grimorio = present("grimorio", TP)))
		return notify_fail("Altriv te dice: Si no tienes un grimorio, no podr�s guardar el conjuro.\n", NOTIFY_NOT_OBJ);
	if (-1 == member(GRI_GUILDS, TP->QueryGuild()))
		return notify_fail("Altriv te dice: Lo siento, pero los de tu gremio no pueden usar este conjuro.\n", NOTIFY_NOT_VALID);
	if (grimorio->HasSpell(GRI_BULLSSTRENGTH))
		return notify_fail("Altriv te dice: �Pero si ya sabes ese conjuro!\n", NOTIFY_NOT_VALID);
	if (QuerySomeonesValue(TP) < GRI_COST)
		return notify_fail("Altriv te dice: Te costar� "+GRI_COST_STR+". Vuelve cuando los tengas.\n", NOTIFY_NOT_VALID);
	PayValue(TP, GRI_COST);
	write("Le das a Altriv "+GRI_COST_STR+".\nAltriv se acerca y te susurra a la oreja c�mo realizar el conjuro 'fuerza de toro'.\nR�pidamente decides que el conjuro es muy valioso y lo escribes en el grimorio para no olvidarlo.\n");
	say("Altriv se acerca a "+CAP(TNAME)+" y le susurra algo.\n"+CAP(TNAME)+" saca una pluma y escribe algo en su grimorio.\nDesgraciadamente no puedes captar de qu� iba la conversaci�n.\n", ({TP}));
	grimorio->AddSpell(GRI_BULLSSTRENGTH);
	return 1;
}
