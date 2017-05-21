/* vi: set tabstop=4 */
/** @file placas.c
	@brief unas placas identificadoras
	@author SimBuilder
	@version 1.00
	@date 2009-03-24

	Estas placas te identifican como miembro del ejército enano.

[T] 28/03/2009: Añadido que guarde el nombre del owner para poder recuperar su objeto.
*/

inherit ARMOUR;

#include "path.h"
#include <config.h>
#include <combat.h>
#include <gremios.h>
#include <moving.h>
#include <properties.h>			// Ya incluye materials.h

//#define CAGE_TESTER		"tagoras"			// Ya definido en annufam.h

//#define CAGE_LICENSED	"cage_licensed"			// Ya definido en annufam.h

#define DEFAULT_SERVICE	(DAY_LENGTH*480)		// Un año (simauriano, se entiende)

#define BASE_YEAR		4240
#define M_DIAS(x)       (x/DAY_LENGTH)
#define M_MESES(x)      (x/(DAY_LENGTH*30))
#define M_ESTACIONES(x) (x/(DAY_LENGTH*120))
#define M_ANYOS(x)      (x/(DAY_LENGTH*480))

protected int nCAGEJoined;				// Cuando se alistó
protected int nCAGELicensed;			// Cuando se licenciará
protected int nCAGEXPJoined;			// La XP que tenía al alistarse
protected int nCAGEXPLicensed;			// La XP que tenía al licenciarse
protected object oOwner;
protected string sOwner;

mapping m_rank = ([
  1:"Recluta",
  5:"Cadete",
  10:"Soldado",
  15:"Soldado de 1ª clase",
  20:"Cabo",
  25:"Cabo Primero",
  30:"Cabo Mayor",
  35:"Sargento",
  40:"Sargento Primero",
  45:"Brigada",
  50:"Subteniente",
  55:"Suboficial Mayor",
  60:"Alférez",
  65:"Teniente",
  70:"Capitán",
  75:"Comandante",
  80:"Teniente Coronel",
  85:"Coronel",
  90:"General de Brigada",
  95:"General de División",
  100:"Teniente General",
  150:"General de Ejército",
  200:"Capitán General",
]);

public string LicenseRank (int xp);

public int QueryCAGEJoined() { return nCAGEJoined; }
public int SetCAGEJoined(int i) { return nCAGEJoined = i; }

public int QueryCAGELicensed() { return nCAGELicensed; }
public int SetCAGELicensed(int i)
{
	remove_call_out("License");
	nCAGELicensed = i;
	if (nCAGELicensed > time())
		call_out("License", nCAGELicensed-time());
	else
		if (!nCAGEXPLicensed)
			call_out("License", 1);
	return nCAGELicensed;
}

public int QueryCAGEXPJoined() { return nCAGEXPJoined; }
public int SetCAGEXPJoined(int i) { return nCAGEXPJoined = i; }

public int QueryCAGEXPLicensed() { return nCAGEXPLicensed; }
public int SetCAGEXPLicensed(int i) { return nCAGEXPLicensed = i; }

object SetOwner(object o) { return oOwner = o; }
object QueryOwner()
{
	if (!oOwner && sOwner)
		SetOwner(find_object(sOwner));
	return oOwner;
}

string QueryOwnerName() { return sOwner; }
string SetOwnerName(string name) { return sOwner = LOWER(trim(name)); }

public void Join(int service_time)
{
	int now=time();
	
	SetCAGEJoined(now);
	if (service_time)
		SetCAGELicensed(now+service_time);
	else
		SetCAGELicensed(now+DEFAULT_SERVICE);
	if (QueryOwner())
	{
		oOwner->SetAttribute(CAGE_LICENSED, QueryCAGELicensed());
		SetCAGEXPJoined(oOwner->QueryXP());
		//oOwner->SetPresay("Recluta ");
		oOwner->SetPresay("");
		//oOwner->SetTitle((oOwner->QueryRace()=="enano"?"del ejército enano":"de la legión enana"));
		oOwner->SetTitle("recluta "+(oOwner->QueryRace()=="enano"?"del ejército enano":"de la legión enana"));
		"/obj/chmaster"->SendEmote("info", CAP(oOwner->QueryRealName())+" se ha alistado "+(oOwner->QueryRace()=="enano"?"al ejército enano.":"a la legión enana.")+" por un periodo no inferior a un año.");
	}
}

public void License()
{
	remove_call_out("License");
	SetCAGEXPLicensed(QueryOwner()->QueryXP());
	QueryOwner()->SetPresay(LicenseRank(QueryCAGEXPLicensed()-QueryCAGEXPJoined())+" ");
	QueryOwner()->SetTitle((QueryOwner()->QueryRace()=="enano"?"del ejército enano.":"de la legión enana."));
	"/obj/chmaster"->SendEmote("info", CAP(QueryOwner()->QueryRealName())+" se ha licenciado con honores "+(QueryOwner()->QueryRace()=="enano"?"del ejército enano":"de la legión enana")+" y ha obtenido el rango de "+QueryOwner()->QueryPresay()+".");
	QueryOwner()->save();
}

public void Expell()
{
	remove_call_out("License");
	QueryOwner()->SetAttribute(CAGE_LICENSED, time());
	QueryOwner()->SetAttribute(CAGE_TRAITOR, time());
	QueryOwner()->SetPresay("");
	QueryOwner()->SetTitle("el traidor");
	"/obj/chmaster"->SendEmote("info", CAP(QueryOwner()->QueryRealName())+" ha sido expulsado con deshonor "+(QueryOwner()->QueryRace()=="enano"?"del ejército enano":"de la legión enana")+" por cometer traición.");
	tell_object(QueryOwner(),"Las placas se deshacen y se convierten en humo.\n");
	QueryOwner()->command_me("desequipar placas");
	QueryOwner()->save();
	remove();
}

public string LicenseRank (int xp)
{
	int level = xp2level(xp);
	int * levels = m_indices(m_rank);
	int i;
	string rank="Recluta";

	for (i=0; i<sizeof(levels); i++)
	{
		if (level >= levels[i])
			rank = m_entry(m_rank, levels[i])[0];
	}

	return rank;
}

//Solo los guerreros masculinos pueden pertenecer al ejército o la legión enanos
public varargs mixed ChkEquip(object wielder, object equipment, int flags)
{
	string msg;
	if (equipment != TO) return EQ_OK;
	if (QueryOwner()->QueryRealName() != wielder->QueryRealName())
	{
		tell_object(wielder, "Tu no eres "+CAP(QueryOwner()->QueryRealName())+" y por tanto no puedes usar sus placas identificadoras.\n");
		return EQ_FORBID;
	}
	if (wielder->QueryGender() != GENERO_MASCULINO)
	{
		msg = "Sólo los varones pueden servir en ";
		if (wielder->QueryRace() == "enano")
			msg += "el ejército enano.\n";
		else
			msg += "la legión enana.\n";
		tell_object(wielder, msg);
		return EQ_FORBID;
	}
	if (CAGE_TESTER == wielder->QueryRealName()) return ::ChkEquip(wielder, equipment, flags);
	if (wielder->QueryGuild() != GC_GUERREROS)
	{
		tell_object(wielder, "Tú no eres un guerrero.\n");
		return EQ_FORBID;
	}
	return ::ChkEquip(wielder, equipment, flags);
}

// Sólo los varones guerreros habrán llegado hasta aquí.
public varargs void NotifyEquip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return;
	if ((wielder->QueryRace() == "enano") || (CAGE_TESTER == wielder->QueryRealName()))
	{
		tell_object(wielder, "Llevar estas placas te llena de orgullo y honor. Eres todo un guerrero enano.\n");
		wielder->AddStrBonus(2);
		wielder->AddConBonus(2);
	}
	else
	{
		tell_object(wielder, "Sientes que llevarás estas placas con orgullo.\n");
		wielder->AddStrBonus(1);
		wielder->AddConBonus(1);
	}
	::NotifyEquip(wielder, equipment, flags);
}

// Sólo los varones guerreros podrían haber equipado las placas.
public varargs void NotifyUnequip(object wielder, object equipment, int flags)
{
	if (equipment != TO) return;
	if ((wielder->QueryRace() == "enano") || (CAGE_TESTER == wielder->QueryRealName()))
	{
		tell_object(wielder, "Te siente menos honorable y orgulloso. ¿Acaso no tienes lo que se necesita para ser un guerrero?\n");
		wielder->AddStrBonus(-2);
		wielder->AddConBonus(-2);
	}
	else
	{
		tell_object(wielder, "Siente como si no dieras la talla.\n");
		wielder->AddStrBonus(-1);
		wielder->AddConBonus(-1);
	}
	::NotifyUnequip(wielder, equipment, flags);
}

public string QueryLong()
{
	string base_long = ::QueryLong();
	string name, race;
	string army_legion, msg;
	int CAGEXP;

	if (extern_call()) return base_long;
	name = QueryOwner()->QueryRealName();
	race = QueryOwner()->QueryRace();
	army_legion = (race == "enano"?"el ejército enano":"la legión enana");
	// Aún es recluta
	if (QueryCAGEJoined() && (QueryCAGELicensed() > time()))
	{
		msg = "Son tus placas de recluta en "+army_legion+".\n";
		msg += "En ellas están grabados tus datos de alistamiento.\n";
		msg += "Nombre: "+CAP(name)+"\n";
		msg += "Raza:   "+CAP(race)+"\n";
		msg += "Cuerpo: "+(race == "enano"?"Ejército":"Legión")+"\n";
		msg += "Alistado el día "+((M_DIAS(QueryCAGEJoined())%30)+1)+" del mes "+((M_MESES(QueryCAGEJoined())%16)+1)+" del año "+(BASE_YEAR+M_ANYOS(QueryCAGEJoined()))+".\n";
	}
	// Se licenció
	if (QueryCAGEJoined() && (QueryCAGELicensed() <= time()))
	{
		msg = "Son tus placas de antiguo recluta en "+army_legion+".\n";
		msg += "En ellas están grabados tus datos de alistamiento y licenciamiento.\n";
		msg += "Rango:  "+LicenseRank(QueryCAGEXPLicensed()-QueryCAGEXPJoined())+"\n";
		msg += "Nombre: "+CAP(name)+"\n";
		msg += "Raza:   "+CAP(race)+"\n";
		msg += "Cuerpo: "+(race == "enano"?"Ejército":"Legión")+"\n";
		msg += "Alistado el día "+((M_DIAS(QueryCAGEJoined())%30)+1)+" del mes "+((M_MESES(QueryCAGEJoined())%16)+1)+" del año "+(BASE_YEAR+M_ANYOS(QueryCAGEJoined()))+".\n";
		msg += "Licenciado el día "+((M_DIAS(QueryCAGELicensed())%30)+1)+" del mes "+((M_MESES(QueryCAGELicensed())%16)+1)+" del año "+(BASE_YEAR+M_ANYOS(QueryCAGELicensed()))+".\n";
	}
	// Ni lo uno ni lo otro
	if (!QueryCAGEJoined())
		msg = "Unas placas identificadoras.\n";

	return msg;
}

create()
{
	::create();
	SetStandard(AT_AMULETO, 1, P_SIZE_GENERIC, M_ALUMINIO);
	SetShort("unas placas identificadoras");
	SetLong("Estas placas te identifican como miembro del ejército enano.\n");
	AddId(({"placas", "placas_cage"}));
	AddAdjective(({"unas", "identificadoras"}));
	Set(P_GENDER, GENERO_FEMENINO);
	Set(P_NUMBER, NUMERO_PLURAL);
	SetNoGive("¿Acaso pretendes desertar?");
	SetNoDrop("¿Acaso pretendes desertar?");
	Set(P_CANT_STEAL,"¿Y enfrentarte a la ira del ejército enano? Ni de coña.");
	Set(P_NOSELL,"¿Acaso pretendes desertar?");
	SetMagic(1);
	if (nCAGELicensed && (nCAGELicensed <= time()))
		call_out("License", 1);
}

// Para que en caso de que el player pierda las placas no las pueda coger otro
varargs int move(mixed dest, int method, mixed data)
{
	//if (find_object("tagoras")) dtell("tagoras",sprintf("Mover a %O con el método %d y datos %O\n", dest, method, data));
	switch (method)
	{
		case M_GET:
			if (QueryOwnerName() && (QueryOwnerName()!=TP->QueryRealName()))
			{
				return ME_NO_GET;
			}
			break;
	}
	return ::move(dest, method, data);
}

