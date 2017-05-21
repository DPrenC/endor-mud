#include <classes.h>
#include <moving.h>
#include <properties.h>
#include "currency_4e.h"
#include "size_4e.h"
#include "weapon_4e.h"

inherit THING;
inherit "/std/equipment";					// De momento, por compatibilidad

// Weapon categories
private int w_category;						// Categoria: IMPROVISED, SIMPLE, MILITARY, SUPERIOR
private int w_melee_ranged;					// MELEE or RANGED (cuerpoa cuerpo o a distancia)
private int w_hands;						// número de manos

// Group
private int w_group;						// AXE, BOW, CROSSBOW, FLAIL, HAMMER, HEAVY_BLADE, LIGHT_BLADE, MACE, PICK, POLEARM, SLING, SPEAR, STAFF, UNARMED (hacha, arco, ballesta, mangual (mayal o bola-y-cadena), martillo, espada pesada, espada ligera (floretes?), maza, pico, alabarda, honda, lanza, vara, desarmado)

// Properties
private mapping w_properties;				// Mapping de propiedades de las armas

// Proficiency (maestría en el uso del arma)
private int w_proficiency;					// Maestría en el uso del arma

// Damage
private string w_damage;					// Daño que puede hacer el arma (en formato dice: "1d8")

// Range
private int w_short_range;					// Alcance efectivo
private int w_long_range;					// Alcance máximo con penalización

// Silvered
private int w_silvered;						// El arma está plateada (para personajes a los que afecta la plata)

// Standard Weapons
/*
*/
#define WS_DATA_NAME			0
#define WS_DATA_GENDER			1
#define WS_DATA_CATEGORY		2
#define WS_DATA_MELEE_RANGED	3
#define WS_DATA_HANDS			4
#define WS_DATA_PROFICIENCY		5
#define WS_DATA_DAMAGE			6
#define WS_DATA_RANGE			7
#define WS_DATA_VALUE			8
#define WS_DATA_WEIGHT			9
#define WS_DATA_GROUP			10
#define WS_DATA_PROPERTIES		11

private mixed * _standard_weapons = ({
	/* WS_CLUB */		({ "porra",		GENDER_FEMALE, WC_SIMPLE, WC_MELEE, WC_ONE_HANDED, 2,	"1d6",	({}),		1*GP_VALUE, 3, WG_MACE,			({}) }),
	/* WS_DAGGER */		({ "daga",		GENDER_FEMALE, WC_SIMPLE, WC_MELEE, WC_ONE_HANDED, 3,	"1d4", 	({5, 10}),	1*GP_VALUE, 1, WG_LIGHT_BLADE,	({WP_OFF_HAND, WP_LIGHT_THROWN}) }),
	/* WS_JAVELIN */	({ "javalina",	GENDER_FEMALE, WC_SIMPLE, WC_MELEE, WC_ONE_HANDED, 2,	"1d6", 	({10, 20}),	5*GP_VALUE, 2, WG_SPEAR,		({WP_HEAVY_THROWN}) }),
	/* WS_MACE */		({ "maza",		GENDER_FEMALE, WC_SIMPLE, WC_MELEE, WC_ONE_HANDED, 2,	"1d8",	({}),		5*GP_VALUE, 6, WG_MACE,			({ WP_VERSATILE }) }),
	/* WS_SICKLE */		({ "hoz",		GENDER_FEMALE, WC_SIMPLE, WC_MELEE, WC_ONE_HANDED, 2,	"1d6",	({}),		2*GP_VALUE, 2, WG_LIGHT_BLADE,	({WP_OFF_HAND}) }),
	/* WS_SPEAR */		({ "lanza",		GENDER_FEMALE, WC_SIMPLE, WC_MELEE, WC_ONE_HANDED, 2, 	"1d8",	({}),		5*GP_VALUE, 6, WG_SPEAR,		({WP_VERSATILE}) }),
	/* WS_GREATCLUB */ 	({ "garrote",	GENDER_MALE, WC_SIMPLE, WC_MELEE, WC_TWO_HANDED, 2,		"2d4",	({}),		1*GP_VALUE, 10, WG_MACE,		({}) }),
	/* WS_MORNINGSTAR */ ({ "mazo con pinchos", GENDER_MALE, WC_SIMPLE, WC_MELEE, WC_TWO_HANDED, 2, "1d10", ({}),	10*GP_VALUE, 8, WG_MACE,		({}) }),
	/* WS_QUARTERSTAFF */ ({ "bastón",	GENDER_MALE, WC_SIMPLE, WC_MELEE, WC_TWO_HANDED, 2,		"1d8",	({}),		5*GP_VALUE, 4, WG_STAFF,		({}) }),
	/* WS_SCYTHE */		({ "guadaña", GENDER_FEMALE, WC_SIMPLE, WC_MELEE, WC_TWO_HANDED, 2,		"2d4",	({}),		5*GP_VALUE, 10, WG_HEAVY_BLADE,	({}) }),
	/* WS_BATTLEAXE */	({ "hacha de batalla", GENDER_FEMALE, WC_MILITARY, WC_MELEE, WC_ONE_HANDED, 2, "1d10", ({}), 15*GP_VALUE, 6, WG_AXE,		({ WP_VERSATILE }) }),
	/* WS_FLAIL */ 		({ "mangual", GENDER_MALE, WC_MILITARY, WC_MELEE, WC_ONE_HANDED, 2,		"1d10",	({}),		10*GP_VALUE, 5, WG_FLAIL, 		({ WP_VERSATILE }) }),
	/* WS_HANDAXE */	({ "hacha de mano", GENDER_FEMALE, WC_MILITARY, WC_MELEE, WC_ONE_HANDED, 2, "1d6", ({5,	10}), 5*GP_VALUE, 3, WG_AXE,		({ WP_OFF_HAND, WP_HEAVY_THROWN }) }),
	/* WS_LONGSWORD */	({ "espada larga", GENDER_FEMALE, WC_MILITARY, WC_MELEE, WC_ONE_HANDED, 3, "1d8", ({}),		15*GP_VALUE, 4, WG_HEAVY_BLADE,	({ WP_VERSATILE }) }),
	/* WS_SCIMITAR */	({ "cimitarra", GENDER_FEMALE, WC_MILITARY, WC_MELEE, WC_ONE_HANDED, 2,	"1d8",	({}),		10*GP_VALUE, 4, WG_HEAVY_BLADE,	({ WP_HIGH_CRIT }) }),
	/* WS_SHORT_SWORD */ ({ "espada corta", GENDER_FEMALE, WC_MILITARY, WC_MELEE, WC_ONE_HANDED, 3, "1d6", ({}),	10*GP_VALUE, 3, WG_LIGHT_BLADE, ({ WP_OFF_HAND }) }),
	/* WS_THROWING_HAMMER */ ({ "martillo lanzador", GENDER_MALE, WC_MILITARY, WC_MELEE, WC_ONE_HANDED, 3, "1d6", ({5, 10}), 5*GP_VALUE, 2, WG_HAMMER, ({ WP_OFF_HAND, WP_HEAVY_THROWN }) }),
	/* WS_WARHAMMER */	({ "martillo de guerra", GENDER_MALE,  WC_MILITARY, WC_MELEE, WC_ONE_HANDED, 2, "1d10", ({}), 15*GP_VALUE, 5, WG_HAMMER,	({ WP_VERSATILE }) }),
	/* WS_WAR_PICK */	({ "pico de guerra", GENDER_MALE,  WC_MILITARY, WC_MELEE, WC_ONE_HANDED, 2, "1d8", ({}),	15*GP_VALUE, 6, WG_PICK,		({ WP_HIGH_CRIT, WP_VERSATILE }) }),
});
/*
Weapon Prof. Damage Range Price Weight Group Properties
Battleaxe +2 1d10 - 15 gp 6 lb. Axe Versatile
Flail +2 1d10 - 10 gp 5 lb. Flail Versatile
Handaxe +2 1d6 5/10 5 gp 3 lb. Axe Off-hand, heavy thrown
Longsword +3 1d8 - 15 gp 4 lb. Heavy blade Versatile
Scimitar +2 1d8 - 10 gp 4 lb. Heavy blade High crit
Short sword +3 1d6 - 10 gp 2 lb. Light blade Off-hand
Throwing hammer +2 1d6 5/10 5 gp 2 lb. Hammer Off-hand, heavy thrown
Warhammer +2 1d10 - 15 gp 5 lb. Hammer Versatile
War pick +2 1d8 - 15 gp 6 lb. Pick High crit, versatile
*/

// -------------------------------------
// Compatibilidad Simauria
// -------------------------------------

private nosave int invshort;

// -------------------------------------
// Fin Compatibilidad Simauria
// -------------------------------------

// DND4e
public int IsDND4E() { return 1; }

// Funciones sobre las categorias
public int QueryCategory() { return w_category || WC_IMPROVISED; }
public int SetCategory(int cat)
{
	if (cat >= WC_IMPROVISED && cat <= WC_SUPERIOR)
		w_category = cat;
	return QueryCategory();
}

public int QueryMeleeRanged() { return w_melee_ranged || WC_MELEE; }
public int SetMeleeRange(int mr)
{
	if (mr == WC_MELEE || mr == WC_RANGED)
		w_melee_ranged = mr;
	return QueryMeleeRanged();
}

public int QueryHands() { return w_hands || WC_ONE_HANDED; }
public int SetHands(int hands)
{
	if (hands == WC_ONE_HANDED || hands == WC_TWO_HANDED)
		w_hands = hands;
	return QueryHands();
}

// Funciones sobre el grupo
public int QueryGroup() { return w_group || WG_UNARMED; }
public int SetGroup(int group)
{
	if (group >= WG_AXE && group <= WG_UNARMED)
		w_group = group;
	return QueryGroup();
}

// Funciones sobre las propiedades
public mapping QueryProperties() { return w_properties || ([]); }
public mapping SetProperties(mapping props) { return w_properties = props; }
public int HasProperty(int prop)
{
	return member(QueryProperties(), prop);
}
public varargs mapping AddProperty(int prop, int value)
{
	return m_add(w_properties, prop, value);
}
public mapping RemoveProperty(int prop)
{
	return m_delete(w_properties, prop);
}
public int QueryProperty(int prop)
{
	if (!HasProperty(prop)) return -1;
	return m_entry(w_properties, prop)[0];
}

// Funciones para la proficiency
public int QueryProficiency() { return w_proficiency; }
public int SetProficiency(int pro) { return w_proficiency = pro; }

// Funciones sobre el daño
public string QueryDamage() { return w_damage || "1d4"; }
// Pone el daño que hace el arma, sólo entro los permitidos para armas de una o dos manos.
public string SetDamage(string damage)
{
	string * damages;
	int damage_idx;

	switch(QueryHands())
	{
		case WC_ONE_HANDED:
			damages = W_DAMAGES_ONE_HANDED; break;
		case WC_TWO_HANDED:
			damages = W_DAMAGES_TWO_HANDED; break;
	}
	damage_idx = member(damages, damage);
	if (-1 == damage_idx)
		damage_idx=0;

	return w_damage = damages[damage_idx];
}
public int QueryMaxDamage()
{
	string * parts = explode(QueryDamage(), "d");
	return atoi(parts[0]) * atoi(parts[1]);
}

// Funciones sobre el alcance (Ranged)
public int QueryShortRange() { return w_short_range || 0; }
public int SetShortRange(int range) { return w_short_range = range; }
public int QueryLongRange() { return w_long_range || QueryShortRange(); }
public int SetLongRange(int range) { return w_long_range = range; }

// Funciones sobre el plateado (silvered)
public int QuerySilvered() { return w_silvered; }
public int SetSilvered(int silver) { return w_silvered = silver; }

// Funciones sobre el tamaño
// Permite cambiar el tamaño para el cual está orientado la arma (p.defecto todas las armas son S_MEDIUM, aptas para la mayoría de caracteres)
// Post: Puede variar el daño que realiza el arma.
public int SetSize(int size)
{
	int old_size = QuerySize(1);
	int diff_size, damage_idx;
	string * damages;

	// Compatibilidad con Simauria
	if (-1 < member(({P_SIZE_GENERIC, P_SIZE_SMALL, P_SIZE_MEDIUM, P_SIZE_LARGE, P_SIZE_HUGE}), size))
		size = m_entry(SIZE_SIM_DND4E, size)[0];
	// Chequeo size buena
	if (-1 == member(({S_TINY, S_SMALL, S_MEDIUM, S_LARGE, S_HUGE, S_GARGANTUAN}), size))
		size = S_MEDIUM;
	// Si cambia el size, cambiamos el damage
	if (old_size != size)
	{
		diff_size = size - old_size;
		switch(QueryHands())
		{
			case WC_ONE_HANDED:
				damages = W_DAMAGES_ONE_HANDED; break;
			case WC_TWO_HANDED:
				damages = W_DAMAGES_TWO_HANDED; break;
		}
		damage_idx = member(damages, QueryDamage());
		if (-1 == damage_idx)
			damage_idx=0;
		damage_idx += diff_size;
		// Sólo si podemos cambiar efectivamente el daño realizado haremos el cambio de tamaño.
		if (damage_idx >= 0 && damage_idx < sizeof(damages))
			SetDamage(damages[damage_idx]);
		else
			size = old_size;			// No permitimos el cambio de tamaño si no deja hacer cambio de daño
	}

	return ::SetSize(size);
}

public int QuerySize(int dnd4e)
{
//if (find_object("tagoras")) dtell("tagoras", sprintf("dnd4e: %d - ::QuerySize: %d - SIZE_DND4E_SIM: %O\n", dnd4e, ::QuerySize(), SIZE_DND4E_SIM));
	if (dnd4e)
		return ::QuerySize() || S_MEDIUM;
	else
		return m_entry(SIZE_DND4E_SIM, ::QuerySize() || S_MEDIUM)[0];
}

public int Enlarge()
{
	int size = QuerySize(1);
	if (size < S_GARGANTUAN)
		return SetSize(size+1);
	return size;
}

public int Reduce()
{
	int size = QuerySize(1);
	if (size > S_TINY)
		return SetSize(size-1);
	return size;
}

// Funciones para compatibilidad con Simauria
// ----- Weapon Class -----
public int QueryWC() { return QueryMaxDamage(); }
public int SetWC(int wc) { return QueryWC(); }

public int QueryWPperQP() { return 2*QueryWC(); }
public int SetWPperQP(int i) { return QueryWPperQP(); }

public int QueryDamType() { return WG_DAMAGES[QueryGroup()]; }
public int SetDamType() { return QueryDamType(); }
public nomask int QueryDamageType() { return QueryDamType(); }

public string QueryWeaponType() { return WS_DND4E_SIM[QueryGroup()]; }
public string SetWeaponType(string w) { return QueryWeaponType(); }

public int QueryValue() { return modifyValue(::QueryValue()); }

// public  int QueryDamage(object enemy) { return 0; }

public string Long(string what) { return modifyLong(::Long(what)); }
public string InvShort (string what)
{
	string rc;
 	invshort = 1;
	rc = ::InvShort(what);
	invshort = 0;
	return modifyInvShort(rc);
}
public string Short (string what)
{
	if (invshort) return ::Short(what);
	return modifyShort(::Short(what));
}

public void DegradeWeapon ( mapping soaked, mapping damage, int success , int target)
{
 	int s, wpq;

 	s = soaked["TOTAL"];
 	wpq = QueryWPperQP();
 	if ( (wpq>0) && ((s >= wpq) || !random(200)) )
		AddQuality( -((s/wpq) || 1) );
}

// Por compatibilidad con el weapon.c
public varargs int SetStandard (mixed weapon_type, int wc, int size, mixed material)
//public int SetStandard(int idx)
{
	string un_una = "una";
	int idx;

// ------------- Compatibilidad -----------------------
	if (pointerp(weapon_type))
		return apply(SF(SetStandard), weapon_type);

	if (stringp(weapon_type))
	{
		if (member(WS_SIM_DND4E, weapon_type))
			idx = m_entry(WS_SIM_DND4E, weapon_type)[0];
		else
			idx = WS_IMPROVISED_MELEE_ONE_ANY;
	}
// ----------------------------------------------------

	if (intp(weapon_type))
		idx = weapon_type;

	if (idx<WS_FIRST || idx>WS_LAST)
		idx = WS_IMPROVISED_MELEE_ONE_ANY;

	un_una = (_standard_weapons[idx][WS_DATA_GENDER]==GENDER_FEMALE?"una":"un");
	//AddId(_standard_weapons[idx][WS_DATA_NAME]);
	SetIds(({_standard_weapons[idx][WS_DATA_NAME]}));
	SetShort(un_una+" "+_standard_weapons[idx][WS_DATA_NAME]);
	SetLong(CAP(un_una)+" simple "+_standard_weapons[idx][WS_DATA_NAME]+".\n");
	SetGender(_standard_weapons[idx][WS_DATA_GENDER]);
	SetCategory(_standard_weapons[idx][WS_DATA_CATEGORY]);
	SetMeleeRange(_standard_weapons[idx][WS_DATA_MELEE_RANGED]);
	SetHands(_standard_weapons[idx][WS_DATA_HANDS]);
	SetProficiency(_standard_weapons[idx][WS_DATA_PROFICIENCY]);
	SetDamage(_standard_weapons[idx][WS_DATA_DAMAGE]);
	switch (sizeof(_standard_weapons[idx][WS_DATA_RANGE]))
	{
		case 2:
			SetShortRange(_standard_weapons[idx][WS_DATA_RANGE][0]);
			SetLongRange(_standard_weapons[idx][WS_DATA_RANGE][1]);
			break;
	}
	SetValue(_standard_weapons[idx][WS_DATA_VALUE]);
	SetWeight(_standard_weapons[idx][WS_DATA_WEIGHT]*LB2GR);
	SetGroup(_standard_weapons[idx][WS_DATA_GROUP]);

// ------------- Compatibilidad --------
	SetSize(S_MEDIUM);					// Por defecto todas las armas MEDIUM
	SetQuality(99);						// /std/equipment
	SetResetQuality(99);				// /std/equipment
	if (!material)
		SetMaterial(m_entry(WG_MATERIALS, QueryGroup())[0]);
	else
		SetMaterial(material);
	SetNumberHands((WC_TWO_HANDED == QueryHands()?2:1));	// /std/equipment
// -------------------------------------

	return 1;
}

// Comandos wield y unwield
// Equip y Unequip se han ido. Probablemente están en std/equipment.c. No se.
//int wield (object own) { return !Equip(objectp(own) ? own : TP, 1); }
//int unwield()          { return !Unequip(); }

public varargs int move (mixed dest, int method, mixed extra) {
  int rc;
  rc = thing::move(dest, method, extra);
  if (rc == ME_OK)
    notify_move(dest, method, extra);
  return rc;
}

public int remove() {
  notify_move(0, M_DESTRUCT);
  return thing::remove();
}

// -------------------------------------
// Fin Compatibilidad Simauria
// -------------------------------------

// -----------------------------------------------------------------------------
// Funciones principales (create, init,...)
// -----------------------------------------------------------------------------

create()
{
    "*"::create();
    SetUsage(EQM_WIELD);									// /std/equipment
    AddClassId(C_WEAPON);
    SetStandard(WS_CLUB);
    seteuid(getuid(TO)); // Para poder cargar el objeto de fórmula.
// Esto sería muy útil, definitivamente...
//    call_out("register_weapon",1);
}

init()
{
    "*"::init();  /* does the add_action for 'show' */
}

