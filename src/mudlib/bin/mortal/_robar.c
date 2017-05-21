/* SIMAURIA '/bin/mortal/_robar.c'
   ===============================

   [t] Theuzifan
   [w] Woo
   [h] Nyh
   [n] Nemesis

   12-03-99 [t] Creación.
   15-10-99 [t] Si robas a un npc y se da cuenta, te ataca.
   16-11-99 [w] Añadida la comprobacion (perc>ob->QuerySteal()) para que
                no puedas robar a ciertos pnjs.
   09-12-99 [t] Modifico un poco... si fallas, el otro se da cuenta. Y si es
   		un NPC, te ataca.
   16-12-99 [t] Se le pasa el valor de la habilidad 'robar' del sujeto robado
   		como modificador de dificultad en el robo.
   		Además me cepillo el QuerySteal, que ya no es util.
   14-01-00 [t] No puedes robar algo puesto o empuñado.
   16-06-00 [t] Si no tiene ningun objeto no se llama al UseSkill y se devuelve
   		un error.
   19-07-00 [t] Recodificadas las comprobaciones de que no te pueden robar algo empuñado.
   		Una serie de circunstancias permitían que, en determinadas ocasiones,
   		pudieras robar algo empuñado/puesto....
   10-04-01 [h] Añade el chekeo de safe y de cant_steal, por cierto, el cant_steal
   		es mas o menos como un QuerySteal() que devuelva 100...
    04-05-01 [h] Usando el ed arreglo el archivo que vilmente me habian pisao
                 diciendo que lo habian arreglao, pero no, petaba si ponia
		 cosas como robar gsdfiu
niputaideadeldiaqeshoy [Maler] modifico para q no pete con robar sin argumentos
    26-11-01 [n] Retocado para que no se puedan robar objetos que no se supone
                 que se deban dar.
   05-04-03 [t] Bueno, digamos que AHORA si que no se pueden robar objetos que
   		sean nogive o nodrop. (sera melon el nyh...)
*/

#define NTF(x) notify_fail(x)
#include "/secure/wizlevels.h"
#include <properties.h>
#include <moving.h>
#include <skills.h>


int main(string str)
{
  object ob, *inv, mymoney;
  string str2;
  mixed *money;
  int n, perc, o, cant;
  mapping m;

  seteuid(getuid());
  if (TP->QueryCombatDelay()) return NTF(TP->QueryCombatDelayMsg());
  if(!str) return NTF("Robar qué a quién?\n");
  if (environment(TP)->QuerySafe()) return NTF("No puedes robar a nadie aqui.\n");
  if(sscanf(str,"a %s", str2)!=1) return NTF("¿Robar a quién?\n");
  if (!str) return NTF("¿Robar a quién?\n");
  if (str2) str=str2;

  if (    !(ob=present(str,environment(TP)))
       ||(!(TP->CanSeeObject(ob))) )
    return NTF("No ves a "+capitalize(str)+" aquí.\n");

  if (TP==ob) return NTF("¿Otra vez robándote?\n");
    /* esto debe de ser el capamiento del kastwey.
  if (query_once_interactive(ob))
  {
    return notify_fail("Actualmente no se puede robar a los jugadores.\n", NOTIFY_NOT_VALID);
  }
*/
  if (!ob->Query(P_IS_NPC) && !living(ob)) return NTF("No puedes robar a "+str+".\n");
  if (IS_LEARNER(ob)) return NTF("Olvídalo, no se puede robar a los administradores del mud.\n");
  if (str2 = ob->Query(P_CANT_STEAL)) return NTF(stringp(str2)?str2:("No puedes robar a "+str+"\n"));

  inv=all_inventory(ob);
  TP->SetCombatDelay(1,"Estas intentando robarle algo a "+ob->QueryName()+".\n");
  if (!sizeof(inv||({}))) return NTF("No consigues robarle nada.\n");

  inv-=ob->QueryWeapons()||({});
  inv-=ob->QueryArmours()||({});

  perc = -ob->QueryInt() -ob->QuerySkillLevel(HAB_ROBAR);
  perc=TP->UseSkill(HAB_ROBAR, perc);

  n=-1;
  while (n==-1) {
    if (sizeof(inv)==0) return NTF("No consigues robarle nada.\n");
    n=random(sizeof(inv));
    if (inv[n]->Query(P_EQUIPPED) || inv[n]->Query(P_NODROP) || inv[n]->Query(P_NOGIVE)) {
      inv-=({inv[n]});
      n=-1;
    }
  }


  if (TP->Query(P_SEE_INVIS)<inv[n]->Query(P_INVIS))
    return NTF("No consigues robarle nada.\n");

  if (perc<0) {
    if (ob->Query(P_IS_NPC)) ob->Kill(TP);
    else if (ob->Query(P_IS_PLAYER)) {
      tell_object(ob, "¡"+capitalize(TP->QueryRealName())+
   	  	" ha intentado robarte algo!\n");
      log_file("ROBOS", STR->etime()+": "+TP->QueryRealName()+" ha intentado robarle "
      		"a "+ob->QueryRealName()+".\n");
    }
    return NTF("¡Oooops! "+ob->QueryShort()+" se ha dado "
    	"cuenta de que le has intentado robar...\n");
  }

  if (perc>0) {
    if (!sizeof(inv)) {
      if (perc>50) return NTF(capitalize(ob->QueryRealName())+" no tiene nada.\n");
      return NTF("No consigues robarle nada.\n");
    }

    if (inv[n]->Query(P_AUTOOBJECT)) {
      if (member(inherit_list(inv[n]), "/obj/money.c")==-1)
        return NTF("No puedes robarle "+inv[n]->QueryShort()+".\n");

      if (perc<50) {
        m=inv[n]->QueryMoney()||([]);
        money=m_indices(m);
        o=random(sizeof(money));
        cant=m[money[o]];
        mymoney=clone_object("/obj/money");
        inv[n]->AdjustMoney(money[o], -cant*perc/100-1);
        mymoney->AdjustMoney(money[o], cant*perc/100+1);
        inv[n]=mymoney;
      }
    }

    if (inv[n]->move(TP)!=ME_OK) {
      // No sólo es que el objeto no pueda moverse, sino que no se pueda dar...
      if ((inv[n]->move(environment(TP))!=ME_OK))
        return NTF("No has podido robarle "+capitalize(inv[n]->QueryShort())+".\n");
      else
        write(capitalize(inv[n]->QueryShort())+" se te cae al suelo.\n");
    }

    write("Le birlas "+inv[n]->QueryShort()+" a "+ob->QueryShort()+".\n");
    return 1;
  }
  return NTF("No consigues robarle nada.\n");
}
