/*
[T] 12/03/2009: Añado los hechizos a la liasta de hechizos.
				Hago que do_harm use Defend.
				Hago que do_harm pase a devolver int.
				Hago que el causar también afecte a PNJs.
[T] 16/03/2009: Añado el impromtar y el recordar.
[T] 18/03/2009: Cambio la manera de ponerl un dueño al grimorio. Ahora es simplemente el nombre del player.
[T] 19/03/2009: Pongo código para probarcómo ir metiendo hechizos en el grimorio y cambio el do_stamine para que tenga en cuenta la inteligencia del player, aparte de verificar si sabe como aplicar la estamina.
[T] 20/03/2009: Hago que do_heal lleve todo el peso de verificacion del curar heridas.
[T] 08/04/2009: Uso efectos para la mayoría de hechizos.
[T] 21/04/2009: Cambio el curar al sistema de efectos basado en el effect_wounds
*/

#include <properties.h>
#include <colours.h>
#include <combat.h>
#include <guild.h>
#include <moving.h>
#include <wizlevels.h>
#include <effects.h>
#include <ts.h>
#include <regexp.h>
#include <stats.h>

#define EFFECT_ACIDARROW				"/d/l_tagoras/comun/objeto/otro/effect_acidarrow"
#define EFFECT_ACIDFOG					"/d/l_tagoras/comun/objeto/otro/effect_acidfog"
#define EFFECT_BARKSKIN					"/d/l_tagoras/comun/objeto/otro/effect_barkskin"
#define EFFECT_BEARSENDURANCE			"/d/l_tagoras/comun/objeto/otro/effect_bearsendurance"
#define EFFECT_BULLSSTRENGTH			"/d/l_tagoras/comun/objeto/otro/effect_bullsstrength"
#define EFFECT_CALLLIGHTNING			"/d/l_tagoras/comun/objeto/otro/effect_calllightning"
#define EFFECT_CALLLIGHTNINGSTORM		"/d/l_tagoras/comun/objeto/otro/effect_calllightningstorm"
#define EFFECT_CATSGRACE				"/d/l_tagoras/comun/objeto/otro/effect_catsgrace"
#define EFFECT_CHILLMETAL				"/d/l_tagoras/comun/objeto/otro/effect_chillmetal"
#define EFFECT_CURELIGHTWOUNDS			"/d/l_tagoras/comun/objeto/otro/effect_curelightwounds"
#define EFFECT_CUREMODERATEWOUNDS		"/d/l_tagoras/comun/objeto/otro/effect_curemoderatewounds"
#define EFFECT_CURESERIOUSWOUNDS		"/d/l_tagoras/comun/objeto/otro/effect_cureseriouswounds"
#define EFFECT_CURECRITICALWOUNDS		"/d/l_tagoras/comun/objeto/otro/effect_curecriticalwounds"
#define EFFECT_FALSELIFE				"/d/l_tagoras/comun/objeto/otro/effect_falselife"
#define EFFECT_FOXSCUNNING				"/d/l_tagoras/comun/objeto/otro/effect_foxscunning"
#define EFFECT_HEATMETAL				"/d/l_tagoras/comun/objeto/otro/effect_heatmetal"
#define EFFECT_INFLICTLIGHTWOUNDS		"/d/l_tagoras/comun/objeto/otro/effect_inflictlightwounds"
#define EFFECT_INFLICTMODERATEWOUNDS	"/d/l_tagoras/comun/objeto/otro/effect_inflictmoderatewounds"
#define EFFECT_INFLICTSERIOUSWOUNDS		"/d/l_tagoras/comun/objeto/otro/effect_inflictseriouswounds"
#define EFFECT_INFLICTCRITICALWOUNDS	"/d/l_tagoras/comun/objeto/otro/effect_inflictcriticalwounds"
#define EFFECT_INVISIBILITY				"/d/l_tagoras/comun/objeto/otro/effect_invisibility"
#define EFFECT_JUMP						"/d/l_tagoras/comun/objeto/otro/effect_jump"
#define EFFECT_MAGEARMOR				"/d/l_tagoras/comun/objeto/otro/effect_magearmor"
#define EFFECT_SEEINVISIBILITY			"/d/l_tagoras/comun/objeto/otro/effect_seeinvisibility"
#define EFFECT_WOUNDS					"/d/l_tagoras/comun/objeto/otro/effect_wounds"

#define EFFECTS_DEBUGGER				"tagoras"

inherit THING;

// Estos defines permiten escalar los hechizos DND a Simauria
#define DND_HB			6					// En DND hay 10 turnos por minuto
#define SIM_HB			2					// En Simauria el heartbeat son 2 segundos

#define DND_MAX_LEVEL	20					// En DND el nivel máximo es 20
#define SIM_MAX_LEVEL	HLP_RLVL			// En Simauria no hay máximo pero podemos tomar el de JAN o HLP

#define DND_MAX_STAT	18					// End DND los stats se calculan con 4d6 despreciando el menor
#define SIM_MAX_STAT	HLP_STAT			// En Simauria el stat máximo es 40
// --------------------------------------------------------

#define GRI_STAMINE					"estamina"
#define GRI_IMPROMPT				"improntar"
#define GRI_RECALL					"regresar"
#define GRI_ACIDARROW				"_acidarrow"
#define GRI_ACIDFOG					"_acidfog"
#define GRI_BARKSKIN				"_barkskin"
#define GRI_BEARSENDURANCE			"_bearsendurance"
#define GRI_BULLSSTRENGTH			"_bullsstrength"
#define GRI_CALLLIGHTNING			"_calllightning"
#define GRI_CALLLIGHTNINGSTORM		"_calllightningstorm"
#define GRI_CATSGRACE				"_catsgrace"
#define GRI_CHILLMETAL				"_chillmetal"
#define GRI_CURELIGHTWOUNDS			"_curelightwounds"
#define GRI_CUREMODERATEWOUNDS		"_curemoderatewounds"
#define GRI_CURESERIOUSWOUNDS		"_cureseriouswounds"
#define GRI_CURECRITICALWOUNDS		"_curecriticalwounds"
#define GRI_FALSELIFE				"_falselife"
#define GRI_FOXSCUNNING				"_foxscunning"
#define GRI_HEATMETAL				"_heatmetal"
#define GRI_INFLICTLIGHTWOUNDS		"_inflictlightwounds"
#define GRI_INFLICTMODERATEWOUNDS	"_inflictmoderatewounds"
#define GRI_INFLICTSERIOUSWOUNDS	"_inflictseriouswounds"
#define GRI_INFLICTCRITICALWOUNDS	"_inflictcriticalwounds"
#define GRI_INVISIBILITY			"_invisibility"
#define GRI_JUMP					"_jump"
#define GRI_MAGEARMOR				"_magearmor"
#define GRI_SEEINVISIBILITY			"_seeinvisibility"

#define GRI_ORDER		({"estamina", "improntar", "regresar", GRI_ACIDARROW, GRI_ACIDFOG, GRI_BARKSKIN, GRI_BEARSENDURANCE, GRI_BULLSSTRENGTH, GRI_CALLLIGHTNING, GRI_CALLLIGHTNINGSTORM, GRI_CATSGRACE, GRI_CHILLMETAL, GRI_CURELIGHTWOUNDS, GRI_CUREMODERATEWOUNDS, GRI_CURESERIOUSWOUNDS, GRI_CURECRITICALWOUNDS, GRI_FALSELIFE, GRI_FOXSCUNNING, GRI_HEATMETAL, GRI_INFLICTLIGHTWOUNDS, GRI_INFLICTMODERATEWOUNDS, GRI_INFLICTSERIOUSWOUNDS, GRI_INFLICTCRITICALWOUNDS, GRI_INVISIBILITY, GRI_JUMP, GRI_MAGEARMOR, GRI_SEEINVISIBILITY})

// Tipo de descanso: SP; mensaje; min_int
mapping m_stamine=([
	"leve":30;"un poco";15,
	"moderada":60;"bastante";30,
	"moderado":60;"bastante";30,
	"fuerte":120;"mucho";45
]);

// Hechizos DND Simples (instantaneos)
#define GRI_SPS_LOCALES		0
#define GRI_SPS_EFFECT		1
#define GRI_SPS_HB_CAST		2
#define GRI_SPS_HB_LAST		3
#define GRI_SPS_SEVERITY	4
#define GRI_SPS_CUREINFLICT	5
#define GRI_SPS_MSG_EXEC	6
#define GRI_SPS_GUILDS		7

// Nombre:locale names;effect;hb_2_cast;hb_lasts;severity;exec msgs;guilds_allowed
mapping m_dnd_spells_simple=([
	GRI_CURELIGHTWOUNDS:"curar heridas leves";EFFECT_WOUNDS;1;1;1;1;
		({"Te sientes algo mejor.\n",			"@@v_name@@ se siente algo mejor.\n"});
		([GC_CLERIGO:1, GC_GUARDABOSQUE:1, GC_AVENTURERO:1]),				// Brd 1, Clr 1, Drd 1, Healing 1, Pal 1, Rgr 2
	GRI_CUREMODERATEWOUNDS:"curar heridas moderadas";EFFECT_WOUNDS;1;1;2;1;
		({"Te sientes un poco mejor.\n",		"@@v_name@@ se siente un poco mejor.\n"});
		([GC_CLERIGO:2, GC_GUARDABOSQUE:3, GC_AVENTURERO:3]),				// Brd 2, Clr 2, Drd 3, Healing 2, Pal 3, Rgr 3
	GRI_CURESERIOUSWOUNDS:"curar heridas graves";EFFECT_WOUNDS;1;1;3;1;
		({"Te sientes bastante mejor.\n",		"@@v_name@@ se siente bastante mejor.\n"});
		([GC_CLERIGO:3, GC_GUARDABOSQUE:4, GC_AVENTURERO:4]),				// Brd 3, Clr 3, Drd 4, Pal 4, Rgr 4, Healing 3
	GRI_CURECRITICALWOUNDS:({"curar heridas críticas", "curar heridas criticas"});EFFECT_WOUNDS;1;1;4;1;
		({"Te sientes mucho mejor.\n",			"@@v_name@@ se siente mucho mejor.\n"});
		([GC_CLERIGO:4, GC_GUARDABOSQUE:5]),								// Brd 4, Clr 4, Drd 5, Healing 4
]);

// Hechizos DND
#define GRI_SP_LOCALE		0
#define GRI_SP_LVL_MIN		1
#define GRI_SP_LVL_MAX		2
#define GRI_SP_HB_CAST		3
#define GRI_SP_HB_LAST		4
#define GRI_SP_ALREADY		5
#define GRI_SP_EFFECT		6
#define GRI_SP_LIVING		7		// Afecta sólo a livings
#define GRI_SP_ROOM			8		// Afecta sólo a la room
#define GRI_SP_MSG_ALREADY	9		// Ya está afectado
#define GRI_SP_MSG_ON		10
#define GRI_SP_MSG_EXEC		11
#define GRI_SP_MSG_OFF		12
#define GRI_SP_GUILDS		13

// Nombre:min_level;max_level;hb_cast;hb_lasts;already casted;propery;base property;min_p;max_p;effect;localee name;already mesg;on msg;off msg;allowed guilds
mapping m_dnd_spells=([
	GRI_ACIDARROW:({"flecha ácida", "flecha acida"});2;18;1;"1+1/3";0;EFFECT_ACIDARROW;1;0;
		({"",											""});
		({"",											""});
		({"La flecha ácida te quema.\n",				"La flecha ácida quema a @@v_name@@.\n"});
		({"",											""});
		([GC_CONJURADOR:2, GC_HECHICERO:2]),								// Sor/Wiz 2
	GRI_ACIDFOG:({"niebla ácida", "niebla acida"});6;20;1;"0+1/1";1;EFFECT_ACIDFOG;0;1;
		({"Ya hay niebla ácida",						""});
		({"",											""});
		({"La niebla ácida te quema.\n",				"La niebla ácida quema a @@v_name@@.\n"});
		({"",											""});
		([GC_CONJURADOR:6, GC_HECHICERO:6]),								// Sor/Wiz 6, Water 7
	GRI_BARKSKIN:"piel robliza";2;12;1;100;1;EFFECT_BARKSKIN;1;0;
		({"Tu piel ya tiene la dureza del roble.\n",	"La piel de @@v_name@@ ya tiene la dureza del roble.\n"});
		({"Tu piel adquiere la dureza del roble.\n",	"La piel de @@v_name@@ adquiere la dureza del roble.\n"});
		({"",											""});
		({"Tu piel vuelve a su forma original.\n",		"La piel de @@v_name@@ vuelve a su forma original.\n"});
		({GC_GUARDABOSQUE, GC_AVENTURERO}),									// Drd 2, Rgr 2, Plant 2
	GRI_BEARSENDURANCE:"resistencia de oso";2;20;1;10;1;EFFECT_BEARSENDURANCE;1;0;
		({"Ya tienes resistencia de oso.\n",			"@@v_name@@ ya tiene resistencia de oso.\n"});
		({"Te sientes más resistente.\n",				"@@v_name@@ parece más resistente.\n"});
		({"",											""});
		({"Te sientes menos resistente.\n",				"@@v_name@@ parece menos resistente.\n"});
		({GC_CLERIGO, GC_GUARDABOSQUE, GC_AVENTURERO, GC_CONJURADOR, GC_HECHICERO}),	// Clr 2, Drd 2, Rgr 2, Sor/Wiz 2
	GRI_BULLSSTRENGTH:"fuerza de toro";2;20;1;10;1;EFFECT_BULLSSTRENGTH;1;0;
		({"Ya tienes fuerza de toro.\n",				"@@v_name@@ ya tiene fuerza de toro.\n"});
		({"Te sientes más fuerte.\n",					"@@v_name@@ parece más fuerte.\n"});
		({"",											""});
		({"Te sientes menos fuerte.\n",					"@@v_name@@ parece menos fuerte.\n"});
		({GC_CLERIGO, GC_GUARDABOSQUE, GC_GUERRERO, GC_CONJURADOR, GC_HECHICERO}),	// Clr 2, Drd 2, Pal 2, Sor/Wiz 2, Strength 2
	GRI_CALLLIGHTNING:({"relámpago", "relampago"});3;10;1;"0+1/1";1;EFFECT_CALLLIGHTNING;1;0;
		({"Ya te afectan los relámpagos.\n",			"Ya le afectan los relámpagos a @@v_name@@.\n"});
		({"",											""});
		({"El relámpago te electrocuta.\n",				"El relámpago electrocuta a @@v_name@@.\n"});
		({"",											""});
		({GC_GUARDABOSQUE}),												// Drd 3
	GRI_CALLLIGHTNINGSTORM:({"tormenta de relámpagos", "tormenta de relampagos"});5;15;1;"0+1/1";1;EFFECT_CALLLIGHTNINGSTORM;1;0;
		({"Ya te afectan los relámpagos.\n",			"Ya le afectan los relámpagos a @@v_name@@.\n"});
		({"",											""});
		({"Los relámpagos te electrocutan.\n",			"Los relámpagos electrocutan a @@v_name@@.\n"});
		({"",											""});
		({GC_GUARDABOSQUE}),												// Drd 5
	GRI_CATSGRACE:"gracia felina";2;20;1;10;1;EFFECT_CATSGRACE;1;0;
		({"Ya tienes gracia felina.\n",					"@@v_name@@ ya tiene gracia felina.\n"});
		({"Te sientes más diestr@@v_ao@@.\n",			"@@v_name@@ parece más diestr@@v_ao@@.\n"});
		({"",											""});
		({"Te sientes menos diestr@@v_ao@@.\n",			"@@v_name@@ parece menos diestr@@v_ao@@.\n"});
		({GC_GUARDABOSQUE, GC_AVENTURERO, GC_CONJURADOR, GC_HECHICERO, GC_KISALA}),	// Brd 2, Drd 2, Rgr 2, Sor/Wiz 2
	GRI_CHILLMETAL:"enfriar metal";2;20;1;"7+0/1";0;EFFECT_CHILLMETAL;1;0;
		({"",											""});
		({"",											""});
		({"",											""});
		({"",											""});
		({GC_GUARDABOSQUE}),												// Drd 2
	GRI_CURELIGHTWOUNDS:"curar heridas leves";1;5;1;"1+0/1";0;EFFECT_CURELIGHTWOUNDS;1;0;
		({"",											""});
		({"",											""});
		({"Te sientes algo mejor.\n",					"@@v_name@@ se siente algo mejor.\n"});
		({"",											""});
		([GC_CLERIGO:1, GC_GUARDABOSQUE:1, GC_GUERRERO:1, GC_AVENTURERO:2, GC_KISALA:1]),// Brd 1, Clr 1, Drd 1, Healing 1, Pal 1, Rgr 2
	GRI_CUREMODERATEWOUNDS:"curar heridas moderadas";2;10;1;"1+0/1";0;EFFECT_CUREMODERATEWOUNDS;1;0;
		({"",											""});
		({"",											""});
		({"Te sientes un poco mejor.\n",				"@@v_name@@ se siente un poco mejor.\n"});
		({"",											""});
		([GC_CLERIGO:2, GC_GUARDABOSQUE:3, GC_GUERRERO:3, GC_AVENTURERO:3, GC_KISALA:2]),// Brd 2, Clr 2, Drd 3, Healing 2, Pal 3, Rgr 3
	GRI_CURESERIOUSWOUNDS:"curar heridas graves";3;15;1;"1+0/1";0;EFFECT_CURESERIOUSWOUNDS;1;0;
		({"",											""});
		({"",											""});
		({"Te sientes bastante mejor.\n",				"@@v_name@@ se siente bastante mejor.\n"});
		({"",											""});
		([GC_CLERIGO:3, GC_GUARDABOSQUE:4, GC_GUERRERO:4, GC_AVENTURERO:4, GC_KISALA:3]),// Brd 3, Clr 3, Drd 4, Pal 4, Rgr 4, Healing 3
	GRI_CURECRITICALWOUNDS:({"curar heridas críticas", "curar heridas criticas"});4;20;1;"1+0/1";0;EFFECT_CURECRITICALWOUNDS;1;0;
		({"",											""});
		({"",											""});
		({"Te sientes mucho mejor.\n",					"@@v_name@@ se siente mucho mejor.\n"});
		({"",											""});
		([GC_CLERIGO:4, GC_GUARDABOSQUE:5, GC_KISALA:4]),					// Brd 4, Clr 4, Drd 5, Healing 4
	GRI_FALSELIFE:"falsa vida";2;10;1;600;1;EFFECT_FALSELIFE;1;0;
		({"Ya tienes falsa vida.\n",					"@@v_name@@ ya tiene falsa vida.\n"});
		({"Tu vida aumenta.\n",							"La vida de @@v_name@@ aumenta.\n"});
		({"",											""});
		({"Tu vida vuelve a su valor original.\n",		"La vida de @@v_name@@ vuelve a su valor original.\n"});
		({GC_CONJURADOR, GC_HECHICERO}),									// Sor/Wiz 2
	GRI_FOXSCUNNING:"astucia de zorro";2;20;1;10;1;EFFECT_FOXSCUNNING;1;0;
		({"Ya tienes astucia de zorro.\n",				"@@v_name@@ ya tiene astucia de zorro.\n"});
		({"Te sientes más inteligente.\n",				"@@v_name@@ parece más inteligente.\n"});
		({"",											""});
		({"Te sientes menos inteligente.\n",			"@@v_name@@ parece menos inteligente.\n"});
		({GC_CONJURADOR, GC_HECHICERO}),									// Brd 2, Sor/Wiz 2
	GRI_HEATMETAL:"calentar metal";2;20;1;"7+0/1";0;EFFECT_HEATMETAL;1;0;
		({"",											""});
		({"",											""});
		({"",											""});
		({"",											""});
		({GC_GUARDABOSQUE}),												// Drd 2
	GRI_INFLICTLIGHTWOUNDS:"infligir heridas leves";1;5;1;"1+0/1";0;EFFECT_INFLICTLIGHTWOUNDS;1;0;
		({"",											""});
		({"",											""});
		({"Te sientes algo peor.\n",					"@@v_name@@ se siente algo peor.\n"});
		({"",											""});
		({GC_CLERIGO}),														// Clr 1, Destruction 1
	GRI_INFLICTMODERATEWOUNDS:"infligir heridas moderadas";2;10;1;"1+0/1";0;EFFECT_INFLICTMODERATEWOUNDS;1;0;
		({"",											""});
		({"",											""});
		({"Te sientes un poco peor.\n",					"@@v_name@@ se siente un poco peor.\n"});
		({"",											""});
		({GC_CLERIGO}),														// Clr 2
	GRI_INFLICTSERIOUSWOUNDS:"infligir heridas graves";3;15;1;"1+0/1";0;EFFECT_INFLICTSERIOUSWOUNDS;1;0;
		({"",											""});
		({"",											""});
		({"Te sientes bastante peor.\n",				"@@v_name@@ se siente bastante peor.\n"});
		({"",											""});
		({GC_CLERIGO}),														// Clr 3
	GRI_INFLICTCRITICALWOUNDS:({"infligir heridas críticas", "infligir heridas criticas"});4;20;1;"1+0/1";0;EFFECT_INFLICTCRITICALWOUNDS;1;0;
		({"",											""});
		({"",											""});
		({"Te sientes mucho peor.\n",					"@@v_name@@ se siente mucho peor.\n"});
		({"",											""});
		({GC_CLERIGO}),														// Clr 4, Destruction 
	GRI_INVISIBILITY:"invisibilidad";2;20;1;10;1;EFFECT_INVISIBILITY;1;0;
		({"Ya eres invisible.\n",						"@@v_name@@ ya es invisible.\n"});
		({"Te vuelves invisible.\n",					"@@v_name@@ se vuelve invisible.\n"});
		({"",											""});
		({"Vuelves a ser visible.\n",					"@@v_name@@ vuelve a ser visible.\n"});
		({GC_CONJURADOR, GC_HECHICERO}),									// Brd 2, Sor/Wiz 2, Trickery 2
	GRI_JUMP:"salto";1;20;1;10;1;EFFECT_JUMP;1;0;
		({"Ya has mejorado tu salto.\n",				"@@v_name@@ ya ha mejorado su salto.\n"});
		({"Mejoras tu habilidad de saltar.\n",			"@@v_name@@ mejora su habilidad de saltar.\n"});
		({"",											""});
		({"Tu habilidad de saltar empeora.\n",			"@@v_name@@ empeora su habilidad de saltar.\n"});
		({GC_GUARDABOSQUE, GC_AVENTURERO, GC_KISALA, GC_CONJURADOR, GC_HECHICERO}),		// Drd 1, Rgr 1, Sor/Wiz 1
	GRI_MAGEARMOR:"armadura de mago";1;20;1;600;1;EFFECT_MAGEARMOR;1;0;
		({"Ya tienes una armadura de mago.\n",			"@@v_name@@ ya tiene una armadura de mago.\n"});
		({"Una armadura de mago te recubre.\n",			"Una armadura de mago recubre a @@v_name@@.\n"});
		({"",											""});
		({"La armadura de mago desaparece.\n",			"@@v_name@@ pierde su armadura de mago.\n"});
		({GC_CONJURADOR, GC_HECHICERO}),									// Sor/Wiz 1
	GRI_SEEINVISIBILITY:"ver lo invisible";2;20;1;100;1;EFFECT_SEEINVISIBILITY;1;0;
		({"Ya ves lo invisible.\n",						"@@v_name@@ ya ve lo invisible.\n"});
		({"Puedes ver lo invisible.\n",					"@@v_name@@ puede ver lo invisible.\n"});
		({"",											""});
		({"Ya no puedes ver lo invisible.\n",			"@@v_name@@ ya no puede ver lo invisible.\n"});
		([GC_GUARDABOSQUE:3, GC_CONJURADOR:2, GC_HECHICERO:2]),				// Brd 3, Sor/Wiz 2
]);

private string sOwnerName;
private string sRecall;
private string * aSpells;

public string QueryOwner() { return sOwnerName; }
public string SetOwner(string name) { return sOwnerName = LOWER(name); }

public string QueryRecall() { return sRecall; }
public string SetRecall(string room) { return sRecall = room; }

public string * QuerySpells() { return aSpells || ({}); }
public string * SetSpells(string * spells) { return aSpells = spells; }
public int HasSpell(string spell)
{
	return (-1!=member(QuerySpells(), spell));
}
public string * AddSpell(string spell)
{
	if (-1==member(GRI_ORDER, spell))
		return aSpells || ({});
	if (!aSpells)
		aSpells=({spell});
	else
		if (!HasSpell(spell))
			aSpells += ({spell});

	return SetSpells(aSpells);
}

public int cast_last(string spell);
private int cast_sp(string spell);
private int cast_tired(string spell);
private int castable_guild(string spell);
private int castable_level(string spell);
private int castable_magic(string spell);

public int cmd_affected(string str);
public int cmd_leer(string str);
public int cmd_recitar(string str);

private int do_imprompt();
private int do_recall();
private int do_stamine(string stam, object * excludes);
public int do_effect(string spell, object victim);

public int is_greater(object a, object b);

public string Read()
{
	int i;
	string msg="";

	if (0 == sizeof(QuerySpells()))
		msg = "El "+TC_RED+"grimorio"+TC_NORMAL+" está en blanco.\n";
	else
	{
		msg = "El "+TC_RED+"grimorio"+TC_NORMAL+" contiene "+sizeof(QuerySpells())+" hechizo"+(sizeof(QuerySpells())==1?"":"s")+":\n";
		msg += "--------------------------------------------------------------------------------\n";
		if (HasSpell(GRI_STAMINE))
			msg += "estamina {leve|moderada|fuerte} [a <objetivo>]: Recupera de la fatiga.\n";
		if (HasSpell(GRI_IMPROMPT))
			msg += "improntar:                                      Impregna un lugar.\n";
		if (HasSpell(GRI_RECALL))
			msg += "regresar:                                       Regresa al lugar impregnado.\n";
		if (HasSpell(GRI_ACIDARROW))
			msg += "flecha ácida a <objetivo>:                      Lanza una flecha ácida.\n";
		if (HasSpell(GRI_ACIDFOG))
			msg += "niebla ácida:                                   Provoca una niebla ácida.\n";
		if (HasSpell(GRI_BARKSKIN))
			msg += "piel robliza [a <objetivo>]:                    Piel de roble.\n";
		if (HasSpell(GRI_BEARSENDURANCE))
			msg += "resistencia de oso [a <objetivo>]:              Aumenta la resistencia.\n";
		if (HasSpell(GRI_BULLSSTRENGTH))
			msg += "fuerza de toro [a <objetivo>]:                  Aumenta la fuerza.\n";
		if (HasSpell(GRI_CALLLIGHTNING))
			msg += "relámpago a <objetivo>:                         Lanza una serie de relámpagos.\n";
		if (HasSpell(GRI_CALLLIGHTNINGSTORM))
			msg += "tormenta de relámpagos a <objetivo>:            Lanza una tormenta de relámpagos.\n";
		if (HasSpell(GRI_CATSGRACE))
			msg += "gracia felina [a <objetivo>]:                   Aumenta la destreza.\n";
		if (HasSpell(GRI_CHILLMETAL))
			msg += "enfriar metal [a <objetivo>]:                   Enfria los objetos metálicos.\n";
		if (HasSpell(GRI_CURELIGHTWOUNDS))
			msg += "curar heridas leves [a <objetivo>]:             Cura heridas leves.\n";
		if (HasSpell(GRI_CUREMODERATEWOUNDS))
			msg += "curar heridas moderadas [a <objetivo>]:         Cura heridas moderadas.\n";
		if (HasSpell(GRI_CURESERIOUSWOUNDS))
			msg += "curar heridas graves [a <objetivo>]:            Cura heridas graves.\n";
		if (HasSpell(GRI_CURECRITICALWOUNDS))
			msg += "curar heridas críticas [a <objetivo>]:          Cura heridas críticas.\n";
		if (HasSpell(GRI_HEATMETAL))
			msg += "calentar metal [a <objetivo>]:                  Calienta los objetos metálicos.\n";
		if (HasSpell(GRI_FALSELIFE))
			msg += "falsa vida:                                     Aumenta los puntos de vida.\n";
		if (HasSpell(GRI_FOXSCUNNING))
			msg += "astucia de zorro [a <objetivo>]:                Aumenta la inteligencia.\n";
		if (HasSpell(GRI_INFLICTLIGHTWOUNDS))
			msg += "infligir heridas leves a <objetivo>:            Inflige heridas leves.\n";
		if (HasSpell(GRI_INFLICTMODERATEWOUNDS))
			msg += "infligir heridas moderadas a <objetivo>:        Inflige heridas moderadas.\n";
		if (HasSpell(GRI_INFLICTSERIOUSWOUNDS))
			msg += "infligir heridas graves a <objetivo>:           Inflige heridas graves.\n";
		if (HasSpell(GRI_INFLICTCRITICALWOUNDS))
			msg += "infligir heridas críticas a <objetivo>:         Inflige heridas críticas.\n";
		if (HasSpell(GRI_INVISIBILITY))
			msg += "invisibilidad [a <objetivo>]:                   Vuelve invisible.\n";
		if (HasSpell(GRI_JUMP))
			msg += "salto [a <objetivo>]:                           Mejora la habilidad de saltar.\n";
		if (HasSpell(GRI_MAGEARMOR))
			msg += "armadura de mago [a <objetivo>]:                Armadura mágica.\n";
		if (HasSpell(GRI_SEEINVISIBILITY))
			msg += "ver lo invisible:                               Ves lo que está invisible.\n";
		msg += "\n";
	}

	return msg;
	
}

public string QueryShort()
{
	if (sOwnerName)
		return "el grimorio de "+CAP(sOwnerName);
	return "un grimorio";
}

public void create()
{
	::create();
	seteuid(getuid());
	SetShort("un grimorio");
	SetLong("Es un "+TC_RED+"grimorio"+TC_NORMAL+", un libro de hechizos que cualquiera puede recitar, incluso los no iniciados en las artes mágicas. Lo único que necesitas es tener suficiente maná y, por supuesto, recitar el hechizo. Lee el "+TC_RED+"grimorio"+TC_NORMAL+" para descubrir los hechizos que contiene.\n");
	AddId(({"grimorio"}));
	SetWeight(2500);
	SetValue(500);
	//SetNumber(NUMERO_SINGULAR);		// P_NUMBER
	Set(P_NUMBER, NUMERO_SINGULAR);
	SetGender(GENERO_MASCULINO);		// P_GENDER
	SetSize(P_SIZE_GENERIC);			// P_SIZE
	Set(P_NODROP, 1);
	Set(P_NOGIVE, 1);
	Set(P_NOGET, 1);
}

public void init()
{
	::init();

	add_action("cmd_affected",	"afectado");
	add_action("cmd_leer",		"leer");
	add_action("cmd_recitar",	"recitar");
}

public int is_greater(object a, object b)
{
	return a->QueryIds()[sizeof(a->QueryIds())-1] > b->QueryIds()[sizeof(b->QueryIds())-1];
}

public int cmd_affected(string str)
{
	object * effects;
	int i;

	effects = filter(filter(all_inventory(TP), (:$1->id("_effect_"):)), (:function_exists("QueryAffectedMessage", $1):));
	sort_array(effects, #'is_greater);
	if (sizeof(effects))
		for (i=0; i<sizeof(effects); i++)
			write(effects[i]->QueryAffectedMessage());
	else
		write ("No te afecta ningún hechizo.\n");

	return 1;
}

public int cmd_leer(string str)
{
	if (!id(str)) return notify_fail("¿Leer qué?\n", NOTIFY_ILL_ARG);
	write (Read());

	return 1;
}

public int cmd_recitar(string str)
{
	object victim;
	string harm, heal, stam, victim_name;
	string * spells;
	string spell_name;
	mixed * spell_names;
	int i;

	if ((sOwnerName) && (TP->QueryRealName() != sOwnerName))
	{
		move_object(TO, environment(TP));
		say (CAP(TNAME)+" sufre un calambre y suelta el "+TC_RED+"grimorio"+TC_NORMAL+".\n", TP);
		return notify_fail("El "+TC_RED+"grimorio"+TC_NORMAL+" de "+CAP(sOwnerName)+" te suelta un chispazo y lo sueltas de golpe.\n", NOTIFY_NOT_VALID);
	}
	if (!str) return notify_fail("¿Recitar qué??\n", NOTIFY_NOT_VALID);
	// Está cansado
	if (TP->QueryTiredMagic())
		return notify_fail("El uso de la magia te ha dejado agotado.\n", NOTIFY_NOT_VALID);
	// Estamina
	if (sscanf(LOWER(str),"estamina %s a %s", stam,  victim_name) == 2)
	{
		victim = find_object(victim_name) || present(trim(victim_name), environment(TP)) || 0;
/*
xlpc write(present("darwen",environment(find_object("tagoras")))->QueryShort()+"\n");
*/
		if (!victim) return notify_fail(CAP(victim_name)+" no está por los alrededores.\n", NOTIFY_NOT_VALID);
		return do_stamine(stam, ({TP, victim}));
	}
	if (sscanf(LOWER(str),"estamina %s", stam) == 1)
	{
		return do_stamine(stam, ({TP}));
	}
	// Improntar
	if (trim(LOWER(str)) == "improntar")
		return do_imprompt();
	// Regresar
	if (trim(LOWER(str)) == "regresar")
		return do_recall();
	// Los spells por effects
	spells = m_indices(m_dnd_spells);
	spell_names = m_values(m_dnd_spells, GRI_SP_LOCALE);
	// Parseo el hechizo que se parsea y la víctima
	if (sscanf(trim(LOWER(str)),"%s a %s", spell_name, victim_name) == 2)
	{
		victim = present(trim(victim_name), environment(TP)) || 0;
		if (!victim) return notify_fail(CAP(victim_name)+" no está por los alrededores.\n", NOTIFY_NOT_OBJ);
	}
	else
	{
		spell_name = trim(LOWER(str));
		victim = TP;
	}
	// Busco el hechizo que concuerda entre los que contiene el grimorio
	for (i = 0; i < sizeof(spells); i++)
	{
		if (!HasSpell(spells[i])) continue;
		if ((!stringp(spell_names[i]) && (-1 < member(spell_names[i], spell_name)))
			|| (stringp(spell_names[i]) && (spell_name == spell_names[i])))
		return do_effect(spells[i], victim);
	}

	return notify_fail("El "+TC_RED+"grimorio"+TC_NORMAL+" no contiene ese hechizo.\n");
}

// Devuelve lo que dura el hechizo en turnos
public int cast_last(string spell)
{
	string * dnd_matches;
	int dnd_turns;
	int t_cast_level, t_max_level;
	int caster_level;					// El nivel del caster reducido a DND

	caster_level = TP->QueryGuildLevel() * DND_MAX_LEVEL / SIM_MAX_LEVEL;

	if (intp(m_entry(m_dnd_spells, spell)[GRI_SP_HB_LAST]))
		dnd_turns = m_entry(m_dnd_spells, spell)[GRI_SP_HB_LAST] * caster_level;
	if (stringp(m_entry(m_dnd_spells, spell)[GRI_SP_HB_LAST]))
	{
		dnd_matches = explode(m_entry(m_dnd_spells, spell)[GRI_SP_HB_LAST], "+");
//dtell("tagoras", sprintf("dnd_matches: %O\n", dnd_matches));
		dnd_matches = ({dnd_matches[0]}) + explode(dnd_matches[1], "/");
//dtell("tagoras", sprintf("dnd_matches: %O\n", dnd_matches));
		
		t_max_level = m_entry(m_dnd_spells, spell)[GRI_SP_LVL_MAX];
		t_cast_level = (t_max_level < caster_level ? t_max_level : caster_level);
		dnd_turns = atoi(dnd_matches[0]) + atoi(dnd_matches[1]) * t_cast_level / atoi(dnd_matches[2]);
	}

	return dnd_turns;
}

private int cast_sp(string spell)
{
	int caster_level;
 
	caster_level = TP->QueryGuildLevel();
	caster_level = (caster_level <= SIM_MAX_LEVEL?caster_level:SIM_MAX_LEVEL) * DND_MAX_LEVEL / SIM_MAX_LEVEL;
	caster_level = (caster_level <= m_entry(m_dnd_spells, spell)[GRI_SP_LVL_MAX]?caster_level:m_entry(m_dnd_spells, spell)[GRI_SP_LVL_MAX]);

	return (2*caster_level-1) /* * SIM_MAX_STAT / DND_MAX_STAT*/;
}

// Los turnos que el caster no podrá hacer más magia
private int cast_tired(string spell)
{
	return m_entry(m_dnd_spells, spell)[GRI_SP_HB_CAST]/* * DND_HB / SIM_HB*/;
}

// Comprueba si el gremio del caster está entre los permitidos
private int castable_guild(string spell)
{
	if (find_object(EFFECTS_DEBUGGER) && find_object(EFFECTS_DEBUGGER)->Query("DebugEffects") && TP->QueryRealName() == EFFECTS_DEBUGGER)
		return 1;
	if (mappingp(m_entry(m_dnd_spells, spell)[GRI_SP_GUILDS]))
	{
		if (!member(m_entry(m_dnd_spells, spell)[GRI_SP_GUILDS], TP->QueryGuild()))
			return notify_fail("Los miembros de tu gremio no pueden recitar este hechizo.\n", NOTIFY_NOT_VALID);
		if (m_entry(m_entry(m_dnd_spells, spell)[GRI_SP_GUILDS], TP->QueryGuild())[0] * SIM_MAX_LEVEL / DND_MAX_LEVEL > TP->QueryGuildLevel())
			return notify_fail("No tienes suficiente nivel para recitar este hechizo.\n", NOTIFY_NOT_VALID);
		return 1;
	}
	return (-1 < member(m_entry(m_dnd_spells, spell)[GRI_SP_GUILDS], TP->QueryGuild()));
}

// Comprueba si el caster tiene suficiente nivel para realizar el hechizo
private int castable_level(string spell)
{
	return ((m_entry(m_dnd_spells, spell)[GRI_SP_LVL_MIN] * SIM_MAX_LEVEL / DND_MAX_LEVEL) <= TP->QueryGuildLevel());
}

// Comprueba si el caster tiene suficiente magia para realizar el hechizo
private int castable_magic(string spell)
{
	return (cast_sp(spell) <= TP->QuerySP());
}

private int do_imprompt()
{
	if (TP->QuerySP() >= (TP->QueryMaxSP()/2))
	{
		write ("Recitas el hechizo y el lugar se impregna de tu misma esencia.\n");
		SetRecall(program_name(environment(TP)));
		TP->SetSP(TP->QuerySP() - (TP->QueryMaxSP()/2));
		return 1;
	}
	else
		return notify_fail("No tienes suficientes puntos de magia.\n", NOTIFY_NOT_VALID);
}

private int do_recall()
{
	object recall;

	if (TP->Fighting())
		return notify_fail("El fragor del combate impide que te concentres lo suficiente en el hechizo.\n", NOTIFY_NOT_VALID);
	if (!QueryRecall())
		return notify_fail("No recuerdas ningún lugar.\n", NOTIFY_NOT_VALID);
	if (TP->QuerySP() >= (TP->QueryMaxSP()))
	{
		if (!(recall=find_object(QueryRecall())))
			recall=load_object(QueryRecall());
		write ("Recitas el hechizo y vuelves al lugar que recuerdas.\n");
		TP->SetSP(0);
		TP->move(recall, M_TELEPORT);
		return 1;
	}
	else
		return notify_fail("No tienes suficientes puntos de magia.\n", NOTIFY_NOT_VALID);
}

// Mejorar resistencia (TP)
private int do_stamine(string stam, object * excludes)
{
	int tp, sp, min_int;				// Deberia ser min_sab pero no hay sabiduría
	string how;
	object victim;

	if (0 == m_entry(m_stamine, stam))
		return notify_fail("No sabes como darte un descanso "+stam+".\n", NOTIFY_ILL_ARG);
	else
	{
		sp = m_entry(m_stamine, stam)[0];
		how = m_entry(m_stamine, stam)[1];
		min_int = m_entry(m_stamine, stam)[2];
	}
	if (TP->QueryInt() < min_int)
		return notify_fail("Intentas descifrar el hechizo pero no eres lo suficientemente inteligente.\n", NOTIFY_NOT_VALID);
	tp = sp/6;							// Se recupera en fatiga un sexto de lo que se gasta en magia
	// A uno mismo
	if (1 == sizeof(excludes))
		victim = excludes[0];
	// A otro
	else
		victim = excludes[1];

	if (TP->QuerySP() > sp)
	{
		TP->SetSP(TP->QuerySP() - sp);
		victim->SetTP(victim->QueryTP() + tp);
		if (victim->QueryTP() > victim->QueryMaxTP())
			victim->SetTP(victim->QueryMaxTP());
		if (1 == sizeof(excludes))
		{
			write ("Recitas el hechizo y te encuentras "+how+" menos cansado.\n");
			say (CAP(TNAME)+" recita un hechizo y parece que se encuentra "+how+" menos cansado.\n", TP);
		}
		else
		{
			write ("Recitas el hechizo y "+CAP(victim->QueryName())+" se encuentra "+how+" menos cansado.\n");
			tell_object(victim, CAP(TNAME)+" recita un hechizo y te encuentras "+how+" menos cansado.\n");
			say (CAP(TNAME)+" recita un hechizo y parece que "+CAP(victim->QueryName())+" se encuentra "+how+" menos cansado.\n", excludes);
		}
		return 1;
	}
	else
	{
		say(CAP(TNAME)+" recita un hechizo pero parece que no hay ningún resultado.\n", TP);
		return notify_fail("No tienes suficientes puntos de magia.\n", NOTIFY_NOT_VALID);
	}
}

public int do_effect(string spell, object victim)
{
	object effect;
	string victim_name;					// Nombre de la victima
	string victim_ao;					// "a" "o" de la victima

	if ((m_entry(m_dnd_spells, spell)[GRI_SP_LIVING]) && !living(victim))
		return notify_fail("Este hechizo sólo lo puedes realizar sobre criaturas vivas.\n", NOTIFY_NOT_OBJ);
	if (!castable_guild(spell))
		return notify_fail("Los miembros de tu gremio no pueden recitar este hechizo.\n", NOTIFY_NOT_VALID);
	if (!castable_level(spell))
		return notify_fail("No tienes suficiente nivel para recitar este hechizo.\n", NOTIFY_NOT_VALID);
	if (!castable_magic(spell))
		return notify_fail("No tienes suficientes puntos de magia para recitar este hechizo.\n", NOTIFY_NOT_VALID);
	// Afecta a un living
	if ((m_entry(m_dnd_spells, spell)[GRI_SP_LIVING]))
	{
		// Datos de la victima
		victim_name = CAP(victim->QueryRealName());
		victim_ao = (victim->QueryGender()==GENERO_FEMENINO?"a":"o");

		if (m_entry(m_dnd_spells, spell)[GRI_SP_ALREADY] && present(spell, victim))
		{
			if (victim->QueryRealName() == TP->QueryRealName())
				return notify_fail(regreplace(regreplace(m_entry(m_dnd_spells, spell)[GRI_SP_MSG_ALREADY][0], "@@v_name@@", victim_name, 1), "@@v_ao@@", victim_ao, 1), NOTIFY_NOT_VALID);
			else
				return notify_fail(regreplace(regreplace(m_entry(m_dnd_spells, spell)[GRI_SP_MSG_ALREADY][1], "@@v_name@@", victim_name, 1), "@@v_ao@@", victim_ao, 1), NOTIFY_NOT_VALID);
		}
	}
	// Afecta a la room
	if ((m_entry(m_dnd_spells, spell)[GRI_SP_ROOM]))
	{
		victim_name = "";
		victim_ao = "";
		victim = environment(TP);

		if (m_entry(m_dnd_spells, spell)[GRI_SP_ALREADY] && present(spell, victim))
		{
			return notify_fail(m_entry(m_dnd_spells, spell)[GRI_SP_MSG_ALREADY][0], NOTIFY_NOT_VALID);
		}
	}

	effect = clone_object(m_entry(m_dnd_spells, spell)[GRI_SP_EFFECT]);
	if (!effect)
		return notify_fail("Los dioses son caprichosos y no quieren que puedas realizar el hechizo en estos momentos.\n", NOTIFY_NOT_OBJ);

	// Mensajes
	if (strlen(m_entry(m_dnd_spells, spell)[GRI_SP_MSG_ON][0]))
		effect->SetInitChat(regreplace(regreplace(m_entry(m_dnd_spells, spell)[GRI_SP_MSG_ON][0], "@@v_name@@", victim_name, 1), "@@v_ao@@", victim_ao, 1));
	if (strlen(m_entry(m_dnd_spells, spell)[GRI_SP_MSG_ON][1]))
		effect->SetEnvInitChat(regreplace(regreplace(m_entry(m_dnd_spells, spell)[GRI_SP_MSG_ON][1], "@@v_name@@", victim_name, 1), "@@v_ao@@", victim_ao, 1));
	if (strlen(m_entry(m_dnd_spells, spell)[GRI_SP_MSG_EXEC][0]))
		effect->SetExecChat(regreplace(regreplace(m_entry(m_dnd_spells, spell)[GRI_SP_MSG_EXEC][0], "@@v_name@@", victim_name, 1), "@@v_ao@@", victim_ao, 1));
	if (strlen(m_entry(m_dnd_spells, spell)[GRI_SP_MSG_EXEC][1]))
		effect->SetEnvExecChat(regreplace(regreplace(m_entry(m_dnd_spells, spell)[GRI_SP_MSG_EXEC][1], "@@v_name@@", victim_name, 1), "@@v_ao@@", victim_ao, 1));
	if (strlen(m_entry(m_dnd_spells, spell)[GRI_SP_MSG_OFF][0]))
		effect->SetEndChat(regreplace(regreplace(m_entry(m_dnd_spells, spell)[GRI_SP_MSG_OFF][0], "@@v_name@@", victim_name, 1), "@@v_ao@@", victim_ao, 1));
	if (strlen(m_entry(m_dnd_spells, spell)[GRI_SP_MSG_OFF][1]))
		effect->SetEnvEndChat(regreplace(regreplace(m_entry(m_dnd_spells, spell)[GRI_SP_MSG_OFF][1], "@@v_name@@", victim_name, 1), "@@v_ao@@", victim_ao, 1));

	// Lanzamos el hechizo
	if (find_object(EFFECTS_DEBUGGER) && find_object(EFFECTS_DEBUGGER)->Query("DebugEffects"))
		dtell(EFFECTS_DEBUGGER, sprintf("%s: sp %d - last: %d - tired: %d\n", spell, cast_sp(spell), cast_last(spell), cast_tired(spell)));

	if (effect->Affect(victim, cast_last(spell)))
	{
		TP->SetSP(TP->QuerySP()-cast_sp(spell));
		TP->SetTiredMagic(cast_tired(spell));
		//play_sound(environment(TP), SND_HABILIDADES("xxx"));
		return 1;
	}
	else
		return notify_fail("Tu hechizo ha fallado.\n");
}
