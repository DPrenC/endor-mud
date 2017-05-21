// Creado por Woo para las Kisalas.
// Adaptado por Izet para los asesinos.
// Modificado por Nyh en los asesinos.
// [w] Woo@Simauria
// [I] Izet@Simauria
// [h] Nyh@Simauria

#include <properties.h>
#include <guild.h>
#include <skills.h>
#include <colours.h>
#include <combat.h>
#include <moving.h>
#include <wizlevels.h>
#include "./path.h"

inherit "/std/thing";
inherit G_GUILDOBJ;

#define DEBUG 1 //[w] Descomentar solo en modo debug.

/*
 ======================
   [I] VARIABLES
 ======================
*/
static object asesino;
static object mascota;
static string nombre_asesino;

varargs string QuerySaveName(string appendix) {
 string s;

 if(!appendix) appendix="";
 if(nombre_asesino) s=lower_case(nombre_asesino);
 else s="nadie";
 s=s+appendix;
 s=ASESINO_SAVE(s);
 return s;
}

object QueryObjectOwner() { return asesino; }

int SetObjectOwner(object jug) {
 if (!jug || !jug->QueryIsPlayer()) return 0;
 asesino=jug;
 nombre_asesino=jug->QueryRealName();
 return 1;
}

int HasSkill(string habilidad) {
 return QueryObjectOwner()->HasSkill(habilidad);
}

string QueryLong() {
  string s;
  s="Es la Rosa Negra del gremio de asesinos.\n";
  if (TP==QueryObjectOwner())
    s+="Puedes usar el comando 'gayuda' para obtener más datos acerca del gremio.\n";
  return s;
}

void create() {
  int i;
  object *armas;

  ::create();
 seteuid(getuid());

  SetMaterial(M_ORO);
  SetSize(P_SIZE_GENERIC);
  SetShort("la rosa negra");

  SetGuild("/guilds/asesinos/gremio");

  if (TP) {
    SetObjectOwner(TP);
    //if (TP->QueryGuild()!=GC_ASESINOS && !IS_LEARNER(TP)) call_out("remove",1);
  }
  SetIds( ({"rosa","rosa negra"}) );
  SetWeight(0);
  SetValue(0);
  Set(P_GENDER,GENDER_MALE);
  Set(P_NUMBER,NUMBER_SINGULAR);
  Set(P_NOSELL,"No puedes vender tu rosa negra.\n");
  Set(P_NOBUY, "No puedes comprar una rosa negra.\n");
  Set(P_NOGIVE,"Hmmm, mejor no dársela a nadie..\n");
  Set(P_NODROP,"Hmmm, mejor no tirarla por ahí.\n");
  restore_object(QuerySaveName(""));
  if (clonep(TO)) // Comprobación para que no pueda ver dos veces las noticias.
  if (file_size(GASESINOS + "NOTICIAS") > 0) cat(GASESINOS+"NOTICIAS");
}

void destruye(){
   TO->remove();
   destruct(TO);
}

void init(){
  object ob;

  ::init();
  if (!TP) return;
  ob=QueryObjectOwner();

/*
  if(!(environment(TO)->QueryIsPlayer())) {
     call_out("destruye",1);
     return;
  }
*/
  if (ob && ob==TP)   {
     //ob->AddArmour(TO);
//     add_action("cmd_estado", "estado");
     add_action("cmd_gayuda", "gayuda");
     add_action("cmd_gbug",   "gbug"  );
     add_action("cmd_quien",  "gquien");
     add_action("cmd_salvar", "salvar");
     add_false_cmds();
  }
}

public int Debug(string texto){
#ifndef DEBUG
  return 0;
#else
  LOG("DEBUG","> "+texto+"\n");
  return 1;
#endif
}

public int SaveMe() {
  save_object(QuerySaveName(""));
  return 1;
}

int remove() {
  if(QueryObjectOwner()) SaveMe();
  return ::remove();
}

/*
 ======================
   [w] COMANDOS 'CMD'
 ======================
*/
int cmd_estado() {
 string msg;

 if (TP->QueryGhost()) return 0;
 msg="Eres "CROJO+CAP(TP->QueryRealName())+CNORMAL", ";
 write(msg);
 return 1;
}

int cmd_gayuda(string str) {
  string s;

  if (!str) {
    s="Escribe '"CNEGRITA"gayuda <tema>"CNORMAL"' para obtener mas informacion.\nTemas disponibles:\n"
    "  "CVERDE"historia"CNORMAL"....... Historia de los asesinos.\n"
    "  "CVERDE"gremio"CNORMAL"......... Informacion genérica acerca del gremio.\n"
    "  "CVERDE"comandos"CNORMAL"....... Comandos especiales del gremio.\n"
    "  "CVERDE"habilidades"CNORMAL".... Información acerca de las distintas habilidades.\n";
    write(s);
    return 1;
  }
  s=GASESINOS+"ayuda/"+str;
  if(file_size(s)<=0) return notify_fail("No existe información sobre ese tema.\n"),0;
  STR->smore(read_file(s));
  return 1;
}

int cmd_salvar(string str) {
 SaveMe();
 return 0;
}

string nivel(int n) {
  if (!n || n<0) return "desastroso";
  if (n>100) return "perfecto";
  switch (n) {
    case 0..4:   return "desastroso";
    case 5..9:   return "fatal";
    case 10..14: return "pésimo";
    case 15..19: return "muy mal";
    case 20..24: return "bastante mal";
    case 25..29: return "mal";
    case 30..39: return "regular";
    case 40..49: return "aceptable";
    case 50..54: return "adecuado";
    case 55..64: return "bueno";
    case 65..69: return "muy bueno";
    case 70..79: return "excelente";
    case 80..89: return "óptimo";
    case 90..98: return "casi perfecto";
    case 99..100: return "perfecto";
    default: return "desconocido";
  }
  return "desconocido";
}

protected string who_list() {
  object *obs;
  string msg;
  int i;
  int seeinvis, invis;

  LoadGuild();
  obs=guild_users();
  msg="";

  seeinvis=QueryObjectOwner()->QuerySeeInvis();

  for (i=0; i<sizeof(obs); i++) {
    if (invis = obs[i]->QueryInvis()) {
      if (invis > seeinvis) continue;
      else {
        msg+=TC_GREEN"|"TC_NORMAL+"  ("+capitalize(obs[i]->QueryRealName())+" )";
        msg+=TC_GREEN" ("TC_NORMAL+capitalize(obs[i]->QueryRace()||"")+", "+obs[i]->QueryGuildLevel()+TC_GREEN"]"TC_NORMAL;
        if (QueryGuildObject()->is_creator(obs[i])) msg+=TC_CYAN" - Creador -\n"TC_NORMAL;
        else if (QueryGuildObject()->is_leader(obs[i])) msg+=TC_RED" - Líder -\n"TC_NORMAL;
        else msg+="\n";
      }
    }
    else {
      msg+=TC_GREEN"|"TC_NORMAL"  "+capitalize(obs[i]->QueryRealName())+"  "+obs[i]->QueryTitle();
      msg+=TC_GREEN" ["TC_NORMAL+capitalize(obs[i]->QueryRace()||"")+", "+obs[i]->QueryGuildLevel()+TC_GREEN"]"TC_NORMAL;
      if (QueryGuildObject()->is_creator(obs[i])) msg+=TC_CYAN"\t - Creador -\n"TC_NORMAL;
      else if (QueryGuildObject()->is_leader(obs[i])) msg+=TC_RED"\t - Líder -\n"TC_NORMAL;
      else msg+="\n";
    }
  }
  return msg;
}

public int cmd_quien(string arg)
{
  if (!TP) return 0;

  switch(TP->QueryTTY())
  {
     case "ansi":
     {
        STR->smore(TC_GREEN"\n"
           "---,--'--{"TC_RED"@"TC_GREEN" "
           "---,--'--{"TC_RED"@"TC_GREEN" "
           "---,--'--{"TC_RED"@"TC_GREEN" "
           "---,--'--{"TC_RED"@"TC_GREEN" "
           "---,--'--{"TC_RED"@"TC_GREEN" "
           "---,--'--{"TC_RED"@"TC_GREEN" "
           "\n                     "
           TC_YELLOW"L A S  R O S A S  N E G R A S"TC_NORMAL
           "\n"
           TC_RED"@"TC_GREEN"}--'--,--- "
           TC_RED"@"TC_GREEN"}--'--,--- "
           TC_RED"@"TC_GREEN"}--'--,--- "
           TC_RED"@"TC_GREEN"}--'--,--- "
           TC_RED"@"TC_GREEN"}--'--,--- "
           TC_RED"@"TC_GREEN"}--'--,--- "
           "\n"TC_NORMAL+who_list()+TC_GREEN+
           "---,--'--{"TC_RED"@"TC_GREEN" "
           "---,--'--{"TC_RED"@"TC_GREEN" "
           "---,--'--{"TC_RED"@"TC_GREEN" "
           "---,--'--{"TC_RED"@"TC_GREEN" "
           "---,--'--{"TC_RED"@"TC_GREEN" "
           "---,--'--{"TC_RED"@"TC_GREEN" "
           "\n                     "TC_NORMAL,TP->QueryPageSize());
        break;
     }
     default:
     {
        STR->smore(
           "\n---,--'--{@ ---,--'--{@ ---,--'--{@ ---,--'--{@ ---,--'--{@ ---,--'--{@ "
           "\n                     L A S  R O S A S  N E G R A S\n"
           "\n@}--'--,--- @}--'--,--- @}--'--,--- @}--'--,--- @}--'--,--- @}--'--,--- "
           "\n"+who_list()+
"---,--'--{@ ---,--'--{@ ---,--'--{@ ---,--'--{@ ---,--'--{@ ---,--'--{@ "
           ,TP->QueryPageSize());
        break;
     }
  }
  return 1;
}
