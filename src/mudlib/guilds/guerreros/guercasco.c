/*
** Guildobject del Gremio de Guerreros: Un casco alado
** Basado en el guildhelm del Gremio de Guerreros de NF.
** Autor: [n] Nemesis@Simauria, Ago'99
**
** Modificaciones:
**	[n] Nemesis@Simauria
**	[h] Nyh@Simauria
**
**		17-Ago-99 [n]:
**		   -Copio el UseSkill de /std/player/skills y
**                  lo modifico para que use las reglas de aprendizaje del
**                  gremio de guerreros.
**		   -Movida owner() al principio de todo.
**		   -Cambiados los "percentage" por UseSkills.
**                 -En la fórmula que calcula diff (chance) eliminada la
**                  multiplicación por 10 y cambiado el +30 a +20, para
**                  que la bonificación máxima sea del 50%.
**                 24-Ago-99 [n]:
**                 Retocado que te sobras UseSkill. Cambiado el nombre de la
**                 variable <sk_prob> a <dado> (que es lo que es) y añadida
**                 la variable <percent> para guardar el valor de retorno del
**                 éxito del skill. En el futuro usaré también el valor del
**                 fallo. De momento no merece la pena calentarse la cabeza.
**                 Más o menos parece que va.
**                 25-Ago-99 [n]:
**                 Dicho y hecho, he vuelto a pasarle a UseSkill <percent> por
**                 referencia para evitar el problema con el golpe crítico.
**                 02-Sep-99 [n]:
**                 Cambiadas las fórmulas de aprendizaje de UseSkill. Ahora no
**                 es difícil. Es casi imposible.
**                 03-Sep-99 [n]:
**                 Introducido un sistema de avance "adaptativo". Es bastante
**                 salvaje, pero parece funcionar.
**		   10-Sep-99 [n]:
**                 Reparado el "golpe crítico", ya que se usaba con éxito
**                 demasiado a menudo. Ahora utilizo la forma de uso del nivel
**                 de skill de NF para los críticos.
**                 Reparado también el skill de parada. Ahora que lo usa, sólo
**                 queda ajustarlo...
**
** Notas de Diseño: La habilidad de "parada" no se ve subir, ya que lo único
**                 que hace el mensaje es molestar.
**
**                 [30-Nov-99] Retocado por Woo para que funcione mejor.
**                 Cambiado owner() y QueryShort().
**
**		   [19-Ene-00] Ampliamente retocado por Theuzifan: Ahora se
**		   usan las habilidades del jugador, se ha corregido algún
**		   fallo como la comprobación de que un miembro podía tener
**   		   o no una habilidad. Antes tan sólo se miraba si tenía el
**                 nivel adecuado para tener un ahabilidad, pero si ese
**		   personaje moría bajaba de nivel, por lo que ya no podía
**		   usar esa habilidad. Además había
**                 por ahí rulando algún que otro fallo de implementación que
**                 ha sido corregido. La función gsk[ill] se ha ido y en su
**                 lugar aparece ghab[ilidades]. El formato de la misma
**                 también ha cambiado (la separación con tabuladores puede
**                 ser peligrosa, como de hecho lo era), siendo copiada
**                 vilmente la del gremio de guardabosques, con colorcillos y
**                 eso. El comando gayuda ha sido modificado y arreglado puesto
**                 que no habia ayuda sobre 'gskills' sino sobre skills, y
**                 alguna que otra cosa por el estilo. La obtención del
**                 skill a partir del arma usada en el WeaponHit es ahora más
**                 simple, no hacía falta semejante tocho de ifs ni de x?y:z
**		   Recortado el daño que hacía el crítico (podía hacer hasta
**		   un 200% de daño (!!!!???), lo que era inutil... ¿pa que le
**		   vas a quitar el doble de su vida?. Ahora como máximo le
**		   quita el 50% de su vida total, no de la que tenga. Antes
**		   se usaba el QueryHP, por lo que se le quitaba en función de
**		   la vida que le quedara. Ahora no, ahora quita en función
**		   del máximo de la vida que tenga (QueryMaxHP).
**		   Para el resto de skills normales se han usado las fórmulas
**		   que hay en el gremio tanto de kisalas como de guardabosques.
**		   que en algunos casos el daño que se le infrinja ahora será
**		   mayor y en otros casos menor. Y más o menos eso es todo!
**
**                 22-02-00 [Theuzifan], Cambiada la función de probabilidad
**		   del crítico... ahora es la destreza tuya menos la del
**                 enemigo.
**
**		   25-02-00 [Theuzifan] Retoco el crítico y el modificador de los
**		   skills.
**                 25-02-02 [n] Retocado el grito para que no se puedan gritar
**                              a sí mismos (mia que hay gente retorcida...)
** 25-04-03 [h] Con el nuevo sistema de combate me penco las actuales
**		habilidades de combate de aqui
*/

#include "wguild.h"
#include <config.h>     // NOTIFY_
#include <combat.h>     // AT_, DT_, EQ_
#include <properties.h> // PSIZE_
#include <skills.h>     // HAB_
#include <races.h>      // RD_
#include <wizlevels.h>
#include <colours.h>

#define P_LAST_ENEMY "LastEnemy" //logging
#define P_LAST_HP "LastHP" // logging

#define skillweapon ([WT_ALABARDA:HAB_ALABARDA,WT_HACHA:HAB_HACHA,\
	WT_CADENA:HAB_CADENA,WT_MAZA:HAB_MAZA,WT_CUCHILLO:HAB_CUCHILLO,\
	WT_LANZA:HAB_LANZA,WT_VARA:HAB_VARA,WT_ESPADA:HAB_ESPADA,\
	WT_ESGRIMA:HAB_ESGRIMA,WT_LATIGO:HAB_LATIGO,WT_MANGUAL:HAB_MANGUAL,\
	WT_MANOPLA:HAB_MANOPLA,"CsHands":HAB_SINARMAS])

#define CR(x) (TC_RED    + x + TC_NORMAL)
#define CY(x) (TC_YELLOW + x + TC_NORMAL)
#define CG(x) (TC_GREEN  + x + TC_NORMAL)
#define CB(x) (TC_BOLD   + x + TC_NORMAL)
#define CU(x) (TC_UNDERL + x + TC_NORMAL)

inherit "/std/armour";
inherit "/obj/lib/guildobj";
inherit STR;
inherit NMB;

private static int normal_attacks;
private string extra;

private object owner()
{
  object pl;
  pl = environment(TO);
  if (!pl) return 0;
  return pl;
}


public varargs void SetAutoObject(mixed value)
{
  object pl;
  ::SetAutoObject(value);
  if (!pl = owner()) return;
  if (IS_LEARNER(pl)) return;
}

string nivel(int n)
{
  if (!n) return "desconocido";
  switch (n) {
    case 0..4:   return CR("desastroso");
    case 5..9:   return CR("fatal");
    case 10..14: return CR("pésimo");
    case 15..19: return CR("muy mal");
    case 20..24: return CR("mal");
    case 25..29: return CB("mediocre");
    case 30..39: return CB("regular");
    case 40..49: return CB("aceptable");
    case 50..54: return CB("adecuado");
    case 55..64: return CG("bueno");
    case 65..69: return CG("muy bueno");
    case 70..79: return CG("excelente");
    case 80..89: return CG("óptimo");
    case 90..98: return CG("casi perfecto");
    case 99..100: return CG("perfecto");
    default: return "desconocido";
  }
  return "desconocido";
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
    if (member(HAB_GUERREROS, idx[i])!=-1 && TP->SkillIsEnabled(idx[i]))
    {
      if (!(j%2))
        g+=sprintf("%-48s", "  "+STR->ladjust(idx[i]+" ",23,".")+" "+nivel(sk[idx[i], 0]))+TC_NORMAL;
      else
        g+=STR->ladjust(idx[i]+" ",23,".")+" "+nivel(sk[idx[i], 0])+"\n";
      j++;
    }
  }
  if (g!="") return TC_BOLD+"Habilidades de guerrero:\n"+TC_NORMAL+g+(j%2?"\n":"");
  return "No tienes ninguna habilidad.\n";
}

public int cmd_guskill()
{
  write(skill_list());
  return 1;
}


public int cmd_gayuda(string str)
{
  string res;
  int lvl;

  if (!TP) return 0;
  if (!str)
    {
      lvl = TP->QueryGuildLevel();
      res = "Tienes los siguientes comandos disponibles:\n";
      res+="  gayuda [<comando>]     ayuda general, sobre los comandos\n";
      res+="  gquien                 ver a los guerreros conectados\n";
      res+="  ggritar <texto>        gritar a todos los miembros del Gremio\n";
      res+="  gbug [<bugmsj>]        dar un bug concerniente al gremio\n";
      res+="  gidea [<ideamsj>]      dar una idea para el gremio\n";
      res+="  gtypo [<typomsj>]      dar un typo concerniente al gremio\n";
      res+="  ghab[ilidades]         ver tus skills de gremio actales\n";
      if (LoadGuild())
	res+=QueryGuildObject()->is_leader(TP)?
	  "  gtp                    Teleportarse al gremio\n":"";
      if (TP->SkillIsEnabled(HAB_BARBARO))
        res+="  barbaro [<víctima>]   Grito del Bárbaro\n";
      if (TP->SkillIsEnabled(HAB_REPARAR))
        res+="  reparar <objeto>      reparar un objeto\n";
      if (TP->SkillIsEnabled(HAB_IDENTIFICAR))
        res+="  identificar <object>  identificar un objeto\n";
//      res+="Las habilidades de combate sólo pueden ser usadas con el casco puesto.\n";
    }
  else
    switch(str)
      {
       case "gayuda":
	 res = "gayuda [<comando>]\n"
               "Da una ayuda general o ayuda sobre un comando específico.\n";
	 break;
	case "gquien":
	  res = "gquien\n"
	        "Da una lista de todos los miembros conectados y visibles.\n";
	 break;
	case "ggritar":
	  res = "ggritar <text>\n"
	        "Lanza tus palabras a todos los miembros conectados.\n";
	 break;
	case "gbug":
	case "gtypo":
	case "gidea":
	  res = "gbug, gtypo, gidea [<text>]\n"
	        "Dar un comentario relacionado con el gremio, p. ej. si un comando\n"
		"no funciona aunque debería.\n";
	 break;
	case "ghab":
	case "ghabilidades":
	  res = "ghabilidades\n"
	        "Listar tus skills de gremio.n";
	 break;
	case "gtp":
	  res = "gtp\n"
	        "Este comando puede ser usado por los líderes de gremio para teleportarse\n"
		"de vuelta al gremio y hablar p. ej. con otros miembros. Ésta es\n"
		"una teleportación muy restringida, asi que DEBES volver al lugar\n"
		"desde el que te transportaste.\n";
	 break;
	case "bárbaro":
	case "barbaro":
	  res = "bárbaro [<víctima>]\n"
	        "Deja inconsciente a tu víctima, o a uno de tus enemigos si no das argumento,\n"
		"mediante un alarido de bárbaro.\n";
	 break;
	case "reparar":
	  res = "reparar <objeto>\n"
	        "Puedes reparar armas y armaduras si estás en una herrería.\n";
	 break;
	case "identificar":
	  res = "identificar <objeto>\n"
	        "Obtener informaciones interesantes para un guerrero sobre un arma\n"
		"o una armadura.\n";
	 break;
	default:
	 return notify_fail("Lo siento, no hay ayuda del gremio sobre ese tema.\n"),0;
       }
  smore(res,TP->QueryPageSize());
  return 1;
}

public int cmd_barbary(string str) { return WMASTER->barbary_scream(str); }

public int cmd_repair(string str) { return WMASTER->repair(str); }

public int cmd_identify(string str) { return WMASTER->identify(str); }

private status check_higher(object compare,int base,int intel)
{
  int delta,cwc;
  delta = random(intel)/10;
  if (delta>2) delta = 2;
  delta = 2-delta;
  cwc = compare->QueryWC();
  return random(2)?cwc>base+delta:cwc>base-delta;
}

private status check_equal(object compare,int base,int intel)
{
  int delta,cwc;
  delta = random(intel)/10;
  if (delta>2) delta = 2;
  delta = 2-delta;
  cwc = compare->QueryWC();
  return (cwc>=base-delta) && (cwc<=base+delta);
}

private status check_lighter(object compare,int base,int intel)
{
  int percent,cweight,i;
  i = random(30);
  if (intel<i)
    percent = intel*100/i;
  else
    percent = 100;
  cweight = compare->QueryWeight();
  return (cweight*percent/100)<base;
}

private void check_weapon(object pl,object wp)
{
  object *weapons,*equal_wc,*higher_wc,*lighter;
  int i,j;
  if (!pl || !wp) return;
  weapons = filter_objects(all_inventory(pl),"QueryWeaponType");
  weapons-=({wp});
  i = pl->QueryInt();
  if (pl->QueryAlcohol()>pl->QueryMaxAlcohol()*75/100)
    i-=1+random(3);
  if (i<0) i = 0;
  j = wp->QueryWC();
  higher_wc = filter(weapons,SF(check_higher),j,i);
  weapons-= higher_wc;
  equal_wc = filter(weapons,SF(check_equal),j,i);
  j = wp->QueryWeight();
  lighter = filter(equal_wc,SF(check_lighter),j,i);
  if (sizeof(lighter))
    tell_object(pl,
		"Sopesas "+(wp->Short()||"el arma")+" en tu mano "
		"y la comparas con las otras armas que llevas.\n Averiguas "
		"que las siguientes armas son tan buenas, pero que "
		"pesan menos: "+implode_list(map_objects(lighter,"Short"), 0, ".\n"));
  if (sizeof(higher_wc))
    tell_object(pl,
		"Compruebas la potencia de "+(wp->Short()||"el arma")+
		" y te das cuenta de que las siguientes armas son mejores:\n"+
		implode_list(map_objects(higher_wc,"Short"), 0, ".\n"));
}

public void NotifyEquip(object liv, object ob, int flags)
{
  object ho;

  if (!ob || !liv) return;
  if (ob->QueryMagic() && 15+liv->QueryInt()>random(30))
    tell_object(liv,"Sientes una extraña sensación en la mano cuando "
		"empuñas "+(ob->Short()||"el arma")+".\n");

  check_weapon(liv, ob);
}

SetExtralook(string desc) { extra = desc; }

string QueryExtralook()
{
// ¿Un tatuaje de lo cualo? Tengo que pensarlo...
return "Lleva un tatuaje en la frente.\n";
}

public void create()
{
  "*"::create();
  if (!clonep()) return;

  seteuid(getuid());
  SetStandard(AT_CASCO,5,P_SIZE_GENERIC,M_TITANIO);
  SetIds(({"casco","casco de gremio","casco alado"}));
  SetAds(({"alado","un"}));
  SetShort("un casco alado");
  SetLong(
       "Este casco alado es de alguna manera especial. Cuando lo miras de\n"
       "cerca encuentras un pequeño signo grabado en él. Este casco debe ser\n"
       "un artículo especial que el Gremio de Guerreros distribuye a todos\n"
       "sus miembros. Sabes que 'gayuda' te dará ayuda sobre este gremio.\n");
  SetValue(0);
  SetWeight(0);
  SetExtralook("");
  SetNoDrop("¡No tires tu casco!\n");
  SetNoGive("¡No des tu casco al primero que pase!\n");
  SetGuild(WARRIORS);
  SetResetQuality(100);
  SetAPperQP(0);
//  SetUsage(EQM_WEAR);
}

public void init()
{
  object ob;
  (::init());

  if (!TP) return;
  ob=owner();

  if (ob && ob==TP)
  {
//    Equip(ob, EWF_WEAPON | EWF_SILENT);
    add_action("cmd_barbary", "barbaro");
    add_action("cmd_barbary", "bárbaro");
    add_action("cmd_repair",  "reparar");
    add_action("cmd_identify","identificar");
    add_action("cmd_gwho",    "gquien");
    add_action("cmd_gshout",  "ggritar");
    add_action("cmd_gbug",    "gbug");
    add_action("cmd_gidea",   "gidea");
    add_action("cmd_gtypo",   "gtypo");
    add_action("cmd_guskill", "ghab", 1);
    add_action("cmd_gtp",     "gtp");
    add_action("cmd_gayuda",  "gayuda");
    add_false_cmds();
  }
}
