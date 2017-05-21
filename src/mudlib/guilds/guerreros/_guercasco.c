/*
** Guildobject del Gremio de Guerreros: Un casco alado
** Basado en el guildhelm del Gremio de Guerreros de NF.
** Autor: [n] Nemesis@Simauria, Ago'99
** Modificaciones: 17-Ago-99 [n]:
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


// learn_chance() ajusta la probabilidad de aprendizaje dependiendo del nivel
// al que esté el skill...:
// P(A+B) = P(A) + P(B) - P(AB)
// P(A.B) = P(B) * P(A/B)
// P(A/B) = P(AB)/P(B)
// Si A Y B son idependientes, P(A.B) = P(A)*P(B) (Como en este caso)
//   [0..19]  -> alrededor del 45% como valor máximo en el intervalo. (1/2)
//   [20..50] ->     "      "  30%   "    "      "    "  "     "    . (9/25)
//   [51..70] ->     "      "  11%   "    "      "    "  "     "    . (15/64)
//      >70   ->     "      "   1%   "    "      "    "  "     "    . (99/2500)

private int learn_chance(int level)
{
switch(level)
 {
  case  1..19 :
  {
   if(random(2)) return 1;
   break;
  }
  case  20..50:
  {
   if( (!random(5)) || (!random(5)) ) return 1;
   break;
  }
  case 51..70:
  {
   if ( (!random(8)) || (!random(8)) )
     return 1;
   break;
  }
  default:
  {
   if ( (!random(50)) || (!random(50)) )
     return 1;
   break;
  }
 }
 return 0;
}


public varargs int UseSkill(string name, int diff, int percent)
/* name=nombre del skill a usar
   diff=dificultad del skill en ese momento (-100..100)
*/
{
  //   Pos. Fallo, dado, diferencia, nivel del skill

  int  chance, dado, dif, level;
  int offset; // Penalizador para el skill "parada"
  mapping skills, tsk;

  // Si no es un skill de combate, no hay razón para no usar el UseSkill
  // normal y corriente.
  // La maza la usaré con el UseSkill normal... pa ver como sube ello...
  if (member(({HAB_HACHA, HAB_MAZA, HAB_CADENA, HAB_CRITICO, HAB_PARADA,
               HAB_ALABARDA, HAB_CUCHILLO, HAB_ESGRIMA, HAB_LANZA,
               HAB_VARA, HAB_ESPADA, HAB_SINARMAS, HAB_MANOPLA, HAB_MANGUAL
              }),name)==-1)
    return (owner()->UseSkill(name,diff));

// Inicializamos variables...
  skills=owner()->QuerySkills();
//  tsk=owner()->QueryTsk();
  level=owner()->QuerySkillLevel(name);
  if (name=HAB_PARADA) offset=random(4);
  else offset=0;
 // Y aquí comienza el rollo...
  if (diff<-100) diff=-100; // Muy difícil
  if (diff>100) diff=100;   // Muy fácil

 // Comprobación de utilidad discutible: siempre usaré skills que tenga.
 // No obstante, por si acaso...
  if (!owner()->HasSkill(name)) return (0);

// <chance> es la probabilidad de fallo: si la tirada es mayor, has fallado.

// El skill "golpe crítico" necesita un ajuste para que no se use muy a menudo.
  if (name == HAB_CRITICO) chance = skills[name,0]*diff/100;
  else chance = skills[name, 0]+diff;

 // Tirada del dado...
  dado = random(101);

  //Usa el skill:
  if (dado<=chance) // Si la tirada es menor que chance, has usado el skill.
  {
//    if (!tsk) tsk=([]);
//    owner()->SetTsk(name,time());
    percent = 100 - dado*100/chance; // Valor de retonno.
  }
  //No consigue usar el skill:

  else if (dado>chance)
  {
  // Falló, pero ¿en qué medida?
  dif=dado-chance;
  percent=dif*100/(100-chance);
  // Falles o no falles, tienes una posibilidad de aprender el skill,
  // siempre que lo tengas a menos del 20%
  // Tendré como máximo un 25% de posibilidades de que el skill suba...
  if (level<20&&percent<20)
   {
    if ( !random(4) && !offset &&
         (random(101) > level )
       )
	{
          write(TC_BOLD+name+" "+dado+owner()->QuerySkillLevel(name)+TC_NORMAL );
          write(TC_BOLD TC_CYAN+"Aprendes a usar la habilidad '"
           +name+"' un poco mejor.\n"+TC_NORMAL );
          skills[name, 0]++;
	}
   }
  return(0);
  }
// write("dado "+dado+"\n"+"chance "+chance+"\n"+"percent "+percent);

  if (skills[name, 0]<skills[name, 1])
    //     Reglas de Aprendizaje:
    //     * Consigas o no usar el skill bien, aprendes si el fallo es de
    //       menos del 20%
    //     * Si tienes el skill por debajo de 50, necesitas 30% de éxito.
    //     * Si tienes el skill por debajo de 70, necesitas 50% de éxito.
    //     * En otro caso, necesitas un 70% de éxito.
    // OJO: Necesitas ello para que te den la oportunidad de aprender.
    //      Aprender el skill supone pasar todos los tests de los "ifs"

    if ( (owner()->QuerySkillLevel(name)<50&&percent>=30) ||
	 (owner()->QuerySkillLevel(name)<70&&percent>=50) ||
         (owner()->QuerySkillLevel(name)>=70&&percent>=70)
	)
       {
       // Coloco la probabilidad en aprox. un 33% inicialmente. ¿M'he pasao?
       // Time will tell... aunque quizá es demasiado alto... O quizá no.
        if( learn_chance(owner()->QuerySkillLevel(name)) && !offset &&
	   ( random(101) > owner()->QuerySkillLevel(name) )
	  )
	{
//          write(TC_BOLD+name+" "+dado+owner()->QuerySkillLevel(name)+TC_NORMAL);
          write(TC_BOLD TC_CYAN+"Aprendes a usar la habilidad '"
           +name+"' un poco mejor.\n"+TC_NORMAL);
          skills[name, 0]++;
	}

       }

// Y finalmente grabas el estado y devuelves un número entre 0 y 100.
// Lo de entre 0 y 100 es para no liarla más aún. En un futuro permitiré
// que devuelva números negativos y los trataré como corresponda... o no.

  if (percent<0) percent=0;
  owner()->save();
  return(1);
}


public string QueryShort()
{
  if (!TP) return 0;
  if (!owner()||!owner()->QueryName()) return "un casco alado";
  if (TP==owner()) return "tu casco alado";
  return "el casco alado de "+capitalize(owner()->QueryName());
}

public varargs void SetAutoObject(mixed value)
{
  object pl;
  ::SetAutoObject(value);
  if (!pl = owner()) return;
  if (IS_LEARNER(pl)) return;
}

public int cmd_guskill()
{
 object pl;
 string sk,res;
 int plvl,sklvl;

 pl=TP;
 plvl=pl->QueryGuildLevel();
 res="";
 res+=HAB_IDENTIFICAR+"        :  "+pl->QuerySkillLevel(HAB_IDENTIFICAR)+"\n";
 res+=HAB_VARA+"    :  "+pl->QuerySkillLevel(HAB_CADENA)+"\n";
 (plvl>=NVL_CADENA?res+=HAB_CADENA+"   :  "+pl->QuerySkillLevel(HAB_CADENA)+"\n":res+="");
 (plvl>=NVL_CUCHILLO?res+=HAB_CUCHILLO+":  "+pl->QuerySkillLevel(HAB_CUCHILLO)+"\n":res+="");
 (plvl>=NVL_LANZA?res+=HAB_LANZA+"    :  "+pl->QuerySkillLevel(HAB_LANZA)+"\n":res+="");
 (plvl>=NVL_MAZA?res+=HAB_MAZA+"     :  "+pl->QuerySkillLevel(HAB_MAZA)+"\n":res+="");
 (plvl>=NVL_MANGUAL?res+=HAB_MANGUAL+"  :  "+pl->QuerySkillLevel(HAB_MANGUAL)+"\n":res+="");
 (plvl>=NVL_VENDAJE?res+=HAB_VENDAJE+"            :  "+pl->QuerySkillLevel(HAB_VENDAJE)+"\n":res+="");
 (plvl>=NVL_REPARAR?res+=HAB_REPARAR+"            :  "+pl->QuerySkillLevel(HAB_REPARAR)+"\n":res+="");
 (plvl>=NVL_ESPADA?res+=HAB_ESPADA+"   :  "+pl->QuerySkillLevel(HAB_ESPADA)+"\n":res+="");
 (plvl>=NVL_PARADA?res+=HAB_PARADA+"             :  "+pl->QuerySkillLevel(HAB_PARADA)+"\n":res+="");
 (plvl>=NVL_ESGRIMA?res+=HAB_ESGRIMA+"            :  "+pl->QuerySkillLevel(HAB_ESGRIMA)+"\n":res+="");
 (plvl>=NVL_HACHA?res+=HAB_HACHA+"    :  "+pl->QuerySkillLevel(HAB_HACHA)+"\n":res+="");
 (plvl>=NVL_LATIGO?res+="pelea con látigos  :  "+pl->QuerySkillLevel(HAB_LATIGO)+"\n":res+="");
 (plvl>=NVL_ALABARDA?res+=HAB_ALABARDA+":  "+pl->QuerySkillLevel(HAB_ALABARDA)+"\n":res+="");
 (plvl>=NVL_SINARMAS?res+=HAB_SINARMAS+"    :  "+pl->QuerySkillLevel(HAB_SINARMAS)+"\n":res+="");
 (plvl>=NVL_MANOPLA?res+=HAB_MANOPLA+"  :  "+pl->QuerySkillLevel(HAB_MANOPLA)+"\n":res+="");
 (plvl>=NVL_CRITICO?res+="golpe crítico"+"      :  "+pl->QuerySkillLevel(HAB_CRITICO)+"\n":res+="");
 (plvl>=NVL_BARBARO?res+=HAB_BARBARO+"    :  "+pl->QuerySkillLevel(HAB_BARBARO)+"\n":res+="");

 write(
 TC_BOLD" Estos son tus skills de Guerrero:\n"
 "===================================\n"
 "       skill        |     nivel\n"
 "-----------------------------------\n"+res+""TC_NORMAL );
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
      res+="  gsk[ills]              ver tus skills de gremio actales\n";
      if (LoadGuild())
	res+=QueryGuildObject()->is_leader(TP)?
	  "  gtp                    Teleportarse al gremio\n":"";
      res+=lvl<NVL_BARBARO?"": "  barbaro [<víctima>]   Grito del Bárbaro\n";
      res+=lvl<NVL_REPARAR?"":  "  reparar <objeto>      reparar un objeto\n";
      res+=lvl<NVL_IDENTIFICAR?"":"  identificar <object>  identificar un objeto\n";
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
	case "sk":
	case "skills":
	  res = "skills\n"
	        "Listar tus skills de gremio.\n";
	 break;
	case "gtp":
	  res = "gtp\n"
	        "Este comando puede ser usado por los líderes de gremio para teleportarse\n"
		"de vuelta al gremio y hablar p. ej. con otros miembros. Ésta es\n"
		"una teleportación muy restringida, asi que DEBES volver al lugar\n"
		"desde el que te transportaste.\n";
	 break;
	case "bárbaro":
	  res = "bárbaro [<víctima>]\n"
	        "Deja inconsciente a tu víctima, o a uno de tus enemigos si no das argumento,\n"
		"mediante un alarido de bárbaro.\n";
	 break;
	case "barbaro":
	  res = "barbaro [<víctima>]\n"
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

// CheckGuildDefend() maneja el skill "parada". Se invoca desde el Defend()
// del propio living antes de comprobar defensas intrínsecas o armaduras.

public int CheckGuildDefend(object enemy, int damage, int type)
{
  object pl;
  int success;
  // Como siempre, <diff> está alrededor del 10% como máximo:
  //diff=3+(pl->QueryStr()/10+pl->QueryDex()/20);

  if (   (pl = owner())
      && (member(({DT_BLUDGEON,DT_SLASH,DT_PIERCE}),type) != -1)
      && UseSkill(HAB_PARADA, 3+(pl->QueryStr()/10+pl->QueryDex()/20), &success)
     )
    {
      tell_object(pl,TC_BOLD" (parado)"TC_NORMAL);
      tell_room(environment(pl)," (parado)",({pl}));
//      write( ""+NMB->min(({damage,1+random(success)}))+"" );
      return NMB->min(({damage,1+random(success)}));
    }
  return 0;
}

SetExtralook(string desc) { extra = desc; }

string QueryExtralook()
{
// ¿Un tatuaje de lo cualo? Tengo que pensarlo...
return "Lleva un tatuaje en la frente.\n";
}

public void create()
{
  armour::create();
  if (!clonep()) return;

  seteuid(getuid());
  SetStandard(AT_CASCO,5,P_SIZE_GENERIC,M_TITANIO);
  SetIds(({"casco","casco de gremio","casco alado"}));
  SetAds(({"alado","un"}));
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
    add_action("cmd_guskill", "gskills");
    add_action("cmd_guskill", "gsk");
    add_action("cmd_gtp",     "gtp");
    add_action("cmd_gayuda",  "gayuda");
    add_false_cmds();
  }
}
