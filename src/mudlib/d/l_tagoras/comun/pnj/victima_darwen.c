/*
Targeta de Darwen.
*/

#include "path.h"
#include <colours.h>
#include <guild.h>

inherit NPC;

string * v_name = ({ "alef", "beth", "gimmel", "dalet", "hei", "vav", "zayin", "het", "tet", "yud" });
int nTarget;
string sPlayer;

public string QueryPlayer() { return sPlayer; }
public string SetPlayer(string str) { return (sPlayer = LOWER(str)); }

public int QueryTarget() { return nTarget; }
public int SetTarget(int i)
{
	nTarget = i%10;
	SetName(CAP(v_name[nTarget]));
	AddId(v_name[nTarget]);
	SetShort(CAP(v_name[nTarget]));
	SetLong(CAP(v_name[nTarget])+" el malvado criminal de alma más negra que el carbón.\n");

	return nTarget;
}

public string QueryShort()
{
	string base_short = ::QueryShort() || "";
	string tip;

	if (extern_call()) return base_short;

	if (TP && (TP->QueryRealName() == QueryPlayer()))
		tip = " "+TC_BOLD+"[RETO]"+TC_NORMAL;
	else
		tip = "";

	return base_short + tip;
}

public int ChkFightFunction(object atk)
{
	if (atk->QueryRealName() == QueryPlayer())
		return 1;
	else
		return notify_fail("Vas a atacar a "+QueryShort()+" pero, de repente, oyes una voz en tu cabeza que te conmina a detener el ataque. Crees que los dioses le tienen reservado otro destino a "+QueryShort()+".\n", NOTIFY_NOT_VALID);;
}

public void create()
{
	::create();
	SetStandard ( "criminal", "elfo-oscuro", ([GC_LUCHADOR:5]), GENDER_MALE);
	SetLong(CAP(v_name[QueryTarget()])+", el malvado criminal de alma más negra que el carbón.\n");
	SetAlign(-1000);
	SetWhimpy(0);
	SetWeight(80000);					// 80 Kg.
	SetSmell("Atufa a maldad.\n");
	SetChkFightFunction(SF(ChkFightFunction));
}

public varargs void Die(mixed silent)
{
	object attacker_ob, watch;
//	string killer;

	attacker_ob = QueryKiller();
/*
	if (attacker_ob)
		killer=capitalize(attacker_ob->QueryRealName());
	else
		killer="Alguien";
*/
	if (attacker_ob && (watch=present("reloj_darwen", attacker_ob)))
		watch->SetTargetDone(1);

	//"/obj/chmaster"->SendEmote("info", "Rak-nal-turi murió a manos de "+killer+".");
	::Die(silent);
}
