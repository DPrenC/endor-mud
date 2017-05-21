/*
** Control de las habilidades de los Guerreros
** Autores: Cadra & Thragor@Nightfall, 22feb96
** Cambios:
** Nemesis@Simauria: [7-Nov-98] Traducción y ligeros cambios.
**                   [9-Nov-98] Función repair()-> Añadida comprobación de género.
**                   [Àgo - 99] Castellanización y adaptación final a Simauria.
**                   [17-Ago-99] Cambiados todos los antiguos UseSkill por
**                              UseSkill de formato nuevo.
**			- Cambiada la fórmula de la dificultad del Grito.
**			  En lugar de multiplicar por 10, se divide; y en
**			  vez de ponerla a 0 si tenía más del 100% de
**                        protección, la pone a -100.
**                      - En este archivo, la comprobación de fallo NO es
**                        que percent sea 0, sino que sea menor o igual que 0.
**                    [27-Ago-99] Repaso general y quitados los writes donde
**                       se mostraba por pantalla el valor de UseSkill y <diff>.
**                    [06-Sep-99] Añadido un if para bajar la ResetQuality en
**			 un 5% cada vez que se tenga un éxito de más del 10%.
**			 Si tienes un éxito de más del 90%, la ResetQuality
**			 subirá en un 10%, porque se supone que es un éxito
**			 crítico.
**                       Por otra parte, si la cagas, la ResetQuality baja en
**                       un 20%.
**                    [14-Sep-99] Quitado lo anterior: me he dado cuenta de
**                       que haciendo esto sólo conseguía pasar de una rodela
**                       ligeramente dañada a una rodela _machacada_ después de
**                       tres o cuatro _aciertos_ :) .
**                    [21-Sep-99] La ResetQuality puede subir como máximo hasta
**                       el 95%. Es decir, sólo por el hecho de reparar un
**                       objeto, ya no lo puedes dejar al 100%.
**                    [22-Ene-00] Alarido del Bárbaro. Bajado el tiempo de stun
**                       de 5 a 3. Si logras hacerle huir, huye y punto, no se
**                       queda iscociente iscociente.
**                    [16-May-00] Reparar: ya no te cansas, era un coñazo...
**                    [11-Ene-01] Reparar: ahora SI funcionan los subniveles...
**
**
**
**
** NOTA sobre el repair: Un guerrero repara las armas mejor que en la herrería,
**                      ya que siempre tiene una probabilidad de cagarla y
**                      cargarse el objeto, cosa que un herrero no hará.
*/

#include "wguild.h"
#include <materials.h>
#include <moving.h>
#include <config.h>
#include <combat.h>
#include <search.h>
#include <properties.h>
#include <colours.h>
#include <messages.h>
#include <sounds.h>
#include <effects.h>
#include <ts.h>
#include <skills.h>

#define ART(x)   (x->QueryGenderEndString())

#define TIPO_DE_SALVACION SAVE_TYPE_FORTITUDE

#define DEBUG

#define LOGFILE(x)	GUILDLOGPATH "guerreros/" + x + ".log"

inherit NMB;

private void Debug(string where, string what) {
#ifdef DEBUG
  write_file(LOGFILE(where),what);
#endif
}

protected varargs int _notify_fail(mixed ownmsg,mixed envmsg,
                                 mixed vicmsg,object victim)
{
  mixed ownfun,envfun,vicfun;
  object pl;
  closure wrap_fun;

  pl = TP;
  wrap_fun = symbol_function("wrap",STR);

  if (!ownmsg&&!envmsg) return 0;

  if (pointerp(ownmsg))
    ownfun = ({SF(tell_object),pl,quote(({MSG_SEE})+map(ownmsg,wrap_fun))});
  else
    if (stringp(ownmsg))
      ownfun = ({SF(write),W(ownmsg)});
    else
      ownfun = 0;

  if (pointerp(envmsg))
    envfun = ({SF(tell_room),environment(pl),
               quote(({MSG_SEE})+map(envmsg,wrap_fun)),SYM(({pl,victim}))});
  else
    if (stringp(envmsg))
      envfun = ({SF(tell_room),environment(pl), quote(({MSG_SEE, W(envmsg)})),
                 SYM(({pl,victim}))});
    else
      envfun = 0;

  if (pointerp(vicmsg))
    vicfun = ({SF(tell_object),victim,quote(({MSG_SEE})+map(vicmsg,wrap_fun))});
  else
    if (stringp(vicmsg))
      vicfun = ({SF(tell_object),victim,W(vicmsg)});
    else
      vicfun = 0;
  return notify_fail(lambda(0,({CL_PROGN,({CL_PROGN,ownfun,vicfun}),envfun})),
                     NOTIFY_NOT_VALID),0;
}

protected varargs int _notify_succes(mixed ownmsg,mixed envmsg,
                                    mixed vicmsg,object victim)
{
  mixed ownfun,envfun,vicfun;
  object pl;

  pl = TP;

  if (!ownmsg&&!envmsg) return 0;

  if (pointerp(ownmsg))
    ownfun = ({SF(tell_object),pl,quote(({MSG_SEE})+ ownmsg)});
  else
    if (stringp(ownmsg))
      ownfun = ({SF(write),ownmsg});
    else
      ownfun = 0;

  if (pointerp(envmsg))
    envfun = ({SF(tell_room), environment(pl),
               quote(({MSG_SEE})+ envmsg),quote(({pl,victim}))});
  else
    if (stringp(envmsg))
      envfun = ({SF(tell_room),environment(pl),envmsg,
                 quote(({pl,victim}))});
    else
      envfun = 0;

  if (pointerp(vicmsg))
    vicfun = ({SF(tell_object),victim,quote(({MSG_SEE})+vicmsg)});
  else
    if (stringp(vicmsg))
      vicfun = ({SF(tell_object),victim,vicmsg});
    else
      vicfun = 0;
  return funcall(lambda(0,({CL_PROGN,({CL_PROGN,ownfun,vicfun}),envfun}))),1;
}

protected status check_sight()
{
  if (TP->Query(P_BLIND))
    return _notify_fail("Estás ciego.\n");
  if (TP->CantSee())
    return _notify_fail(TP->CantSee()<0?"Está demasiado oscuro.\n":"Hay demasiada luz.\n");
  return 1;
}

protected status check_ghost()
// Used to check if a spell might be cast, if it mustn't be cast
// when TP is a ghost.
{
  if (TP->QueryGhost())
    return _notify_fail("No puedes hacer eso en tu estado inmaterial.\n"),1;
  return 0;
}

protected object check_env()
// Check if the environment of TP is existant
{
  return environment(TP)||
         _notify_fail("No puedes hacer magia en el tejido del espacio-tiempo.\n");
}

protected status check_delay()
{
  if (TP->QueryCombatDelay())
    return _notify_fail(TP->QueryCombatDelayMsg()||"Estás inconsciente.\n"),1;
  return 0;
}

protected object get_enemy(object pl,string str)
{
  object enemy,*enemies;
  if (!str)
    {
      if (!sizeof(enemies = (pl->QueryEnemies()||({}))-({0})))
        return _notify_fail("No estás peleando con nadie.\n"),0;
      enemy = enemies[<1];
    }
  else
    {
      if (!enemy=search(pl,str,SEARCH_ENV|SM_OBJECT|SM_IGNLIGHT))
        return _notify_fail(capitalize(str)+" no está aquí.\n"),0;
      if (!living(enemy))
        return _notify_fail(capitalize(str)+" no está vivo.\n"),0;
    }
  return enemy;
}

protected int calc_defence(object ob,int damtype)
// To detect how well the opponent is protected against certain
// damages.
{
  int defence,i,*defs;
  object *arms;
  defence = ob->GetDefence(damtype);
  arms = ob->QueryArmours();
  for (i=sizeof(arms); i--; )
    defence += arms[i]->GetDefence(damtype);
  return defence;
}

protected varargs string Descr(object ob, status cap)
{
  string res;
  if (!ob) return cap?"Algo":"algo";
  if (!res) res = ob->QueryName();
  if (!res) res = ob->QueryShort();
  if (!res) res = "algo";
  return cap?capitalize(res):res;
}

private status check_scream()
{
  int drink;
  if (!TP) return 0;
  drink = TP->QueryDrink();
  if (drink<-COST_SCREAM)
    return _notify_fail("Te duele la garganta. Está demasiado seca.\n");
  return 1;
}

// object: tio q lo usa
// int: nivel del que lo usa
// nada: dc a nivel NIV_STUN_ASESINOS
public varargs int QuerySaveDC(mixed mix) {
  if (objectp(mix)) {
    return 10 + (mix->QueryGuildLevel())/10 + mix->QueryDexModifier();
  }
  if (intp(mix)) {
    return 10 + ((int)mix)/10;
  }
  return 10 + NIV_STUN_ASESINOS/10;
}

public int barbary_scream(string str)
  /*
   ** Command: scream
   ** Skill:   HAB_BARBARY
   ** Alias:   sc
   ** Descr.:  Force a monster to run away or to 'stun' it.
   ** Author:  Thragor@Nightfall, 03jun95
   ** Update:  Thragor@Nightfall, 15jan96
   */
{
  object victim, atk, effect;
  int defence, percent, drink_cost, tiempo;
  string action;

  atk=TP;
  if(atk->QueryGuildLevel()<NIV_BARBARO_GUERREROS)
  return _notify_fail("Aún no puedes impresionar a la gente con tus gritos de bárbaro.\n");
  if (!atk) return 0;
  if (atk->QueryTP()<5) return _notify_fail("Estás demasiado cansad " + ART(atk) + " para gritar.\n");
  if (   check_delay()
      || check_ghost()
      || !check_sight()
      || !(victim=get_enemy(atk,str))
      || victim == atk
      || !check_scream()
      || !atk->CanKill(victim)
     )
    return 0;
  if (!query_wiz_level(atk) && query_once_interactive(victim))
  // intento de pk ?
  {
    seteuid(getuid());
    log_file("TRY_PK", ctime() + ". " + NREAL(atk) + " intentó gritarle a " + NREAL(victim) + ".\n");
    return notify_fail("La lucha entre jugadores no está permitida.\n");
  }
  victim->Kill(atk);
  percent = atk->UseSkill(HAB_BARBARO,5*(atk->QueryGuildLevel()-victim->QueryGuildLevel()),1);
  atk->SetTP(atk->QueryTP()-1);
  if ( atk->QueryGuildLevel()<NIV_BARBARO_GUERREROS || percent <= 0 || atk->QueryTP()<4   )
    return _notify_fail(
		      "De tu garganta sólo sale un gritito.\n",
                      ({Descr(atk,1)+" suelta un gritito.\n",
                        "Alguien suelta un gritito.\n"
                      })
                     );
  drink_cost = COST_SCREAM / 10 * (10 - ((atk->QueryGuildLevel()-NIV_BARBARO_GUERREROS) / 10));
  if (drink_cost < 5) drink_cost = 5;
  // dtell("kastwey", "Coste sed: " + drink_cost + ".\n");
  atk->AddDrink(-drink_cost);

  seteuid(getuid(TO));

  effect = clone_object(EFFECT_PARALYZE);

  if (percent>40) {
    tiempo = 2+(percent-60)/15;

    effect->SetInitChat("¡Quedas aterrad"+ART(victim)+" por "+atk->QueryName()+"!\n");
    effect->SetEnvInitChat("¡"+capitalize(victim->QueryName())+" queda aterrad"+ART(victim)+"!\n");

    effect->SetExecChat("Continúas aterrad"+ART(victim)+" por "+atk->QueryName()+"\n");

    effect->SetEndChat("Dejas de estar aterrad"+ART(victim)+" por "+atk->QueryName()+".\n");
    effect->SetEnvEndChat(capitalize(victim->QueryName())+" deja de estar aterrad"+ART(victim)+".\n");

    action = Descr(victim,1)+" queda aterrado.\n";
  }
  else {
    tiempo = 2;

    effect->SetInitChat("¡Quedas asustad"+ART(victim)+" por "+atk->QueryName()+"!\n");
    effect->SetEnvInitChat("¡"+capitalize(victim->QueryName())+" queda asutad"+ART(victim)+"!\n");

    effect->SetExecChat("Continúas asustad"+ART(victim)+" por "+atk->QueryName()+"\n");

    effect->SetEndChat("Dejas de estar asustad"+ART(victim)+" por "+atk->QueryName()+".\n");
    effect->SetEnvEndChat(capitalize(victim->QueryName())+" deja de estar asustad"+ART(victim)+".\n");

    action = Descr(victim,1)+" se asusta.\n";

    victim->Whimpy(WHIMPY_FORCE);
  }

  effect->SetSaveDC(QuerySaveDC(atk));
  effect->SetSaveType(TIPO_DE_SALVACION);

  if (effect->Affect(victim, tiempo)) {
    //play_sound(environment(TP), SND_HABILIDADES("xxx"));
  }

  Debug("barbary",sprintf("[%O] [%O]%O gritó a [%O]%O y el resultado fue: %O\n"
  	,ctime(),atk->QueryGuildLevel(),atk->QueryName(),victim->QueryGuildLevel(),victim->QueryName(),percent));
  atk->SetCombatDelay(1, "Estás gritando.\n");

  return _notify_succes("Haces una profunda inspiración y sueltas un "
		       "tremendo alarido.\n"+action,
                       ({Descr(atk,1)+" se vuelve hacia "+Descr(victim)+
			 " y grita como sólo los guerreros pueden hacer.\n",
			 "Oyes un fuerte alarido.\n"}),
		       ({Descr(atk,1)+" grita como un bárbaro, asustándote.\n",
			 "Alguien grita como un bárbaro, asustándote.\n"}),
		       victim
		       );
}

protected status compare_armour(object a1,object a2)
{
  return (a1->QueryAC()!=a2->QueryAC()
           ?a1->QueryAC()>a2->QueryAC()
           :a1->QueryWeight()!=a2->QueryWeight()
             ?a1->QueryWeight()<a2->QueryWeight()
             :a1->QueryQuality()>a2->QueryQuality()
         );
}

public int identify(string str)
{
  object ob,*obs;
  string type,desc,res;
  int success;
  if (!TP) return 0;
  if (!str)
    return notify_fail("¿Qué quieres identificar?\n"),0;
  if (  !check_sight()
      ||check_ghost()
      ||check_delay()
     )
    return 0;
  if (!ob=search(TP,str,SM_OBJECT|SEARCH_INV_ENV))
    return _notify_fail("No encuentras "+str+" por ningún sitio.\n");
  // Una vez más, diff no puede pasar del 15%
  success = TP->UseSkill(HAB_IDENTIFICAR,(TP->QueryGuildLevel()/10+TP->QueryInt()/4) );
  if (   TP->QueryGuildLevel()<NVL_IDENTIFICAR || success<=0    )
    return _notify_fail("No eres capaz de identificar "+Descr(ob)+".\n",
                      ({Descr(TP)+" mira a "+Descr(ob)+" y "
                        "se rasca la cabeza.\n",
			""
		      }));
  res = "";
  if (member(inherit_list(ob),"/std/armour.c")!=-1)
    {
      object worst,best;
      switch(type = ob->QueryArmourType())
	{
         case AT_SKIN:
           desc ="Ésta es tu piel desnuda.\n";
	   break;
         case AT_RING:
	   desc = "Esto es un anillo.\n";
	   break;
         case AT_AMULET:
	   desc = "Esto es un amuleto.\n";
	   break;
         case AT_BOOTS:
	   desc = "Esto son unas botas.\n";
	   break;
         case AT_CLOAK:
	   desc = "Esto es una capa.\n";
	   break;
         case AT_MAIL:
	   desc = "Esto es una coraza.\n";
	   break;
         case AT_GLOVES:
	   desc = "Esto son unos guantes.\n";
	   break;
         case AT_HELMET:
	   desc = "Esto es un casco.\n";
	   break;
         case AT_SHIELD:
	   desc = "Esto es un escudo.\n";
	   break;
	 case AT_TROUSERS:
	   desc = "Esto son unos pantalones.\n";
	   break;
	}
      obs = sort_array(
              filter(
                all_inventory(TP),
                lambda(
                  ({SYM(v)}),
                  ({SF(==),
                      type,
                      ({SF(call_other),SYM(v),"QueryArmourType"})
                  })
                )
              ),
              SF(compare_armour)
            );
       if (sizeof(obs)) best = obs[<1];
      if (sizeof(obs)>1) worst=obs[0];
      obs -= ({ ob });
      res +=desc+
            (sizeof(obs)?"Tienes"+(sizeof(obs)==1?"":itoa(sizeof(obs))):"No tienes")+
             " otra"+(sizeof(obs)==1?"":"s")+" cosa"+(sizeof(obs)==1?"":"s")+" de ese tipo.\n";
      if (sizeof(obs))
        res += "Tu mejor armadura de este tipo es "+Descr(best)+
               (worst?" y la peor es "+Descr(worst):"")+".\n";
    }
  else if (member(inherit_list(ob),"/std/weapon.c")!=-1)
    {
      switch (ob->QueryWeaponType())
	{
	 case WT_ALABARDA: type=HAB_ALABARDA; break;
	 case WT_HACHA:    type=HAB_HACHA;    break;
	 case WT_CADENA:   type=HAB_CADENA;   break;
	 case WT_MAZA:     type=HAB_MAZA;     break;
	 case WT_CUCHILLO: type=HAB_CUCHILLO; break;
	 case WT_LANZA:    type=HAB_LANZA;    break;
	 case WT_VARA:     type=HAB_VARA;     break;
	 case WT_ESPADA:   type=HAB_ESPADA;   break;
	 case WT_ESGRIMA:  type=HAB_ESGRIMA;  break;
	 case WT_LATIGO:   type=HAB_LATIGO;   break;
	 case WT_MANOPLA:  type=HAB_MANOPLA;  break;
	 case WT_MANGUAL:  type=HAB_MANGUAL;  break;
	    case WT_DAGA: type=HAB_DAGA;  break;
	        case WT_GARROTE:  type=HAB_GARROTE;   break;
	            case WT_ESPADA_CORTA:  type=HAB_ESPADA_CORTA;  break;
	                case WT_CIMITARRA:  type=HAB_CIMITARRA;  break;
	                    case WT_MANDOBLE:  type=HAB_MANDOBLE;  break;
	 default: type="El tipo de daño "+ob->QueryWeaponType()+
	    "es dESCONOCIDO (por favor, informa a un Vala sobre esto)";
	}
    res+="Necesitarás el skill "+type+" para luchar más eficazmente cuando\n"
      "uses "+Descr(ob)+" en combate.\n";
    }
  if (res=="")
     return _notify_fail(Descr(ob,1)+" no es arma ni armadura.\n",
		       ({Descr(TP,1)+" mira a "+Descr(ob)+", se rasca "+
		         "la cabeza y decide que eso "
		         "no es ni arma ni armadura.\n",
			 ""
		       })
		      );
  return _notify_succes(res,
		       ({Descr(TP,1)+" mira a "+Descr(ob)+" y mueve "
			 "la cabeza convencid"+
			 (TP->QueryGender()==2?"a.\n":"o.\n"),""
		       })
		       );
}

public int repair(string str)
{
  object ob,*obs,env,destr_ob;
  int percent,q,qr,diff;

  if (!TP) return 0;
  if (!str)
    return notify_fail("¿Qué quieres reparar?\n"),0;
  if (  !check_sight()
      ||check_ghost()
      ||check_delay()
     )
    return 0;
  if (!ob=search(TP,str,SM_OBJECT|SEARCH_INV_ENV))
    return _notify_fail("No encuentras "+str+" por ninguna parte.\n");
  if (   member(inherit_list(ob),"/std/armour.c")==-1
      && member(inherit_list(ob),"/std/weapon.c")==-1
     )
    return _notify_fail("No puedes reparar "+Descr(ob)+" porque no es "
		      "arma ni armadura.\n",
                      ({Descr(TP)+" mira a "+Descr(ob)+" y "
                        "se rasca la cabeza.\n",
			""
		      }));
  if (ob->QueryMagic())
    return _notify_fail("No puedes reparar "+Descr(ob)+" porque tiene "
		      "una fuerte aura mágica.\n",
                      ({Descr(TP)+" mira a "+Descr(ob)+" y "
                        "se rasca la cabeza.\n",
			""
		      }));
  if (ob->QueryNoDrop())
    return _notify_fail("No puedes poner "+Descr(ob)+" encima del yunque.\n");
/*
    if (ob->Query(P_AUTOOBJECT))
    return _notify_fail(Descr(ob,1)+" es demasiado dificil de reparar.\n",
                      ({Descr(TP)+" mira a "+Descr(ob)+" y "
                        "se rasca la cabeza.\n",
			""
		      }));
  Seria cosa de manejar los ellos de otra manera...
*/
  if (!env = check_env())
    return _notify_fail("No puedes hacer eso en el tejido del espacio-tiempo.\n");
  if (!env->IsSmithy())
    return _notify_fail("Debes estar en una herrería.\n");
  if (TP->QueryGuildLevel()<NVL_REPARAR)
    return _notify_fail("Todavía no has aprendido a reparar cosas.\n");
  if (ob->QueryEquipped())
    return _notify_fail("Debes quitarte la armadura antes de poder repararla.\n");
  if (ob->QueryEquipped())
    return _notify_fail("Debes desempuñar el arma antes de poder repararla.\n");
  if (TP->QueryTP()<5)
    return _notify_fail("Estás demasiado cansado como para reparar nada.\n");

  if (TP->QueryGuildLevel()<NVL_RPR_NORMAL
/*      && ( !(member(MAT_METALICOS,ob->QueryMaterial())==-1)
        || !(member(MAT_PRECIOSOS,ob->QueryMaterial())==-1)*/
	&& ( ob->QueryMaterial() == M_PIEDRA_TXT ||
	     ob->QueryMaterial() == M_CRISTAL_TXT )
         )
//     )
    {
    write(ob->QueryMaterial());
    return _notify_fail("Todavía no has aprendido a reparar este tipo de cosas.\n");
    }
  if (TP->QueryGuildLevel()<NVL_RPR_AVANZADO
      && (ob->QueryMaterial()==M_PLATA_TXT     ||
          ob->QueryMaterial()==M_PLATINO_TXT   ||
	  ob->QueryMaterial()==M_ORO_TXT       ||
	  ob->QueryMaterial()==M_MITHRIL_TXT   ||
	  ob->QueryMaterial()==M_ADAMANTIO_TXT ||
	  ob->QueryMaterial()==M_DIAMANTE_TXT  ||
	  ob->QueryMaterial()==M_TITANIO_TXT   ||
	  ob->QueryMaterial()==M_ALUMINIO_TXT  ||
	  ob->QueryMaterial()==M_CRISTAL_TXT
	 )
     )
    return _notify_fail("Todavía no has aprendido a reparar cosas tan refinadas.\n");

  q = ob->QueryQuality();
  // Como siempre, diff no debe sobrepasar el 10%...
  diff=( (TP->QueryStr()+TP->QueryInt()/2+TP->QueryDex()/2)/10
// Daríame rollo usar el valor del objeto también, pero aún no sé cómo...
//         - NMB->max( ({10,ob->QueryValue()/200}) )
       );
  percent=TP->UseSkill(HAB_REPARAR,diff);
//  TP->SetTP(TP->QueryTP()-2);
// Actualmente, UseSkill devuelve valores entre -100 y 100, por lo que
// se considera fallo cuando está por debajo de 1.
  if (percent<=0)
    {
      q+=(q*percent*(1+random(2))/200)-1;
      if (percent<-90||q<1) // Cagada desastrosa.
	{
	  seteuid(getuid());
	  destr_ob = clone_object("/std/thing");
	  destr_ob->SetProperties(ob->QueryProperties());
	  destr_ob->SetShort(ob->QueryShort()+" (destruíd"+
	                    (ob->Query(P_GENDER)==GENERO_FEMENINO?"a":"o")+
			    (ob->Query(P_NUMBER)==1?"s)":")"));
      destr_ob->SetLong("Hubo un tiempo en que esto fue:\n"+ob->QueryLong());
	  destr_ob->SetValue(0);
	  destr_ob->move(environment(ob),M_SILENT);
	  play_sound(environment(ob), SND_SUCESOS("herreria_romper"));
   write(TC_BOLD TC_RED "¡Oh no! Has destruído "+Descr(ob)+".\n" TC_NORMAL);
	  ob->remove();
	  return 1;
	}
      // Cagada normalilla.
      if (ob->QueryResetQuality()>20)
       ob->SetResetQuality(ob->QueryResetQuality()-5);
      ob->SetQuality(q);
      play_sound(environment(ob), SND_SUCESOS("herreria_mal"));
      return _notify_succes("¡Oh no! ¡¡Has dañado "+Descr(ob)+"!!\n",
			   ({Descr(TP,1)+" golpea brutalmente con el martillo "
			     "y daña "+Descr(ob)+" más todavía.\n",
			     "Oyes metal golpeando metal y a "
			     "alguien que suelta horribles tacos.\n"
			   }));
    }
  qr=ob->QueryResetQuality();
  if (percent>90)
    {
      ob->SetQuality(min(({qr+20,100})));
      if(qr<=85) ob->SetResetQuality(qr+10);
      else       ob->SetResetQuality(95);
      play_sound(environment(ob), SND_SUCESOS("herreria_bien"));
      return _notify_succes(TC_BOLD TC_GREEN"¡Hey, has hecho un trabajo excelente!\n"
			   TC_NORMAL"Ahora, "+Descr(ob)+" está"+
			   (ob->QueryThingNumber()==1?"n":"")+" mejor que nunca.\n",
			   ({Descr(TP,1)+" usa el martillo como un"+
			   (TP->QueryGender()==2?"a maestra ":" maestro ")+
			     "de la forja. En pocos minutos "+
			     Descr(ob)+" tiene"+
			   (ob->QueryThingNumber()==1?"n":"")+" un tenue brillo"
			     " y está"+(ob->QueryThingNumber()==1?"n":"")+
			     " mejor que nunca.\n",
			     "Oyes metal golpeando metal y de pronto "
			     "suena una salva de aplausos.\n"
			   }));
    }
  if(qr<95) ob->SetResetQuality(qr+1);
  ob->SetQuality(min(({q+percent,qr,100})));
  play_sound(environment(ob), SND_SUCESOS("herreria_bien"));
  return _notify_succes("Eso es buen trabajo de forja.\n",
		       ({Descr(TP,1)+" hace un excelente trabajo reparando "+
			 Descr(ob)+".\n",
			 "Oyes metal golpeando metal y de pronto todo "
			 "se queda en silencio otra vez.\n"
		       }));
}
