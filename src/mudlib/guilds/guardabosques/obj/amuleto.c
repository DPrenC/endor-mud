/* SIMAURIA '/guilds/guardabosques/obj/amuleto.c'
   ==============================================

   [t] Theuzifan
   [h] Nyh

   20-10-99 [t] Creación (GUILDOBJECT)
   22-02-00 [t] Modifico las funciones de ataque y defensa.
   29-02-00 [t] Arreglo el Defend...
   03-03-00 [t] Arreglo un fallo del create() añadiendo un call_out
   18-04-00 [t] El objeto ya no se salva.
   28-06-00 [t] El objeto deja de ser algo 'wereable' para ser un objeto
   		común.
   09-01-01 [t] Reescrito para añadir la funcionalidad requerida para resetear
   		el estado del personaje al salir (cambios del Short, Long, ...,
   		por medio de la magia).
   18-01-01 [t] Eliminado el save al mover el objeto, que interfería con
   		el del quit, y se perdía el inventario...
   19-02-01 [t] Again... ahora en el remove...
   09-02-02 [t] Se comprueba que las armaduras que se puedan poner sean, eso,
   		armaduras (ChkEquip)
   10-01-02 [t] Se da cuenta de que puede viajar en el tiempo! TEMBLAD MORTALES!!
   		MWA HA HA HA!!! hmmm... estee... el amuleto vuelve a su estado
   		original para hacer que sea wereable (PC?).
   		Las habilidades de gremio cuestan menos para subir que las
   		estándar.
   13-01-02 [t] Se añade una comprobación en el ResetProperty. La propiedad puede
   		haber variado desde que se cambió hasta que vuelve a su estado
   		original.
   05-03-03 [t] Cambio el parámetro "old" a tipo mixed, que por alguna extraña
   		razón era int. De paso loggeo los casos curiosos de recuperación
   		de propiedades (cuando haces un setproperty y lo que se
   		devuelve no es lo que has metido).
   09-03-03 [t] Arreglo un bug en el log_file (TP no es %s, por
   		poco que lo parezca ;)).
   21-04-03 [t] Arreglo un division by zero...
   25-04-03 [h] Con el nuevo sistema de combate me penco las actuales
 		habilidades de combate de aqui
*/

#include <properties.h>
#include <guild.h>
#include <skills.h>
#include <colours.h>
#include <combat.h>
#include <moving.h>
#include <spells.h>
#include "./path.h"

inherit "/std/thing";
inherit "/obj/lib/guildobj";

//#define DEBUG
#define glog(x) log_file("gremios/guardabosques/amuleto.log", sprintf("%O %s: ", TP, ctime())+x)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

#define wear_allowed ({M_CUERO_TXT, M_TELA_TXT, M_PIEL_TXT, M_MADERA_TXT,\
		M_HUESO_TXT, M_ESPECIAL_TXT, M_DESCONOCIDO_TXT})

#define CR(x) (TC_RED    + x + TC_NORMAL)
#define CY(x) (TC_YELLOW + x + TC_NORMAL)
#define CG(x) (TC_GREEN  + x + TC_NORMAL)
#define CB(x) (TC_BOLD   + x + TC_NORMAL)
#define CU(x) (TC_UNDERL + x + TC_NORMAL)
#define SPELL(x) "'"+x+"'"

static int bonus;
static string *autospell;
static mapping properties;

create()
{
  int i;

  ::create();
  if (!clonep()) return;

  seteuid(getuid(TO));
  SetLong("Es un amuleto hecho con el colmillo de algún animal que "
  	"te identifica como miembro del gremio de los Guardabosques. "
  	"Puedes usar el comando 'gayuda' para obtener información del "
  	"gremio.\n");
  SetShort("un amuleto");
  SetMaterial(M_HUESO);
  SetSize(P_SIZE_GENERIC);

  SetGuild(BASE+"gremio");

  SetIds(({"amuleto", "amuleto de los guardabosques"}));
  SetWeight(0);
  SetValue(0);
  Set(P_NOSELL,"Sería una ofensa para el gremio si lo vendieses.\n");
  Set(P_NOBUY);
  Set(P_NOGIVE);
  Set(P_NODROP);
  SetUsage(EQM_WEAR);
  autospell=({});

}


init()
{
  string *sk;
  int i;

  ::init();

  if (!TP) return;

  if (TP->QueryRealName()==QueryOwner())
  {
    Equip(TP, EWF_WEAPON | EWF_SILENT);
  }

  add_action("cmd_gayuda", "gayuda");
  add_action("cmd_gestado", "ghab",1);
  add_action("cmd_magia", "", 1);

}

/* obtener las propiedades a restaurar */
mapping QueryPlayerProperties() {
	return properties||([]);
}

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
			glog(sprintf("Oldvalue Changed %s, SET %O(%O), WAS %O, IS %O\n", prop, tovalue, must, oldvalue, newvalue));
			/* uiuiui */
		}
		else if (tovalue != newvalue) {
			newvalue = oldvalue;
			glog(sprintf("Tovalue Changed %s, SET %O(%O), WAS %O, IS %O\n", prop, tovalue, must, oldvalue, newvalue));
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
	glog(sprintf("RESET BY TIME %d, PROPS %O\n", time, props));
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

	glog(sprintf("RESET %O\n", props));
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
//	TP->save();
	return ::remove();
}

int cmd_magia(string str)
{
  if (!member(magia, query_verb())) return 0;

  if (TP->QueryTiredMagic())
    return notify_fail(W("El uso de otras habilidades mágicas te ha agotado; "
    	"debes esperar un poco.\n")),0;

  return "/secure/daemons/magicd"->main(TP, SPELL(magia[query_verb()])+" "+str);
}


string nivel(int en, int rn)
{
  int n;
  string str;

  if (!en || !rn) return "desconocido";
  n=(en*100)/rn;
  switch (n) {
    case 0..4:   str=CR("desastroso"); break;
    case 5..9:   str=CR("fatal"); break;
    case 10..14: str=CR("pésimo"); break;
    case 15..19: str=CR("bastante mal"); break;
    case 20..24: str=CR("mal"); break;
    case 25..29: str=CY("mediocre"); break;
    case 30..39: str=CY("regular"); break;
    case 40..49: str=CY("aceptable"); break;
    case 50..54: str=CY("adecuado"); break;
    case 55..64: str=CG("bueno"); break;
    case 65..69: str=CG("muy bueno"); break;
    case 70..79: str=CG("excelente"); break;
    case 80..89: str=CG("óptimo"); break;
    case 90..98: str=CG("casi perfecto"); break;
    case 99..100: str=CG("perfecto"); break;
    default: str=CG("desconocido"); break;
  }
  if (en>=rn-1) str+=" (+)";
  return str;
}

string skill_list()
{
  mapping sk;
  mixed *idx;
  string g;
  int i, j;

  g="";

  sk=TP->QuerySkills();
  idx=m_indices(sk||({}));
  j=0;

  for (i=0; i<sizeof(idx); i++)
  {
    if (member(HAB_GUARDABOSQUES, idx[i])!=-1 && TP->SkillIsEnabled(idx[i]))
    {
      if (!(j%2))
        g+=sprintf("%-48s", "  "+STR->ladjust(idx[i]+" ",20,".")+" "+nivel(sk[idx[i], 0], sk[idx[i], 1]));
      else
        g+=STR->ladjust(idx[i]+" ",20,".")+" "+nivel(sk[idx[i], 0], sk[idx[i], 1])+"\n";
      j++;
    }
  }
  if (g!="") return TC_BOLD+"Habilidades:\n"+TC_NORMAL+g+(j%2?"\n":"");
  return "No tienes ninguna habilidad.\n";
}

string spell_list()
{
  mapping sk;
  mixed *idx;
  string g;
  int i, j;

  g="";

  sk=TP->QuerySpells();
  idx=m_indices(sk||({}));
  j=0;

  for (i=0; i<sizeof(idx); i++)
  {
    if (member(MAG_GUARDABOSQUES, idx[i])!=-1 && TP->SpellIsEnabled(idx[i]))
    {
    if (!(j%2))
      g+=sprintf("%-48s", "  "+STR->ladjust(idx[i]+" ",20,".")+" "+nivel(sk[idx[i], 0], sk[idx[i], 1]));
    else
      g+=STR->ladjust(idx[i]+" ",20,".")+" "+nivel(sk[idx[i], 0], sk[idx[i], 1])+"\n";
    j++;
    }
  }

  if (g!="") return TC_BOLD+"Habilidades Mágicas:\n"+TC_NORMAL+g+(j%2?"\n":"");
  return "No tienes ninguna habilidad mágica.\n";
}

int cmd_gestado()
{
  string str;
  str=skill_list()+spell_list();
  if (strstr(str, "(+)")) str+="El '(+)' indica que puedes continuar aprendiendo esa habilidad en tu gremio.\n";
  write(str);
  return 1;
}


int cmd_gayuda(string str)
{
  string txt;
  int err, size;

  if (!str) str="general";
  txt=BASE+"ayuda/"+str;
  err = catch(size = file_size(txt));
  if (err || size <= 0)
    return notify_fail("No hay información disponible sobre ese tema.\n"),0;
  TP->more(txt, 1);

 return 1;
}

varargs mixed ChkEquip(object liv, object wear, int flags)
{
  if (member(inherit_list(wear), "/std/armour.c") != -1 &&
      member(wear_allowed, wear->QueryMaterial()) == -1) {
  	return EQ_FORBID;
  }
  return ::ChkEquip(liv, wear, flags);
}
