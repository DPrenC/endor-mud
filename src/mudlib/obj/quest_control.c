/* SIMAURIA '/obj/quest_control.c'
   ===============================
   [w] Woo@simauria

   03-02-99 [w] Adaptación para Simauria. Quitadas algunas cosas por aquí,
                puestas otras por allá, castellanizado... etc...
   16-06-00 [t] Meto un catch en el logfile ese pa que no pete de vez en
   		cuando.
   22-09-01 [n] Retocado el valor de BASE_VALUE porque 1000 era una sobrada,
                especialmente teniendo en cuenta que tenemos 100 QP en total...
		Cambiada la función QPointLevel(int level). Básicamente, he
		cambiado en las condiciones los 20's y 25's que aparecían
		por 30's y 35's. Era un poco tonto que el nivel al que
		bajaban los jugatas fuera alrededor de 20 (JAN en NF) cuando
		nuestro nivel de JAN es 30.
		Des-retocado todo, porque pasaban cosas raras. La próxima
		vez, me morderé los dedos antes de tocar nada...
   07-05-02 [n] Vale, esta vez sí que sí. A condición de que el quest dé menos
                de 10 QP, la cosa rula mogollón. Ahora, si da más, los players
		caen a nivel 19 de manera impepinable.
   09-05-02 [n] Ahora sí. Faltaba cambiar la constante por la que se dividía
                en la primera condición de 320 a un valor más "adecuado". En
		general, este valor es NivelJAN*(NivelJAN-4).
   10-04-03 [t] Rebajada la comprobación para RemoveQuest.
*/

#include <config.h>
#include <properties.h>
#include <wizlevels.h>
#include <sounds.h>

/*-- CONFIGURATION -------------------------------------------------------*/
#define TOTAL              (off_total+mini_total)
#define OFF_SAVE_FILE      "/obj/questctrl/questlist"
#define MINI_SAVE_FILE     "/obj/questctrl/miniquests"
#define QUESTOBJLIST       "/log/QUESTS"
#define MINI_MAX_QP        5     /* máximos puntos de QP para un miniquest */
                                   /* Si no se define no tiene límite */

/* May be undefined if the list is stored sorted. If defined, actively
   sorts by QP value. Looks better, but may cause smaller confusion as
   the sorting sometimes turnes the order of same-valued quests. Also
   needs eval time, about 20 % of the usual create() eval time */
#undef SORT_QUESTLIST

// Define this macro if the necessary QP shall be determined just once
// at login. When changing this, be sure to change the macro in /std/player
// as well.

#undef FIXED_QP

/*-- The QP requirement. Might be adjusted ---------------------------------*/

#define QP_FACTOR  1.25
#define QP_MAX_LEVEL   200

/*--------------------------------------------------------------------------*/

/* the format of the quests array. In the questlist file they have to be  */
/* stored in same order with all data but Q_SHORT and Q_LONG in the first */
/* line, Q_SHORT in the second and Q_LONG takes the rest. Quests are      */
/* separated by empty lines. See the savefile for further information.    */

#define Q_NAME		0    /* queststring set in the player object      */
#define Q_CREATOR	1    /* programmer responsible for ideas and code */
#define Q_DOMAIN        2    /* where to display the quest hints          */
#define Q_POINTS	3    /* Questpoints given for this quest          */
#define Q_XP            4    /* Experience given                          */
#define Q_SHORT		5    /* shown in the guilds                       */
#define Q_LONG		6    /* hint shown in guilds                      */

/* the format of the miniquests list. The miniquests are loaded
   from file and only stored in the all_quests mapping. */
#define MQ_NAME         0
#define MQ_CREATOR      1
#define MQ_POINTS       2
#define MQ_XP           3
#define MQ_SIZEOF       4  /* To omit additional parameters, may be used
			      for comments */

/* the format of the all_quests mapping */
#define AQ_QP           0
#define AQ_XP           1
#define AQ_CREATOR      2

mixed *questlist;
mapping all_quests;
int off_total,mini_total,mini_number,min_wiz_qp;

/* just prototypes of internal functions */

static mixed LoadQuestList(string file);
static void LoadMiniQuestList();
static string GetDomain(mixed ob);
static string DomainName(string a);
static void log_questobj(string text,object pl);

/* Some more macros. Don't switch off! */
#define _DEBUG

#define OB2STR(ob) ((ob) ? object_name(ob): "<none>")
#define GETUID(ob) ("["+((ob) ? getuid(ob):"<none>")+"]")
#define LOG(s) log_file ("QUESTCTRL", s)

/*-------------------------------------------------------------------------*/
/* the old quest list : quests
 * "find_kirk#orc_slayer#feed_ice_monster#cleanPhishsCastle#planetary#
 * wand_of_fire#beg_quest#adv_quest#vikingmania#sceptre_of_rocknroll#
 * mountain_sprite#pirates_cave#gaul_quest#king's_weapons#elementals"
 */
void create() {
  int i;

/* Don't see the plot of logging this. Loco Jul 14 1993
   Should be enough to log the initialisation in one line. Shorten the logfile
  LOG (ctime(time())+" create()\n");
  LOG ("    this    : "+OB2STR(TO)+" "+GETUID(TO)+"\n");
  LOG ("    previous: "+OB2STR(PO)+" "+GETUID(PO)+"\n");
  LOG ("    player  : "+OB2STR(TP)+" "+GETUID(TP)+"\n");
  LOG ("    iactive : "+OB2STR(TI)+" "+GETUID(TI)+"\n");
*/

  questlist=LoadQuestList(OFF_SAVE_FILE);

#ifdef SORT_QUESTLIST
  questlist=sort_array(questlist,"MoreQP",TO);
#endif

  all_quests=([]);
  for(i=0 ; i<sizeof(questlist); i++) {
    off_total += questlist[i][Q_POINTS];
    all_quests+=([questlist[i][Q_NAME]:
		  questlist[i][Q_POINTS];
		  questlist[i][Q_XP];
		  questlist[i][Q_CREATOR]]);
  }
#ifdef MINI_SAVE_FILE
  LoadMiniQuestList();
#endif

  LOG (ctime(time())+": create() ("+sizeof(questlist)+"+"+mini_number+"= "+
       (sizeof(questlist)+mini_number)+" Quests, "+off_total+"+"+mini_total+
       "= "+TOTAL+" QP)"+(object_name(TO)=="/obj/quest_control" ?
       "" : "[test]")+"\n");
}

/*------------------------------------------------------------------*/
/* Query several values                                             */

int QueryTotalQuestPoints() {
  return TOTAL;
}
int QueryOfficialQP() {
  return off_total;
}
int QueryMiniQP() {
  return mini_total;
}
int QueryQuestXP(string qname) {
  return all_quests[qname,AQ_XP];
}

/*------------------------------------------------------------------------*/
/* Don't use anyway, only for debugging purposes.                         */
/* QueryQuests() returns only the official ones.                          */
/* QueryAllQuests() the mapping with all questnames                         */


mixed QueryQuests() {
  mixed *rc;
  int i;

  if (!sizeof(questlist)) {
    LOG (ctime(time())+" QueryQuests() on empty questlist\n");
    LOG ("    this    : "+OB2STR(TO)+" "+GETUID(TO)+"\n");
    LOG ("    previous: "+OB2STR(PO)+" "+GETUID(PO)+"\n");
    LOG ("    player  : "+OB2STR(TP)+" "+GETUID(TP)+"\n");
    LOG ("    iactive : "+OB2STR(TI)+" "+GETUID(TI)+"\n");
    return 0;
  }

  // Produce a value-copy of the array to annoy cheaters.
  rc = ({});
  for (i = 0; i < sizeof(questlist); i++)
    rc += ({ questlist[i]+({}) });
  return rc;
}

mixed QueryAllQuests() {
  mixed rc,ind;
  int i;

//return all_quests;

  rc=([]);
  ind=m_indices(all_quests);
  // Produce a value-copy of the alist to annoy cheaters.
  for (i=sizeof(ind)-1;i>=0;--i)
    rc+=([ind[i]:all_quests[ind[i]];all_quests[ind[i],1];
	  all_quests[ind[i],2]]);
  return rc;
}


/*-------------------------------------------------------------------------
** string *QueryQuestNames()
**   Return the names of all valid official quests in Nightfall
** string *QueryAllQuestNames()
**   Return the names of all quests, including miniquests.
*/

string *QueryQuestNames() {
  string *qnames;
  int i;
  for (qnames = ({}); i<sizeof(questlist); i++)
    qnames += ({ questlist[i][Q_NAME] });
  return qnames;
}

string *QueryAllQuestNames() {
  return m_indices(all_quests);
}


/*-------------------------------------------------------------------------
 ** string *QueryPlayerQuests(mixed player)
 **   Return an array of the names of the quests that the player already has
 **   solved. The structure of the player's quests variable is hidden in this
 **   and the next function.
 */

string *QueryPlayerQuests(mixed player) {
  string q,file,trash;
  object pl;

  if (objectp(player))
    return (q = (string)player->QueryQuests())? explode(q, "#") : ({});
  if (stringp(player)) {
    if (pl = find_object(lower_case(player)))
      return QueryPlayerQuests(pl);
    if (file = read_file("/save/" + player[0..0] + "/" + player + ".o")) {
      sscanf(file,
	     "%s\nquests \"%s\"%s",
	     trash,q,trash);
      return q?explode(q, "#"):({});
    }
  }
  return ({});
}


/*------------------------------------------------------------------------*/
/* Check whether a player already has solved a specific quest.            */

int QueryQuestSolved(mixed qname,mixed pl) {
  mixed q;
  if (intp(qname)) {
    if (qname>=0 && qname<sizeof(questlist)) qname=questlist[qname][Q_NAME];
    else return 0;
  }
  return (member(q = QueryPlayerQuests(pl), qname) != -1);
}

/*------------------------------------------------------------------------*/
/* return the creator of a quest. Number or string allowed. Not for       */
/* miniquests, look them up yourself...                                   */

string QueryQuestCreator(mixed q) {
  if (stringp(q)) return all_quests[q,AQ_CREATOR];
  if (q<0 || q>=sizeof(questlist)) return "Nobody";
  return capitalize(questlist[q][Q_CREATOR]);
}

/*-------------------------------------------------------------------------
 ** int SetPlayerQuest(string qname, object player)
 **   Sets the quest in the player. This function has some potential for
 **   security checks (but doing real security is really hard !)
 **   Currently we allow setting of non-official quests, might be useful for
 **   guild-specific mini-quests. Non-official quests will just not be counted
 **   for quest points.
 **   Return 0 for failure, string of player's quests for success.
 */

varargs mixed SetPlayerQuest(string qname, object pl, int no_sound) {
  string *q;

  if ((pl != TI)) {
    int qt;
    object o;

    if (!query_once_interactive(pl)) return 0;
    if (!TI) for (qt=0; ((o=previous_object(qt))/* && (object_name(efun::blueprint(o))!="/obj/qtyper")*/); ++qt);
      else if (object_name(efun::blueprint(TI))==LOGIN) o=TP;
    if (!o) {
      if (IS_ARCH(TP))
	LOG (ctime(time())+" Legally set quest '"+qname+"' for "+pl->QueryRealName()+"\n");
      else
	LOG (ctime(time())+" Illegal attempt to set quest '"+qname+"' for "+pl->QueryRealName()+"\n");
      qt=0;
      while (previous_object(qt)) {
	LOG ("    previous: "+OB2STR(previous_object(qt))+" "+GETUID(previous_object(qt))+"\n");
	++qt;
      }
      LOG ("    player  : "+OB2STR(TP)+" "+GETUID(TP)+"\n");
      LOG ("    iactive : "+OB2STR(TI)+" "+GETUID(TI)+"\n");
    }
  }
  if (QueryQuestSolved(qname,pl)) return 0;
  log_questobj(qname+" ["+object_name(efun::blueprint(PO))+"] ",pl);
  q=pl->SetQuests(implode(QueryPlayerQuests(pl) + ({qname}), "#"));
  if (q) pl->AddXP(all_quests[qname,AQ_XP]);
  pl->save();
  if (!no_sound && member(pl->QueryChannels() || ({}), "infomud") < 0) play_sound(pl, SND_SUCESOS("quest"));
    log_file("QUESTS",ctime()[4..18]+": "+capitalize(getuid(pl))+" : "+qname+
	   (q ? "" : " - unsuccessful -")+"\n");
  return q;
}

public void InformSolution(string text)
// Informa de uqe alguien ha resuelto un quest, enviándose el texto <text> por le info,
// y reproduciéndose, a los jugadores que lo tengan activado, el sonido de quest
{
    load_object(CHANNELMASTER)->SendEmote("infomud", text);
    play_sound(filter(users(), (:member($1->QueryChannels() || ({}), "infomud") >= 0:)), SND_SUCESOS("quest"));
}


/*-------------------------------------------------------------------------
** string ListQuests(object player)
**   Return an string with all quest descriptions. If a pointer to a player
**   is given, also give info if the player already has solved the quest.
**   (Writing out the quest points might be debatable).
*/

varargs string ListQuests(mixed pl,int shortflag) {
  int i;
  string s;
  mapping q;

  q = pl ? (mkmapping(QueryPlayerQuests(pl))) : ([]);
  if (!shortflag) {
    for (s = ""; i<sizeof(questlist); i++) {
      s += sprintf("%2d. %s (%d)",(i+1),questlist[i][Q_SHORT],
		   questlist[i][Q_POINTS]);
      if (member(q,questlist[i][Q_NAME])) s += " (resuelto)";
      s += "\n";
    }
  } else {
    for (s = ""; i<sizeof(questlist); i++)
      if (member(q,questlist[i][Q_NAME]))
	s += questlist[i][Q_SHORT]+"\n";
  }
  return s;
}

/*-------------------------------------------------------------------------
** string QueryQuestLong(int n)
**   Return the hint to a given quest
**   Check for restricted information if wanted.
*/

//#define QLONG(n) (questlist[n][Q_LONG]+"This quest was created by "+questlist[n][Q_CREATOR]+".\n")
#define QDOM(n) (questlist[n][Q_DOMAIN])

string QueryQuestLong(int nr) {
  string s;
  int i;

  if (nr >= sizeof(questlist) || nr < 0) return "No existe ese quest.\n";
    /* wizards may query any hint */
  if (IS_LEARNER(TP))
   return questlist[nr][Q_LONG]+"Este Quest fue creado por "+questlist[nr][Q_CREATOR]+"\n";
  if (!QDOM(nr))
    return "No te podemos dar ningún tipo de información.\n";
  if (intp(QDOM(nr)) || QDOM(nr)=="*")
    return questlist[nr][Q_LONG];//QLONG(nr);
  s=GetDomain(PO);
  if ((stringp(QDOM(nr)) && LOWER(QDOM(nr))==s)
      || (pointerp(QDOM(nr)) && member(map(QDOM(nr), (:LOWER($1):)), s)!=-1))
    return questlist[nr][Q_LONG]+"Este Quest fue creado por "+questlist[nr][Q_CREATOR]+"\n";

  s="";
  if (stringp(QDOM(nr))) s=DomainName(QDOM(nr));
  else for (i=sizeof(QDOM(nr))-1;i>=0;--i) {
    s+=DomainName(QDOM(nr)[i]);
    if (i>1) s+=", ";
    else if (i==1) s+=" o ";
  }

  return implode(STR->break_line("Podrás obtener más información en alguna parte de "+s+" y pregunta allí.\n"),"\n");
}


/*-----------------------------------------------------------------------*/
/* QueryQuestShort(string|int quest)                                     */
/* Return the Questlist line of a specific offical quest                 */

string QueryQuestShort(mixed quest) {

  int i;
  if (intp(quest)) return
    ((quest>0 && quest<=sizeof(questlist)) ? questlist[quest-1][Q_SHORT] : 0);

  i=sizeof(questlist)-1;
  while(i>=0 && questlist[i][Q_NAME]!=quest) i--;
  return ((i>=0) ? questlist[i][Q_SHORT] : 0);
}

/*-------------------------------------------------------------------------
** int QueryQuestPoints (mixed player)
**   Return the amount of collected qp for player.
*/

int QueryQuestPoints (mixed pl) {
  string *q;
  int i, points;
  q=QueryPlayerQuests(pl);
  for (i=0;i<sizeof(q);++i) points+=all_quests[q[i]];

  return points;
}

/*----------------------------------------------------------------------*/
/* Return the QP associated with a quest                                */

int QueryQuestQP(string qname) {
  return all_quests[qname];
}

/*-------------------------------------------------------------------------
** int QPointLevel (int level)
**   Return the amount of qp associated with the given 'general <level>'.** slightly, but accelerating. For Lv. 20 it's the Seer value. Linear
*/

int QPointLevel (int level)
{
  if (level<5) return 0;
  return to_int(pow(level, QP_FACTOR)/pow(QP_MAX_LEVEL, QP_FACTOR) * TOTAL);
}

/*-------------------------------------------------------------------------



/*-------------------------------------------------------------------------
** int CheckAdvance (object player, string stat, int delta)
**   Check if player has enough questpoints to advance its <stat> by <delta>.
**   Return the amount of qp missing, or zero if advancing is ok.
*/

int CheckAdvance (object pl, string stat, int delta) {
  int at, cost;
  at = (int)pl->QueryAttribute (stat) - (int)pl->QueryBonus (stat);
  cost = QPointLevel (at+delta) - QueryQuestPoints (pl);
  return (cost <= 0 ? 0 : cost);
}

/*-------------------------------------------------------------------------*/
/* Some internal functions                                                 */
/* Declared static they cannot be called from outside                      */

static void LoadMiniQuestList() {
  mixed list,q;
  int i;
  list=explode(read_file(MINI_SAVE_FILE),"\n");
  for (i=0;i<sizeof(list);++i) {
    q=explode(list[i],"#");
    if (q[0]!="") {
      if (sizeof(q)>=MQ_SIZEOF) {
	++mini_number;
	q[MQ_POINTS]=to_int(q[MQ_POINTS]);
	q[MQ_XP]=to_int(q[MQ_XP]);
#ifdef MINI_MAX_QP
	if (q[MQ_POINTS] > MINI_MAX_QP) {
	  LOG("Valor Ilegal de QP "+q[MQ_POINTS]+" para el miniquest '"+q[MQ_NAME]+"'\n");
	  q[MQ_POINTS]=0;
	}
#endif
	mini_total+=q[MQ_POINTS];
	all_quests+=([q[MQ_NAME]:q[MQ_POINTS];q[MQ_XP];q[MQ_CREATOR]]);
      } else
	LOG( "Bogus Miniquest Entry\n"+list[i]+"s\n");
    }
  }
}

static mixed LoadQuestList(string file) {
  mixed list,h;
  int i;
  list=explode(read_file(file),"\n\n");
  for (i=sizeof(list)-1;i>=0;i--) {
    list[i]=filter(explode(list[i],"\n"),"NoComment");
    if (sizeof(list[i])<3 || list[i][0][0]=='-') {
      if (list[i][0][0]!='-')
	LOG(sprintf("Bogus Quest Entry %d:\n%s\n",
		    i,"obj/lib/string"->mixed_to_string(list[i])));
      list[i]=0;
    }
    else {  /* Seems to be loadable */
      list[i]=explode(list[i][0],"#")+({list[i][1]})+
	({implode(list[i][2..],"\n")+"\n"});
      if (list[i][Q_DOMAIN]=="*") list[i][Q_DOMAIN]=1;
      else
	list[i][Q_DOMAIN]=(sscanf(list[i][Q_DOMAIN],"%d",h) ? h :
			   explode(list[i][Q_DOMAIN],","));
      list[i][Q_POINTS]=(sscanf(list[i][Q_POINTS],"%d",h) ? h : 0);
      list[i][Q_XP]=(sscanf(list[i][Q_XP],"%d",h) ? h : 0);
    }
    list-=({0});
  }
  return list;
}

static NoComment(string blubb) {
  return (blubb!="" && blubb[0]!='#');
}

static string GetDomain(mixed a) {
  string *ex;
  if (a && a->QueryGuildclass() && a->QueryGuildDomain()) return LOWER(a->QueryGuildDomain());
  ex=explode(blueprint(a),"/");
  if (ex[1]==DDIR) return ex[2];
  else return "NoDomain";
}

static string DomainName(string a) {
  switch(a) {
  case "Goldhai": return "la isla de Goldhai";
    case "Pais-bree": return "el País de Bree";
        case "Montañas-nubladas": return "las Montañas Nubladas";
  default:
  }
  return capitalize(a);
}

static void log_questobj(string text,object pl) {
  /* partly stolen from /std/food */
  string list, foo1, foo2;
  int cod;

  if (file_size(QUESTOBJLIST) > 0) {
    list = read_file(QUESTOBJLIST);
    catch(cod=sscanf(list,"%s"+text+"%s",foo1,foo2));
    if (cod) return;
  }
  if (IS_LEARNER(pl)) return;
  write_file(QUESTOBJLIST,text+" ("+pl->QueryRealName()+")\n");
}

#ifdef SORT_QUESTLIST
static int MoreQP(mixed a,mixed b) {
  return ( a[Q_POINTS] > b[Q_POINTS] );
}
#endif

RemoveQuest(mixed pl, string q) {
  object who;
  if (stringp(pl)) pl=find_object(lower_case(pl));
  who = TI;
  if (!who) {
  	who = PO;
  }
  if (!IS_ARCH(who)) {
    LOG("Unsuccessful attempt to delete quest "+q+" for "+OB2STR(pl)+"\n");
    LOG ("  player  : "+OB2STR(TP)+" "+GETUID(TP)+"\n");
    LOG ("  iactive : "+OB2STR(TI)+" "+GETUID(TI)+"\n");
    return 0;
  }
  if (!pl) return 0;
  pl->SetQuests(implode(explode(pl->QueryQuests(),"#")-({q}),"#"));
  LOG(ctime()+": Deleted Quest "+q+" for "+OB2STR(pl)+ "\n");
  LOG ("  previous: "+OB2STR(PO)+" "+GETUID(PO)+"\n");
  LOG ("  player  : "+OB2STR(TP)+" "+GETUID(TP)+"\n");
  LOG ("  iactive : "+OB2STR(TI)+" "+GETUID(TI)+"\n");
  return q;
}
