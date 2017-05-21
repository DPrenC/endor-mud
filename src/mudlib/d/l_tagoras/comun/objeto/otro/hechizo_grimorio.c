/* vi: set tabstop=4 */
/** @file hechizo_grimorio.c
	@brief hechizo de grimorio
	@author SimBuilder
	@version 1.00
	@date 2009-03-27

Un hechizo temporal realizado por un grimorio.

Para usar este objeto deberás añadir el siguiente define en algún punto de la lista de inclusión.
#define OTRO(x) "/d/l_tagoras/comun/objeto/otro/" + x
*/

#include "path.h"
#include <properties.h>

inherit THING;

static mapping properties;

mapping QueryPlayerProperties() {
    return properties||([]);
}

public void create()
{
	::create();
	SetShort("hechizo de grimorio");
	SetLong("Un hechizo temporal realizado por un grimorio.\n");
	AddId(({"hechizo", "hechizo_grimorio"}));
	SetGender(GENDER_MALE);
	SetInvis(1);
	SetMagic(1);
	SetNoDrop(1);
	SetNoFollow(1);
//	SetNoGet(1);
	SetNoGive(1);
	SetNoTake(1);
	SetSize(P_SIZE_GENERIC);
	SetWeight(0);
}

// Copiado de /guilds/guardabosques/obj/amuleto.c
/*
Propiedades interesantes de modificar en el player:
AC
Armours

Attr:
		MagicDefense
		Invis
		MagicDefence

Bonus?
Bright
ChkFightFunction
ChkMagicFunction
CombatAction
ConBonus
ConModifier
Danyo
DanyoMedio
DanyoMedioTotal
DexBonus
DexModifier
Fortitude?
Gender
HP
Hidden
IVision
IntBonus
IntBright
IntLight
IntModifier
Light
Magic
MagicDefense
MaxHP
MaxSP
MaxTP
MaxIntWeight
MaxWeight
Paralyzed
RateHP
RateSP
RateTP
Reflex
RegHP
RegSP
RegTP
StrBonus
StrModifier
TmpCon
TmpDex
TmpInt
TmpStr
UVision
Will
*/

/* reiniciar una propiedad a la que está guardada en el mapping properties */
ResetProperty(string prop) {
	/* [t] oldvalue es el valor al que le he puesto la propiedad, newvalue
	   la que tiene ahora, y tovalue a lo que se la puse
	*/
	mixed oldvalue, newvalue, tovalue, must;

	if (!properties || !prop || prop == "") return;
	if (!member(properties, prop)) {
		return;
	}

	oldvalue = properties[prop, 0];
	tovalue = properties[prop, 1];
	must = properties[prop, 2];
	newvalue = TP->Query(prop);

	if (intp(oldvalue) && intp(newvalue)) {
		/* [t] Si los valores son numéricos y difieren, la propiedad ha cambiado,
			y hay que reflejar ese cambio.  Sin embargo puede darse el caso en el
			que hayan modificadores internos, y el Set y el Query "difieran".
		*/
		if (must != tovalue) {
			newvalue = oldvalue;
			//glog(sprintf("Oldvalue Changed %s, SET %O(%O), WAS %O, IS %O\n", prop, tovalue, must, oldvalue, newvalue));
			/* uiuiui */
		}
		else if (tovalue != newvalue) {
			newvalue = oldvalue;
			//glog(sprintf("Tovalue Changed %s, SET %O(%O), WAS %O, IS %O\n", prop, tovalue, must, oldvalue, newvalue));
		}
		else {
			newvalue = oldvalue;
		}
	}
	else {
		newvalue = oldvalue;
	}
	TP->Set(prop, newvalue);
	if (prop == P_TMPCON && TP->QueryHP() > TP->QueryMaxHP()) TP->SetHP(TP->QueryMaxHP());
	// para evitar que tenga más vida de la cuenta
	m_delete(properties, prop);
}

/* resetear las propiedades *props por tiempo, mostrando un mensaje al caster
	(mymsg) y otro a la habitación (allmsg) */
varargs ResetPropertiesByTime(int time, string *props, string mymsg, string allmsg) {
	//glog(sprintf("RESET BY TIME %d, PROPS %O\n", time, props));
	if (!time || !props) {
		return;
	}
	call_out("ResetProperties", time, props, mymsg, allmsg);
}

int _find_callout() {
	return find_call_out("ResetProperties");
}

/* resetear las propiededas *props mostrando un mensaje al caster (mymsg) y
	otro a la habitación (allmgs) */
varargs ResetProperties(string *props, string mymsg, string allmsg) {
	int i;

	//glog(sprintf("RESET %O\n", props));
	if (properties) {
		if (!props) {
			props = m_indices(properties);
		}

		for (i=0; i<sizeof(props); i++) {
			ResetProperty(props[i]);
		}
	}
	if (mymsg) write(mymsg);
	if (allmsg) say(allmsg);
}

/* modificar una propiedad y restaurarla al salir (o destruir el objeto);
   hay que tener especial cuidado con los valores que son metidos pero
   cambiados internamente, por eso meto el valor y el valor real TP->Query...
*/
AddProperty(string prop, mixed value) {
	mixed old;

	if (!properties) properties = ([]);
	old = TP->Query(prop);

	TP->Set(prop, value);
	properties += ([prop:old;value;TP->Query(prop)]);
}

/* eliminar las propiedades cambiadas por magia */
varargs int move(string dest, int method, mixed data) {
	ResetProperties();

	return ::move(dest, method, data);
}

/* eliminar las propiedades cambiadas mediante la magia */
int remove() {
	ResetProperties();
//      TP->save();
	return ::remove();
}
