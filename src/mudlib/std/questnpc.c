// Softbyte May '99:  Quest NPC
// This NPC will set a quest string/substring give XP, money, items
// for bringing it items with a given id
//
// [n] nemesis@simauria
// Dic'2000 Explicaci�n de la falla y traducci�n.
// [07-Nov-2001 23:45:23 CET]
// [n] Eliminado un bug por el que, si llamabas a la funci�n Give() del
//     npc/putget.c, te daba el dinero pero petaba y no destru�a el objeto
//     NOTA: El putget peta en la l�nea 685... tiene un bug, por tanto...
// [n] Como Uzi es mu majo, ha arreglao el bug anterior, as� que ya se puede
//     usar el Give() y todo ir� bien (yupi)
//
// Este NPC lo que hace b�sicamente es esperar un objeto cualquiera de
// un conjunto dado y hacer un SetAttr() al player del string que ha
// recibido como nombre del quest. Es decir, no sirve para resolver un
// determinado quest, pero es �til para hacer de pnj "intermedio". Es
// decir, un pnj al que se le debe dar algo antes de continuar con el
// quest en s�.
//
// BUGS: Al dar el dinero con un move, no lo suma :(
//
// MEJORAS: Con modificaciones m�nimas se podr�a conseguir que:
//         a) Permitiera esperar una serie de objetos en lugar de uno solo.
//         b) Sirviera realmente para dar el quest por resuelto (hiciera
//            el SetQuest() �l solito)


#include <properties.h>
#include <moving.h>
#include <money.h>

inherit NPC;

static object itemgot;     // internally used
static string m_quest;
static string m_subquest;
static string *m_items;    // we want these items
static int m_money;        // we give money
static int m_xp;           // or xp
static string m_reward;    // or an item
static string m_helptext;  // said when getting the right item
static string m_againtext; // said when getting it again
int SetHelpText(string s) {m_helptext=s;return 1;}
string QueryHelpText()
{
  return W(capitalize(QueryName())+" dice: "+
            process_string(m_helptext));
}
int SetAgainText(string s) {m_againtext=s;return 1;}
string QueryAgainText()
{
  return W(capitalize(QueryName())+" dice: "+
           process_string(m_againtext));
}



// Actualizar el miniquest que ser� resuelto.
// quest es un identificador �nico para un quest o una serie de
// quests (p.ej.:"nandor_quests")
// subquest es el subquest con respecto al principal, y normalmente
// ser� el nombre del pnj. En ese caso, se puede dejar a 0.
// ids es un string o array de strings que contiene los ids ante
// los que el pnj tendr� que reaccionar.
// Los rewards o recompensas se dar�n en forma de dinero, XPs o un
// art�culo. Uno o todos ellos pueden ser distintos de cero.
//
// Si la funci�n os parece demasiado larga, pod�is omitir
// los tres �ltimos argumentos y asignarles un valor con
// SetRewardXP, SetRewardMoney y SetReward
varargs int SetQuest(string quest, string subquest,mixed ids,
                    int money, int xp,string reward)
{
  if (!quest) quest="default_quests";
  if (!subquest) subquest=lower_case(QueryName()||"brumsumsius");
  m_quest=quest;
  m_subquest=subquest;
  if (stringp(ids)) ids=({ids});
  if (!pointerp(ids)) ids=0;
  m_items=ids;
  m_money=money;
  m_xp=xp;
  m_reward=reward;
  return 1;
}

int SetRewardMoney(int reward)
{
  m_money=reward;
  return 1;
}
int SetRewardXP(int reward)
{
  m_xp=reward;
  return 1;
}
int SetReward(string reward)
{
  m_reward=reward;
  return 1;
}

// For debugging query the quests
mixed * QueryQuest()
{
  return ({m_quest,m_subquest,m_items,m_money,m_xp,m_reward});
}

string itemshort()
{
  if (itemgot) return itemgot->QueryShort();
  else return "esto";
}

create()
{
  ::create();
 m_quest=0;
  m_subquest=0;
  m_money=0;
  m_items=0;
  m_xp=0;
  m_reward=0;
  m_helptext="Gracias por traerme @@itemshort@@. Me has ayudado mucho.\n";
  m_againtext="Me has vuelto a ayudar. �Qu� amable eres!\n";
}

void givebackornot(object ob,int flag)
{
string name;
  if (!ob) return;
  if (flag==1)
  {
    name=capitalize(QueryName()||"Someone");
    say(name+" dice: No creo necesitar "+ob->QueryShort()+".\n");
    say(name+" deja caer "+ob->QueryShort()+".\n");
    ob->move(environment(),M_DROP);
  }
  else
  {
    ob->remove();
  }
}

void reward_again(object pl,object ob)
{
int pres;
    if (environment()==environment(pl)) pres=1;
    else pres=0;
    if (pres) say(QueryAgainText());

    ob->remove();
}

void reward_player(object pl,object ob)
{
object money;
int pres;

    if (environment()==environment(pl)) pres=1;
    else pres=0;
    if (pres) say(QueryHelpText());

    if (m_xp && pres )
    {
      tell_object(pl,"Te sientes m�s experimentado.\n");
    }
    if (m_money && pres )
    {
      money=clone_object(MONEY);
      money->AdjustMoney(m_money,"cobre");
      Give(money,pl,M_GIVE);
    }
    if (m_reward && pres )
    {
      money=clone_object(m_reward); // a pesar del nombre, esto es un objeto...
      Give(money,pl,M_GIVE);
    }
    ob->remove();
}

varargs void notify_enter (mixed oldenv, int method, mixed extra)
{
  object what;
  string *wq;
  int i,found,again;
  string name;

  ::notify_enter (oldenv, method, extra);
  if (!m_items) return; // nothing to check for

  what = PO;
  itemgot=what;

  // do not reject own stuff
  if (!what || !oldenv || what==TO) return ;
  if (blueprint(what)==MONEY) return 0;

  found=0;
  again=0;
  for (i=0;i<sizeof(m_items);i++)
  {
    if (what->id(m_items[i])) found=1;
  }
  if (found)
  {
    name=capitalize(QueryName()||"Alguien");
    if (m_quest && m_subquest)
    {
      wq=TP->QueryAttr(m_quest)||({});
      if (-1==member(wq,m_subquest))
      {
        wq+=({m_subquest});
        TP->SetAttr(m_quest,wq);
      }
      else
      {
        again=1;
      }
    }
    if (!again)
    {
      // He will get the XP even if he runs out of the room
      if (m_xp) TP->AddXP(m_xp);
      call_out("reward_player",1,TP,what);
    }
    else
    {
      call_out("reward_again",1,TP,what);
    }
  }
  else
  {
    call_out("givebackornot",1,what,1);
  }
  return;
}



