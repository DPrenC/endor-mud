/* vi: set tabstop=4 */
/** @file hacha_altriv.c
	@brief el hacha de Altriv
	@author [T] Tagoras
	@version 1.00
	@date 2009-03-07

	Nunca antes habías visto un arma parecida a la que estás mirando. Se trata de un hacha de doble filo forjada hace muchos años por los herreros enanos de la ciudad de Kha-annu. En su empuñadura, de puro mithril, puedes ver grabada la cabeza de un león y al fijarte en ella algo te dice que ese hacha sólo podrá ser empuñada por su dueño o por quien le haya quitado la vida.


[T] Tagoras: He arreglado el QuerySize de manera que al equipar (o empunyar) devuelve el valor real, y si se llama de otra manera devolvera el valor real si tenemos el amuleto de Atriv o SIZE_GENERIC sino. En este último caso ninguna herreria o el reudicr, agrandar funcionarán.
*/

inherit WEAPON;

#include <combat.h>
#include <guild.h>
#include <properties.h>			// Ya incluye materials.h

#define DAMAGE_NOT_OWNER	5	// Se resta esto de vida cada vez que alguien intenta empuñar el arma si no es suya.

protected string pOwner = "altriv";

public void SetOwner(string name) { pOwner = name; }
public string QueryOwner() { return pOwner; }

public varargs mixed ChkEquip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return EQ_OK;
	if (wielder->QueryRealName() != QueryOwner())
	{
		tell_object(wielder, "Intentas empuñar el hacha y cuando estás a punto de hacerlo, todo tu cuerpo se pone a temblar y caes al suelo derrotado.\n");
		wielder->Defend(DAMAGE_NOT_OWNER, TM_VENENO, DEFEND_NOLIV | DEFEND_NOMSG | DEFEND_SPELL | DEFEND_NO_DEF_SK | DEFEND_NO_AC);
		return EQ_FORBID;
	}
	return ::ChkEquip(wielder, equipment, flags);
}

public varargs void NotifyEquip(object wielder, object equipment, int flags)
{
	int str_bonus = 1;

	if (equipment != TO) return;
	if (wielder->QueryRace() == "enano")
		str_bonus++;
	if (wielder->QueryGuild() == GC_GUERREROS)
		str_bonus++;
	tell_object(wielder, "Empuñas el hacha de Altriv y te sientes "+(({"un poco", "bastante", "mucho"})[str_bonus-1])+" más fuerte\n");
	wielder->AddStrBonus(str_bonus);
	::NotifyEquip(wielder, equipment, flags);
}

public varargs void NotifyUnequip(object wielder, object equipment, int flags)
{
	int str_bonus = 1;

	if (equipment != TO) return;
	if (wielder->QueryRace() == "enano")
		str_bonus++;
	if (wielder->QueryGuild() == GC_GUERREROS)
		str_bonus++;
	tell_object(wielder, "Desempuñas el hacha de Altriv y te sientes "+(({"un poco", "bastante", "mucho"})[str_bonus-1])+" menos fuerte\n");
	wielder->AddStrBonus(-str_bonus);
	::NotifyEquip(wielder, equipment, flags);
}

public int QuerySize()
{
// /d/kha-annu/comun/pnj/annufam/centro_entrenamiento/altriv
//tell_object(find_object("tagoras"), sprintf("po: %O\n", PO));
	// Al equipar, empunyar, empuñar siempre devolvemos el tamaño real.
	if (-1 < strstr(sprintf("%O", caller_stack(1)), "/bin/mortal/_equipar"))
		return ::QuerySize();
//tell_object(find_object("tagoras"), sprintf("Stack de llamadas: %O\n", caller_stack(1)));

//tell_object(find_object("tagoras"), sprintf("Owner: %s <-> %s - Extern %d\n", QueryOwner(), TP->QueryRealName(), extern_call()));
	if ((TP->QueryRealName() != QueryOwner()) || !present("amuleto_altriv", TP))
		return P_SIZE_GENERIC;
	else
		return ::QuerySize();
}

create()
{
	::create();
	SetStandard(WT_HACHA, 14, P_SIZE_LARGE, M_ACERO);
	SetShort("el hacha de Altriv");
	SetLong("Nunca antes habías visto un arma parecida a la que estás mirando. Se trata de un hacha de doble filo forjada hace muchos años por los herreros enanos de la ciudad de Kha-annu. En su empuñadura, de puro mithril, puedes ver grabada la cabeza de un león y al fijarte en ella algo te dice que ese hacha sólo podrá ser empuñada por su dueño o por quien le haya quitado la vida.\n");
	Set(P_NOSELL,"No estarás hablando en serio, ¿verdad? Es un hacha muy valiosa pero nunca encontraría un comprador que la quisiera.");
	SetMagic(1);
}
