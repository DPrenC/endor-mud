/* vi: set tabstop=4 */
/** @file arma_test.c
	@brief Excalibur
	@author SimBuilder
	@version 1.00
	@date 2008-08-09

	Has oído hablar de esta legendaria espada por todo lo ancho del reino. Dicen que la forjaron los dioses con el material que extrajeron de una piedra que cayó del cielo hace ya eones.
	La hoja irradia poder y su brillo es especial. Está muy afilada.
	Se comenta que aquel que la empuñe no puede ser derrotado en singular combate.
	Parece que hay una leyenda grabada en la hoja.
*/

inherit WEAPON;

#include <combat.h>
#include <properties.h>			// Ya incluye materials.h

public varargs mixed ChkEquip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return EQ_OK;
	if (wielder->QueryGuildLevel() < 100)
	{
		tell_object(wielder, "Tu nivel ha de ser más alto para poder ni siquiera intentar empuñar a Excalibur\n");
		return EQ_FORBID;
	}
	if ((wielder->QueryAlign()<750))
	{
		tell_object(wielder, "Sólo aquellos que siguen la senda del Bien son dignos de empuñar esta magnífica espada.\n");
		return EQ_FORBID;
	}
	if (wielder->QueryRace() == "draconiano")
	{
		tell_object(wielder, "Los que son como tú no pueden empuñar esta espada.\n");
		return EQ_FORBID;
	}
	if (wielder->QueryRace() == "duende")
	{
		tell_object(wielder, "Los que son como tú no pueden empuñar esta espada.\n");
		return EQ_FORBID;
	}
	if (wielder->QueryRace() == "elfo-oscuro")
	{
		tell_object(wielder, "Los que son como tú no pueden empuñar esta espada.\n");
		return EQ_FORBID;
	}
	if (wielder->QueryRace() == "enano")
	{
		tell_object(wielder, "Los que son como tú no pueden empuñar esta espada.\n");
		return EQ_FORBID;
	}
	if (wielder->QueryRace() == "gnomo")
	{
		tell_object(wielder, "Los que son como tú no pueden empuñar esta espada.\n");
		return EQ_FORBID;
	}
	if (wielder->QueryRace() == "kender")
	{
		tell_object(wielder, "Los que son como tú no pueden empuñar esta espada.\n");
		return EQ_FORBID;
	}
	if (wielder->QueryRace() == "orco")
	{
		tell_object(wielder, "Los que son como tú no pueden empuñar esta espada.\n");
		return EQ_FORBID;
	}
	return ::ChkEquip(wielder, equipment, flags);
}

public varargs void NotifyEquip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return;
	tell_object(wielder, "Vibras de poder al empuñar a Excalibur\n");
	SetWC(QueryWC()+50);
	wielder->AddStrBonus(3);
	wielder->AddConBonus(3);
	wielder->AddDexBonus(3);
	SetBright(25*QueryQuality()/100);
	::NotifyEquip(wielder, equipment, flags);
}

public varargs void NotifyUnequip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return;
	tell_object(wielder, "Notas que el poder de Excalibur te abandona\n");
	SetWC(QueryWC()-50);
	wielder->AddStrBonus(-3);
	wielder->AddConBonus(-3);
	wielder->AddDexBonus(-3);
	SetBright(0);
	::NotifyUnequip(wielder, equipment, flags);
}

// Solo tiene en cuenta el brillo del primer portador
public void DegradeWeapon(mapping soaked, mapping damage, int success, int target)
{
	::DegradeWeapon(soaked, damage, success, target);
	SetBright(25*QueryQuality()/100);
}

create()
{
	::create();
	SetStandard(WT_ESPADA, 16, P_SIZE_GENERIC, M_ESPECIAL);
	SetShort("Excalibur");
	SetLong("Has oído hablar de esta legendaria espada por todo lo ancho del reino. Dicen que la forjaron los dioses con el material que extrajeron de una piedra que cayó del cielo hace ya eones.\n"
	"La hoja irradia poder y su brillo es especial. Está muy afilada.\n"
	"Se comenta que aquel que la empuñe no puede ser derrotado en singular combate.\n"
	"Parece que hay una leyenda grabada en la hoja.\n");
	AddId(({"excalibur","Excalibur"}));
	AddSubDetail(({"brillo", "hoja"}),"Debido al exótico material con que se forjó esta espada el brillo de su hija es extrañamente verde.\n");
	AddSubDetail(({"leyenda"}),"Está grabada en la lengua de los dioses que no puedes interpretar pero en tu mente crees adivinar un susurro que dice: \"Esta es Excalibur, sólo los justos podrán empuñarla\"\n");
	SetMagic(1);
}
