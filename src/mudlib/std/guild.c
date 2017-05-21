/**
 * SIMAURIA '/std/guild.c'
 */

#include <guild.h>
#include <config.h>    // QUESTMASTER, NOTIFY-Priorities
#include <moving.h>    // move-methods
#include <rooms.h>     // REFRESH-Modes
#include <wizlevels.h> // IS_LEARNER
#include <colours.h>    //Salidas ANSI
#include <skills.h>  //habilidades
#include <spells.h>  //hechizos
#include <money.h>  // pagos
#include <attributes.h> // para la desc
#include <stats.h>
#include <input_to.h>
#include <characters.h>

#define MYFILE  "/std/guild"
#define MYREG   "GUILD"

// [Nyh] añado el infndef...
#ifndef STATS
#define STATS ({ P_CON, P_STR, P_DEX, P_INT, "Cha", P_WIS})
#endif

#define POS_IDS 0
#define POS_DESCR 1
#define POS_ROOM 2

#define TITLE_LEVEL   10      // nivel para cambiarte el titulo
#define TITLE_PRICE   25000   //   5 mithril
#define PRESAY_LEVEL  30      // nivel para cambiarte el antetitulo
#define PRESAY_PRICE  125000  //  25 mithril
#define DESC_LEVEL    20      // nivel para cambiarte la descripcion
#define DESC_PRICE    500000  // 100 mithril
#define DESC_MAX      1000    // mil caracteres como máximo

// -----------------------------------------------------------------------------

inherit ROOM;
inherit "/std/guild/banish";
inherit "/std/guild/guildquests";
inherit "/std/guild/member";
inherit "/std/guild/stats";
inherit "/std/guild/level";

// -----------------------------------------------------------------------------

private nosave mapping gSkills, // Habilidades que suben automaticamente
                       gSpells, // Conjuros que se añaden automaticamente
                       mSkills,  // texto que aparece cuando aprendes un skill
                       mSpells;  // texto que aparece cuando aprendes un spell

private nosave string guildobject, // el fichero del objeto del gremio.
                      guildclass,  // Ejemplo: Mago
                      guildname,   // Ejemplo: Gremio de magos
                      guildmaster, // Ejemplo: El maestro de la flema
                      guilddomain; // el dominio al que pertenece la sede del gremio

private nosave mixed  sign, list;   // ({({<ids>}),<descr>,<room>})

// -----------------------------------------------------------------------------

public varargs mapping QueryMembers(int ForceQuery); // std/guild/members
public mapping AddGuildSkill(string skill, int ini, int max, int modif, int level); //forward
public mapping QueryMember(mixed who); // std/guild/members
public mapping QueryMessages(string name); // std/guild/members
public int RemoveMessages(string name); // std/guild/members


protected int check_for_guildob(object ob)
  { return (blueprint(ob)==guildobject); }

/*
* ----------------------------------------------------------------------
* Queries, Settings, Adds
* ----------------------------------------------------------------------
*/
//Nyh: modifico esta funcion para que se añadan las habilidades...
public varargs string SetGuildclass(string cl)
// The guildclass. This will be used to set the Guild-Property in a
// player. Examples: Cleric, Adventurer, Headhunter, ...
{
  mapping habmap;
  string *ind;

  if (!VALID_GUILDCLASS(cl)) return guildclass;

  ind = m_indices((habmap=HAB_MAP[cl])||([]));
  if (!habmap || !ind || !sizeof(ind)) return 0;
  foreach (string hab:ind) if (habmap[hab,HAB_MAP_GRA]==HAB_GRATIS)
    AddGuildSkill(hab,1,habmap[hab,HAB_MAP_MAX],0,habmap[hab,HAB_MAP_NIV]);
  SetMinStats(STATS_MAP[cl][STAT_MIN]);
  SetModMaxStats(STATS_MAP[cl][STAT_MAX]);
  SetModMaxHLPStats(STATS_MAP[cl][STAT_HLP]);
  return guildclass = cl;
}

public string QueryGuildclass()    { return guildclass; }

// The guildname. This will be used in some messages, e. g. in the
// Top-Score-List. Examples: Temple of Fahr, Adventurer Guild,
// Headhunter
public string SetGuildname(string gn)  { return guildname=gn; }
public string QueryGuildname()    { return guildname; }

// Opcional
public string SetGuildMaster(string gm)  { return guildmaster=gm || 0; }
public string QueryGuildMaster()  { return guildname || 0; }

// dominio en el que se encuentra el gremio (para los quests en los que la información
// está restringida a un dominio en concreto)
public string SetGuildDomain(string dom) { return guilddomain = dom; }
public string QueryGuildDomain() { return guilddomain; }

// Set the guildobject, this guild uses, which will be
// automatically cloned, if a member enters, automatically
// destructed, if a member leaves, and so on
public string SetGuildobject(string gf)  { return guildobject = gf; }
public string QueryGuildobject()  { return guildobject; }

/*
* Guildobject related help-funs
* =============================
*/
public object CreateGuildobject(object pl)
// Create the guildobject for the player <pl> if he doesn't have
// one and inform us about this event with
//    InformGuildobject(pl)
// If this function is present in the guild, it is called. E. g.
// you may define your own message here, what the player will
// get receiving this item.
// If the function returns a non-zero value, the default message
// when receiving the guildobject, won't be printed.
{
  object ob;
  string err;
  int rc;
  string msg;

  if (!guildobject||!pl) return 0;
  if (member(map(all_inventory(pl),SF(blueprint)),guildobject)!=-1)
    return 0;

  if (err = catch(ob = clone_object(guildobject))) {
    msg = sprintf("%O->%O::CreateGuildObject() %O: %s"
                 , PO, TO, guildobject, err);
    log_file("GUILD", msg);
    catch(load_object(CHANNELMASTER)->SendMsg("error", msg));
    return 0;
  }

  if (ME_OK != (rc = ob->move(pl,M_SILENT))) {
    msg = sprintf("%O->%O::CreateGuildObject() %O: move failed %d"
                 , PO, TO, guildobject, rc);
    log_file("GUILD", msg);
    catch(load_object(CHANNELMASTER)->SendMsg("error", msg));
    return 0;
  }

  if (!TO->InformGuildobject(pl,ob))
   if (!QueryGuildMaster())
     tell_object(pl,"El supervisor del Gremio te da "+
                (ob->QueryShort()||"un objeto interesante")+".\n");
   else
     tell_object(pl,guildmaster+" te da "+
                (ob->QueryShort()||"un objeto interesante")+".\n");
  return ob;
}

public string helpsign()
// description of the sign
{
  string h;
  h="Puedes usar los siguientes comandos:\n"+
  TC_BOLD+"aumentar"+TC_NORMAL+", "+TC_BOLD+"stats"+TC_NORMAL+", "+
    TC_BOLD+"listar"+TC_NORMAL+", "+TC_BOLD+"mensaje"+TC_NORMAL+", "+
  TC_BOLD+"características"+TC_NORMAL+", "+TC_BOLD+"título"+TC_NORMAL+", "+
  TC_BOLD+"antetítulo"+TC_NORMAL+", "+TC_BOLD+"descripción"+TC_NORMAL+
  (is_leader(TP)?", "+TC_BOLD+"banear"+TC_NORMAL+", "+
   TC_BOLD+"desbanear"+TC_NORMAL:"")+".\n"
  "Para obtener información sobre cualquiera de los comandos escribe\n"
  "'"+TC_BOLD+"ayuda"+TC_NORMAL+" <comando>'. "
  "También puedes obtener ayuda sobre '"+TC_BOLD+"minstats"+TC_NORMAL+
  "' y\nsobre '"+TC_BOLD+"maxstats"+TC_NORMAL+"'.\n"+
  ((h = TO->QueryGuildleader())?
  "Si tienes algún problema habla con tu guildleader "+capitalize(h)+
  ((h = TO->QueryViceGuildleader())?" o con tu vice-guildleader.\n"+
  capitalize(h):"")+".\n":"")+

  (sizeof(QueryCreators())?sizeof(QueryCreators())>1?
  "Los creadores del gremio son: ":"El creador del gremio es: ":"")+
  implode(map(QueryCreators(),SF(capitalize)),", ")+".\n";

  return h;
}


//[t] ¿deberia cambiar esta rutina para que tuviera en cuenta el gremio anterior?
public void banished_entered()
// If a banished member enters this room, kick him out of the guild
{
  object *obs;
  int i;

  write("Has sido desterrado del gremio por "+Banisher(getuid(TP))+".\n");
  TP->SetGuild(0);
  TP->SetGuildLevel(1);

  if (guildobject)
    if (i = sizeof(obs = filter(map(all_inventory(TP),
                                                SF(blueprint)
                                               ),
                                      lambda(({SYM(v)}),
                                             ({SF(==),SYM(v),guildobject})
                                            )
                                     )
                  )
       )
      while(i--)
        obs[i]->check_owner(TP);
  //[t] Los titulos no reflejan el estatus del gremio
  //TP->SetTitle("the former "+guildclass);
  TO->RemoveMember(getuid(TP));
}

public void member_entered()
// This is called in the init of the guild.
// It does several checks. E. g. it updates the date, when
// a member entered, it restores the guildobject, if it
// was lost and it gives notes from other guildmembers
// to the player, if there are some.
{
  string uid;
  int i;
  mapping mb, messages;
  object ob;
  if (!TP) return;
  if (!(mb = QueryMember(uid = getuid(TP)))) return;
  TO->UpdateTime(uid);
  if ((messages = QueryMessages(uid))&&
      (i=sizeof(messages)))
    {
      write("Alguien te da "+(i>1?"unas notas":"una nota")+".\n");
      foreach(int note_id, string note_from_name, int note_date, string note_msg:messages)
      {
        TO->create_note(note_from_name, note_date, note_msg)->move(TP,M_GIVE);
      }
      RemoveMessages(uid);
    }
  if (ob = CreateGuildobject(TP))
    write("Has perdido "+(ob->QueryShort()||"guildobject")+".\n"
      "Aquí tienes otro.\n");
// [t] quito esta comprobacion temporalmente...
// [h] Lo reactivo, teoricamente ya esta arreglado
  TO->CheckSkills(TP);
  TO->InformEnter(uid);
}
// gSkills = ([ "habilidad":base;max;stat;niv ])
//Nyh: Funcion que chekea las habilidades...
//[h] la modifico para que no coja las skills del HAB_MAP sino de su propio gSkills
// nota, ahora uso el enable/disable en vez de quitarlas
public void CheckSkills(object pl) {
  int l;
  string *ind;

  if (!pl) return;
  l=pl->QueryGuildLevel();
  if(pl->QueryGuild()!=QueryGuildclass()) return;
//  if (!(habmap=HAB_MAP[QueryGuildclass()])) return;
//ahora ya no es habmap sino gskills...
  if (!mappingp(gSkills) || !sizeof(ind=m_indices(gSkills))) return;
  foreach (string hab:ind) {
    if(pl->HasSkill(hab)) { //si la tengo
      if (pl->QueryMaxSkillLevel(hab)!=gSkills[hab,1]) { // con maxlevel distinto...
        pl->SetMaxSkillLevel(hab,gSkills[hab,1]); //lo igualo...
        if (pl->QuerySkillLevel(hab)>pl->QueryMaxSkillLevel(hab)) {
          pl->SetSkillLevel(hab, pl->QueryMaxSkillLevel(hab));
        }
      }
      if ( (l<gSkills[hab,3]) && pl->SkillIsEnabled(hab)) {
        pl->DisableSkill(hab);
        write("Pierdes la habilidad '"+hab+"'.\n");
      }
      else if ( (l>=gSkills[hab,3]) && !pl->SkillIsEnabled(hab)) {
        pl->EnableSkill(hab);
        write("Recuperas la habilidad '"+hab+"'\n");
      }
    } //no la tenia
    else {
      if (l>=gSkills[hab,3]) {
        pl->AddSkill(hab, 1, gSkills[hab,2], gSkills[hab,1]);
        write("Ganas la habilidad '"+hab+"'.\n");
      }
    }
  }
}

public void ChangeSign(mixed ids,string descr,string roomdescr)
// As you might want another sign than the wooden one, you can
// change this.
// <ids> is a string or an array of strings containing the ids
//       the sign identifies to
// <descr> is the description you get when examining it (will be
//         followed by the normal helpsign-description
// <roomdescr> is the text appended to the roomdescr.
//             If the sign is described somewhere else in the IntLong
//             you may set it to "".
{
  if (sign)
    {
      RemoveDetail(sign[POS_IDS]);
      RemoveReadMsg(sign[POS_IDS]);
    }
  AddDetail(ids,
            lambda(0,({SF(+),
                       descr,
                       ({SF(call_other),TO,"helpsign"})
         })
                  )
           );
  AddReadMsg(ids,SF(helpsign));
  sign = ({ids,descr,roomdescr});
}

public void ChangeList(mixed ids,string descr,string roomdescr)
// As you might want another topscore-list than the given one, you can
// change this.
// <ids> is a string or an array of strings containing the ids
//       the list identifies to
// <descr> is the description you get when examining it (will be
//         followed by the normal toplist)
// <roomdescr> is the text appended to the roomdescr.
//             If the list is described somewhere else in the IntLong
//             you may set it to "".
{
  if (list) {
      RemoveDetail(list[POS_IDS]);
      RemoveReadMsg(list[POS_IDS]);
  }

  AddDetail( ids,
            lambda(0, ({ SF(+),
                         descr,
                         ({ SF(call_other), TO, "toplist" })
                  })
                  )
           );
  AddReadMsg( ids,
             lambda(0, ({ CL_PROGN,
                          ({ SF(call_other), STR, "smore",
                             ({ SF(call_other), TO, "toplist" }),
                             ({ SF(call_other), ({ SF(this_player) }),
                                                "QueryPageSize" })
                           }),
                           ""
                    })
                   )
            );

  list = ({ ids, descr, roomdescr});
}

private void ActualizeSecondaryGuild()
{
  int i;
  string *str, *r;

  r=({});
  //Desactiva los skills del gremio
  str=HABILIDADES[QueryGuildclass()];
  for (i=0; i<sizeof(str); i++)
  {
    if (member(HAB_GENERALES, str[i])==-1 && TP->HasSkill(str[i]))
    {
      TP->DisableSkill(str[i]);
      r+=({"'"+str[i]+"'"});
    }
  }
  /*
  if (sizeof(r)>1)
    tell_object(TP, W("Pierdes las "
      "habilidades "+implode(r[0..<2], ", ")+(r[<1][1]=='i'?" e ":" y ")+r[<1]+".\n"));
  else if (sizeof(r))
    tell_object(TP, "Pierdes la habilidad '"+r[0]+"'.\n");
  */
  r=({});
  //Desactiva los hechizos del gremio anterior.
  str=HECHIZOS[QueryGuildclass()];
  for (i=0; i<sizeof(str); i++)
  {
    if (TP->HasSpell(str[i]))
    {
      TP->DisableSpell(str[i]);
      r+=({"'"+str[i]+"'"});
    }
  }
  /*
  if (sizeof(r)>1)
    tell_object(TP, W("Pierdes las "
      "habilidades mágicas "+implode(r[0..<2], ", ")+(r[<1][1]=='i'?" e ":" y ")+r[<1]+".\n"));
  else if (sizeof(r))
    tell_object(TP, "Pierdes la habilidad mágica '"+r[0]+"'.\n");
  */
  i=TP->QueryGuildLevel();
  if (i>1) i--;
  TP->AddOldGuild(QueryGuildclass(), i, level2xp(i));
}


public void check_leave(string answer,object pl)
// This function is called by input_to. It waits for an answer,
// if the player really wants to leave the guild.
// If so, the Guild-Property will be set to 0, the XP reduced
// by one third of their amount and the title set to 'former ...'
// Last but not least the message will be spread on the news-
// channel, if the player is visible.
{
  int i;
  object *obs;
  string on;

  if (!pl) return;

  if (member(({"si","s", "sí", "S", "SI"}),lower_case(answer||""))==-1)
    write("Quizá aún no estas preparado para abandonar el gremio.\n");
  else
    {
      ActualizeSecondaryGuild();
      TO->RemoveMember(getuid(pl));
      TP->SetGuild(0);
      TP->SetGuildXP(0);

      if (guildobject)
        if (i = sizeof(obs = filter_objects(all_inventory(pl),
                                            "IdGuildobject")))
          while(i--)
          {
            on=obs[i]->QueryShort();
            obs[i]->check_owner(pl,1);
            //if (obs[i]) on=0;
          }
      // The check of the guildobject might look a bit complicated,
      // but this allows to use the std-guildobject without an extra
      // file and no problems when destructing it (because the guildobject
      // is asked to remove itself, when the owner is not a member of the
      // right guild.

      if (on)
        write(W(guildmaster+" te coge "+on+
          " mientras te dice: 'Ya no necesitarás esto. Si algún día "
          "regresas te lo devolveré gustoso.'\n"));
      write("Abandonas el "+QueryGuildname()+".\n");
      if (!pl->QueryInvis())
        CHANNELMASTER->SendEmote("ayuda",capitalize(getuid(pl))+
                          " abandonó el "+QueryGuildname());
   }
}


/*
* ----------------------------------------------------------------------
* Functions
* ----------------------------------------------------------------------
*/

public object create_note(string from_name, int date, string msg)
// Create a note from a message
{
  object ob;
  ob = clone_object("/std/thing");
  ob -> SetShort("una nota");
  ob -> SetLong("Es una pequeña nota de tu gremio.\n");
  ob -> SetValue(0);
  ob -> SetWeight(0);
  ob -> SetIds(({"nota","papel", "nota de gremio", "nota del gremio", "nota de tu gremio"}));
  ob -> SetAds(({"pequeña","una","la", "pequenya"}));
  ob -> SetReadMsg("De: " + from_name + ".\nFecha: " + STR->etime(1, ctime(date)) + ".\n\n" + msg);
  ob -> Set(P_NOSELL,1);
  return ob;
}

public int ForbidJoin (object pl)

/* Return non-zero if <pl> is not allowed to join the guild.
 * A suitable notify_fail() must be set in that case, too.
 */
{
  return 0;
}


/* [w] Habilidades que se añaden automaticamente.
 */
public mapping QueryGuildSkills() { return copy(gSkills); }

public mapping AddGuildSkill(string skill, int ini, int max, int modif, int level)
{
  if (!skill) return(0);
  gSkills+=([skill:ini;max;modif;level]);
  //Si level==0, entonces el skill no se aprende si no es de alguna manera especial.
  return QueryGuildSkills();
}

public mapping SetGuildSkillLearnMessages(mapping messages)
  { return mSkills=messages; }
public mapping QueryGuildSkillLearnMessages()
  { return mSkills; }
public string SetGuildSkillLearnMessage(string skill, mixed message) {
  if (!mSkills) mSkills=([]);
  if (!member(gSkills, skill)) return 0;
  if (!message || message=="") mSkills+=([skill:"Aprendes la habilidad '"+skill+"'.\n"]);
  else mSkills+=([skill:message]);
  return message;
}
public mapping QueryGuildSkillLearnMessage(string skill) {
  if (!mSkills) mSkills=([]);
  if (!member(gSkills, skill)) return 0;
  if (!member(mSkills, skill)) mSkills+=([skill:"Aprendes la habilidad '"+skill+"'.\n"]);
  return mSkills[skill];
}
public mapping AdvanceSkills() {
  string *idx;
  int i, ql;

  if (!gSkills) return(0);
  idx=m_indices(gSkills);
  if (!idx) return(0);

  for (i=0; i<sizeof(idx); i++) {
    if (TP->QueryGuildLevel()>=gSkills[idx[i], 3] && !TP->HasSkill(idx[i])) {
      TP->AddSkill(idx[i], gSkills[idx[i], 0], gSkills[idx[i], 2], gSkills[idx[i], 1]);
       if (closurep(QueryGuildSkillLearnMessage(idx[i])))
         call_other(TO, QueryGuildSkillLearnMessage(idx[i]), idx[i]);
       else if (stringp(QueryGuildSkillLearnMessage(idx[i])))
         write(QueryGuildSkillLearnMessage(idx[i]));
    }
  }
  return(gSkills);
}

public string ListSkills(string guild) {
  int i;
  string *str=({}), msg="";
  mapping habmap;
//  HAB_MAP: ([ GC_XXX: ([ HAB: NIV; MAX; GRA ]) ])

  if (!(habmap=(HAB_MAP[guild])||(HAB_MAP[guild=QueryGuildclass()]))) return 0;

  foreach (string hab, int niv, int max, int gra : habmap) {
    str += ({ " "+STR->radjust(to_string(niv),3," ")+"  "+STR->ladjust(capitalize(hab),25," ")+"   "+(gra?"si":"no")+"\n" });
  }
  str = sort_array(str, SF(<));
  str += ({"Nivel "+STR->ladjust("Habilidad",25," ")+" Gratis\n"});
  str += ({" Habilidades del "+QueryGuildname()+".\n" });

  for (i=sizeof(str);i--;) msg+=str[i];

  return msg;
}


/* [w] Parte de memorización automatica de Hechizos/conjuros.
 */



public mapping SetGuildSpellLearnMessages(mapping messages)
  { return mSpells=messages;}
public mapping QueryGuildSpellLearnMessages()
  { return mSpells;}
public string SetGuildSpellLearnMessage(string spell, mixed message) {
  if (!mSpells) mSpells=([]);
  if (!member(gSpells, spell)) return 0;
  if (!message || message=="") mSpells+=([spell:"Aprendes la habilidad mágica '"+spell+"'.\n"]);
  else mSpells+=([spell:message]);

  return message;
}
public mapping QueryGuildSpellLearnMessage(string spell) {
  if (!mSpells) mSpells=([]);
  if (!member(gSpells, spell)) return 0;
  if (!member(mSpells, spell)) mSpells+=([spell:"Aprendes la habilidad mágica '"+spell+"'.\n"]);
  return mSpells[spell];
}
public mapping AdvanceSpells() {
  string *idx;
  int i, ql;

  if (!gSpells) return(0);
  idx=m_indices(gSpells);
  if (!idx) return(0);

  for (i=0; i<sizeof(idx); i++) {
    if (TP->QueryGuildLevel()>=gSpells[idx[i], 3] && !TP->HasSpell(idx[i])) {
      if (ql=TP->AddPlayerSpell(idx[i], gSpells[idx[i], 0], gSpells[idx[i], 1], gSpells[idx[i],2])>=1) {
        if (closurep(QueryGuildSpellLearnMessage(idx[i])))
           call_other(TO, QueryGuildSpellLearnMessage(idx[i]), idx[i]);
         else if (stringp(QueryGuildSpellLearnMessage(idx[i])))
           write(QueryGuildSpellLearnMessage(idx[i]));
       }
    }
  }
  return(gSpells);
}


/*
* ----------------------------------------------------------------------
* Comandos
* ----------------------------------------------------------------------
*/

public int cmd_cost(string str)
// RoomCmd "cost"
{
  if (!TP) return 0;
  if (str) return notify_fail("Ese comando no acepta argumentos.\n",NOTIFY_ILL_ARG);
  if (!is_member(getuid(TP))) return notify_fail("No perteneces a este gremio.\n",NOTIFY_NOT_VALID);
  PrintAdvanceCosts(TP);
  return 1;
}

public int cmd_message(string str)
// RoomCmd "message"
{
  string towhom, text;

  if (!check_member(TP))
    return notify_fail("Sólo los miembros del gremio pueden enviar/recibir mensajes.\n",
                            NOTIFY_NOT_OBJ);

  if (!str) return notify_fail("Sintáxis: mensaje <jugador> <texto>.\n", NOTIFY_ILL_ARG);
  if (sscanf(str,"%s %s", towhom, text) != 2 && sizeof(str))
    return notify_fail("Debes especificar tanto el nombre del destinatario como el mensaje a escribir.\n",
                            NOTIFY_ILL_ARG);

  if (!sizeof(towhom))
    return notify_fail("¿A quién le quieres escribir el mensaje?\n",
                            NOTIFY_ILL_ARG);

  if (!is_member(lower_case(towhom)))
    return notify_fail(capitalize(towhom)+" no es miembro del gremio.\n",
                            NOTIFY_NOT_VALID);

  if (!sizeof(text))
    return notify_fail("¿Qué le quieres decir a "+capitalize(towhom)+"?\n",
                            NOTIFY_ILL_ARG);

  AddMessage(towhom,CAP(TNREAL), text);

  write("Mensaje almacenado. Tu mensaje se entregará a " + CAP(towhom) + " cuando le veamos por el gremio.\n");
  return 1;
}

string stat_from_spanish(string what)
{
  if (!what) return what;

  switch (lower_case(what)) {
    case "fza":
    case "fue":
    case "fuerza": return "str";
    case "destreza":
    case "des": return "dex";
    case "constitucion":
    case "constitución":
        case "complexión":
            case "complexion":
    case "con":
    case "cons": return "con";
    case "inteligencia":
    case "int": return "int";
        case "sabiduría":
            case "sabiduria":
                case "sab": return "wis";
                    case "carisma":
                        case "car": return "cha";
  };
  return(what);
}

// RoomCmd "advance"
public int cmd_advance(string str) {
  int newl,maxl;
  mixed h;
  string new_title;

  if (!TP) return 0;
  // the player needs to be a member of our guild
  if (!is_member(TP)) return notify_fail("No eres miembro de este gremio.\n",NOTIFY_NOT_OBJ);
  // ghost can't advance
  if (TP->QueryGhost()) return notify_fail("No puedes avanzar de nivel en tu estado inmaterial.\n",NOTIFY_NOT_OBJ);

  str=stat_from_spanish(str);
  maxl = TP->QueryMaxLevel();
  if (  !sscanf(str = lower_case(str||""),"a %d",newl)
      &&!sscanf(str,"a nivel %d",newl)
      &&!sscanf(str,"al nivel %d",newl)
      &&!sscanf(str,"nivel a nivel %d",newl)
      &&str!="nivel"
      &&str!="")
    if ((member(STATS,capitalize(str))==-1)
        &&member(STATS, (["strength":"Str",
                               "dexterity":"Dex",
                               "constitution":"Con",
                               "intelligence":"Int"])[str])==-1)
      return notify_fail("¿Avanzar qué?\n",NOTIFY_ILL_ARG)||TO->InformAdvance(TP,str);
      // if the std/guild can't identify what the player wants to advance
      // and the guild itself doesn't either (InformAdvance) then give
      // the notify_fail-message
    else { // the player wants to advance one of the stats
      if (h = AdvanceStat(TP,capitalize(str))) TO->InformAdvance(TP,capitalize(str));
      return h;
    }

  // unvalidates nicks can't advance
  if (CHARMASTER->QueryValidName(TNREAL) != NICK_VALID)
  {
    return notify_fail("Tu nombre aún no ha sido validado. Hasta entonces, no "
                       "podrás avanzar de nivel.\n");
  }

  if (xp2level(TP->QueryGuildXP()) < maxl ) maxl=xp2level(TP->QueryGuildXP());
  if (!newl) newl = maxl;
  if (newl>maxl) return notify_fail("No puedes avanzar hasta el nivel "+to_string(newl)+".\n");
//  if (newl==TP->QueryGuildLevel() && <calculo de nivel maximo>==newl) return notify_fail("Ya no puedes avanzar más.\n",NOTIFY_NOT_VALID);
  if (newl<TP->QueryGuildLevel()) return notify_fail("¡No puedes perder un nivel.\n");
  if (newl==TP->QueryGuildLevel()) return notify_fail("No tienes suficientes XP para aumentar el nivel.\n");
  if (newl>maxl)
    if (TP->QueryGuildLevel()<maxl) return notify_fail("Sólo puedes avanzar hasta el nivel "+to_string(maxl)+"\n",NOTIFY_NOT_VALID);
    else return notify_fail("Todavía no puedes aumentar el nivel.\n", NOTIFY_NOT_VALID);
  TP->SetGuildLevel(newl);
  ChangeLevel(getuid(TP),newl);

  if ( sizeof( new_title = GuildLeveltoTitle(newl, TP->QueryGender()) ) )
  { // Gana titulo de gremio
    string my_title;
    if ( !sizeof(my_title = TP->QueryTitle()) || (my_title != new_title) )
    { // Y es distinto del que tengo
      TP->SetTitle(new_title);
    }
  }

  if (newl>=TITLE_LEVEL)  write("Ahora puedes escoger tu título.\n"
                                "Teclea 'ayuda titulo' para más información.\n");
  if (newl>=PRESAY_LEVEL) write("Ahora puedes escoger tu antetítulo.\n"
                                "Teclea 'ayuda antetitulo' para más información.\n");
  if (newl>=DESC_LEVEL)    write("Ahora puedes escoger tu descripción.\n"
                                "Teclea 'ayuda descripcion' para más información.\n");

  //Aqui iba InitSkills
  AdvanceSkills();
  AdvanceSpells();
  TO->InformAdvance(TP,"level"); // InformAdvance may do additional things
  AnnounceNewLevel();
  return 1;
}

// RoomCmd "join"
public int cmd_join(string str) {
  string *s, *r;
  int i;

  if (str&&lower_case(str)!="gremio") return notify_fail("Unirse... ¿a que?\n",NOTIFY_NOT_OBJ);
//Nyh muevo esta linea xq daba problemas con los pj suicidados que luego reaparecian
//  if (is_member(TP)) return notify_fail("Ya eres miembro del gremio.\n",NOTIFY_NOT_OBJ);
  else if (TP->QueryGuild() && TP->QueryGuild() != "ninguno") {
    if (TP->QueryGuild()==guildclass) return notify_fail("Ya eres miembro del gremio.\n",NOTIFY_NOT_OBJ);
    //[t] Ya estas en un gremio... para facilitar las cosas deberias dejar
    //tu gremio anterior y despues unirte a un gremio.
    return notify_fail("Debes notificar a tu gremio anterior que deseas abandonarlo.\n",NOTIFY_NOT_OBJ);
  }

  if (QueryMinStat(P_INT,TP)>TP->QueryTrueInt())
     return notify_fail("No eres suficientemente inteligente.\n",NOTIFY_NOT_VALID);
  if (QueryMinStat(P_CON,TP)>TP->QueryTrueCon())
    return notify_fail("No eres lo bastante fornido.\n",NOTIFY_NOT_VALID);
  if (QueryMinStat(P_STR,TP)>TP->QueryTrueStr())
    return notify_fail("Eres demasiado débil.\n",NOTIFY_NOT_VALID);
  if (QueryMinStat(P_DEX,TP)>TP->QueryTrueDex())
    return notify_fail("No eres suficientemente hábil.\n",NOTIFY_NOT_VALID);
  if (IsBanished(getuid(TP)))
    return notify_fail(capitalize(Banisher(getuid(TP)))+" te ha desterrado del gremio.\n",NOTIFY_NOT_VALID);
  if (ForbidJoin(TP)) return notify_fail("No se te permite ser miembro de este gremio.\n");
  if (TP->QueryOldGuild(guildclass)) {
    write("¡Bienvenido al gremio! Esperábamos tu regreso con impaciencia.\n");
    TP->SetGuildLevel(TP->QueryOldGuildLevel(guildclass));
    TP->SetGuildXP(TP->QueryOldGuildXP(guildclass));
    TP->RemoveOldGuild(guildclass);
    TP->SetGuild(guildclass);
  }
  else {
    write("Ahora eres un miembro de "+guildname+".\n");
    TP->SetGuild(guildclass);
    TP->SetGuildLevel(1);
    TP->SetGuildXP(0);
  }

  //[t] No se tiene informacion del gremio a traves de titulo.
  if (GuildLeveltoTitle(TP->QueryGuildLevel(), TP->QueryGender()))
    TP->SetTitle(GuildLeveltoTitle(TP->QueryGuildLevel(),TP->QueryGender()));
  CorrectStats(TP);
  AddMember(getuid(TP),TP->QueryGuildLevel(),G_MEMBER);

  // Quizás ya hayas estado en este gremio... se te devuelve lo que sabías
  s=HABILIDADES[QueryGuildclass()];
  r=({});
  for (i=0; i<sizeof(s); i++) {
    if (TP->HasSkill(s[i]) && !TP->SkillIsEnabled(s[i])) {
      TP->EnableSkill(s[i]);
      r+=({"'"+s[i]+"'"});
    }
  }
  if (sizeof(r)>1)
    tell_object(TP, W("Recuperas las "
      "habilidades "+implode(r[0..<2], ", ")+(r[<1][1]=='i'?" e ":" y ")+r[<1]+".\n"));
  else if (sizeof(r))
    tell_object(TP, "Recuperas la habilidad "+r[0]+".\n");
  s=HECHIZOS[QueryGuildclass()];

  r=({});
  for (i=0; i<sizeof(s); i++) {
    if (TP->HasSpell(s[i]) && !TP->SpellIsEnabled(s[i])) {
      TP->EnableSpell(s[i]);
      r+=({"'"+s[i]+"'"});
    }
  }
  if (sizeof(r)>1)
    tell_object(TP, W("Recuperas las "
      "habilidades mágicas"+implode(r[0..<2], ", ")+(r[<1][1]=='i'?" e ":" y ")+r[<1]+".\n"));
  else if (sizeof(r))
    tell_object(TP, "Recuperas la habilidad mágica "+r[0]+".\n");

/*
  if (!TO->InformJoin(TP))
    {
      write("You are now a member of the "+
            (guildname||"guild")+".\n");
*/
      if (!TP->QueryInvis())
  {
    say(capitalize(getuid(TP))+" se ha unido al "+QueryGuildname()+".\n");
          if (guildname)
            CHANNELMASTER->SendEmote("ayuda",capitalize(getuid(TP))+
                              " se ha unido al "+QueryGuildname());
        }
/*
    }
*/
  AdvanceSkills();
  AdvanceSpells();
  CreateGuildobject(TP);
  return 1;
}

// RoomCmd "list"
public int cmd_list(string str) {
  int which=0;
  string str1, str2=0;

  if (!str) str = "quests";

  if (sscanf(str=lower_case(str),"%s %s",str1,str2)==2) which=to_int(str2);
  else {
    if (sscanf(str,"%d",which)) str1="quest";
    else if (sscanf(str,"#%d",which)) str1="guildquest";
    else str1 = str;
  }

  switch (str1) {
    case "quests":  return STR->smore(QUESTMASTER->ListQuests(TP),TP->QueryPageSize()),1;
    case "guildquests":  return STR->smore(ListGuildquests(TP),TP->QueryPageSize()),1;
    case "miembros":  return STR->smore(MemberList(),TP->QueryPageSize()),1;
    case "baneados":  return STR->smore(ListBanished(),TP->QueryPageSize()),1;
    case "habilidades":  return STR->smore(ListSkills(str2||QueryGuildclass())),1;
    case "quest":
      STR->smore(QUESTMASTER->QueryQuestLong(--which),TP->QueryPageSize());
      if (QUESTMASTER->QueryQuestSolved(which,TP)) write("Ya has solucionado este quest.\nFelicitaciones especiales de "+QUESTMASTER->QueryQuestCreator(which)+".\n");
      return 1;
    case "guildquest":
      mapping quests;
      ListGuildquests(TP,0,&quests);
      if (!mappingp(quests)) return notify_fail("No hay ningún guildquest.\n",NOTIFY_ILL_ARG);
      if (!member(quests,which)) return notify_fail("No existe ese guildquest.\n",NOTIFY_ILL_ARG);
      STR->smore(TO->QueryGuildquests()[quests[which],Q_LONG]);
      return 1;
    default:
  }
  notify_fail("¿Que quieres listar?\n",NOTIFY_ILL_ARG);
  return TO->InformList(TP,str);
}

public int cmd_help(string str) {
  int what;
  string txt;
  int i;

  if (!str) return notify_fail("¿Ayuda sobre que?\n",NOTIFY_NOT_OBJ);
  what = member(({"aumentar","listar","mensaje","título",
                  "banear","desbanear","minstats","maxstats","características", "titulo",
                  "descripcion","descripción","antetitulo","antetítulo"}),
                  lower_case(str));
  switch(what) {
    case 0: // advance
            txt = TC_BOLD+"aumentar:\n"+TC_NORMAL+
                  TC_UNDERL+"aumentar"+TC_NORMAL+" <con|int|des|fza|sab|car>: avanza uno de tus stats "
                  "(Constitución, Inteligencia, Destreza, Fuerza, Sabiduría o Carisma) un punto, a cambio de una cierta "
                  "cantidad de XP.\n"
                  TC_UNDERL+"aumentar"+TC_NORMAL+" [nivel]: avanza hasta el máximo nivel que puedes "
                  "alcanzar con tus QP y XP.\n"
                  TC_UNDERL+"aumentar"+TC_NORMAL+" [a(l) [nivel] <nr>]: avanza hasta el nivel <nr> si "
                  "es posible.\n";
            break;
    case 1: // join
            txt = TC_BOLD+"unirse:\n"+TC_NORMAL+
                  "Te conviertes en un miembro del gremio. Sólo puedes unirte "
                  "al gremio si no eres miembro de otro, y tienes que tener una "
                  "cierta cantidad de stats para poder unirte (ver tambien: ayuda "
      "minstats, maxstats).\n"
                  "Si tus stats son mayores que los HLP-maxstats del gremio, "
                  "serán ajustados automaticamente.\n";
            break;
    case 2: // list
            txt = TC_BOLD+"listar:\n"+TC_NORMAL+
                  TC_UNDERL+"listar"+TC_NORMAL+" [quests]: lista todos los posibles quests\n"
                  +TC_UNDERL+"listar"+TC_NORMAL+" [quest] <nr>: lista la descripción del quest número <nr>.\n"
                  +TC_UNDERL+"listar"+TC_NORMAL+" guildquests: lista todos los guildquests del gremio.\n"
                  +TC_UNDERL+"listar"+TC_NORMAL+" [guildquest <nr>|#<nr>]: lista la descripción del guildquest número <nr>.\n"
                  +TC_UNDERL+"listar"+TC_NORMAL+" habilidades: lista las habilidades del gremio.\n";
            if (is_member(TP)||IS_LEARNER(TP))
              txt+=TC_UNDERL+"listar"+TC_NORMAL+" miembros: lista todos los miembros del gremio.\n";
            if (is_leader(TP)||IS_LEARNER(TP))
              txt+=TC_UNDERL+"listar"+TC_NORMAL+" baneados: lista todos los jugadores desterrados del gremio.\n";
            break;
    case 3: // message
            txt = TC_BOLD+"mensaje"+TC_NORMAL+" <nombre-jugador> <mensaje-a-enviar>:\n"
                  "Crea un mensaje para otro miembro del gremio. El destinatario del mensaje "
                  "encontrará la nota la proxima vez que entre al gremio.\n";
            break;
    case 4: // title
            txt = TC_BOLD+"título"+TC_NORMAL+":\n"
                "Si perdiste tu título al subir de nivel escribe esto para recuperarlo.\n"
                TC_BOLD+"título"+TC_NORMAL+" <tu título>:\n"
                  "Si cuando avanzaste se te informó de que podías cambiar tu título, usa esto "
                  "para hacerlo.\n";
            break;
    case 5: // banish
            txt = TC_BOLD+"banear"+TC_NORMAL+" <nombre>[,<razon>]:\n"
                  "Si eres un (vice-)guildleader o el propio creador, puedes prohibirle la entrada "
                  "al gremio a un jugador. Si el jugador era miembro, será baneado del gremio.\n"
      +TC_RED+"Los baneos son monitorizados."+TC_CNORMAL+"\n";
            break;
    case 6: // unbanish
            txt = TC_BOLD+"desbanear"+TC_NORMAL+" <nombre>:\n"
                  "Si eres (vice-)guildleader o creador del gremio puedes hacer que un jugador "
                  "baneado del gremio vuelva a poder pertenecer a él.\n";
            break;
    case 7: // minstats
            txt = TC_BOLD+"minstats:\n"+TC_NORMAL+
                  "Son los stats mínimos que tienes que tener para unirte al gremio:\n";
            for (i=0;i<sizeof(STATS);i++)
              txt+=STATS[i]+": "+
                   STR->radjust(to_string(QueryMinStat(STATS[i],TP)),2)+"   ";
            txt+="\n";
            break;
    case 8: // maxstats
            txt = TC_BOLD+"maxstats:\n"+TC_NORMAL+
                  "Son los stats hasta los que puedes avanzar en el gremio:\n";
            for (i=0;i<sizeof(STATS);i++)
              txt+=STATS[i]+": "+
                   STR->radjust(to_string(TP->QueryGuildLevel()<30
         ?QueryMaxStat(STATS[i],TP)
         :QueryMaxHLPStat(STATS[i],TP)),2)+"   ";
            txt+="\n";
            break;
    case 9: // cost
            txt = TC_BOLD+"características:\n"+TC_NORMAL+
      "Te dará información detallada sobre lo que necesitas para avanzar los stats o "
                  "el nivel.\n";
            break;
    case 10: // title
            txt = TC_BOLD+"título"+TC_NORMAL+" <tu título>:\n"
                  "Si cuando avanzaste se te informó de que podías cambiar tu título, usa esto "
                  "para hacerlo.\n";
            break;
    case 11: // descripcion
    case 12:
            txt = TC_BOLD+"descripción"+TC_NORMAL+" <tu descripción>:\n"
                  "Si cuando avanzaste se te informó de que podías cambiar tu descripción, usa esto "
                  "para hacerlo.\n";
            break;
    case 13: //antetitulo
    case 14:
            txt = TC_BOLD+"antetítulo"+TC_NORMAL+" <tu antetítulo>:\n"
                  "Si cuando avanzaste se te informó de que podías cambiar tu antetítulo, usa esto "
                  "para hacerlo.\n";

    default:
             notify_fail("No hay ayuda sobre '"+str+"'.\n",NOTIFY_ILL_ARG);
             return TO->InformHelp(TP,str);
    }
  STR->smore(W(txt),TP->QueryPageSize());
  return 1;
}

public int cmd_leave() {
  string warn, *str, *h, *m;
  int i;

  if (!TP) return 0;
  if (!is_member(getuid(TP)))
    return notify_fail("No eres un miembro del gremio.\n",
                            NOTIFY_NOT_VALID);
  warn=TC_RED+"ATENCION"+TC_CNORMAL+": Si renuncias perderás ";

  str=HABILIDADES[QueryGuildclass()];
  h=({});
  for (i=0; i<sizeof(str); i++)
  {
    if (member(HAB_GENERALES, str[i])==-1 && TP->HasSkill(str[i]))
      h+=({"'"+TC_BOLD+str[i]+TC_NORMAL+"'"});
  }

  str=HECHIZOS[QueryGuildclass()];
  m=({});
  for (i=0; i<sizeof(str); i++)
  {
    if (TP->HasSpell(str[i]))
      m+=({"'"+TC_BOLD+str[i]+TC_NORMAL+"'"});
  }
  if (sizeof(h)>1)
    warn+="las habilidades "+implode(h[0..<2], ", ")+(h[<1][5]=='i'?" e ":" y ")+h[<1];
  else if (sizeof(h))
    warn+="la habilidad "+h[0];

  if (sizeof(h) && sizeof(m))
  {
    if (TP->QueryGuildLevel()<2)
      warn+=" y ";
    else
      warn+=", ";
  }
  if (sizeof(m)>1)
    warn+="las habilidades mágicas "+implode(m[0..<2], ", ")+(m[<1][5]=='i'?" e ":" y ")+m[<1];
  else if (sizeof(m))
    warn+="la habilidad mágica "+m[0];

  i=TP->QueryGuildLevel();
  if (i>1)
  {
    i--;
    if (sizeof(h) || sizeof(m))
      warn+=", ";
    warn+=TC_BOLD+"un nivel "+TC_NORMAL+"y "+
      TC_BOLD+NMB->abs(level2xp(i)-TP->QueryGuildXP())+TC_NORMAL+
      " puntos de experiencia de este gremio";
  }
  warn+=".\n";
  if (sizeof(h) || sizeof(m))
    warn+="Más adelante podrías volver a ingresar, serías nivel "+i+" y "
      "volverías a tener tus habilidades, pero mientras tanto no las podrás "
      "usar y con el paso del tiempo podrías olvidarlas.\n";
  write(warn);

  write("¿Realmente quieres renunciar? (si/[no]) ");
  input_to("check_leave",0,TP);
  return 1;
}

public int cmd_banish(string str)
{
  string whom,why,err;
  object pl,*obs;
  int i;

  if (!TP) return 0;
  if (!str)
    return notify_fail("¿A quién quieres banear?\n",NOTIFY_ILL_ARG);
  if (sscanf(lower_case(str),"%s %s",whom,why)!=2)
    whom = lower_case(str),why = 0;
  if ((err = AddBanish(whom,why))!=NO_ERR)
    return notify_fail(err,NOTIFY_NOT_VALID);
  if (pl = find_object(whom))
    {
      tell_object(pl,"Has sido baneado en el "+guildname+" por "+
                     Banisher(getuid(TP))+".\n");
      if (pl->QueryGuild()==guildclass)
        {
          pl->SetGuild(0);
          pl->SetGuildLevel(0);
          if (guildobject)
            if (i = sizeof(obs = filter(map(all_inventory(pl),
                                                        SF(blueprint)
                                                       ),
                                              lambda(({SYM(v)}),
                                                     ({SF(==),SYM(v),
                                                       guildobject})
                                                    )
                                            )
                         )
              )
              while(i--)
                obs[i]->check_owner(pl);
          //pl->SetTitle("the former "+guildclass);
  }
    }
  RemoveMember(whom);
  write("Ok.\n");
  return 1;
}

public int cmd_unbanish(string str)
{
  string err;
  if (!TP) return 0;
  if (!str)
    return notify_fail("¿A quién quieres desbanear?\n",NOTIFY_ILL_ARG);
  str = lower_case(str);
  if ((err = RemoveBanish(str))!=NO_ERR)
    return notify_fail(err,NOTIFY_NOT_VALID);
  write("Ok.\n");
  return 1;
}

public int cmd_title(string str) {
  if (!TP) return 0;
  if (!is_member(TP))
    return notify_fail("No eres un miembro de este gremio.\n",NOTIFY_NOT_OBJ),0;
  if (TP->QueryGuildLevel()<TITLE_LEVEL /*&& QueryLevelTitles()[TP->QueryGuildLevel()]*/)
    return notify_fail("Necesitas ser al menos de nivel "+to_string(TITLE_LEVEL)+
          " para poder cambiarte el título.\n",NOTIFY_NOT_OBJ),0;
//  if (find_object("nyh")) dtell("nyh",sprintf("str = %O\nOwnTitle= %O\n",str, TP->QueryAttr(P_OWN_TITLE)));
  if (!str) {
    if ((str=TP->QueryAttr(P_OWN_TITLE)) && str!=TP->QueryTitle()) {
//      if (find_object("nyh")) dtell("nyh",sprintf("str = %O\nOwnTitle= %O\n",str, TP->QueryAttr(P_OWN_TITLE)));
      write("Recuperas tu antiguo título.\n");
      TP->SetTitle(str);
      return 1;
    }
    else return notify_fail("¿Cambiarte el titulo a qué?\n",NOTIFY_ILL_ARG),0;
  }
  if (MONEY_LIB->QuerySomeonesValue(TP)<TITLE_PRICE)
    return notify_fail(W("Para poder cambiarte el título deberás pagar "+
      MONEY_DEMON->QueryValueString(TITLE_PRICE)+".\n")),0;
  TP->SetTitle(str);
  TP->SetAttr(P_OWN_TITLE,str);
  log_file("TITULOS","["+(STR->etime())+"] "+capitalize(TP->QueryRealName())+" se ha puesto como título: "+str+"\n");
  return 1;
}

public int cmd_presay(string str) {
  if (!TP) return 0;
  if (!is_member(TP))
    return notify_fail("No eres un miembro de este gremio.\n",NOTIFY_NOT_OBJ),0;
  if (TP->QueryGuildLevel()<PRESAY_LEVEL)
    return notify_fail("Necesitas ser al menos de nivel "+to_string(PRESAY_LEVEL)+
          " para poder cambiarte el antetítulo.\n",NOTIFY_NOT_OBJ),0;
  if (!str) return notify_fail("¿Cambiarte el antetítulo a qué?\n",NOTIFY_ILL_ARG),0;
  if (MONEY_LIB->QuerySomeonesValue(TP)<PRESAY_PRICE)
    return notify_fail(W("Para poder cambiarte el antetítulo deberás pagar "+
      MONEY_DEMON->QueryValueString(PRESAY_PRICE)+".\n")),0;
  TP->SetPresay(str+" ");
  TP->SetAttr(P_OWN_PRESAY,str+" ");
  log_file("ANTETITULOS","["+(STR->etime())+"] "+capitalize(TP->QueryRealName())+" se ha puesto como antetítulo: "+str+"\n");
  return 1;
}



public int cmd_desc() {
  if (!TP) return 0;
  if (!is_member(TP))
    return notify_fail("No eres un miembro de este gremio.\n",
                            NOTIFY_NOT_OBJ);
  if (TP->QueryGuildLevel()<DESC_LEVEL)
    return notify_fail("Necesitas ser al menos de nivel "+to_string(DESC_LEVEL)+
          " para poder cambiarte la descripción.\n",NOTIFY_NOT_OBJ);

  if (MONEY_LIB->QuerySomeonesValue(TP)<DESC_PRICE)
    return notify_fail("Para poder cambiarte la descripción deberás pagar "+
                     MONEY_DEMON->QueryValueString(DESC_PRICE)+".\n");
  write("Teclea a continuación tu descripción. Para finalizar, escribe un punto (.) en "
        "una línea vacía. No te preocupes si te equivocas, antes de proceder al cambio se "
        "te permitirá visualizarla tal y como será vista por los demás, y cambiarla "
        "o volver a escribirla.\n");
  input_to("almacena_desc", INPUT_PROMPT, "Descripción: (" + to_string(DESC_MAX) +
           " caracteres restantes)", "");
  return 1;
}

public void almacena_desc(string str, string total)
{
    int tam;
    if (!TP) return;
    if (str == ".")
    // fin de la descripción
    {
        if (total == "")
        // no ha escrito nada
        {
            write("No has escrito ninguna descripción. Saliendo.\n");
            return;
        }
        write("Tu descripción quedará del siguiente modo:\n" + total);
        input_to("confirmar_desc", INPUT_PROMPT,
                 "¿Pulsa s para confirmarla, n para volver a escribirla, o x para salir.\n",
                 total);
        return;
    }
    if ((tam = strlen(total + str)) > DESC_MAX)
    {
        write("Tu descripción ha sobrepasado en " + to_string(tam - DESC_MAX) + " caracteres "
              "el máximo de " + to_string(DESC_MAX) +
              " caracteres establecido. La última línea se ignorará. Si deseas "
              "escribir tu descripción  de nuevo, finaliza la actual, cancela el "
              "resultado y vuelve a empezar.\n");
    }
    else
    {
        total += str + "\n";
    }
    input_to("almacena_desc", INPUT_PROMPT, "* (" + to_string(DESC_MAX - strlen(total)) +
             " caracteres restantes)\n", total);
}

public void confirmar_desc(string respuesta, string desc)
// función para confirmar o rechazar una descripción
{
    string msg;
    if (member(({"s", "n", "x"}), respuesta) < 0)
    // no ha pulsado ninguna de las tres opciones disponibles
    {
        input_to("confirmar_desc", INPUT_PROMPT,
                 "Elige una de las siguientes opciones: s para confirmar la descripción, "
                 "n para volver a escribirla, o x para salir.\n", desc);
        return;
    }
    if (respuesta == "x")
    {
        write("Saliendo...\n");
        return;
    }
    if (respuesta == "n")
    {
        cmd_desc();
        return;
    }
    if (!stringp(msg = MONEY_LIB->PayValueString(TP, DESC_PRICE, 0,
                                                 "por el cambio de descripción")))
    // ha fallado el pagar. Devolvemos un error... NO podemos devolver el del pagar,
    // porque el input_to no permite devolver 0 o 1 en caso de éxito o error y por
    // lo tanto, no podemos sacar el mensaje del notify_fail.
    {
        write("Ha sido imposible cobrarte el dinero de la descripción.\n");
        return;
    }

    write(msg);
    TP->SetLong(desc);
    TP->SetAttr(P_OWN_LONG, desc);
    log_file("DESCRIPCIONES", sprintf("%-78=s", "     "+CAP(TNREAL)+" ["+(STR->etime())+
             "] se ha puesto como descripción:\n" + desc + "\n"));
    write("Descripción modificada.\n");
}


public int cmd_quit()
{
  object *inv,pl;
  pl = PO;
  if (!IS_LEARNER(pl)
      &&sizeof(inv = filter(all_inventory(pl),SF(check_for_guildob)))
      &&inv[0]->QuerySource())
    inv[0]->gtp();
  return 0;
}

/*
* ----------------------------------------------------------------------
* create, init, reset .. the global functions
* ----------------------------------------------------------------------
*/

public varargs string QueryIntLong(mixed what)
{
  if (what) return (::QueryIntLong(what));
  return (::QueryIntLong())+(sign?sign[POS_ROOM]:"")+
         (list?list[POS_ROOM]:"");
}

public void create_ob()
// Sólo se ejecuta cuando se crea un objeto, no cuando se carga para ser heredado
{
  "*"::create();
  if (!gSkills) gSkills=m_allocate(0, 4);
  if (!gSpells) gSpells=m_allocate(0, 3);
  call_out("update_toplist",2+random(5));
  SetIntShort("un gremio");
  SetIntLong("Estás en un gremio.\n");

  AddDetail("gremio","Estas en él.\n");
  ChangeSign(({"tablón","tablon", "tablon de madera","tablón de madera", "panel",
    "panel de madera"}),
    "Es un tablón de madera en el que puedes leer:\n",
    "Ves un tablón de madera ");
  ChangeList(({"lista"}),"",
    "y lo que parece una lista en la pared.\n");
  AddDetail("pared","Hay un tablón fijado en la pared.\n");
  AddRoomCmd("renunciar",SF(cmd_leave));
  AddRoomCmd("banear",SF(cmd_banish));
  AddRoomCmd("desbanear",SF(cmd_unbanish));
  AddRoomCmd(({"características", "caracteristicas", "stats", "atributos"}),SF(cmd_cost));
  AddRoomCmd("unirse",SF(cmd_join));
  AddRoomCmd(({"mejorar","aumentar","avanzar"}),SF(cmd_advance));
  AddRoomCmd("ayuda",SF(cmd_help));
  AddRoomCmd("listar",SF(cmd_list));
  AddRoomCmd("mensaje",SF(cmd_message));
  AddRoomCmd("titulo",SF(cmd_title));
  AddRoomCmd("título",SF(cmd_title));
  AddRoomCmd("antetítulo",SF(cmd_presay));
  AddRoomCmd("antetitulo",SF(cmd_presay));
  AddRoomCmd("presay",SF(cmd_presay));
  AddRoomCmd("ante",SF(cmd_presay));
  AddRoomCmd("descripcion",SF(cmd_desc));
  AddRoomCmd("descripción",SF(cmd_desc));
  AddRoomCmd("quit",SF(cmd_quit)); // to prevent cheating for guildleaders

  REGISTER->Register(TO,MYREG);
}

public void init() {
  ::init();
  if (TP&&TP->QueryGuild()==guildclass&&IsBanished(getuid(TP)))
    call_out("banished_entered",1);
  if (TP&&is_member(getuid(TP))&&TP->QueryGuild()==guildclass)
  call_out("member_entered",1);
}

public int prevent_leave(mixed dest,int method,mixed extra)
{
  object *inv,pl;
  pl = PO;
  if (!IS_LEARNER(pl)
      &&sizeof(inv = filter(all_inventory(pl),SF(check_for_guildob)))
      &&inv[0]->QuerySource())
    return ME_NO_LEAVE;
  return (::prevent_leave(dest,method,extra));
}

public void reset()
{
  string *m,h;
  m = m_indices(QueryMembers(1)||([]));
  m -= filter(m,SF(find_savefile));
  map(m,SF(RemoveMember));
  if ((h = QueryGuildleader())&&IS_LEARNER(h))
    {
      ChangeStat(h,G_MEMBER);
      if (h=QueryViceGuildleader())
        ChangeStat(h,G_LEADER);
    }
  if ((h = QueryViceGuildleader())&&IS_LEARNER(h))
    ChangeStat(h,G_MEMBER);
  call_out("update_toplist",2);
  (::reset());
}

public int allow_enter(int method,mixed extra)
{
  if (object_name(TO) == MYFILE) return ME_NO_ENTER;
  return ::allow_enter(method,extra);
}


