/*
Fichero: /d/l_tagoras/comun/objeto/otro/advanced_effect.c
Autor: [T] Tagoras
Fecha: 08/03/2009
Descripcion: Base de fectos avanzados. Sobre la base de Nyh añado funciones que se usan típicamente en un efecto como saber quien es el caster, el saving throw, el saving difficulty class, etc.
*/

#include <magia.h>
#include <properties.h>
#include <ts.h>
#include <wizlevels.h>

#define DND_MAX_LEVEL		20				// En d20 el máximo nivel es 20
#define EFFECTS_DEBUGGER	"tagoras"

inherit EFFECT;

//------------------------------------------------------------------------------

private string sCasterName;					// Nombre del caster
private int pSaveDC;						// Difficulty class del saving throw
private int pSaveType;						// Tipo de save para el saving throw

public string QueryCasterName() { return sCasterName; }
public string SetCasterName(string name) { return sCasterName = name; }

public int QueryCasterLevel(int dnd)
{
	int level = HLP_RLVL / 2;
	object caster;

	caster = find_object(QueryCasterName()) || present(QueryCasterName(), environment(QueryAffected())) || 0;
	if (caster && caster->QueryIsPlayer())
		level = caster->QueryGuildLevel();
	if (caster && caster->QueryIsNPC())
		level = caster->QueryLevel();

	if (level > HLP_RLVL) level = HLP_RLVL;

	if (dnd)
		level = level * DND_MAX_LEVEL / HLP_RLVL;

	return level;
}

public int QuerySaveType() { return pSaveType; }
public int SetSaveType(int i) {
  switch (i) { //El switch es una forma de solo permitir salvaciones legales
  case SAVE_TYPE_NOSAVE:	pSaveType = SAVE_TYPE_NOSAVE;		break;
  case SAVE_TYPE_FORTITUDE:	pSaveType = SAVE_TYPE_FORTITUDE;	break;
  case SAVE_TYPE_REFLEX:	pSaveType = SAVE_TYPE_REFLEX;		break;
  case SAVE_TYPE_WILL:		pSaveType = SAVE_TYPE_WILL;			break;
  }
  return QuerySaveType();
}

public int QuerySaveDC()
{
	int modifier = 0;
	object caster;

	if (!pSaveDC)
	{
		// Es un player
		if ((caster = find_object(QueryCasterName())) && caster->QueryIsPlayer())
		{
			switch (QuerySaveType())
			{
				case SAVE_TYPE_FORTITUDE:	modifier = caster->QueryConModifier(); break;
				case SAVE_TYPE_REFLEX:		modifier = caster->QueryDexModifier(); break;
				case SAVE_TYPE_WILL:		modifier = caster->QueryIntModifier(); break;	 // Debería ser Sabiduría
			}
		}

		pSaveDC = 10 + QueryCasterLevel(0)/10 + modifier;
	}
	return pSaveDC;
}
public int SetSaveDC(int i) { return pSaveDC = i; }

// Al menos una mano libre - Si el caster no está suponemos que tiene una mano libre
public int CheckSomatic()
{
	object caster;

	caster = find_object(QueryCasterName()) || present(QueryCasterName(), environment(QueryAffected())) || 0;
	if (caster)
		return sizeof(filter(caster->QueryHands(), (:$1[1] == 0:)));	// Número de manos libres del caster
	else
		return 1;						// Si el caster no está suponemos que tiene una mano libre
}

// Saving Throw
public int SavingThrow()
{
	int dice20 = d20();

	return ((1!=dice20) && ((20==dice20) || (QuerySaveType() && (dice20 + QueryAffected()->QuerySaveBonusType(QuerySaveType()) > QuerySaveDC()))));
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

create_clone()
{
	::create_clone();
	SetCasterName(TP->QueryRealName());
}

//------------------------------------------------------------------------------
